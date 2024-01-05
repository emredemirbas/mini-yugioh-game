/**
 * @file GUIPlayerPanel.h
 * @author Faruk
 * @date 20.12.2023
 * @brief This file contains the GUIPlayerPanel class which handles the player panel of the MiniYugioh game.
 */

#ifndef MINIYUGIOHGUI_GUIPLAYERPANEL_H
#define MINIYUGIOHGUI_GUIPLAYERPANEL_H

#include "SFML/Graphics.hpp" ///< Include the SFML Graphics library
#include "GUILifeBar.h" ///< Include the GUILifeBar class
#include "GUIWindowElement.h" ///< Include the GUIWindowElement class
#include "Player.h" ///< Include the Player class
#include "SetoKaiba.h" ///< Include the SetoKaiba class

/**
 * @class GUIPlayerPanel
 * @brief This class handles the player panel of the MiniYugioh game.
 * @details It inherits from the GUIWindowElement class and overrides some of its functions.
 */
class GUIPlayerPanel: public GUIWindowElement{
public:
    /**
     * @brief Default constructor for the GUIPlayerPanel class.
     */
    GUIPlayerPanel();

    /**
     * @brief Constructor for the GUIPlayerPanel class.
     * @param x The x-coordinate of the player panel.
     * @param y The y-coordinate of the player panel.
     */
    GUIPlayerPanel(float x, float y);

    /**
     * @brief Destructor for the GUIPlayerPanel class.
     */
    ~GUIPlayerPanel();

    /**
     * @brief Update the player panel based on the health percent.
     * @param healthPercent The current health percent of the player.
     */
    void update(float healthPercent);

    /**
     * @brief Draw the player panel on the window.
     * @param window Pointer to the RenderWindow object.
     */
    void draw(sf::RenderWindow* window) override;

    /**
     * @brief Draw the player panel on the window.
     * @param window Pointer to the RenderWindow object.
     * @param player Pointer to the Player object.
     */
    void draw(sf::RenderWindow* window, Player *player);

private:
    sf::Texture *setoKaibaTexture; ///< Texture for Seto Kaiba
    sf::Texture *yugiMotoTexture; ///< Texture for Yugi Moto
    sf::Text playerName; ///< Text object for the player name
    sf::Text health; ///< Text object for the health
    sf::Font font; ///< Font for the text objects
    sf::Sprite characterSprite; ///< Sprite for the character
    sf::RectangleShape background; ///< Background of the player panel
    GUILifeBar lifeBar; ///< Life bar of the player
};

#endif //MINIYUGIOHGUI_GUIPLAYERPANEL_H
