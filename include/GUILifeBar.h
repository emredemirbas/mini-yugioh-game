//
// Created by faruk on 20.12.2023.
//

#ifndef MINIYUGIOHGUI_GUILIFEBAR_H
#define MINIYUGIOHGUI_GUILIFEBAR_H

#include <SFML/Graphics.hpp>
#include "GUIWindowElement.h"

/**
 * @class GUILifeBar
 * @brief A class that represents the GUI Life Bar.
 * @details This class inherits from GUIWindowElement and provides functionalities to manage the life bar.
 */
class GUILifeBar:public GUIWindowElement {
public:
    /**
     * @brief Default constructor.
     */
    GUILifeBar();

    /**
     * @brief Constructor with parameters.
     * @param x The x-coordinate of the life bar.
     * @param y The y-coordinate of the life bar.
     * @param width The width of the life bar.
     * @param height The height of the life bar.
     */
    GUILifeBar(float x, float y, float width, float height);

    /**
     * @brief Destructor.
     */
    ~GUILifeBar();

    /**
     * @brief Updates the life bar.
     * @param healthPercent The health percentage to be displayed.
     */
    void update(float healthPercent);

    /**
     * @brief Draws the life bar on the window.
     * @param window Pointer to the RenderWindow object.
     */
    void draw(sf::RenderWindow* window) override;

private:
    sf::RectangleShape outerRect; ///< RectangleShape object for the outer rectangle of the life bar.
    sf::RectangleShape innerRect; ///< RectangleShape object for the inner rectangle of the life bar.
};

#endif //MINIYUGIOHGUI_LIFEBAR_H
