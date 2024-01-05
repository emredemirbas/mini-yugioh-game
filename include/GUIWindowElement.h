/**
 * @file GUIWindowElement.h
 * @brief This file contains the declaration of the GUIWindowElement class.
 */

#ifndef MINIYUGIOHGUI_GUIWINDOWELEMENT_H
#define MINIYUGIOHGUI_GUIWINDOWELEMENT_H

#include "SFML/Graphics.hpp"

/**
 * @brief The GUIWindowElement class is an abstract class that represents a graphical element in a window.
 */
class GUIWindowElement {
protected:
    float basePositionX; /**< The x-coordinate of the base position of the element. */
    float basePositionY; /**< The y-coordinate of the base position of the element. */

public:
    /**
     * @brief Default constructor for the GUIWindowElement class.
     */
    GUIWindowElement();

    /**
     * @brief Constructor for the GUIWindowElement class.
     * @param x The x-coordinate of the base position of the element.
     * @param y The y-coordinate of the base position of the element.
     */
    GUIWindowElement(float x, float y);

    /**
     * @brief Virtual destructor for the GUIWindowElement class.
     */
    virtual ~GUIWindowElement();

    /**
     * @brief Pure virtual function that draws the element on the window.
     * @param window The window on which the element is to be drawn.
     */
    virtual void draw(sf::RenderWindow *window) = 0;
};

#endif //MINIYUGIOHGUI_GUIWINDOWELEMENT_H
