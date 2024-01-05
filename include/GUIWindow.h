//
// Created by faruk on 20.12.2023.
//

#ifndef MINIYUGIOHGUI_GUIWINDOW_H
#define MINIYUGIOHGUI_GUIWINDOW_H

#include "SFML/Graphics.hpp"

/**
 * @brief This class represents a GUI window.
 *
 * This class contains information about a GUI window, such as its dimensions and elements.
 */
class GUIWindow {
public:
    /**
     * @brief Constructs a new GUIWindow object.
     *
     * This constructor initializes the GUI window with the specified render window.
     *
     * @param window The render window to use for the GUI window.
     */
    GUIWindow(sf::RenderWindow* window);

    /**
     * @brief Destroys the GUIWindow object.
     *
     * This destructor deallocates the memory used by the GUI window.
     */
    virtual ~GUIWindow();

    /**
     * @brief Updates the GUI window.
     *
     * This function updates the GUI window by processing events and updating the window elements.
     */
    virtual void update() = 0;

    /**
     * @brief Displays the GUI window.
     *
     * This function displays the GUI window by rendering its elements to the screen.
     */
    virtual void display() = 0;

    /**
     * @brief Checks if the GUI window is running.
     *
     * This function checks if the GUI window is running by checking if the render window is open.
     *
     * @return True if the GUI window is running, false otherwise.
     */
    virtual const bool isRunning() = 0;

protected:
    sf::RenderWindow *window; /**< The render window used by the GUI window. */
    sf::Event event; /**< The event object used by the GUI window. */

    /**
     * @brief Initializes the GUI window.
     *
     * This function initializes the GUI window by setting its dimensions and background color.
     */
    virtual void initWindow() = 0;

    /**
     * @brief Initializes the textures used by the GUI window.
     *
     * This function initializes the textures used by the GUI window, such as images and fonts.
     */
    virtual void initTextures() = 0;

    /**
     * @brief Initializes the window elements.
     *
     * This function initializes the window elements, such as text boxes and buttons.
     */
    virtual void initWindowElements() = 0;

    /**
     * @brief Initializes the buttons used by the GUI window.
     *
     * This function initializes the buttons used by the GUI window, such as play and pause buttons.
     */
    virtual void initButtons() = 0;
};

#endif MINIYUGIOHGUI_GUIWINDOW_H