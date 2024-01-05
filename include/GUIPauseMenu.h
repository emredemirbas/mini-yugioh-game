/**
 * @file GUIPauseMenu.h
 * @author Esat
 * @date 29.12.2023
 * @brief This file contains the GUIPauseMenu class which handles the pause menu of the MiniYugioh game.
 */

#ifndef MINIYUGIOHGUI_GUIPAUSEMENU_H
#define MINIYUGIOHGUI_GUIPAUSEMENU_H

#include "GUIWindow.h" ///< Include the GUIWindow class
#include "GUIGameState.h" ///< Include the GUIGameState class

/**
 * @class GUIPauseMenu
 * @brief This class handles the pause menu of the MiniYugioh game.
 * @details It inherits from the GUIWindow class and overrides some of its functions.
 */
class GUIPauseMenu : public GUIWindow{
public:
    /**
     * @brief Constructor for the GUIPauseMenu class.
     * @param window Pointer to the RenderWindow object.
     * @param guiGameState Pointer to the current game state.
     */
    GUIPauseMenu(sf::RenderWindow *window , GUIGameState *guiGameState);

    /**
     * @brief Destructor for the GUIPauseMenu class.
     */
    ~GUIPauseMenu();

    /**
     * @brief Handle user input and update the state.
     */
    void update() override;

    /**
     * @brief Draw the pause menu elements.
     */
    void display() override;

    /**
     * @brief Check if the game is running.
     * @return True if the game is running, false otherwise.
     */
    const bool isRunning() override;

private:
    /**
     * @brief Initialize the window.
     */
    void initWindow() override;

    /**
     * @brief Initialize the textures.
     */
    void initTextures() override;

    /**
     * @brief Initialize the window elements.
     */
    void initWindowElements() override;

    /**
     * @brief Initialize the buttons.
     */
    void initButtons() override;

    /**
     * @brief Draw the buttons on the window.
     */
    void drawButtons();

    sf::RectangleShape resumeButton; ///< Button to resume the game
    sf::RectangleShape optionsButton; ///< Button to go to the options menu
    sf::RectangleShape returnToMenuButton; ///< Button to return to the main menu

    sf::Texture *resumeTexture; ///< Texture for the resume button
    sf::Texture *resumeGreenTexture; ///< Texture for the resume button when it's highlighted
    sf::Texture *optionsTexture; ///< Texture for the options button
    sf::Texture *optionsGreenTexture; ///< Texture for the options button when it's highlighted
    sf::Texture *mainMenuTexture; ///< Texture for the main menu button
    sf::Texture *mainMenuGreenTexture; ///< Texture for the main menu button when it's highlighted

    bool isRed1; ///< Flag to track the color of the first button
    bool isRed2; ///< Flag to track the color of the second button
    bool isRed3; ///< Flag to track the color of the third button

    GUIGameState *guiGameState; ///< Pointer to the current game state
};

#endif //MINIYUGIOHGUI_GUIPAUSEMENU_H
