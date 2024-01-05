/**
 * @file SpellCard.h
 * @author Emre
 * @brief Contains the SpellCard class.
 */

#ifndef YUGIOH_SPELLCARD_H
#define YUGIOH_SPELLCARD_H

#include <string>
#include <functional>
#include "Card.h"

/**< forward declaration */
class Player;

/**
 * @brief A class representing a spell card.
 */
class SpellCard : public Card {
private:
    std::function<void(Player *owner, Player *enemy)> effect; /**< Function pointer to a function that takes two Player pointers as arguments and returns nothing. */

public:
    /**
     * @brief Constructor for SpellCard class.
     * @param[in] name Name of the spell card.
     * @param[in] description Description of the spell card.
     * @param[in] effect Function pointer to a function that takes two Player pointers as arguments and returns nothing.
     * @param[in] id ID of the spell card.
     */
    SpellCard(std::string name, std::string description,
              std::function<void(Player *owner, Player *enemy)> effect, int id);

    /**
     * @brief Destructor for SpellCard class.
     */
    ~SpellCard();

    /**
     * @brief Get the details of the spell card.
     * @return Details of the spell card.
     */
    std::string getCardDetails() const override;

    /**
     * @brief Activate the effect of the spell card.
     * @param[in] owner Pointer to the owner of the spell card.
     * @param[in] enemy Pointer to the enemy of the spell card.
     */
    void activateEffect(Player *owner, Player *enemy);
};

#endif //YUGIOH_SPELLCARD_H
