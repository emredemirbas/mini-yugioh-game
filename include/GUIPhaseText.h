/**
 * @file GUIPhaseText.h
 * @author Faruk
 * @date 30.12.2023
 * @brief This file contains the GUIPhaseText class which handles the phase text of the MiniYugioh game.
 */

#ifndef MINIYUGIOHGUI_GUIPHASETEXT_H
#define MINIYUGIOHGUI_GUIPHASETEXT_H

#include "GUIWindowElement.h" ///< Include the GUIWindowElement class
#include <SFML/System.hpp> ///< Include the SFML System library

/**
 * @class GUIPhaseText
 * @brief This class handles the phase text of the MiniYugioh game.
 * @details It inherits from the GUIWindowElement class and overrides some of its functions.
 */
class GUIPhaseText : public GUIWindowElement
{
public:
    /**
     * @brief Constructor for the GUIPhaseText class.
     * @param x The x-coordinate of the phase text.
     * @param y The y-coordinate of the phase text.
     */
    GUIPhaseText(float x, float y);

    /**
     * @brief Set the text string for the phase text.
     * @param textString The text string to be set.
     */
    void setTextString(std::string textString);

    /**
     * @brief Animate the phase text.
     * @param window Pointer to the RenderWindow object.
     * @param clock Clock object to keep track of the time.
     * @param amplitude The amplitude of the animation.
     * @param frequency The frequency of the animation.
     */
    void animate(sf::RenderWindow *window, sf::Clock clock, float amplitude, float frequency);

    /**
     * @brief Reset the position of the phase text.
     */
    void resetTextPosition();

    /**
     * @brief Draw the phase text on the window.
     * @param window Pointer to the RenderWindow object.
     * @param clock Clock object to keep track of the time.
     */
    void draw(sf::RenderWindow *window, sf::Clock clock);

    /**
     * @brief Draw the phase text on the window.
     * @param window Pointer to the RenderWindow object.
     */
    void draw(sf::RenderWindow *window) override;

private:
    sf::Font font; ///< Font for the phase text
    sf::Text text; ///< Text object for the phase text
    std::string phase; ///< String to hold the phase
};

#endif //MINIYUGIOHGUI_GUIPHASETEXT_H
