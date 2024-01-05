#include "MonsterCard.h"

MonsterCard::MonsterCard(std::string name, std::string description, int attackPoints, int defensePoints,
                         int level, MonsterType type, int id)
        : Card(name, description, id) {
    this->attackPoints = attackPoints;
    this->defensePoints = defensePoints;
    this->level = level;
    this->type = type;

    // determine the best possible activePoint and mode of the MonsterCard
    this->activePoints = std::max(attackPoints, defensePoints);
    if (activePoints == defensePoints) {
        mode = false; // DEF mode
        setIsFaceUp(false); // if MonsterCard is in DEF mode -> must be face down initially.
    } else {
        mode = true; // ATK mode
        setIsFaceUp(true); // if MonsterCard is in ATK mode -> must be face up initially.
    }
}

MonsterCard::~MonsterCard() = default;

int MonsterCard::getAttackPoints() const {
    return attackPoints;
}

int MonsterCard::getDefensePoints() const {
    return defensePoints;
}

int MonsterCard::getLevel() const {
    return level;
}

int MonsterCard::getActivePoints() const {
    return activePoints;
}


MonsterType MonsterCard::getType() const {
    return type;
}

bool MonsterCard::isAttackMode() const {
    return mode;
}

std::string MonsterCard::getCardDetails() const {
    std::string details;
    details += getDescription() + "\n\n";
    details += "ATK/" + std::to_string(attackPoints) + " DEF/" + std::to_string(defensePoints);
    return details;
}

void MonsterCard::setMode(bool expr) {
    mode = expr;
}

void MonsterCard::changeMode() {
    if (!this->isAttackMode() && !this->isFacedUp()) {
        this->flip();
    }
    mode = !mode;
    if (activePoints == attackPoints) {
        activePoints = defensePoints;
    } else {
        activePoints = attackPoints;
    }
}

void MonsterCard::setAttackPoints(int attackPoints) {
    this->attackPoints = attackPoints;
}

void MonsterCard::setDefensePoints(int defensePoints) {
    this->defensePoints = defensePoints;
}

void MonsterCard::setActivePoints(int activePoints) {
    this->activePoints = activePoints;
}
