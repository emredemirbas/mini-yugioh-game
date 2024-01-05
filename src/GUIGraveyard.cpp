//
// Created by faruk on 20.12.2023.
//

#include "GUIGraveyard.h"

#define CARD_PLACE_HEIGHT 175
#define CARD_PLACE_WIDTH 125

GUIGraveyard::GUIGraveyard() {}

GUIGraveyard::GUIGraveyard(float x, float y):GUIWindowElement(x,y) {
    this->color = sf::Color(0,0,0, 100);
}

GUIGraveyard::~GUIGraveyard() noexcept {}

void GUIGraveyard::draw(sf::RenderWindow *window) {
}

void GUIGraveyard::draw(sf::RenderWindow *window, std::vector<Card*> graveyard){
    sf::RectangleShape graveyardArea(sf::Vector2f(CARD_PLACE_WIDTH, CARD_PLACE_HEIGHT));
    graveyardArea.setOutlineColor(sf::Color::White);
    graveyardArea.setOutlineThickness(2);
    if(graveyard.size() > 0){
        graveyardArea.setTexture(graveyard.back()->getCardTexture());
    }else{
        graveyardArea.setFillColor(this->color);
    }
    graveyardArea.setPosition(this->basePositionX, this->basePositionY);
    window->draw(graveyardArea);
}