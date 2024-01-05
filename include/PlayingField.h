/**
 * @file PlayingField.h
 * @author Emre
 * @brief Contains the PlayingField class.
 */

#ifndef YUGIOH_PLAYINGFIELD_H
#define YUGIOH_PLAYINGFIELD_H

#include <iostream>
#include <vector>
#include "Card.h"
#include "MonsterCard.h"
#include "SpellCard.h"
#include "TrapCard.h"

/**
 * @brief A class representing a playing field.
 */
class PlayingField {

private:
    std::vector<MonsterCard *> monsterField; /**< Vector to store MonsterCards on the field. */
    std::vector<Card *> spellTrapField; /**< Vector to store Spell and Trap Cards on the field. */
    std::vector<Card *> graveyard; /**< Vector to store Cards in the graveyard. */

public:
    /**
     * @brief Constructor for PlayingField class.
     */
    PlayingField();

    /**
     * @brief Destructor for PlayingField class.
     */
    ~PlayingField();

    /**
     * @brief Add the specified Card to the field.
     * @param[in] card Card to add to the field.
     */
    void addCardToPlayingField(Card *card);

    /**
     * @brief Add the specified MonsterCard to the field.
     * @param[in] monsterCard MonsterCard to add to the field.
     */
    void addCardToPlayingField(MonsterCard *monsterCard);

    /**
     * @brief Add the specified SpellCard to the field.
     * @param[in] spellCard SpellCard to add to the field.
     */
    void addCardToPlayingField(SpellCard *spellCard);

    /**
     * @brief Add the specified TrapCard to the field.
     * @param[in] trapCard TrapCard to add to the field.
     */
    void addCardToPlayingField(TrapCard *trapCard);

    /**
     * @brief Remove the specified Card object from the Spell/Trap field and add this Card to the graveyard.
     * @param[in] card Card to remove from the Spell/Trap field.
     */
    void removeCardFromSpellTrapField(Card *card);

    /**
     * @brief Remove the specified MonsterCard object from the Monster field and add this Card to the graveyard.
     * @param[in] card MonsterCard to remove from the Monster field.
     */
    void removeCardFromMonsterField(MonsterCard *card);

    /**
     * @brief Remove the specified SpellCard object from the Spell/Trap field and add this Card to the graveyard.
     * @param[in] spellCard SpellCard to remove from the Spell/Trap field.
     */
    void removeCardFromSpellTrapField(SpellCard *spellCard);

    /**
     * @brief Remove the specified TrapCard object from the Spell/Trap field and add this Card to the graveyard.
     * @param[in] trapCard TrapCard to remove from the Spell/Trap field.
     */
    void removeCardFromSpellTrapField(TrapCard *trapCard);

    /**
     * @brief Add the specified Card object to the graveyard.
     * @param[in] card Card to add to the graveyard.
     */
    void addCardToGraveyard(Card *card);

    /**
     * @brief Add the specified MonsterCard object to the graveyard.
     * @param[in] monsterCard MonsterCard to add to the graveyard.
     */
    void addCardToGraveyard(MonsterCard *monsterCard);

    /**
     * @brief Add the specified SpellCard object to the graveyard.
     * @param[in] spellCard SpellCard to add to the graveyard.
     */
    void addCardToGraveyard(SpellCard *spellCard);

    /**
     * @brief Add the specified TrapCard object to the graveyard.
     * @param[in] trapCard TrapCard to add to the graveyard.
     */
    void addCardToGraveyard(TrapCard *trapCard);

    /**
     * @brief Remove MonsterCard objects from the graveyard and return the removed card.
     * @param[in] card MonsterCard to remove from the graveyard.
     * @return Removed MonsterCard.
     */
    MonsterCard *removeMonsterCardFromGraveyard(MonsterCard *card);

    /**
     * @brief Get the vector of MonsterCards on the field.
     * @return Vector of MonsterCards on the field.
     */
    std::vector<MonsterCard *> getMonsterField();

    /**
     * @brief Get the count of active MonsterCards on the field.
     * @return Count of active MonsterCards on the field.
     */
    int getCountOfActiveMonsters();

    /**
     * @brief Get the vector of Spell/Trap Cards on the field.
     * @return Vector of Spell/Trap Cards on the field.
     */
    std::vector<Card *> getSpellTrapField();

/**
     * @brief Get the vector of Cards in the graveyard.
     * @return Vector of Cards in the graveyard.
     */
    std::vector<Card *> getGraveyard();

    /**
     * @brief Get the vector of MonsterCards in the graveyard.
     * @return Vector of MonsterCards in the graveyard.
     */
    std::vector<MonsterCard *> getMonsterCardsInGraveyard();

    /**
     * @brief Get a pointer to the strongest MonsterCard on the field.
     * @return Pointer to the strongest MonsterCard on the field.
     */
    MonsterCard *getStrongestMonsterInField();

    /**
     * @brief Get a pointer to the strongest MonsterCard in the graveyard.
     * @return Pointer to the strongest MonsterCard in the graveyard.
     */
    MonsterCard *getStrongestMonsterInGY();

    /**
     * @brief Get a pointer to the weakest MonsterCard on the field.
     * @return Pointer to the weakest MonsterCard on the field.
     */
    MonsterCard *getWeakestMonsterInField();

    /**
     * @brief Get a pointer to the weakest MonsterCard in the graveyard.
     * @return Pointer to the weakest MonsterCard in the graveyard.
     */
    MonsterCard *getWeakestMonsterInGY();

    /**
     * @brief Check if there is at least one MonsterCard on the field.
     * @return True if there is at least one MonsterCard on the field, false otherwise.
     */
    bool isThereMonsterInField();

    /**
     * @brief Check if there is at least one attacking MonsterCard on the field.
     * @return True if there is at least one attacking MonsterCard on the field, false otherwise.
     */
    bool isThereAttackingMonsterInField();

    /**
     * @brief Check if there is at least one TrapCard on the field.
     * @return True if there is at least one TrapCard on the field, false otherwise.
     */
    bool isThereTrapCardInField();
};

#endif //YUGIOH_PLAYINGFIELD_H