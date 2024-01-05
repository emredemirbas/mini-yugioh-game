/**
 * @file yugioh_deck.h
 * @author Emre
 * @brief Contains the Deck class.
 */

#ifndef YUGIOH_DECK_H
#define YUGIOH_DECK_H

#include <vector>
#include "Card.h"

/**
 * @brief A class representing a deck of cards.
 */
class Deck {
private:
    std::vector<Card *> cards; /**< Vector to store the Cards in the Deck */

public:

    /**
     * @brief Constructor for Deck class.
     */
    Deck();

    /**
     * @brief Destructor for Deck class.
     */
    ~Deck();

    /**
     * @brief Draw a Card from the deck.
     * @return Drawn Card.
     */
    Card *drawCard();

    /**
     * @brief Shuffle the Deck.
     */
    void shuffle();

    /**
     * @brief Get a reference to the vector of Cards in the Deck.
     * @return Reference to the vector of Cards in the Deck.
     */
    std::vector<Card *> &getCards();

    /**
     * @brief Add a Card to the Deck.
     * @param[in] card Card to be added to the Deck.
     */
    void addCard(Card *card);


};


#endif //YUGIOH_DECK_H
