//
// Created by faruk on 20.12.2023.
//

#include "GUIPlayingField.h"
#include <iostream>

#define CARD_PLACE_HEIGHT 175
#define CARD_PLACE_WIDTH 125
#define CARD_PLACE_OFFSET 25
#define MONSTER_SPELL_FIELD_OFFSET 10

GUIPlayingField::GUIPlayingField() {}

GUIPlayingField::GUIPlayingField(float x, float y, bool isOpposite) : GUIWindowElement(x,y) {
    this->isOpposite = isOpposite;
    this->monsterFieldColor = sf::Color(144, 52, 33, 150);
    this->spellTrapFieldColor = sf::Color(14, 93, 141, 150);
    this->emptyTexture = new sf::Texture();
    this->cardBackTexture = new sf::Texture();
    this->cardBackTexture->loadFromFile("textures/card_back.png");
}

GUIPlayingField::~GUIPlayingField() noexcept {
    delete this->emptyTexture;
    delete this->cardBackTexture;
}

void GUIPlayingField::draw(sf::RenderWindow *window) {

}

void GUIPlayingField::draw(sf::RenderWindow *window, PlayingField *playingField) {
    this->drawMonsterCardFields(window, playingField->getMonsterField());
    this->drawSpellTrapCardFields(window, playingField->getSpellTrapField());
}

void GUIPlayingField::drawMonsterCardFields(sf::RenderWindow *window, std::vector<MonsterCard *> cards) {
    this->monsterCardAreas.clear();
    for(int i=0; i<cards.size(); i++){
        sf::RectangleShape cardArea(sf::Vector2f(CARD_PLACE_WIDTH, CARD_PLACE_HEIGHT));
        if(cards[i] != nullptr){
            if(!cards[i]->isFacedUp()){
                cardArea.setTexture(this->cardBackTexture);
        }
            else{
                cardArea.setTexture(cards[i]->getCardTexture());
            }

            if(cards[i]->isAttackMode()){
                cardArea.setOutlineColor(sf::Color(160,61,178));
                cardArea.setOutlineThickness(5);
            }
            else{
                cardArea.setOutlineColor(sf::Color(250,150,0));
                cardArea.setOutlineThickness(5);
            }
        }
        else{
            cardArea.setTexture(this->emptyTexture);
            cardArea.setFillColor(this->monsterFieldColor);
        }

        cardArea.setPosition(this->basePositionX + i * (CARD_PLACE_WIDTH + CARD_PLACE_OFFSET), this->basePositionY);
        this->monsterCardAreas.push_back(cardArea);
        window->draw(this->monsterCardAreas.back()); // Draw the cardArea stored in cardAreas
    }
}

void GUIPlayingField::drawSpellTrapCardFields(sf::RenderWindow *window, std::vector<Card*> cards) {
    this->spellTrapCardAreas.clear();
    for(int i=0; i<cards.size(); i++){
        sf::RectangleShape cardArea(sf::Vector2f(CARD_PLACE_WIDTH, CARD_PLACE_HEIGHT));
        if(cards[i]!= nullptr){
            if(!cards[i]->isFacedUp()){
                cardArea.setTexture(this->cardBackTexture);
            }
            else{
                cardArea.setTexture(cards[i]->getCardTexture());
            }

        }
        else{
            cardArea.setTexture(this->emptyTexture);
            cardArea.setFillColor(this->spellTrapFieldColor);
        }
        //Set position.
        if(isOpposite){
            cardArea.setPosition(this->basePositionX + i * (CARD_PLACE_WIDTH + CARD_PLACE_OFFSET), this->basePositionY-(MONSTER_SPELL_FIELD_OFFSET+CARD_PLACE_HEIGHT));
        }
        else{
            cardArea.setPosition(this->basePositionX + i * (CARD_PLACE_WIDTH + CARD_PLACE_OFFSET), this->basePositionY+(MONSTER_SPELL_FIELD_OFFSET+CARD_PLACE_HEIGHT));
        }
        this->spellTrapCardAreas.push_back(cardArea);
        window->draw(this->spellTrapCardAreas.back()); // Draw the cardArea stored in cardAreas
    }
}

int GUIPlayingField::getClickedMonsterCardAreaIndex(sf::RenderWindow *window) {
    sf::Vector2f mousePos = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
    for(int i=0; i<this->monsterCardAreas.size(); i++){
        if (this->monsterCardAreas[i].getGlobalBounds().contains(mousePos.x, mousePos.y)){
            return i;
        }
    }
    return -1;
}

int GUIPlayingField::getClickedSpellTrapCardAreaIndex(sf::RenderWindow *window) {
    sf::Vector2f mousePos = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
    for(int i=0; i<this->spellTrapCardAreas.size(); i++){
        if (this->spellTrapCardAreas[i].getGlobalBounds().contains(mousePos.x, mousePos.y)){
            return i;
        }
    }
    return -1;
}