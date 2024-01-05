//
// Created by Esat on 29.12.2023.
//

#include "GUIPauseMenu.h"

GUIPauseMenu::GUIPauseMenu(sf::RenderWindow *window, GUIGameState *guiGameState)  : GUIWindow(window){
    this->initTextures();
    this->initButtons();
    this->guiGameState = guiGameState;
}

GUIPauseMenu::~GUIPauseMenu(){

}

void GUIPauseMenu::initTextures() {
    this->resumeTexture = new sf::Texture;
    this->resumeTexture->loadFromFile("textures/resumebutton.png");

    this->resumeGreenTexture = new sf::Texture;
    this->resumeGreenTexture->loadFromFile("textures/resumebuttongreen.png");

    this->optionsTexture = new sf::Texture;
    this->optionsTexture->loadFromFile("textures/optionsbutton.png");

    this->optionsGreenTexture = new sf::Texture;
    this->optionsGreenTexture->loadFromFile("textures/optionsbuttongreen.png");

    this->mainMenuTexture = new sf::Texture;
    this->mainMenuTexture->loadFromFile("textures/mainmenubutton.png");

    this->mainMenuGreenTexture = new sf::Texture;
    this->mainMenuGreenTexture->loadFromFile("textures/mainmenubuttongreen.png");
}

void GUIPauseMenu::initButtons() {
    this->resumeButton.setSize(sf::Vector2f(500.f , 125.f));
    this->resumeButton.setPosition(720.f , 420.f);

    this->optionsButton.setSize(sf::Vector2f(500.f , 125.f));
    this->optionsButton.setPosition(720.f , 580.f);

    this->returnToMenuButton.setSize(sf::Vector2f(500.f , 125.f));
    this->returnToMenuButton.setPosition(720.f , 740.f);
}

void GUIPauseMenu::drawButtons() {
    this->resumeButton.setTexture(isRed1 ? this->resumeTexture : this->resumeGreenTexture);
    this->window->draw(resumeButton);

    this->optionsButton.setTexture(isRed2 ? this->optionsTexture : this->optionsGreenTexture);
    this->window->draw(optionsButton);

    this->returnToMenuButton.setTexture(isRed3 ? this->mainMenuTexture : this->mainMenuGreenTexture);
    this->window->draw(returnToMenuButton);
}

void GUIPauseMenu::update() {
    while(this->window->pollEvent(event)){
//        if(event.type = sf::Event::KeyPressed){
//            if(event.key.code == sf::Keyboard::Escape){
//                guiGameState->setGUIGameState(GuiState::GAME);
//            }
//        }
        if(event.type == sf::Event::MouseMoved){

            sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);

            if (resumeButton.getGlobalBounds().contains(static_cast<float>(mousePosition.x),
                                                        static_cast<float>(mousePosition.y))) {
                isRed1 = false;

            } else {
                isRed1 = true;
            }

            if (optionsButton.getGlobalBounds().contains(static_cast<float>(mousePosition.x),
                                                        static_cast<float>(mousePosition.y))) {
                isRed2 = false;

            } else {
                isRed2 = true;
            }

            if (returnToMenuButton.getGlobalBounds().contains(static_cast<float>(mousePosition.x),
                                                        static_cast<float>(mousePosition.y))) {
                isRed3 = false;

            } else {
                isRed3 = true;
            }
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            if (resumeButton.getGlobalBounds().contains(static_cast<float>(event.mouseButton.x),
                                                        static_cast<float>(event.mouseButton.y))) {
                guiGameState->setGUIGameState(GuiState::GAME);
            }
            if (optionsButton.getGlobalBounds().contains(static_cast<float>(event.mouseButton.x),
                                                        static_cast<float>(event.mouseButton.y))) {
                guiGameState->setGUIGameState(GuiState::SETTINGS);
            }
            if (returnToMenuButton.getGlobalBounds().contains(static_cast<float>(event.mouseButton.x),
                                                        static_cast<float>(event.mouseButton.y))) {
                guiGameState->setGUIGameState(GuiState::MAIN_MENU);

            }
        }

    }
}

void GUIPauseMenu::display() {
 //   this->window->clear();
    drawButtons();
    this->window->display();
}

const bool GUIPauseMenu::isRunning() {
    return this->window->isOpen();
}

void GUIPauseMenu::initWindow() {}
void GUIPauseMenu::initWindowElements() {}