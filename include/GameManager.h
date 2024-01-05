/**
 * @file GameManager.h
 * @author Emre
 * @brief Contains the GameManager class.
 */

#ifndef MINIYUGIOHGUI_GAMEMANAGER_H
#define MINIYUGIOHGUI_GAMEMANAGER_H

#include "Player.h"
#include "GUIGameState.h"

/**
 * @brief An enumerated type representing different game states.
 */
enum GameState {
    DRAW_PHASE, /**< The draw phase. */
    MAIN_PHASE, /**< The main phase. */
    BATTLE_PHASE, /**< The battle phase. */
    END_PHASE /**< The end phase. */
};

/**
 * @brief A class representing the game manager.
 */
class GameManager {
private:
    int round; /**< Current round of the game */
    Player *currentPlayer; /**< Pointer to the current player */
    Player *opposingPlayer; /**< Pointer to the opposing player */
    GameState gameState; /**< Current state of the game (draw phase, main phase, etc.) */
    bool isCurrentPlayerPlayedCardAtMP; /**< Flag indicating if the current player played a card in the main phase */
    bool isCurrentPlayerChangesCardModeAtMP; /**< Flag indicating if the current player changed mode of any monster card at main phase */

public:
    /**
     * @brief Constructor for GameManager class.
     */
    GameManager();

    /**
     * @brief Destructor for GameManager class.
     */
    ~GameManager();

    /**
     * @brief Initiates a battle between the provided attacker and target MonsterCards, resolving the outcome.
     * @param[in] attacker Attacking MonsterCard.
     * @param[in] target Target MonsterCard.
     */
    void declareAttack(MonsterCard *attacker, MonsterCard *target);

    /**
     * @brief Directly decrease LP of opposingPlayer by attacker MonsterCard's Active Points.
     * @param[in] attacker Attacking MonsterCard.
     */
    void attackLifePoints(MonsterCard *attacker);

    /**
     * @brief Initialize the game state.
     */
    void initializeGame();

    /**
     * @brief Restart the game.
     */
    void restartTheGame();

    /**
     * @brief Activates the first found TrapCard on the opposingPlayer's field.
     * If TrapCard is activated, this Card is also will be added to opposingPlayer's graveyard.
     */
    void activateTrapCard();

    /**
     * @brief Execute draw phase.
     */
    void drawPhase();

    /**
     * @brief Execute main phase with selected card index.
     * @param[in] selectedCardIndex Index of the selected card.
     */
    void mainPhase(int selectedCardIndex);

    /**
     * @brief Execute battle phase with attacker and target indexes.
     * @param[in] attackerIndex Index of the attacking MonsterCard.
     * @param[in] targetIndex Index of the target MonsterCard.
     */
    void battlePhase(int attackerIndex, int targetIndex);

    /**
     * @brief Execute end phase.
     */
    void endPhase();

    /**
     * @brief Swap the current player and opposing player.
     */
    void swapPlayers();

    /**
     * @brief Change the card mode of the selected card.
     * @param[in] selectedCardIndex Index of the selected card.
     */
    void changeCardMode(int selectedCardIndex);

    /**
     * @brief Get the flag indicating if the current player played a card in the main phase.
     * @return True if the current player played a card in the main phase, false otherwise.
     */
    bool getIsCurrentPlayerPlayedCardAtMP() const;

    /**
     * @brief Get the flag indicating if the current player changed the card mode in the main phase.
     * @return True if the current player changed the card mode in the main phase, false otherwise.
     */
    bool getIsCurrentPlayerChangedCardModeAtMP() const;

    /**
     * @brief Get the current game state.
     * @return Current game state.
     */
    GameState getGameState() const;

    /**
     * @brief Get a pointer to the current player.
     * @return Pointer to the current player.
     */
    Player *getCurrentPlayer() const;

    /**
     * @brief Get a pointer to the opposing player.
     * @return Pointer to the opposing player.
     */
    Player *getOpposingPlayer() const;

    /**
     * @brief Determine the winner of the game.
     * @return Pointer to the winner of the game.
     */
    Player *determineWinner();
};


#endif //MINIYUGIOHGUI_GAMEMANAGER_H
