//
// Created by faruk on 20.12.2023.
//

#ifndef MINIYUGIOHGUI_GUIHAND_H
#define MINIYUGIOHGUI_GUIHAND_H

#include "SFML/Graphics.hpp"
#include "GUIWindowElement.h"
#include "Card.h"
#include <vector>

/**
 * @class GUIHand
 * @brief A class that represents the GUI Hand.
 * @details This class inherits from GUIWindowElement and provides functionalities to manage the hand.
 */
class GUIHand: public GUIWindowElement{
public:
    /**
     * @brief Default constructor.
     */
    GUIHand();

    /**
     * @brief Constructor with parameters.
     * @param x The x-coordinate of the hand.
     * @param y The y-coordinate of the hand.
     */
    GUIHand(float x, float y);

    /**
     * @brief Destructor.
     */
    ~GUIHand();

    /**
     * @brief Updates the hand.
     */
    void update();

    /**
     * @brief Draws the hand on the window.
     * @param window Pointer to the RenderWindow object.
     */
    void draw(sf::RenderWindow *window) override;

    /**
     * @brief Draws the hand on the window.
     * @param window Pointer to the RenderWindow object.
     * @param cards Vector of pointers to the Card objects in the hand.
     * @param reverseCards Boolean to determine if the cards should be reversed.
     */
    void draw(sf::RenderWindow *window, std::vector<Card*> cards, bool reverseCards=false);

    /**
     * @brief Gets the index of the clicked card area.
     * @param window Pointer to the RenderWindow object.
     * @return The index of the clicked card area.
     */
    int getClickedCardAreaIndex(sf::RenderWindow *window);

private:
    sf::Color color; ///< Color object for the hand.
    sf::Texture *emptyTexture; ///< Texture object for the empty texture.
    sf::Texture *cardBackTexture; ///< Texture object for the card back texture.
    std::vector<sf::RectangleShape> cardAreas; ///< Vector of RectangleShape objects for the card areas.
};

#endif //MINIYUGIOHGUI_GUIHAND_H
