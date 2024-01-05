#include "Card.h"

Card::Card(std::string name, std::string description, int id) {
    this->name = name;
    this->description = description;
    isFaceUp = true;
    this->id = id;
    this->cardTexture = new sf::Texture();
    this->cardTexture->loadFromFile("textures/cards/" + std::to_string(id) + ".jpg");
}

Card::~Card() = default;

std::string Card::getName() const {
    return name;
}

std::string Card::getDescription() const {
    return description;
}

sf::Texture *Card::getCardTexture() const {
    return this->cardTexture;
}

void Card::setCardTexture(sf::Texture *texture) {
    this->cardTexture = texture;
}

bool Card::isFacedUp() const {
    return isFaceUp;
}

void Card::setIsFaceUp(bool expr) {
    isFaceUp = expr;
}

void Card::flip() {
    isFaceUp = !isFaceUp;
}








