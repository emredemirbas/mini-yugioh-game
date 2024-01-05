/**
 * @file YugiMuto.h
 * @author Emre
 * @brief Contains the YugiMuto class.
 */

#ifndef MINIYUGIOH_YUGIMUTO_H
#define MINIYUGIOH_YUGIMUTO_H

#include "Player.h"

/**
 * @brief A class representing Yugi Muto.
 */
class YugiMuto : public Player {
private:
    /**
     * @brief Override the initializeDeck() method of the Player class.
     * @return Deck of the player.
     */
    Deck *initializeDeck() override;

public:
    /**
     * @brief Constructor for YugiMuto class.
     */
    YugiMuto();

    /**
     * @brief Destructor for YugiMuto class.
     */
    ~YugiMuto();

    /**
     * @brief Check if Yugi Muto has all pieces of Exodia.
     * @return True if Yugi Muto has all pieces of Exodia, false otherwise.
     */
    bool hasAllPiecesOfExodia();
};

#endif //MINIYUGIOH_YUGIMUTO_H
