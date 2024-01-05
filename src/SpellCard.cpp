#include "SpellCard.h"
#include "Player.h"

SpellCard::SpellCard(std::string name, std::string description,
                     std::function<void(Player *owner, Player *enemy)> effect, int id) : Card(name, description, id) {
    setIsFaceUp(true);
    this->effect = effect;
}

SpellCard::~SpellCard() = default;

void SpellCard::activateEffect(Player *owner, Player *enemy) {
    effect(owner, enemy);
}

std::string SpellCard::getCardDetails() const {
    return getDescription();
}





