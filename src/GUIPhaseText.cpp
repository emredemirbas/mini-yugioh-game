//
// Created by faruk on 30.12.2023.
//

#include "GUIPhaseText.h"
#include <math.h>
#include <iostream>

GUIPhaseText::GUIPhaseText(float x, float y): GUIWindowElement(x, y){

    this->font.loadFromFile("fonts/RomanAntique.ttf");

    this->text.setFont(font);
    this->text.setCharacterSize(50);
    this->text.setFillColor(sf::Color(134,68,255));
    this->text.setPosition(this->basePositionX, this->basePositionY);
    this->text.setOutlineThickness(2);
    this->text.setOutlineColor(sf::Color(61,46,33));
}

void GUIPhaseText::setTextString(std::string textString) {
    this->text.setString(textString);
}

void GUIPhaseText::animate(sf::RenderWindow *window, sf::Clock clock, float amplitude, float frequency){
    float elapsed = clock.getElapsedTime().asSeconds();

    if (text.getGlobalBounds().getPosition().y < 500){
        this->text.move(0,5.f);
    }
}

void GUIPhaseText::resetTextPosition() {
    this->text.setPosition(this->basePositionX, this->basePositionY);
}
void GUIPhaseText::draw(sf::RenderWindow *window, sf::Clock clock) {
    float elapsed = clock.getElapsedTime().asSeconds();
    if(elapsed <= 3.f){
        window->draw(this->text);
    }
}
void GUIPhaseText::draw(sf::RenderWindow *window){
    window->draw(text);
}
