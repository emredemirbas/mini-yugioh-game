#include "GUICardInfoPanel.h"

#define CARD_PLACE_HEIGHT 450
#define CARD_PLACE_WIDTH 325

GUICardInfoPanel::GUICardInfoPanel() : GUIWindowElement() {}

GUICardInfoPanel::GUICardInfoPanel(float x, float y) : GUIWindowElement(x, y) {
    this->cardImage = new sf::Texture();
    this->cardImage->loadFromFile("textures/card_back.png");

    this->font.loadFromFile("fonts/MorrisRomanBlack.ttf");

    this->background = sf::RectangleShape(sf::Vector2f(CARD_PLACE_WIDTH, CARD_PLACE_HEIGHT+200));
    //this->background.setFillColor(sf::Color(61,46,33));
    this->background.setFillColor(sf::Color(144, 52, 33, 175));
    this->background.setPosition(basePositionX, basePositionY);
}

GUICardInfoPanel::~GUICardInfoPanel() {}

void GUICardInfoPanel::setCardImage(sf::Texture* image) {
    cardImage = image;
}

void GUICardInfoPanel::setCardDescription(std::string description) {
    cardDescription = description;
}

sf::Text GUICardInfoPanel::createText(std::string inputString) {
    sf::Text text(inputString, this->font, 24);
    std::string outputString = "";
    int width = 0;
    for (int i = 0; i < inputString.length(); i++) {
        text.setString(outputString + inputString[i]);
        if (text.getLocalBounds().width + 3 > CARD_PLACE_WIDTH) {
            outputString += "\n";
            width = 0;
        }
        outputString += inputString[i];
        width += text.findCharacterPos(outputString.length()).x - text.findCharacterPos(outputString.length() - 1).x;
    }
    text.setString(outputString);
    text.setFillColor(sf::Color(245, 207, 101));
    return text;
}

void GUICardInfoPanel::draw(sf::RenderWindow *window) {
    // Create a RectangleShape from the card image
    //sf::RectangleShape background(sf::Vector2f(CARD_PLACE_WIDTH, CARD_PLACE_HEIGHT+200));
    sf::RectangleShape cardArea(sf::Vector2f(CARD_PLACE_WIDTH, CARD_PLACE_HEIGHT));

    cardArea.setTexture(cardImage);
    cardArea.setPosition(basePositionX, basePositionY);

    //Create description text:
    sf::Text cardDescriptionText = this->createText(this->cardDescription);
    cardDescriptionText.setPosition(this->basePositionX, this->basePositionY+CARD_PLACE_HEIGHT+10);

    // Draw the RectangleShape and text on the window
    window->draw(this->background);
    window->draw(cardDescriptionText);
    window->draw(cardArea);
}

