//
// Created by faruk on 20.12.2023.
//

#ifndef MINIYUGIOHGUI_GUIGAMEWINDOW_H
#define MINIYUGIOHGUI_GUIGAMEWINDOW_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "GUIWindow.h"
#include "GUIPlayerPanel.h"
#include "GUIPlayingField.h"
#include "GUIHand.h"
#include "GUIGraveyard.h"
#include "GUICardInfoPanel.h"
#include "GUIPhaseText.h"
#include "GameManager.h"
#include "GUIPauseMenu.h"
#include "GUIGameState.h"

/**
 * @class GUIGameWindow
 * @brief Class representing the GUI game window.
 * @details This class inherits from GUIWindow and provides functionalities for the game window in the GUI.
 */
class GUIGameWindow : public GUIWindow {
public:
    /**
     * @brief Constructor for GUIGameWindow.
     * @param window Pointer to the RenderWindow object.
     * @param gameManager Pointer to the GameManager object.
     * @param guiGameState Pointer to the GUIGameState object.
     */
    GUIGameWindow(sf::RenderWindow *window, GameManager *gameManager, GUIGameState *guiGameState);

    /**
     * @brief Destructor for GUIGameWindow.
     */
    ~GUIGameWindow();

    /**
     * @brief Updates the game window.
     * @details This function is overridden from the base class.
     */
    virtual void update() override;

    /**
     * @brief Displays the game window.
     * @details This function is overridden from the base class.
     */
    virtual void display() override;

    /**
     * @brief Checks if the game window is running.
     * @details This function is overridden from the base class.
     * @return Boolean value indicating whether the game window is running.
     */
    virtual const bool isRunning() override;

private:

    /**
     * @brief Initializes the game window.
     * @details This function is overridden from the base class.
     */
    virtual void initWindow() override;

    /**
     * @brief Initializes the textures for the game window.
     * @details This function is overridden from the base class.
     */
    virtual void initTextures() override;

    /**
     * @brief Initializes the window elements for the game window.
     * @details This function is overridden from the base class.
     */
    virtual void initWindowElements() override;

    /**
     * @brief Initializes the buttons for the game window.
     * @details This function is overridden from the base class.
     */
    virtual void initButtons() override;

    /**
     * @brief Initializes the game.
     */
    void initGame();

    /**
     * @brief Iterates the main phase 1 of the game.
     */
    void iterateMainPhase1();

    /**
     * @brief Iterates the battle phase of the game.
     */
    void iterateBattlePhase();

    /**
     * @brief Iterates the turn of the game.
     */
    void iterateTurn();

    /**
     * @brief Updates the card info panel.
     */
    void updateCardInfoPanel();

    /**
     * @brief Handles the winner events.
     */
    void winnerEvents();

    // Texture and Sprite objects
    sf::Texture *backgroundTexture;
    sf::Texture *cardBackTexture;
    sf::Texture *deckTexture;
    sf::Texture *deckOppositeTexture;
    sf::Texture *yugiWinsTexture;
    sf::Texture *setoWinsTexture;

    sf::Sprite backgroundSprite;
    sf::Sprite yugiWinsSprite;
    sf::Sprite setoWinsSprite;

    // GUI objects
    GUIPlayerPanel *currentPlayersPlayerPanel;
    GUIPlayerPanel *opposingPlayersPlayerPanel;

    GUIPlayingField *currentPlayersPlayingField;
    GUIPlayingField *opposingPlayersPlayingField;

    GUIHand *currentPlayersHand;
    GUIHand *opposingPlayersHand;

    GUIGraveyard *currentPlayersGraveyard;
    GUIGraveyard *opposingPlayersGraveyard;

    GUICardInfoPanel *cardInfoPanel;

    GUIPhaseText *mainPhaseText;
    GUIPhaseText *battlePhaseText;

    // Clock objects
    sf::Clock mainPhaseClock;
    sf::Clock battlePhaseClock;

    bool isBattlePhaseClockStarted;

    // Game management objects
    GameManager *gameManager;
    GUIGameState *guiGameState;
    GUIPauseMenu pauseMenu;

    /**
     * @brief Draws the decks.
     */
    void drawDecks();
};


#endif //MINIYUGIOHGUI_GUIGAMEWINDOW_H
