/**
 * @file GUIMainMenuWindow.h
 * @author Esat
 * @date 22.12.2023
 * @brief This file contains the GUIMainMenuWindow class which handles the main menu window of the MiniYugioh game.
 */

#ifndef MINIYUGIOHGUI_GUIMainMenuWindow_H
#define MINIYUGIOHGUI_GUIMainMenuWindow_H

#include "GUIWindow.h" ///< Include the GUIWindow class
#include "GUIGameState.h" ///< Include the GUIGameState class

/**
 * @class GUIMainMenuWindow
 * @brief This class handles the main menu window of the MiniYugioh game.
 * @details It inherits from the GUIWindow class and overrides some of its functions.
 */
class GUIMainMenuWindow : public GUIWindow{
public:
    /**
     * @brief Constructor for the GUIMainMenuWindow class.
     * @param window Pointer to the RenderWindow object.
     * @param guiGameState Pointer to the current game state.
     */
    GUIMainMenuWindow(sf::RenderWindow *window , GUIGameState *guiGameState);

    /**
     * @brief Destructor for the GUIMainMenuWindow class.
     */
    ~GUIMainMenuWindow();

    /**
     * @brief Handle user input and update the state.
     */
    void update() override;

    /**
     * @brief Draw the main menu elements.
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

    sf::Texture *backgroundTexture; ///< Texture for the background
    sf::Texture *startTexture; ///< Texture for the start button
    sf::Texture *settingsTexture; ///< Texture for the settings button
    sf::Texture *exitTexture; ///< Texture for the exit button
    sf::Texture *startTextureGreen; ///< Texture for the start button when it's highlighted
    sf::Texture *settingsTextureGreen; ///< Texture for the settings button when it's highlighted
    sf::Texture *exitTextureGreen; ///< Texture for the exit button when it's highlighted
    sf::Texture *miniYugiohTexture; ///< Texture for the MiniYugioh logo

    sf::Sprite backgroundSprite; ///< Sprite for the background
    sf::Sprite textSprite; ///< Sprite for the text

    sf::RectangleShape *buttonArea1; ///< Area for the first button
    sf::RectangleShape *buttonArea2; ///< Area for the second button
    sf::RectangleShape *buttonArea3; ///< Area for the third button

    bool isBlue1 = true; ///< Flag to track the color of the first button
    bool isBlue2 = true; ///< Flag to track the color of the second button
    bool isBlue3 = true; ///< Flag to track the color of the third button

    GUIGameState *guiGameState; ///< Pointer to the current game state
};

#endif //MINIYUGIOHGUI_GUIMainMenuWindow_H
