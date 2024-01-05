#include "PlayingField.h"
#include <algorithm>
#include <iostream>


PlayingField::PlayingField() {
    // Initialize the monsterField, spellTrapField, and graveyard with empty vectors.
    this->monsterField = std::vector<MonsterCard *>();
    this->spellTrapField = std::vector<Card *>();
    this->graveyard = std::vector<Card *>();

    // Set the initial size of the monsterField and spellTrapField to 5,
    // with all elements initialized to nullptr.
    monsterField.assign(5, nullptr);
    spellTrapField.assign(5, nullptr);
}

PlayingField::~PlayingField() {
    for (MonsterCard *card: monsterField) {
        delete card;
    }
    monsterField.clear();
    for (Card *card: spellTrapField) {
        delete card;
    }
    spellTrapField.clear();
    for (Card *card: graveyard) {
        delete card;
    }
    graveyard.clear();
}


void PlayingField::addCardToPlayingField(MonsterCard *monsterCard) {
    for (int i = 0; i < 5; i++) {
        if (monsterField.at(i) == nullptr) { // if the index i at the monsterField is not occupied
            monsterField.at(i) = monsterCard; // place the monsterCard to the ith index
            return; // terminate method if the monsterCard is successfully placed
        }
    }
}

void PlayingField::addCardToPlayingField(TrapCard *trapCard) {
    for (int i = 0; i < 5; i++) {
        if (spellTrapField.at(i) == nullptr) {
            spellTrapField.at(i) = trapCard;
            return;
        }
    }
}

void PlayingField::addCardToPlayingField(SpellCard *spellCard) {
    for (int i = 0; i < 5; i++) {
        if (spellTrapField.at(i) == nullptr) {
            spellTrapField.at(i) = spellCard;
            return;
        }
    }
}

void PlayingField::addCardToPlayingField(Card *card) {
    if (card == nullptr) return; // terminate the method if card is nullptr.

    else if (auto *monsterCard = dynamic_cast<MonsterCard *>(card)) {
        addCardToPlayingField(monsterCard);
    } else if (auto *spellCard = dynamic_cast<SpellCard *>(card)) {
        addCardToPlayingField(spellCard);
    } else if (auto *trapCard = dynamic_cast<TrapCard *>(card)) {
        addCardToPlayingField(trapCard);
    }
}

// Remove the specified MonsterCard from monsterField and add it to the graveyard.
void PlayingField::removeCardFromMonsterField(MonsterCard *card) {
    if (card == nullptr) return; // if the card is null, terminate the method
    for (int i = 0; i < 5; i++) {
        if (monsterField.at(i) == card) {
            auto *copy = new MonsterCard(*card); // create copy of card
            monsterField.at(i) = nullptr; // remove the card from monsterField
            graveyard.push_back(copy); // add copy of the card to the graveyard
            return; // since the specific task of this method is done, terminate method.
        }
    }
}


void PlayingField::addCardToGraveyard(MonsterCard *monsterCard) {
    for (int i = 0; i < 5; i++) {
        if (monsterField.at(i) == monsterCard) {
            graveyard.push_back(new MonsterCard(*monsterCard)); // add it to the graveyard
            return; // terminate the method
        }
    }
}


void PlayingField::addCardToGraveyard(SpellCard *spellCard) {
    for (int i = 0; i < 5; i++) {
        if (spellTrapField.at(i) == spellCard) {
            graveyard.push_back(new SpellCard(*spellCard));
            return;
        }
    }
}


void PlayingField::addCardToGraveyard(TrapCard *trapCard) {
    for (int i = 0; i < 5; i++) {
        if (spellTrapField.at(i) == trapCard) {
            graveyard.push_back(new TrapCard(*trapCard));
            return;
        }
    }
}

MonsterCard *PlayingField::removeMonsterCardFromGraveyard(MonsterCard *card) {
    if (card == nullptr) return nullptr; // terminate method if card is null

    for (auto it = graveyard.begin(); it != graveyard.end(); it++) {
        MonsterCard *currentCard = dynamic_cast<MonsterCard *>(*it);

        if (currentCard && currentCard->getName() == card->getName()) {
            it = graveyard.erase(it);
            return currentCard;
        }
    }
    return nullptr; // return nullptr if card is not found in the graveyard.
}

std::vector<MonsterCard *> PlayingField::getMonsterField() {
    return monsterField;
}

std::vector<Card *> PlayingField::getSpellTrapField() {
    return spellTrapField;
}

std::vector<Card *> PlayingField::getGraveyard() {
    return graveyard;
}

std::vector<MonsterCard *> PlayingField::getMonsterCardsInGraveyard() {
    std::vector<MonsterCard *> monsterCardsInGY;
    for (Card *card: graveyard) {
        if (auto *monsterCard = dynamic_cast<MonsterCard *>(card)) {
            monsterCardsInGY.push_back(monsterCard);
        }
    }
    return monsterCardsInGY;
}

void PlayingField::addCardToGraveyard(Card *card) {
    if (card == nullptr) return;

    else if (auto *monsterCard = dynamic_cast<MonsterCard *>(card)) {
        addCardToGraveyard(monsterCard);
    } else if (auto *spellCard = dynamic_cast<SpellCard *>(card)) {
        addCardToGraveyard(spellCard);
    } else if (auto *trapCard = dynamic_cast<TrapCard *>(card)) {
        addCardToGraveyard(trapCard);
    }
}

bool PlayingField::isThereMonsterInField() {
    for (MonsterCard *monsterCard: monsterField) {
        if (monsterCard != nullptr) {
            return true;
        }
    }
    return false;
}

bool PlayingField::isThereAttackingMonsterInField() {
    for (MonsterCard *monsterCard: monsterField) {
        if (monsterCard != nullptr && monsterCard->isAttackMode()) {
            return true;
        }
    }
    return false;
}

bool PlayingField::isThereTrapCardInField() {
    for (Card *card: getSpellTrapField()) {
        if (card) {
            if (auto *trapCard = dynamic_cast<TrapCard *> (card)) {
                return true;
            }
        }
    }
    return false;
}

void PlayingField::removeCardFromSpellTrapField(SpellCard *spellCard) {
    for (int i = 0; i < spellTrapField.size(); i++) {
        Card *currentCard = spellTrapField.at(i);
        if (currentCard == spellCard) {
            auto *copy = new SpellCard(*spellCard);
            spellTrapField.at(i) = nullptr;
            graveyard.push_back(copy);
        }
    }
}

void PlayingField::removeCardFromSpellTrapField(TrapCard *trapCard) {
    for (int i = 0; i < spellTrapField.size(); i++) {
        Card *currentCard = spellTrapField.at(i);
        if (currentCard == trapCard) {
            auto *copy = new TrapCard(*trapCard);
            spellTrapField.at(i) = nullptr;
            graveyard.push_back(copy);
        }
    }
}

void PlayingField::removeCardFromSpellTrapField(Card *card) {
    if (card == nullptr) {
        return;
    }
    if (auto *spellCard = dynamic_cast<SpellCard *> (card)) {
        removeCardFromSpellTrapField(spellCard);
    } else if (auto *trapCard = dynamic_cast<TrapCard * >(card)) {
        removeCardFromSpellTrapField(trapCard);
    }
}

// This method finds strongest MonsterCard in field in terms of Active Points.
// Returns nullptr if there is no MonsterCard in field.
MonsterCard *PlayingField::getStrongestMonsterInField() {
    // return nullptr if there is no MonsterCard in Field.
    if (!isThereMonsterInField()) {
        return nullptr;
    }

    // Find Strongest MonsterCard in terms of Active Points.
    MonsterCard *strongest = nullptr;
    for (MonsterCard *monsterCard: monsterField) {
        if (monsterCard != nullptr) {
            strongest = monsterCard;
            break;
        }
    }

    for (MonsterCard *monsterCard: monsterField) {
        if (monsterCard != nullptr) {
            if (strongest->getActivePoints() < monsterCard->getActivePoints()) {
                strongest = monsterCard;
            }
        }
    }

    return strongest;
}

// This method finds strongest MonsterCard in GY in terms of Active Points.
// Returns nullptr if there is no MonsterCard in GY.
MonsterCard *PlayingField::getStrongestMonsterInGY() {
    std::vector<MonsterCard *> monsterCardsInGY = getMonsterCardsInGraveyard();

    if (monsterCardsInGY.empty()) {
        return nullptr;
    }
    MonsterCard *strongest = monsterCardsInGY.at(0);
    for (MonsterCard *monsterCard: monsterCardsInGY) {
        if (strongest->getActivePoints() < monsterCard->getActivePoints()) {
            strongest = monsterCard;
        }
    }
    return strongest;
}

MonsterCard *PlayingField::getWeakestMonsterInField() {
    // return nullptr if there is no MonsterCard in Field.
    if (!isThereMonsterInField()) {
        return nullptr;
    }

    // Find Strongest MonsterCard in terms of Active Points.
    MonsterCard *weakest = nullptr;
    for (MonsterCard *monsterCard: monsterField) {
        if (monsterCard != nullptr) {
            weakest = monsterCard;
            break;
        }
    }

    for (MonsterCard *monsterCard: monsterField) {
        if (monsterCard != nullptr) {
            if (weakest->getActivePoints() > monsterCard->getActivePoints()) {
                weakest = monsterCard;
            }
        }
    }

    return weakest;
}

MonsterCard *PlayingField::getWeakestMonsterInGY() {
    std::vector<MonsterCard *> monsterCardsInGY = getMonsterCardsInGraveyard();
    if (monsterCardsInGY.empty()) {
        return nullptr;
    }
    MonsterCard *weakest = monsterCardsInGY.at(0);
    for (MonsterCard *monsterCard: monsterCardsInGY) {
        if (weakest->getActivePoints() > monsterCard->getActivePoints()) {
            weakest = monsterCard;
        }
    }
    return weakest;
}

int PlayingField::getCountOfActiveMonsters() {
    int count = 0;
    for (MonsterCard *monsterCard: monsterField) {
        if (monsterCard) {
            count++;
        }
    }
    return count;
}









