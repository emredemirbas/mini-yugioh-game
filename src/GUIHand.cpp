//
// Created by faruk on 20.12.2023.
//

#include "GUIHand.h"
#define HAND_PLACE_HEIGHT 150
#define HAND_PLACE_WIDTH 165
#define HAND_PLACE_OFFSET 25

#include "iostream"

GUIHand::GUIHand() {}

GUIHand::GUIHand(float x, float y) : GUIWindowElement(x, y) {
    this->color = sf::Color(95,78,67,100);
    this->emptyTexture = new sf::Texture();
    this->cardBackTexture = new sf::Texture();
    this->cardBackTexture->loadFromFile("textures/card_back.png");
    this->cardAreas = std::vector<sf::RectangleShape>();
}

GUIHand::~GUIHand() noexcept {}

void GUIHand::draw(sf::RenderWindow *window) {

}

void GUIHand::draw(sf::RenderWindow *window, std::vector<Card*> cards, bool reverseCards) {
    this->cardAreas.clear();
    for(int i=0; i<cards.size(); i++){
        sf::RectangleShape cardArea(sf::Vector2f(HAND_PLACE_WIDTH, HAND_PLACE_HEIGHT));
        if(reverseCards){
            cardArea.setTexture(this->cardBackTexture);
        }
        else{
            cardArea.setTexture(cards[i]->getCardTexture());
        }
        cardArea.setPosition(this->basePositionX + i * (HAND_PLACE_WIDTH + HAND_PLACE_OFFSET), this->basePositionY);
        this->cardAreas.push_back(cardArea);
        window->draw(this->cardAreas.back()); // Draw the cardArea stored in cardAreas
    }
}


int GUIHand::getClickedCardAreaIndex(sf::RenderWindow *window) {
    sf::Vector2f mousePos = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
    for(int i=0; i<cardAreas.size(); i++){
        if (this->cardAreas[i].getGlobalBounds().contains(mousePos.x, mousePos.y)){
            return i;
        }
    }
    return -1;
}

