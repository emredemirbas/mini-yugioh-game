
//
// Created by Esat on 28.12.2023.
//

#ifndef MINIYUGIOHGUI_GUIGAMESTATE_H
#define MINIYUGIOHGUI_GUIGAMESTATE_H

/**
 * @enum GuiState
 * @brief Enumerates the possible states of the GUI.
 */
enum GuiState{
    MAIN_MENU, ///< Represents the main menu state.
    GAME, ///< Represents the game state.
    PAUSE_MENU, ///< Represents the pause menu state.
    SETTINGS, ///< Represents the settings state.
    EXIT ///< Represents the exit state.
};

/**
 * @class GUIGameState
 * @brief A class that represents the GUI Game State.
 * @details This class provides functionalities to manage the game state.
 */
class GUIGameState{
private:
    GuiState guiGameState; ///< The current state of the GUI.
    GuiState previousState; ///< The previous state of the GUI.

public:
    /**
     * @brief Default constructor.
     */
    GUIGameState();

    /**
     * @brief Destructor.
     */
    ~GUIGameState();

    /**
     * @brief Gets the current GUI game state.
     * @return The current GUI game state.
     */
    GuiState getGUIGameState();

    /**
     * @brief Gets the previous GUI game state.
     * @return The previous GUI game state.
     */
    GuiState getPreviousState();

    /**
     * @brief Sets the GUI game state.
     * @param state The new GUI game state.
     */
    void setGUIGameState(GuiState state);
};

#endif //MINIYUGIOHGUI_GUIGAMESTATE_H
