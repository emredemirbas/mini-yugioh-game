//
// Created by faruk on 24.12.2023.
//
#include "GameManager.h"
#include "Player.h"
#include "YugiMuto.h"
#include "SetoKaiba.h"

GameManager::GameManager() {
    this->currentPlayer = new YugiMuto();
    this->opposingPlayer = new SetoKaiba();
    this->isCurrentPlayerPlayedCardAtMP = false;
    this->isCurrentPlayerChangesCardModeAtMP = false;
    round = 1;
}

GameManager::~GameManager() {
    delete currentPlayer;
    delete opposingPlayer;
}

void GameManager::initializeGame() {
    // add 5 card to hand of current and opposing players
    for (int i = 0; i < 5; i++) {
        this->currentPlayer->addCardToHandFromDeck();
        this->opposingPlayer->addCardToHandFromDeck();
    }
    this->gameState = DRAW_PHASE;
}

void GameManager::restartTheGame() {
    // Reset players
    delete currentPlayer;
    delete opposingPlayer;
    currentPlayer = new YugiMuto();
    opposingPlayer = new SetoKaiba();

    // Reset game state variables
    isCurrentPlayerPlayedCardAtMP = false;
    isCurrentPlayerChangesCardModeAtMP = false;
    round = 1;



    // Initialize the game again
    initializeGame();
}


void GameManager::attackLifePoints(MonsterCard *attacker) {
    if (!opposingPlayer->getPlayingField()->isThereTrapCardInField()) {
        opposingPlayer->decreaseLifePoints(attacker->getAttackPoints());
    } else {
        activateTrapCard();
    }
}

void GameManager::declareAttack(MonsterCard *attacker, MonsterCard *target) {
    // Terminate method if attacker is not in Attack Mode.
    if (!attacker->isAttackMode()) {
        return;
    }
    // If opposingPlayer has no TrapCard in field, perform attack.
    if (!opposingPlayer->getPlayingField()->isThereTrapCardInField()) {
        int activePointOfAttacker = attacker->getActivePoints();
        int activePointOfTarget = target->getActivePoints();

        // if the target is in defense mode and target is face-down, flip target.
        if (!target->isAttackMode() && !target->isFacedUp()) {
            target->flip();
        }

        if (activePointOfAttacker > activePointOfTarget) {
            opposingPlayer->getPlayingField()->removeCardFromMonsterField(target);
            if (target->isAttackMode()) {
                opposingPlayer->decreaseLifePoints(activePointOfAttacker - activePointOfTarget);
            }

        } else if (activePointOfAttacker < activePointOfTarget) {
            currentPlayer->getPlayingField()->removeCardFromMonsterField(attacker);
            currentPlayer->decreaseLifePoints(activePointOfTarget - activePointOfAttacker);
        }
    }
        // If opposingPlayer has TrapCard in field,
    else {
        activateTrapCard(); // activate first found TrapCard in opposingPlayer's field.
    }
}




void GameManager::drawPhase() {
    // Draw a Card if the Deck is not empty
    if (!this->currentPlayer->getDeck()->getCards().empty()) {
        this->currentPlayer->addCardToHandFromDeck();
    }

    // Special Case:
    // if Seto Kaiba has three Blue-Eyes White Dragon in his hand,
    // he is able to summon Blue Eyes Ultimate Dragon.
    if (auto *p = dynamic_cast<SetoKaiba *>(currentPlayer)) {
        if (p->hasThreeBlueEyesWhiteDragon()) {
            p->summonBlueEyesUltimateDragon();
        }
    }
    this->gameState = MAIN_PHASE;
}

void GameManager::mainPhase(int selectedCardIndex) {
    // Play chosenCard to the PlayingField.
    Card *chosenCard = currentPlayer->getHand()->at(selectedCardIndex);
    currentPlayer->removeCardFromHand(chosenCard);
    currentPlayer->getPlayingField()->addCardToPlayingField(chosenCard);

    // if chosenCard is a SpellCard, activate it's unique effect.
    if (auto *spellCard = dynamic_cast<SpellCard *>(chosenCard)) {
        spellCard->activateEffect(currentPlayer, opposingPlayer);
    }
    this->isCurrentPlayerPlayedCardAtMP = true;

    // determine next state
    this->gameState = (round <= 2 || !currentPlayer->getPlayingField()->isThereAttackingMonsterInField()) ? END_PHASE

                                                                                                          : BATTLE_PHASE;
}

void GameManager::battlePhase(int attackerIndex, int targetIndex) {
    // if attackerIndex is valid and targetIndex is not valid,
    // directly attack LP of opposingPlayer.
    if (attackerIndex != -1 && targetIndex == -1) {
        MonsterCard *attacker = currentPlayer->getPlayingField()->getMonsterField().at(attackerIndex);
        this->attackLifePoints(attacker);
    }

        // if both attackerIndex and targetIndex is valid,
        // declare attack with attacker to target.
    else if (attackerIndex != -1) {
        MonsterCard *attacker = currentPlayer->getPlayingField()->getMonsterField().at(attackerIndex);
        MonsterCard *target = opposingPlayer->getPlayingField()->getMonsterField().at(targetIndex);
        this->declareAttack(attacker, target);
    }

    this->gameState = END_PHASE;
}

void GameManager::swapPlayers() {
    // swap opposingPlayer and currentPlayer objects
    Player *temp = this->currentPlayer;
    this->currentPlayer = opposingPlayer;
    this->opposingPlayer = temp;
}

void GameManager::endPhase() {
    // Remove already used TrapCards and SpellCards from field.
    for (Card *card: currentPlayer->getPlayingField()->getSpellTrapField()) {
        if (card) {
            if (auto *spellCard = dynamic_cast<SpellCard * >(card)) {
                currentPlayer->getPlayingField()->removeCardFromSpellTrapField(spellCard);
            } else if (auto *trapCard = dynamic_cast<TrapCard * >(card)) {
                if (card->isFacedUp()) {
                    currentPlayer->getPlayingField()->removeCardFromSpellTrapField(trapCard);
                }
            }
        }
    }
    this->isCurrentPlayerPlayedCardAtMP = false;
    this->isCurrentPlayerChangesCardModeAtMP = false;
    this->gameState = DRAW_PHASE;
    round++;
}

Player *GameManager::getCurrentPlayer() const {
    return this->currentPlayer;
}

Player *GameManager::getOpposingPlayer() const {
    return this->opposingPlayer;
}

GameState GameManager::getGameState() const {
    return this->gameState;
}

bool GameManager::getIsCurrentPlayerPlayedCardAtMP() const {
    return this->isCurrentPlayerPlayedCardAtMP;
}

bool GameManager::getIsCurrentPlayerChangedCardModeAtMP() const {
    return this->isCurrentPlayerChangesCardModeAtMP;
}

void GameManager::changeCardMode(int selectedCardIndex) {
    this->currentPlayer->getPlayingField()->getMonsterField().at(selectedCardIndex)->changeMode();
    this->isCurrentPlayerChangesCardModeAtMP = true;
}

// This method returns the winner Player. Returns nullptr if none of the Player is winner yet.
Player *GameManager::determineWinner() {
    if (auto *p = dynamic_cast<YugiMuto *>(currentPlayer)) {
        if (p->hasAllPiecesOfExodia()) {
            return currentPlayer;
        }
    }
    if (currentPlayer->getLifePoints() == 0 || currentPlayer->getDeck()->getCards().empty())
        return opposingPlayer;
    if (opposingPlayer->getLifePoints() == 0 || opposingPlayer->getDeck()->getCards().empty())
        return currentPlayer;
    else
        return nullptr;
}


void GameManager::activateTrapCard() {
    // Terminate the method if there is no TrapCard in the opposingPlayer's PlayingField
    if (!opposingPlayer->getPlayingField()->isThereTrapCardInField()) {
        return;
    }

    // TrapCard that will be activated
    TrapCard *chosenCard = nullptr;

    // Seek
    for (Card *card: opposingPlayer->getPlayingField()->getSpellTrapField()) {
        // if card is an instance of a TrapCard*
        if (auto *t = dynamic_cast<TrapCard *>(card)) {
            chosenCard = t;
            break; // terminate for-each loop
        }
    }

    // Flip and activate the effect of Trap Card
    if (chosenCard) {
        chosenCard->flip();
        chosenCard->activateEffect(opposingPlayer, currentPlayer);
        opposingPlayer->getPlayingField()->removeCardFromSpellTrapField(chosenCard);
    }
}





