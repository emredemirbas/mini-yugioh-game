/**
 * @file GUIPlayingField.h
 * @author Faruk
 * @date 20.12.2023
 * @brief This file contains the GUIPlayingField class which handles the GUI playing field of the MiniYugioh game.
 */

#ifndef MINIYUGIOHGUI_GUIPLAYINGFIELD_H
#define MINIYUGIOHGUI_GUIPLAYINGFIELD_H

#include "SFML/Graphics.hpp" ///< Include the SFML Graphics library
#include "GUIWindowElement.h" ///< Include the GUIWindowElement class
#include "PlayingField.h" ///< Include the PlayingField class
#include "Card.h" ///< Include the Card class
#include <vector> ///< Include the vector library
#include "MonsterCard.h" ///< Include the MonsterCard class

/**
 * @class GUIPlayingField
 * @brief This class handles the GUI playing field of the MiniYugioh game.
 * @details It inherits from the GUIWindowElement class and overrides some of its functions.
 */
class GUIPlayingField:public GUIWindowElement{
public:
    /**
     * @brief Default constructor for the GUIPlayingField class.
     */
    GUIPlayingField();

    /**
     * @brief Constructor for the GUIPlayingField class.
     * @param x The x-coordinate of the playing field.
     * @param y The y-coordinate of the playing field.
     * @param isOpposite Flag to indicate if the playing field is opposite.
     */
    GUIPlayingField(float x, float y, bool isOpposite=false);

    /**
     * @brief Destructor for the GUIPlayingField class.
     */
    ~GUIPlayingField();

    /**
     * @brief Draw the playing field on the window.
     * @param window Pointer to the RenderWindow object.
     */
    void draw(sf::RenderWindow *window) override;

    /**
     * @brief Draw the playing field on the window.
     * @param window Pointer to the RenderWindow object.
     * @param playingField Pointer to the PlayingField object.
     */
    void draw(sf::RenderWindow *window, PlayingField *playingField);

    /**
     * @brief Get the index of the clicked monster card area.
     * @param window Pointer to the RenderWindow object.
     * @return The index of the clicked monster card area.
     */
    int getClickedMonsterCardAreaIndex(sf::RenderWindow *window);

    /**
     * @brief Get the index of the clicked spell trap card area.
     * @param window Pointer to the RenderWindow object.
     * @return The index of the clicked spell trap card area.
     */
    int getClickedSpellTrapCardAreaIndex(sf::RenderWindow *window);

private:
    bool isOpposite; ///< Flag to indicate if the playing field is opposite
    sf::Color monsterFieldColor; ///< Color of the monster field
    sf::Color spellTrapFieldColor; ///< Color of the spell trap field
    sf::Texture *emptyTexture; ///< Texture for the empty field
    sf::Texture *cardBackTexture; ///< Texture for the back of the card
    std::vector<sf::RectangleShape> monsterCardAreas; ///< Vector of monster card areas
    std::vector<sf::RectangleShape> spellTrapCardAreas; ///< Vector of spell trap card areas

    /**
     * @brief Draw the monster card fields on the window.
     * @param window Pointer to the RenderWindow object.
     * @param cards Vector of pointers to the MonsterCard objects.
     */
    void drawMonsterCardFields(sf::RenderWindow *window, std::vector<MonsterCard *> cards);

    /**
     * @brief Draw the spell trap card fields on the window.
     * @param window Pointer to the RenderWindow object.
     * @param cards Vector of pointers to the Card objects.
     */
    void drawSpellTrapCardFields(sf::RenderWindow *window, std::vector<Card *> cards);
};

#endif //MINIYUGIOHGUI_GUIPLAYINGFIELD_H
