/**
 * @file SetoKaiba.h
 * @author Emre
 * @brief Contains the SetoKaiba class.
 */

#ifndef MINIYUGIOH_SETOKAIBA_H
#define MINIYUGIOH_SETOKAIBA_H

#include "Player.h"

/**
 * @brief A class representing Seto Kaiba.
 */
class SetoKaiba : public Player {
private:
    /**
     * @brief Override the initializeDeck() method of the Player class.
     * @return Deck of the player.
     */
    Deck *initializeDeck() override;

public:
    /**
     * @brief Constructor for SetoKaiba class.
     */
    SetoKaiba();

    /**
     * @brief Destructor for SetoKaiba class.
     */
    ~SetoKaiba();

    /**
     * @brief Check if Seto Kaiba has three Blue-Eyes White Dragon cards in his deck.
     * @return True if Seto Kaiba has three Blue-Eyes White Dragon cards in his deck, false otherwise.
     */
    bool hasThreeBlueEyesWhiteDragon();

    /**
     * @brief Summon Blue-Eyes Ultimate Dragon.
     */
    void summonBlueEyesUltimateDragon();
};

#endif //MINIYUGIOH_SETOKAIBA_H
