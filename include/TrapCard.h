/**
 * @file TrapCard.h
 * @author Emre
 * @brief Contains the TrapCard class.
 */

#ifndef YUGIOH_TRAPCARD_H
#define YUGIOH_TRAPCARD_H

#include <string>
#include <functional>
#include "Card.h"

/**< forward declaration */
class Player;

/**
 * @brief A class representing a trap card.
 */
class TrapCard : public Card {
private:
    bool m_blocksAttack; /**< Flag to indicate whether the TrapCard blocks attacks. */
    std::function<void(Player *owner, Player *enemy)> effect; /**< Function for the TrapCard's effect. */

public:
    /**
     * @brief Constructor for TrapCard class.
     * @param[in] name Name of the trap card.
     * @param[in] description Description of the trap card.
     * @param[in] blocksAttack Flag to indicate whether the TrapCard blocks attacks.
     * @param[in] effect Function pointer to a function that takes two Player pointers as arguments and returns nothing.
     * @param[in] id ID of the trap card.
     */
    TrapCard(std::string name, std::string description, bool blocksAttack,
             std::function<void(Player *owner, Player *enemy)> effect, int id);

    /**
     * @brief Destructor for TrapCard class.
     */
    ~TrapCard();

    /**
     * @brief Get the face-up status of the trap card.
     * @return True if the trap card is face up, false otherwise.
     */
    bool isFacedUp();

    /**
     * @brief Get the blocks-attack status of the trap card.
     * @return True if the trap card blocks attacks, false otherwise.
     */
    bool blocksAttack();

    /**
     * @brief Get the details of the trap card.
     * @return Details of the trap card.
     */
    std::string getCardDetails() const override;

    /**
     * @brief Activate the effect of the trap card.
     * @param[in] owner Pointer to the owner of the trap card.
     * @param[in] enemy Pointer to the enemy of the trap card.
     */
    void activateEffect(Player *owner, Player *enemy);
};

#endif //YUGIOH_TRAPCARD_H
