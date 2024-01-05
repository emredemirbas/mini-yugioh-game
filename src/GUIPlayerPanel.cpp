//
// Created by faruk on 17.12.2023.
//

#include "GUIPlayerPanel.h"

GUIPlayerPanel::GUIPlayerPanel() {}

GUIPlayerPanel::GUIPlayerPanel(float x, float y): GUIWindowElement(x,y){
    this->setoKaibaTexture = new sf::Texture();
    this->setoKaibaTexture->loadFromFile("textures/seto_kaiba.png");
    this->yugiMotoTexture = new sf::Texture();
    this->yugiMotoTexture->loadFromFile("textures/yugi_moto.png");
    this->lifeBar = GUILifeBar(this->basePositionX, this->basePositionY+170, 200, 20);
    this->font.loadFromFile("fonts/MorrisRomanBlack.ttf");

    this->background = sf::RectangleShape(sf::Vector2f(325,200));
    this->background.setFillColor(sf::Color(144, 52, 33, 175));
    this->background.setPosition(this->basePositionX, this->basePositionY);
}

void GUIPlayerPanel::draw(sf::RenderWindow *window, Player *player) {
    this->update(player->getLifePoints() / 8000.0);
    if(auto *p = dynamic_cast<SetoKaiba*>(player)){
        this->playerName.setString("Seto Kaiba");
        this->characterSprite.setTexture(*this->setoKaibaTexture);
    }else{
        this->playerName.setString("Yugi Moto");
        this->characterSprite.setTexture(*this->yugiMotoTexture);
    }

    sf::Vector2u textureSize = this->setoKaibaTexture->getSize();
    sf::FloatRect spriteSize = characterSprite.getLocalBounds();
    characterSprite.setScale(spriteSize.width / textureSize.x, spriteSize.height / textureSize.y);

    this->playerName.setCharacterSize(30);
    this->playerName.setFont(this->font);
    this->playerName.setFillColor(sf::Color(245, 207, 101));

    this->playerName.setPosition(this->basePositionX, this->basePositionY);
    this->characterSprite.setPosition(this->basePositionX, this->basePositionY + 40);


    window->draw(this->background);
    window->draw(this->playerName);
    window->draw(this->characterSprite);
    this->lifeBar.draw(window);
}

GUIPlayerPanel::~GUIPlayerPanel(){
    delete this->yugiMotoTexture;
    delete this->setoKaibaTexture;
}

void GUIPlayerPanel::update(float healthPercent) {
    lifeBar.update(healthPercent);
}

void GUIPlayerPanel::draw(sf::RenderWindow* window) {
    window->draw(this->background);
    window->draw(playerName);
    window->draw(characterSprite);
    lifeBar.draw(window);
}

