//
// Created by Esat on 22.12.2023.
//

#include "GUIMainMenuWindow.h"
#include "GUIGameWindow.h"

#define BUTTON_HEIGHT 125
#define BUTTON_WIDTH 500
#define WINDOW_HEIGHT 1080
#define WINDOW_WIDTH 1920
#define WINDOW_TITLE "Mini YuGiOh! Game"

GUIMainMenuWindow::GUIMainMenuWindow(sf::RenderWindow *window , GUIGameState *guiGameState) : GUIWindow(window) {
    this->initTextures();
    this->initWindow();
    this->initButtons();
    this->guiGameState = guiGameState;
}

GUIMainMenuWindow::~GUIMainMenuWindow() {}

void GUIMainMenuWindow::initTextures() {
    this->backgroundTexture = new sf::Texture;
    backgroundTexture->loadFromFile("textures/menubackground.png");

    this->startTexture = new sf::Texture;
    startTexture->loadFromFile("textures/playblue.png");

    this->settingsTexture = new sf::Texture;
    settingsTexture->loadFromFile("textures/settingsblue.png");

    this->exitTexture = new sf::Texture;
    exitTexture->loadFromFile("textures/exitblue.png");

    this->startTextureGreen = new sf::Texture;
    startTextureGreen->loadFromFile("textures/settingsgreen.png");

    this->startTextureGreen = new sf::Texture;
    startTextureGreen->loadFromFile("textures/playgreen.png");

    this->settingsTextureGreen = new sf::Texture;
    settingsTextureGreen->loadFromFile("textures/settingsgreen.png");

    this->exitTextureGreen = new sf::Texture;
    exitTextureGreen->loadFromFile("textures/exitgreen.png");

    this->miniYugiohTexture = new sf::Texture();
    miniYugiohTexture->loadFromFile("textures/miniyugioh.png");
}

void GUIMainMenuWindow::initButtons() {
    this->buttonArea1 = new sf::RectangleShape(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT));
    buttonArea1->setPosition(720.f, 420.f);

    this->buttonArea2 = new sf::RectangleShape(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT));
    buttonArea2->setPosition(720.f, 580.f);

    this->buttonArea3 = new sf::RectangleShape(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT));
    buttonArea3->setPosition(720.f, 740.f);
}

void GUIMainMenuWindow::drawButtons() {
    buttonArea1->setTexture(isBlue1 ? this->startTexture : this->startTextureGreen);
    this->window->draw(*buttonArea1);

    buttonArea2->setTexture(isBlue2 ? this->settingsTexture : this->settingsTextureGreen);
    this->window->draw(*buttonArea2);

    buttonArea3->setTexture(isBlue3 ? this->exitTexture : this->exitTextureGreen);
    this->window->draw(*buttonArea3);
};

void GUIMainMenuWindow::initWindowElements() {

}

void GUIMainMenuWindow::initWindow() {
    sf::Vector2u windowSize = this->window->getSize(); // Get size of window.
    sf::Vector2u textureSize = backgroundTexture->getSize(); // Get size of texture.
    float scaleX = (float) windowSize.x / textureSize.x;
    float scaleY = (float) windowSize.y / textureSize.y; // Calculate scale.

    this->backgroundSprite.setTexture(*this->backgroundTexture);
    this->backgroundSprite.setScale(scaleX, scaleY);
    this->backgroundSprite.setTexture(*this->backgroundTexture);

    this->textSprite.setTexture(*this->miniYugiohTexture);
    this->textSprite.setScale(0.75f , 0.75f);
    this->textSprite.setPosition(558.f , 25.f);
}

void GUIMainMenuWindow::update() {
    while (this->window->pollEvent(this->event)) {
        if(event.type == sf::Event::Closed){
            this->guiGameState->setGUIGameState(GuiState::EXIT);
            this->window->close();}

        if(event.type == sf::Event::KeyPressed){
            if (this->event.key.code == sf::Keyboard::Key::Escape) {
                this->window->close();
            }
        }

        if(event.type == sf::Event::MouseMoved){

            sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);

            if (buttonArea1->getGlobalBounds().contains(static_cast<float>(mousePosition.x),
                                                        static_cast<float>(mousePosition.y))) {
                isBlue1 = false;

            } else {
                isBlue1 = true;
            }

            if (buttonArea2->getGlobalBounds().contains(static_cast<float>(mousePosition.x),
                                                        static_cast<float>(mousePosition.y))) {
                isBlue2 = false;

            } else {
                isBlue2 = true;
            }

            if (buttonArea3->getGlobalBounds().contains(static_cast<float>(mousePosition.x),
                                                        static_cast<float>(mousePosition.y))) {
                isBlue3 = false;

            } else {
                isBlue3 = true;
            }
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            if (buttonArea1->getGlobalBounds().contains(static_cast<float>(event.mouseButton.x),
                                                        static_cast<float>(event.mouseButton.y))) {
                guiGameState->setGUIGameState(GuiState::GAME);
            }
            if (buttonArea2->getGlobalBounds().contains(static_cast<float>(event.mouseButton.x),
                                                        static_cast<float>(event.mouseButton.y))) {
                guiGameState->setGUIGameState(GuiState::SETTINGS);
            }
            if (buttonArea3->getGlobalBounds().contains(static_cast<float>(event.mouseButton.x),
                                                        static_cast<float>(event.mouseButton.y))) {
                guiGameState->setGUIGameState(GuiState::EXIT);
                this->window->close();
            }
        }
    }
}

void GUIMainMenuWindow::display() {
    this->window->clear();
    this->window->draw(this->backgroundSprite);
    this->window->draw(this->textSprite);
    this->drawButtons();
    this->window->display();
}

const bool GUIMainMenuWindow::isRunning() {
    return this->window->isOpen();
}