#include "Deck.h"
#include <ctime>
#include <iostream>


Deck::Deck() {

}

Deck::~Deck() {
    // Iterate through the vector and delete each Card pointer
    for (Card *card: cards) {
        delete card;
    }

    // Clear the vector to release the memory occupied by the pointers
    cards.clear();
}

Card *Deck::drawCard() {
    if (!cards.empty()) {
        Card *drawnCard = cards.back(); // Get the top card (peek)
        cards.pop_back();               // Remove the drawn card from the deck
        return drawnCard;
    }
        // return nullptr, if the deck is empty
    else return nullptr;
}

void Deck::shuffle() {
    srand(time(0));

    for (int i = 0; i < cards.size(); i++) {
        // generate a random index between 0 and size of deck - 1
        int randomIndex = rand() % cards.size();

        // swap the (i)th and (randomIndex)th card
        Card *temp = cards.at(i);
        cards.at(i) = cards.at(randomIndex);
        cards.at(randomIndex) = temp;
    }
}

std::vector<Card *> &Deck::getCards() {
    return cards;
}

void Deck::addCard(Card *card) {
    cards.push_back(card);
}


