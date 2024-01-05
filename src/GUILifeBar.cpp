//
// Created by faruk on 16.12.2023.
//

#include "GUILifeBar.h"

GUILifeBar::GUILifeBar() {}

GUILifeBar::GUILifeBar(float x, float y, float width, float height): GUIWindowElement(x, y){

    this->outerRect = sf::RectangleShape(sf::Vector2f(width, height));
    this->innerRect = sf::RectangleShape(sf::Vector2f(width, height));


    outerRect.setPosition(x, y);
    outerRect.setFillColor(sf::Color(61,46,33));

    innerRect.setPosition(x, y);
    innerRect.setFillColor(sf::Color(245, 207, 101));

}

GUILifeBar::~GUILifeBar() noexcept {

}

void GUILifeBar::update(float healthPercent) {
    innerRect.setSize(sf::Vector2f(outerRect.getSize().x * healthPercent, outerRect.getSize().y));
}

void GUILifeBar::draw(sf::RenderWindow* window) {
    window->draw(outerRect);
    window->draw(innerRect);
}
