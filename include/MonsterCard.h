/**
 * @file MonsterCard.h
 * @author Emre
 * @brief Contains the MonsterCard class.
 */

#ifndef YUGIOH_MONSTERCARD_H
#define YUGIOH_MONSTERCARD_H

#include <string>
#include "Card.h"

/**
 * @brief An enumerated type representing the type of the MonsterCard.
 */
enum MonsterType {
    DRAGON, /**< Dragon type. */
    SPELLCASTER, /**< Spellcaster type. */
    WARRIOR, /**< Warrior type. */
    BEAST_WARRIOR, /**< Beast-Warrior type. */
    BEAST, /**< Beast type. */
    FIEND, /**< Fiend type. */
    ROCK, /**< Rock type. */
    DINOSAUR, /**< Dinosaur type. */
    AQUA, /**< Aqua type. */
    MACHINE, /**< Machine type. */
    DIVINE_BEAST, /**< Divine-Beast type. */
    SEA_SERPENT, /**< Sea Serpent type. */
    REPTILE, /**< Reptile type. */
    FAIRY, /**< Fairy type. */
    WINGED_BEAST /**< Winged Beast type. */
};

/**
 * @brief A class representing a MonsterCard.
 */
class MonsterCard : public Card {
private:
    int attackPoints; /**< Attack Points of the MonsterCard. */
    int defensePoints; /**< Defense Points of the MonsterCard. */
    int activePoints; /**< Active Points of the MonsterCard. */
    int level; /**< Level of the MonsterCard. */
    bool mode; /**< Flag that indicates the current mode of the MonsterCard. If mode is true, the MonsterCard is in Attack Mode. */
    MonsterType type; /**< Type of the MonsterCard. */

public:
    /**
     * @brief Constructor for MonsterCard class.
     * @param[in] name Name of the MonsterCard.
     * @param[in] description Description of the MonsterCard.
     * @param[in] attackPoints Attack Points of the MonsterCard.
     * @param[in] defensePoints Defense Points of the MonsterCard.
     * @param[in] level Level of the MonsterCard.
     * @param[in] type Type of the MonsterCard.
     * @param[in] id ID of the MonsterCard.
     */
    MonsterCard(std::string name, std::string description, int attackPoints, int defensePoints, int level,
                MonsterType type, int id);

    /**
     * @brief Destructor for MonsterCard class.
     */
    ~MonsterCard();

    // Getters & Setters

    /**
     * @brief Get the Attack Points of the MonsterCard.
     * @return Attack Points of the MonsterCard.
     */
    int getAttackPoints() const;

    /**
     * @brief Get the Defense Points of the MonsterCard.
     * @return Defense Points of the MonsterCard.
     */
    int getDefensePoints() const;

    /**
     * @brief Get the Level of the MonsterCard.
     * @return Level of the MonsterCard.
     */
    int getLevel() const;

    /**
     * @brief Get the Active Points of the MonsterCard.
     * @return Active Points of the MonsterCard.
     */
    int getActivePoints() const;

    /**
     * @brief Check if the MonsterCard is in Attack Mode.
     * @return True if the MonsterCard is in Attack Mode, false otherwise.
     */
    bool isAttackMode() const;

    /**
     * @brief Get the Type of the MonsterCard.
     * @return Type of the MonsterCard.
     */
    MonsterType getType() const;

    /**
     * @brief Get the details of the MonsterCard.
     * @return Details of the MonsterCard.
     */
    std::string getCardDetails() const override;

    /**
     * @brief Set the Attack Points of the MonsterCard.
     * @param[in] attackPoints Attack Points of the MonsterCard.
     */
    void setAttackPoints(int attackPoints);

    /**
     * @brief Set the Defense Points of the MonsterCard.
     * @param[in] defensePoints Defense Points of the MonsterCard.
     */
    void setDefensePoints(int defensePoints);

    /**
     * @brief Set the Active Points of the MonsterCard.
     * @param[in] activePoints Active Points of the MonsterCard.
     */
    void setActivePoints(int activePoints);

    /**
     * @brief Set the mode of the MonsterCard.
     * @param[in] expr True if the MonsterCard is in Attack Mode, false otherwise.
     */
    void setMode(bool expr);

    /**
     * @brief Change the mode of the MonsterCard and re-determine the Active Points of the MonsterCard.
     */
    void changeMode();
};

#endif //YUGIOH_MONSTERCARD_H
