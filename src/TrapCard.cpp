#include "TrapCard.h"


TrapCard::TrapCard(std::string name, std::string description, bool blocksAttack,
                   std::function<void(Player *, Player *)> effect, int id) : Card(name, description, id) {
    setIsFaceUp(false);
    m_blocksAttack = blocksAttack;
    this->effect = effect;
}

TrapCard::~TrapCard() = default;


bool TrapCard::blocksAttack() {
    return m_blocksAttack;
}

void TrapCard::activateEffect(Player *owner, Player *enemy) {
    effect(owner, enemy);
}

std::string TrapCard::getCardDetails() const {
    return getDescription();
}





