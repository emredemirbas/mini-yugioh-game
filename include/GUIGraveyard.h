//
// Created by faruk on 20.12.2023.
//

#ifndef MINIYUGIOHGUI_GUIGRAVEYARD_H
#define MINIYUGIOHGUI_GUIGRAVEYARD_H

#include "SFML/Graphics.hpp"
#include "GUIWindowElement.h"
#include <vector>
#include "Card.h"

/**
 * @class GUIGraveyard
 * @brief A class that represents the GUI Graveyard.
 * @details This class inherits from GUIWindowElement and provides functionalities to manage the graveyard.
 */
class GUIGraveyard:public GUIWindowElement{
public:
    /**
     * @brief Default constructor.
     */
    GUIGraveyard();

    /**
     * @brief Constructor with parameters.
     * @param x The x-coordinate of the graveyard.
     * @param y The y-coordinate of the graveyard.
     */
    GUIGraveyard(float x, float y);

    /**
     * @brief Destructor.
     */
    ~GUIGraveyard();

    /**
     * @brief Draws the graveyard on the window.
     * @param window Pointer to the RenderWindow object.
     */
    void draw(sf::RenderWindow *window) override;

    /**
     * @brief Draws the graveyard on the window.
     * @param window Pointer to the RenderWindow object.
     * @param graveyard Vector of pointers to the Card objects in the graveyard.
     */
    void draw(sf::RenderWindow *window, std::vector<Card*> graveyard);

private:
    sf::Color color; ///< Color object for the graveyard.
};

#endif //MINIYUGIOHGUI_GUIGRAVEYARD_H
