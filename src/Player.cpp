#include "Player.h"

Player::Player(std::string name, Deck *deck) {
    this->name = name;
    this->deck = deck;
    this->lifePoints = 8000;
    this->hand = new std::vector<Card *>();
    this->playingField = new PlayingField();
}

Player::~Player() {
    delete deck;
    delete playingField;
    for (Card *card: *hand) {
        delete card;
    }
}

void Player::setLifePoints(int lifePoints) {
    this->lifePoints = lifePoints;
}

void Player::decreaseLifePoints(int amount) {
    if (lifePoints - amount >= 0) {
        lifePoints -= amount;
    } else {
        lifePoints = 0;
    }
}

void Player::increaseLifePoints(int amount) {
    lifePoints += amount;
}


void Player::addCardToHand(Card *card) {
    if (hand->size() < 6 && card) {
        this->hand->push_back(card);
    }
}

void Player::addCardToHandFromDeck() {
    if (hand->size() < 6) {
        addCardToHand(getDeck()->drawCard());
    }
}

void Player::removeCardFromHand(Card *card) {
    auto it = std::find(hand->begin(), hand->end(), card);
    if (it != hand->end()) {
        hand->erase(it);
    }
}

Deck *Player::getDeck() const {
    return deck;
}

std::vector<Card *> *Player::getHand() const {
    return hand;
}

PlayingField *Player::getPlayingField() const {
    return playingField;
}

std::string Player::getName() const {
    return name;
}

int Player::getLifePoints() const {
    return lifePoints;
}

void Player::discard(Card *card) {
    if (card == nullptr) return; // terminate method if card is null
    for (Card *currentCard: *hand) {
        // if currentCard is the Card that we are looking for,
        // remove this card from hand add it to the graveyard.
        if (currentCard == card) {
            removeCardFromHand(card);
            getPlayingField()->addCardToGraveyard(card);
            return;
        }
    }
}

void Player::tribute(MonsterCard *monsterCard) {
    if (monsterCard == nullptr) return; // terminate method if card is null
    for (MonsterCard *currentCard: playingField->getMonsterField()) {
        // if currentCard is the MonsterCard that we are looking for,
        // remove this card from field.
        if (currentCard == monsterCard) {
            playingField->removeCardFromMonsterField(currentCard);
            return;
        }
    }
}












