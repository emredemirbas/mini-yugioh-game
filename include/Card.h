/**
 * @file Card.h
 * @author Emre
 * @brief Contains the Card class.
 */

#ifndef YUGIOH_CARD_H
#define YUGIOH_CARD_H

#include <string>
#include "SFML/Graphics.hpp"

/**
 * @brief Abstract Card Class.
 */
class Card {
private:
    std::string name; /**< Name of the Card */
    std::string description; /**< Description of the Card */
    bool isFaceUp; /**< Flag that indicates whether the Card is faced-up */
    sf::Texture *cardTexture; /**< Texture of Card */
    int id; /**< ID of Card */

public:

    /**
     * @brief Constructor for Card class.
     * @param[in] name Name of the Card.
     * @param[in] description Description of the Card.
     * @param[in] id ID of the Card.
     */
    Card(std::string name, std::string description, int id);

    /**
     * @brief Destructor for Card class.
     */
    virtual ~Card();

    // Getters & Setters

    /**
     * @brief Get the name of the Card.
     * @return Name of the Card.
     */
    std::string getName() const;

    /**
     * @brief Get the description of the Card.
     * @return Description of the Card.
     */
    std::string getDescription() const;

    /**
     * @brief Get the details of the Card.
     * @return Details of the Card.
     */
    virtual std::string getCardDetails() const = 0;

    /**
     * @brief Get the texture of the Card.
     * @return Texture of the Card.
     */
    sf::Texture *getCardTexture() const;

    /**
     * @brief Check if the Card is faced-up.
     * @return True if the Card is faced-up, false otherwise.
     */
    bool isFacedUp() const;

    /**
     * @brief Set the face-up status of the Card.
     * @param[in] expr True if the Card is faced-up, false otherwise.
     */
    void setIsFaceUp(bool expr);

    /**
     * @brief Set the texture of the Card.
     * @param[in] texture Texture of the Card.
     */
    void setCardTexture(sf::Texture *texture);

    /**
     * @brief Flip the Card.
     */
    void flip();


};


#endif //YUGIOH_CARD_H