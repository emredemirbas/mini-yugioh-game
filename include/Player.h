/**
 * @file Player.h
 * @author Emre
 * @brief Contains the Player class.
 */

#ifndef YUGIOH_CHARACTER_H
#define YUGIOH_CHARACTER_H

#include <iostream>
#include <string>
#include <vector>
#include "Deck.h"
#include "Card.h"
#include "PlayingField.h"

/**
 * @brief An abstract class representing a player.
 */
class Player {
private:
    std::string name; /**< Name of the player. */
    int lifePoints; /**< Life points of the player. */
    Deck *deck; /**< Deck of the player. */
    std::vector<Card *> *hand; /**< Hand of the player. */
    PlayingField *playingField; /**< Playing field of the player. */

protected:
    /**
     * @brief Pure virtual function that initializes and returns the deck of each player.
     * (See YugiMuto.cpp and SetoKaiba.cpp to see how it's implemented.)
     * @return Deck of the player.
     */
    virtual Deck *initializeDeck() = 0;

public:
    /**
     * @brief Constructor for Player class.
     * @param[in] name Name of the player.
     * @param[in] deck Deck of the player.
     */
    Player(std::string name, Deck *deck);

    /**
     * @brief Destructor for Player class.
     */
    virtual ~Player();

    // Getters & Setters

    /**
     * @brief Get the name of the player.
     * @return Name of the player.
     */
    std::string getName() const;

    /**
     * @brief Get the life points of the player.
     * @return Life points of the player.
     */
    int getLifePoints() const;

    /**
     * @brief Get the deck of the player.
     * @return Deck of the player.
     */
    Deck *getDeck() const;

    /**
     * @brief Get the hand of the player.
     * @return Hand of the player.
     */
    std::vector<Card *> *getHand() const;

    /**
     * @brief Get the playing field of the player.
     * @return Playing field of the player.
     */
    PlayingField *getPlayingField() const;

    /**
     * @brief Set the life points of the player.
     * @param[in] lifePoints Life points of the player.
     */
    void setLifePoints(int lifePoints);

    /**
     * @brief Decrease the life points of the player by the specified amount.
     * @param[in] amount Amount to decrease the life points by.
     */
    void decreaseLifePoints(int amount);

    /**
     * @brief Increase the life points of the player by the specified amount.
     * @param[in] amount Amount to increase the life points by.
     */
    void increaseLifePoints(int amount);

    /**
     * @brief Add the specified card to the hand of the player.
     * @param[in] card Card to add to the hand.
     */
    void addCardToHand(Card *card);

    /**
     * @brief Draw a card from the deck of the player and add it to the hand.
     */
    void addCardToHandFromDeck();

    /**
     * @brief Remove the specified card from the hand of the player.
     * @param[in] card Card to remove from the hand.
     */
    void removeCardFromHand(Card *card);

    /**
     * @brief Discard the specified card from the hand of the player.
     * @param[in] card Card to discard from the hand.
     */
    void discard(Card *card);

    /**
     * @brief Tribute the specified monster card from the playing field of the player.
     * @param[in] monsterCard Monster card to tribute from the playing field.
     */
    void tribute(MonsterCard *monsterCard);
};

#endif //YUGIOH_CHARACTER_H
