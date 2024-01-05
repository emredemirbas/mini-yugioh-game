//
// Created by faruk on 20.12.2023.
//

#include "GUIGameWindow.h"
#include <iostream>

#define WINDOW_HEIGHT 1080
#define WINDOW_WIDTH 1920
#define WINDOW_TITLE "Mini YuGiOh! Game"

#define CARD_PLACE_HEIGHT 175
#define CARD_PLACE_WIDTH 125


GUIGameWindow::GUIGameWindow(sf::RenderWindow *window, GameManager *gameManager, GUIGameState *guiGameState) : GUIWindow(window),
                                                                                                               pauseMenu(window, guiGameState) {
    this->gameManager = gameManager;
    this->isBattlePhaseClockStarted = false;
    this->initTextures();
    this->initWindow();
    this->initButtons();
    this->initWindowElements();
    this->initGame();
    this->guiGameState = guiGameState;

};

GUIGameWindow::~GUIGameWindow() {
    delete this->window;
    delete this->backgroundTexture;
    delete this->deckTexture;
    delete this->deckOppositeTexture;

    delete this->currentPlayersPlayingField;
    delete this->opposingPlayersPlayingField;

    delete this->currentPlayersPlayerPanel;
    delete this->opposingPlayersPlayerPanel;

    delete this->currentPlayersHand;
    delete this->opposingPlayersHand;

    delete this->currentPlayersGraveyard;
    delete this->opposingPlayersGraveyard;

    delete this->cardInfoPanel;

    delete this->mainPhaseText;
    delete this->battlePhaseText;
}

const bool GUIGameWindow::isRunning() {
    return this->window->isOpen() && gameManager->determineWinner() == nullptr;
}

void GUIGameWindow::initTextures() {
    this->backgroundTexture = new sf::Texture();
    this->backgroundTexture->loadFromFile("textures/background1.jpg");

    this->deckTexture = new sf::Texture();
    this->deckTexture->loadFromFile("textures/deck.png");

    this->deckOppositeTexture = new sf::Texture();
    this->deckOppositeTexture->loadFromFile("textures/deck_opposite.png");

    this->cardBackTexture = new sf::Texture();
    this->cardBackTexture->loadFromFile("textures/card_back.png");

    this->yugiWinsTexture = new sf::Texture;
    this->yugiWinsTexture->loadFromFile("textures/yugiwins.png");
    this->yugiWinsSprite.setTexture(*yugiWinsTexture);

    this->setoWinsTexture = new sf::Texture;
    this->setoWinsTexture->loadFromFile("textures/setowins.png");
    this->setoWinsSprite.setTexture(*setoWinsTexture);
}

void GUIGameWindow::initWindow() {
    sf::Vector2u windowSize = this->window->getSize(); // Get size of window.
    sf::Vector2u textureSize = backgroundTexture->getSize(); // Get size of texture.
    float scaleX = (float) windowSize.x / textureSize.x;
    float scaleY = (float) windowSize.y / textureSize.y; // Calculate scale.

    this->backgroundSprite.setTexture(*this->backgroundTexture);
    this->backgroundSprite.setScale(scaleX, scaleY);
    this->backgroundSprite.setTexture(*this->backgroundTexture);
}

void GUIGameWindow::initWindowElements() {
    this->currentPlayersHand = new GUIHand(398.f, 950.f);
    this->opposingPlayersHand = new GUIHand(398.f, -25.f);

    this->currentPlayersPlayingField = new GUIPlayingField(600.f, 550.f);
    this->opposingPlayersPlayingField = new GUIPlayingField(600.f, 325.f, true);

    this->currentPlayersGraveyard = new GUIGraveyard(1350.f, 545.f);
    this->opposingPlayersGraveyard = new GUIGraveyard(450.f, 335.f);

    this->currentPlayersPlayerPanel = new GUIPlayerPanel(0, 850);
    this->opposingPlayersPlayerPanel = new GUIPlayerPanel(0, 25);

    this->cardInfoPanel = new GUICardInfoPanel(1580, 25);

    this->mainPhaseText = new GUIPhaseText(825, 400);
    this->mainPhaseText->setTextString("MAIN PHASE");

    this->battlePhaseText = new GUIPhaseText(815, 400);
    this->battlePhaseText->setTextString("BATTLE PHASE");
}

void GUIGameWindow::initButtons() {

}

void GUIGameWindow::drawDecks() {
    //Set deckArea's attributes.
    sf::RectangleShape deckArea(sf::Vector2f(CARD_PLACE_WIDTH + 25, CARD_PLACE_HEIGHT));
    deckArea.setOutlineColor(sf::Color::Black);
    deckArea.setOutlineThickness(2);
    deckArea.setTexture(this->deckTexture);

    deckArea.setPosition(1355.f, 735.f);
    this->window->draw(deckArea);

    deckArea.setPosition(425.f, 140.f);
    deckArea.setTexture(this->deckOppositeTexture);
    this->window->draw(deckArea);
}

void GUIGameWindow::update() {
    while (this->window->pollEvent(this->event)) {
        if (event.type == sf::Event::Closed) {
            this->guiGameState->setGUIGameState(GuiState::EXIT);
            this->window->close();
        } else if (event.type == sf::Event::KeyPressed) {
            if (this->event.key.code == sf::Keyboard::Key::Escape) {
                this->guiGameState->setGUIGameState(GuiState::PAUSE_MENU);
            }
        }
        this->updateCardInfoPanel();
        this->iterateTurn();
    }
}

void GUIGameWindow::initGame() {
    this->gameManager->initializeGame();
}

void GUIGameWindow::iterateMainPhase1() {
    //Handle playing card operation.
    if (this->event.type == sf::Event::MouseButtonPressed) {
        if (this->event.mouseButton.button == sf::Mouse::Button::Left) {
            if (!this->gameManager->getIsCurrentPlayerPlayedCardAtMP()) {
                int selectedIndex = this->currentPlayersHand->getClickedCardAreaIndex(this->window);
                if (selectedIndex != -1) {
                    this->gameManager->mainPhase(selectedIndex);
                }
            }
        }else if(this->event.mouseButton.button == sf::Mouse::Button::Right){
            if(!this->gameManager->getIsCurrentPlayerChangedCardModeAtMP()){
                int selectedIndex = this->currentPlayersPlayingField->getClickedMonsterCardAreaIndex(this->window);
                if(selectedIndex != -1 && this->gameManager->getCurrentPlayer()->getPlayingField()->getMonsterField().at(selectedIndex) != nullptr){
                    this->gameManager->changeCardMode(selectedIndex);
                    this->display();
                }
            }
        }
    }
}

void GUIGameWindow::iterateBattlePhase() {
    int attackerIndex = -1;
    int targetIndex = -1;

    //If current player has no attacking monster in field, end battle phase.

    if (!this->gameManager->getCurrentPlayer()->getPlayingField()->isThereAttackingMonsterInField()) {
        this->gameManager->battlePhase(-1, -1);
        return;
    }

        //If opposing player has no monster in its field perform attack on opposing players lifepoints.
    else if (!this->gameManager->getOpposingPlayer()->getPlayingField()->isThereMonsterInField()) {
        while (attackerIndex == -1) {
            this->window->pollEvent(this->event);
            this->updateCardInfoPanel();
            this->display();
            if (this->event.type == sf::Event::MouseButtonPressed) {
                if (this->event.mouseButton.button == sf::Mouse::Button::Left) {
                    int index = this->currentPlayersPlayingField->getClickedMonsterCardAreaIndex(this->window);
                    if(index != -1 && this->gameManager->getCurrentPlayer()->getPlayingField()->getMonsterField().at(index)->isAttackMode()){
                        attackerIndex = index;
                    }
                }
            }
        }
        this->gameManager->battlePhase(attackerIndex, -1);
        return;
    }

        //If current player and opposing player both has monsters in their fields.
    else {
        while (attackerIndex == -1) {
            this->window->pollEvent(this->event);
            this->updateCardInfoPanel();
            this->display();
            if (this->event.type == sf::Event::MouseButtonPressed) {
                if (this->event.mouseButton.button == sf::Mouse::Button::Left) {
                    int index = this->currentPlayersPlayingField->getClickedMonsterCardAreaIndex(this->window);
                    if(index != -1 && this->gameManager->getCurrentPlayer()->getPlayingField()->getMonsterField().at(index)->isAttackMode()){
                        attackerIndex = index;
                    }
                }
            }
        }

        while (targetIndex == -1) {
            this->window->pollEvent(this->event);
            this->updateCardInfoPanel();
            this->display();
            if (this->event.type == sf::Event::MouseButtonPressed) {
                this->window->pollEvent(this->event);
                if (this->event.mouseButton.button == sf::Mouse::Button::Left) {
                    targetIndex = this->opposingPlayersPlayingField->getClickedMonsterCardAreaIndex(this->window);
                }
            }
        }
        gameManager->battlePhase(attackerIndex, targetIndex);
    }
}

void GUIGameWindow::iterateTurn() {
    if (this->gameManager->getGameState() == DRAW_PHASE) {
        this->gameManager->drawPhase();
    } else if (this->gameManager->getGameState() == MAIN_PHASE) {
        this->iterateMainPhase1();

        while(gameManager->determineWinner() != nullptr && guiGameState->getGUIGameState() != GuiState::MAIN_MENU){
            if(gameManager->determineWinner()->getName() == "Yugi Muto"){
                this->window->draw(yugiWinsSprite);
                this->window->display();
                winnerEvents();
            }
            else if(gameManager->determineWinner()->getName() == "Seto Kaiba"){
                this->window->draw(setoWinsSprite);
                this->window->display();
                winnerEvents();
            }
        }

    } else if (this->gameManager->getGameState() == BATTLE_PHASE) {
        if(!this->isBattlePhaseClockStarted){
            this->battlePhaseClock.restart();
            this->isBattlePhaseClockStarted = true;
        }
        this->iterateBattlePhase();

        while(gameManager->determineWinner() != nullptr && guiGameState->getGUIGameState() != GuiState::MAIN_MENU){
            if(gameManager->determineWinner()->getName() == "Yugi Muto"){
                this->window->draw(yugiWinsSprite);
                this->window->display();
                winnerEvents();
            }
            else if(gameManager->determineWinner()->getName() == "Seto Kaiba"){
                this->window->draw(setoWinsSprite);
                this->window->display();
                winnerEvents();
            }
        }

    } else if (this->gameManager->getGameState() == END_PHASE) {
        this->gameManager->endPhase();
        this->mainPhaseClock.restart();
        this->mainPhaseText->resetTextPosition();
        this->isBattlePhaseClockStarted = false;
        this->battlePhaseText->resetTextPosition();
        this->display();
        sf::sleep(sf::seconds(2));
        this->gameManager->swapPlayers();
    }
}

void GUIGameWindow::updateCardInfoPanel() {
    if(this->event.type == sf::Event::MouseMoved){
        int index;
        if((index = this->currentPlayersHand->getClickedCardAreaIndex(this->window)) != -1){
            this->cardInfoPanel->setCardImage(this->gameManager->getCurrentPlayer()->getHand()->at(index)->getCardTexture());
            this->cardInfoPanel->setCardDescription(this->gameManager->getCurrentPlayer()->getHand()->at(index)->getCardDetails());
            //this->cardInfoPanel->setCardDescription("handdeki card");
        }else if((index = this->currentPlayersPlayingField->getClickedMonsterCardAreaIndex(this->window)) != -1){
            Card *card;
            if((card = this->gameManager->getCurrentPlayer()->getPlayingField()->getMonsterField().at(index)) != nullptr){
                this->cardInfoPanel->setCardImage(card->getCardTexture());
                this->cardInfoPanel->setCardDescription(card->getCardDetails());
            }
        }else if((index = this->opposingPlayersPlayingField->getClickedMonsterCardAreaIndex(this->window)) != -1){
            Card *card;
            if((card = this->gameManager->getOpposingPlayer()->getPlayingField()->getMonsterField().at(index)) != nullptr && card->isFacedUp()){
                this->cardInfoPanel->setCardImage(card->getCardTexture());
                this->cardInfoPanel->setCardDescription(card->getCardDetails());
            }
        }else if((index = this->opposingPlayersPlayingField->getClickedSpellTrapCardAreaIndex(this->window)) != -1){
            Card *card;
            if((card = this->gameManager->getOpposingPlayer()->getPlayingField()->getSpellTrapField().at(index)) != nullptr && card->isFacedUp()){
                this->cardInfoPanel->setCardImage(card->getCardTexture());
                this->cardInfoPanel->setCardDescription(card->getCardDetails());
            }
        }else if((index = this->currentPlayersPlayingField->getClickedSpellTrapCardAreaIndex(this->window)) != -1){
            Card *card;
            if((card = this->gameManager->getCurrentPlayer()->getPlayingField()->getSpellTrapField().at(index)) != nullptr){
                this->cardInfoPanel->setCardImage(card->getCardTexture());
                this->cardInfoPanel->setCardDescription(card->getCardDetails());
            }
        }
    }
}

void GUIGameWindow::winnerEvents() {
    while(this->window->pollEvent(event)){
        if(this->event.type == sf::Event::MouseButtonPressed){
            if(event.mouseButton.button == sf::Mouse::Button::Left){
                this->guiGameState->setGUIGameState(GuiState::MAIN_MENU);
            }
        }
    }
}

void GUIGameWindow::display() {
    this->window->clear(sf::Color::Black);
    this->window->draw(this->backgroundSprite);
    this->drawDecks();
    this->currentPlayersHand->draw(this->window, *this->gameManager->getCurrentPlayer()->getHand());
    this->opposingPlayersHand->draw(this->window, *this->gameManager->getOpposingPlayer()->getHand(), true);
    this->currentPlayersPlayingField->draw(this->window, this->gameManager->getCurrentPlayer()->getPlayingField());
    this->opposingPlayersPlayingField->draw(this->window, this->gameManager->getOpposingPlayer()->getPlayingField());
    this->currentPlayersPlayerPanel->draw(this->window, this->gameManager->getCurrentPlayer());
    this->opposingPlayersPlayerPanel->draw(this->window, this->gameManager->getOpposingPlayer());
    this->currentPlayersGraveyard->draw(this->window,
                                        gameManager->getCurrentPlayer()->getPlayingField()->getGraveyard());
    this->opposingPlayersGraveyard->draw(this->window,
                                         gameManager->getOpposingPlayer()->getPlayingField()->getGraveyard());
    this->cardInfoPanel->draw(this->window);

    if(this->gameManager->getGameState() == MAIN_PHASE){
        this->mainPhaseText->animate(this->window, this->mainPhaseClock, 30.f, 0.005f);
        this->mainPhaseText->draw(this->window, this->mainPhaseClock);
    }else if(this->gameManager->getGameState() == BATTLE_PHASE){
        this->battlePhaseText->animate(this->window, this->battlePhaseClock, 30.f, 0.005f);
        this->battlePhaseText->draw(this->window, this->battlePhaseClock);
    }
    this->window->display();
}