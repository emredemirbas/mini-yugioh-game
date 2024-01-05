/**
 * @file GUISettings.h
 * @author Esat
 * @date 28.12.2023
 * @brief This file contains the GUISettings class which handles the GUI settings of the MiniYugioh game.
 */

#ifndef MINIYUGIOHGUI_GUISETTINGS_H
#define MINIYUGIOHGUI_GUISETTINGS_H

#include "GUIWindow.h"  ///< Include the base class header
#include "GUIGameState.h"  ///< Include the GameState enum
#include <SFML/Graphics.hpp>

/**
 * @class GUISettings
 * @brief This class handles the GUI settings of the MiniYugioh game.
 * @details It inherits from the GUIWindow class and overrides some of its functions.
 */
class GUISettings : public GUIWindow {
private:
    sf::RectangleShape volumeBar; ///< Represents the volume bar
    sf::RectangleShape volumeSlider; ///< Represents the slider on the volume bar
    sf::RectangleShape volumeText;
    sf::RectangleShape videoModeButton;
    sf::RectangleShape backButton;

    sf::Texture *backgroundTexture;
    sf::Texture *buttonTexture;
    sf::Texture *buttonTextureGreen;
    sf::Texture *backButtonTexture;
    sf::Texture *backButtonTextureGreen;
    sf::Texture *volumeTexture;

    sf::Sprite backgroundSprite;

    GUIGameState *guiGameState; ///< Pointer to the current game state

    float volumeLevel; ///< Current volume level (0 to 100)

    bool isDraggingSlider = false; ///< Flag to track whether the slider is being dragged

    bool isFullScreen = false; ///< Flag to track whether the game is in full screen mode

    bool isBlue1 = true; ///< Flag to track the color of the first button
    bool isBlue2 = true; ///< Flag to track the color of the second button

    void initWindow() override; ///< Initialize the window
    void initButtons() override; ///< Initialize the buttons
    void drawButtons(); ///< Draw the buttons on the window
    void initTextures() override; ///< Initialize the textures
    void initWindowElements() override; ///< Initialize the window elements

public:
    /**
     * @brief Constructor for the GUISettings class.
     * @param window Pointer to the RenderWindow object.
     * @param guiGameState Pointer to the current game state.
     */
    GUISettings(sf::RenderWindow *window , GUIGameState *guiGameState);

    /**
     * @brief Destructor for the GUISettings class.
     */
    ~GUISettings();

    /**
     * @brief Initialize the elements for the Settings.
     */
    void initElements();

    /**
     * @brief Get the current volume level.
     * @return The current volume level.
     */
    float getVolumeLevel();

    /**
     * @brief Handle user input and update the state.
     */
    void update() override;

    /**
     * @brief Draw the Settings elements.
     */
    void display() override;

    /**
     * @brief Check if the game is running.
     * @return True if the game is running, false otherwise.
     */
    bool const isRunning() override;
};

#endif //MINIYUGIOHGUI_GUISETTINGS_H
