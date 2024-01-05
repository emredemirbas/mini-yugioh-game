//
// Created by Esat on 28.12.2023.
//

#include "GUISettings.h"

#define BAR_WIDTH 600.0f
#define BAR_HEIGHT 30.0f
#define SLIDER_WIDTH 50.0f
#define SLIDER_HEIGHT 30.0f

GUISettings::GUISettings(sf::RenderWindow *window , GUIGameState *guiGameState ) : GUIWindow(window){
    initTextures();
    initButtons();
    initWindow();
    this->volumeLevel = 58.f;
    this->guiGameState = guiGameState;
}

GUISettings::~GUISettings() {

}

void GUISettings::display() {
    this->window->clear();

    this->window->draw(backgroundSprite);
    drawButtons();

    this->window->display();
}

void GUISettings::update() {
    while (window->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                guiGameState->setGUIGameState(GuiState::EXIT);
                window->close();
                break;
            case sf::Event::KeyPressed:
                if(event.key.code == sf::Keyboard::Escape){
                    if(guiGameState->getPreviousState() == GuiState::MAIN_MENU){
                        guiGameState->setGUIGameState(GuiState::MAIN_MENU);
                    }
                    if(guiGameState->getPreviousState() == GuiState::PAUSE_MENU){
                        guiGameState->setGUIGameState(GuiState::GAME);
                    }
                }
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f mousePos = window->mapPixelToCoords(sf::Mouse::getPosition(*window));

                    // Check if the mouse is over the slider
                    if (this->volumeSlider.getGlobalBounds().contains(mousePos)) {
                        this->isDraggingSlider = true;
                    }
                    if (videoModeButton.getGlobalBounds().contains(static_cast<float>(event.mouseButton.x),
                                                                static_cast<float>(event.mouseButton.y))) {
                        if(isFullScreen){
                            this->window->create(sf::VideoMode(1920 , 1080) , "Mini YuGiOh! Game");
                            isFullScreen = false;
                        }
                        else{
                            this->window->create(sf::VideoMode(1920 , 1080) , "Mini YuGiOh! Game" , sf::Style::Fullscreen);
                            isFullScreen = true;
                        }


                    }
                    if (backButton.getGlobalBounds().contains(static_cast<float>(event.mouseButton.x),
                                                                static_cast<float>(event.mouseButton.y))) {
                        if(guiGameState->getPreviousState() == GuiState::MAIN_MENU){
                            guiGameState->setGUIGameState(GuiState::MAIN_MENU);
                        }
                        if(guiGameState->getPreviousState() == GuiState::PAUSE_MENU){
                            guiGameState->setGUIGameState(GuiState::GAME);
                        }
                    }
                }
                break;
            case sf::Event::MouseButtonReleased:
                if (event.mouseButton.button == sf::Mouse::Left) {
                    this->isDraggingSlider = false;
                }
                break;
            case sf::Event::MouseMoved:
                sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
                if (this->isDraggingSlider) {
                    // Update slider position based on mouse movement
                    sf::Vector2f mousePos = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
                    float sliderX = mousePos.x - this->volumeSlider.getSize().x / 2;

                    // Ensure the slider stays within the volume bar bounds
                    float minSliderX = this->volumeBar.getPosition().x;
                    float maxSliderX = this->volumeBar.getPosition().x + this->volumeBar.getSize().x - this->volumeSlider.getSize().x;

                    if (sliderX < minSliderX) {
                        sliderX = minSliderX;
                    } else if (sliderX > maxSliderX) {
                        sliderX = maxSliderX;
                    }

                    // Update volume level based on slider position
                    this->volumeLevel = ((sliderX - minSliderX) / (maxSliderX - minSliderX)) * 100.0f;

                    // Update the position of the volume slider
                    this->volumeSlider.setPosition(sliderX, this->volumeSlider.getPosition().y);
                }
                else {
                    if (videoModeButton.getGlobalBounds().contains(static_cast<float>(mousePosition.x),
                                                                   static_cast<float>(mousePosition.y))) {
                        isBlue1 = false;

                    } else {
                        isBlue1 = true;
                    }

                    if (backButton.getGlobalBounds().contains(static_cast<float>(mousePosition.x),
                                                              static_cast<float>(mousePosition.y))) {
                        isBlue2 = false;

                    } else {
                        isBlue2 = true;
                    }
                    break;
                }
        }
    }
}

void GUISettings::initWindow() {
    sf::Vector2u windowSize = this->window->getSize(); // Get size of window.
    sf::Vector2u textureSize = backgroundTexture->getSize(); // Get size of texture.
    float scaleX = (float) windowSize.x / textureSize.x;
    float scaleY = (float) windowSize.y / textureSize.y; // Calculate scale.

    this->backgroundSprite.setTexture(*this->backgroundTexture);
    this->backgroundSprite.setScale(scaleX, scaleY);
    this->backgroundSprite.setTexture(*this->backgroundTexture);
}

void GUISettings::initButtons() {

    // Setup volume bar
    this->volumeBar.setSize(sf::Vector2f(BAR_WIDTH, BAR_HEIGHT));


    // Setup volume slider
    this->volumeSlider.setSize(sf::Vector2f(SLIDER_WIDTH, SLIDER_HEIGHT));


    this->videoModeButton.setSize(sf::Vector2f(500.f , 125.f));


    this->backButton.setSize(sf::Vector2f(500.f , 125.f));


    this->volumeText.setSize(sf::Vector2f(500.f , 125.f));

}

void GUISettings::drawButtons() {
    this->volumeBar.setFillColor(sf::Color::Green);
    this->volumeBar.setPosition(660.0f, 300.0f);
    this->window->draw(volumeBar);

    this->volumeSlider.setFillColor(sf::Color(150,75,0));
    this->volumeSlider.setPosition(660.0f + (BAR_WIDTH * this->volumeLevel / 100.0f) - SLIDER_WIDTH / 2, 300.0f);
    this->window->draw(volumeSlider);

    this->videoModeButton.setPosition(725.f , 450.f);
    this->videoModeButton.setTexture(isBlue1 ? buttonTexture : buttonTextureGreen);
    this->window->draw(videoModeButton);

    this->backButton.setPosition(725.f , 750.f);
    this->backButton.setTexture(isBlue2 ? backButtonTexture : backButtonTextureGreen);
    this->window->draw(backButton);

    this->volumeText.setPosition(700.f , 175.f);
    this->volumeText.setTexture(volumeTexture);
    this->window->draw(volumeText);

}

void GUISettings::initTextures(){
    this->backgroundTexture = new sf::Texture;
    this->backgroundTexture->loadFromFile("textures/menuBackground.png");
    this->backgroundSprite.setTexture(*this->backgroundTexture);

    this->buttonTexture = new sf::Texture;
    this->buttonTexture->loadFromFile("textures/changescreenmode.png");

    this->backButtonTexture = new sf::Texture;
    this->backButtonTexture->loadFromFile("textures/backbutton.png");

    this->volumeTexture = new sf::Texture;
    this->volumeTexture->loadFromFile("textures/volume.png");

    this->buttonTextureGreen = new sf::Texture;
    this->buttonTextureGreen->loadFromFile("textures/changescreenmodegreen.png");

    this->backButtonTextureGreen = new sf::Texture;
    this->backButtonTextureGreen->loadFromFile("textures/backbuttongreen.png");

}

const bool GUISettings::isRunning() {
    return this->window->isOpen();
}

void GUISettings::initWindowElements() {

}

float GUISettings::getVolumeLevel() {
    return volumeLevel;
}