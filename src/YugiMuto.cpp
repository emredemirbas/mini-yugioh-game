#include "YugiMuto.h"

Deck *YugiMuto::initializeDeck() {

    Deck *deck = new Deck();

    // Monster Cards
    deck->addCard(
            new MonsterCard("Exodia the Forbidden One",
                            "If you have \"Right Leg of the Forbidden One\", \"Left Leg of the Forbidden One\", \"Right Arm of the Forbidden One\" and \"Left Arm of the Forbidden One\" in addition to this card in your hand, you win the Duel.",
                            1000, 1000, 3, SPELLCASTER, 1));

    deck->addCard(
            new MonsterCard("Left Arm of the Forbidden One",
                            "A forbidden left arm sealed by magic. Whosoever breaks this seal will know infinite power.",
                            200, 300, 1, SPELLCASTER, 2));

    deck->addCard(
            new MonsterCard("Left Leg of the Forbidden One",
                            "A forbidden left leg sealed by magic. Whosoever breaks this seal will know infinite power.",
                            200, 300, 1, SPELLCASTER, 3));

    deck->addCard(
            new MonsterCard("Right Arm of the Forbidden One",
                            "A forbidden right arm sealed by magic. Whosoever breaks this seal will know infinite power.",
                            200, 300, 1, SPELLCASTER, 4));

    deck->addCard(
            new MonsterCard("Right Leg of the Forbidden One",
                            "A forbidden right leg sealed by magic. Whosoever breaks this seal will know infinite power.",
                            200, 300, 1, SPELLCASTER, 5));

    deck->addCard(new MonsterCard("Dark Magician", "The ultimate wizard in terms of attack and defense.", 2500, 2100, 7,
                                  SPELLCASTER, 6));


    deck->addCard(new MonsterCard("Summoned Skull",
                                  "A fiend with dark powers for confusing the enemy. Among the Fiend-Type monsters, this monster boasts considerable force.",
                                  2500, 1200, 6, FIEND, 7));

    deck->addCard(new MonsterCard("Gaia The Fierce Knight",
                                  "A knight whose horse travels faster than the wind. His battle-charge is a force to be reckoned with.",
                                  2300, 2100, 7, WARRIOR, 8));

    deck->addCard(new MonsterCard("Curse of Dragon",
                                  "A wicked dragon that taps into dark forces to execute a powerful attack.",
                                  2000, 1500, 5, DRAGON, 9));

    deck->addCard(new MonsterCard("Celtic Guardian",
                                  "An elf who learned to wield a sword, he baffles enemies with lightning-swift attacks.",
                                  1400, 1200, 4, WARRIOR, 10));

    deck->addCard(new MonsterCard("Koumori Dragon",
                                  "A vicious, fire-breathing dragon whose wicked flame corrupts the souls of its victims.",
                                  1500, 1200, 4, DRAGON, 11));

    deck->addCard(new MonsterCard("Winged Dragon",
                                  "A dragon commonly found guarding mountain fortresses. Its signature attack is a sweeping dive from out of the blue.",
                                  1400, 1200, 4, DRAGON, 12));

    deck->addCard(new MonsterCard("Feral Imp",
                                  "A playful little fiend that lurks in the dark, waiting to attack an unwary enemy.",
                                  1300, 1400, 4, FIEND, 13));

    deck->addCard(new MonsterCard("Beaver Warrior",
                                  "What this creature lacks in size it makes up for in defense when battling in the prairie.",
                                  1200, 1500, 4, BEAST_WARRIOR, 14));

    deck->addCard(
            new MonsterCard("Griffore", "This monster's tough hide deflects almost any attack.", 1200, 1500, 4, BEAST,
                            15));

    deck->addCard(new MonsterCard("Mystical Elf",
                                  "A delicate elf that lacks offense, but has a terrific defense backed by mystical power.",
                                  800, 2000, 4, SPELLCASTER, 16));

    deck->addCard(new MonsterCard("Giant Soldier of Stone",
                                  "A giant warrior made of stone. A punch from this creature has earth-shaking results.",
                                  1300, 2000, 3, ROCK, 17));

    deck->addCard(new MonsterCard("Mammoth Graveyard",
                                  "A mammoth that protects the graves of its pack and is absolutely merciless when facing grave-robbers.",
                                  1200, 800, 3, DINOSAUR, 18));

    deck->addCard(
            new MonsterCard("Silver Fang", "A snow wolf that's beautiful to the eye, but absolutely vicious in battle.",
                            1200, 800, 3, BEAST, 19));





    // Spell Cards
    deck->addCard(new SpellCard("Pot Of Greed", "Draw 2 cards.",
                                [](Player *owner, Player *enemy) {
                                    owner->addCardToHandFromDeck();
                                    owner->addCardToHandFromDeck();
                                }, 20));


    deck->addCard(new SpellCard("Shield & Sword",
                                "Switch the original ATK and DEF of all face-up monsters currently on the field.",
                                [](Player *owner, Player *enemy) {
                                    for (MonsterCard *monsterCard: owner->getPlayingField()->getMonsterField()) {
                                        if (monsterCard != nullptr) {
                                            int initialAttackPoints = monsterCard->getAttackPoints();
                                            int initialDefensePoints = monsterCard->getDefensePoints();
                                            int newActivePoints = (monsterCard->isAttackMode()) ? initialDefensePoints
                                                                                                : initialAttackPoints;
                                            monsterCard->setAttackPoints(initialDefensePoints);
                                            monsterCard->setDefensePoints(initialAttackPoints);
                                            monsterCard->setActivePoints(newActivePoints);
                                        }
                                    }

                                    for (MonsterCard *monsterCard: enemy->getPlayingField()->getMonsterField()) {
                                        if (monsterCard != nullptr) {
                                            int initialAttackPoints = monsterCard->getAttackPoints();
                                            int initialDefensePoints = monsterCard->getDefensePoints();
                                            int newActivePoints = (monsterCard->isAttackMode()) ? initialDefensePoints
                                                                                                : initialAttackPoints;
                                            monsterCard->setAttackPoints(initialDefensePoints);
                                            monsterCard->setDefensePoints(initialAttackPoints);
                                            monsterCard->setActivePoints(newActivePoints);
                                        }
                                    }
                                }, 21));

    deck->addCard(new SpellCard("Monster Reborn", "Target 1 monster in either Graveyard; Special Summon it.",
                                [](Player *owner, Player *enemy) {
                                    // A vector of MonsterCards in both players' graveyard.
                                    std::vector<MonsterCard *> availableMonsters;

                                    // Add monsters from the owner's graveyard.
                                    for (Card *card: owner->getPlayingField()->getGraveyard()) {
                                        if (card) {
                                            if (auto *monsterCard = dynamic_cast<MonsterCard *>(card)) {
                                                availableMonsters.push_back(monsterCard);
                                            }
                                        }
                                    }

                                    // Add monsters from the enemy's graveyard.
                                    for (Card *card: enemy->getPlayingField()->getGraveyard()) {
                                        if (card) {
                                            if (auto *monsterCard = dynamic_cast<MonsterCard *>(card)) {
                                                availableMonsters.push_back(monsterCard);
                                            }
                                        }

                                    }

                                    // Terminate this method if there are no available MonsterCards in either graveyard.
                                    if (availableMonsters.empty()) {
                                        return;
                                    }

                                    // Find Strongest Monster in terms of Active Points.
                                    MonsterCard *strongestMonsterInGY = nullptr;

                                    for (MonsterCard *monsterCard: availableMonsters) {
                                        if (strongestMonsterInGY == nullptr || strongestMonsterInGY->getActivePoints() <
                                                                               monsterCard->getActivePoints()) {
                                            strongestMonsterInGY = monsterCard;
                                        }
                                    }


                                    // Summon the selected monster to the owner's side of the field.
                                    owner->getPlayingField()->addCardToPlayingField(strongestMonsterInGY);

                                    // Remove the selected monster from either graveyard.
                                    owner->getPlayingField()->removeMonsterCardFromGraveyard(strongestMonsterInGY);
                                    enemy->getPlayingField()->removeMonsterCardFromGraveyard(strongestMonsterInGY);
                                }, 22));

    deck->addCard(new SpellCard("Book of Secret Arts",
                                "A SpellCaster-Type monster equipped with this card increases its ATK and DEF by 300 points.",
                                [](Player *owner, Player *enemy) {
                                    if (!owner->getPlayingField()->isThereMonsterInField()) {
                                        return;
                                    }
                                    // Find a SpellCaster MonsterCard in field.
                                    MonsterCard *spellCasterMonster = nullptr;
                                    for (MonsterCard *monsterCard: owner->getPlayingField()->getMonsterField()) {
                                        if (monsterCard && monsterCard->getType() == MonsterType::SPELLCASTER) {
                                            spellCasterMonster = monsterCard;
                                            break;
                                        }
                                    }
                                    // If there is a SpellCaster Monster in field, increase ATK, DEF and ACT points by 300.
                                    if (spellCasterMonster) {
                                        spellCasterMonster->setAttackPoints(
                                                spellCasterMonster->getAttackPoints() + 300);
                                        spellCasterMonster->setDefensePoints(
                                                spellCasterMonster->getDefensePoints() + 300);
                                        spellCasterMonster->setActivePoints(
                                                spellCasterMonster->getActivePoints() + 300);
                                    }
                                }, 23));

    deck->addCard(new SpellCard("Dark Hole", "Destroy all monsters on the field.",
                                [](Player *owner, Player *enemy) {
                                    for (MonsterCard *monsterCard: owner->getPlayingField()->getMonsterField()) {
                                        owner->getPlayingField()->removeCardFromMonsterField(monsterCard);
                                    }
                                    for (MonsterCard *monsterCard: enemy->getPlayingField()->getMonsterField()) {
                                        enemy->getPlayingField()->removeCardFromMonsterField(monsterCard);
                                    }
                                }, 24));

    deck->addCard(new SpellCard("Raigeki", "Destroy all monsters your opponent controls.",
                                [](Player *owner, Player *enemy) {
                                    for (MonsterCard *monsterCard: enemy->getPlayingField()->getMonsterField()) {
                                        enemy->getPlayingField()->removeCardFromMonsterField(monsterCard);
                                    }
                                }, 63));

    deck->addCard(new SpellCard("Monster Reincarnation",
                                "Discard 1 card, then target 1 monster in your GY; add it to your hand.",
                                [](Player *owner, Player *enemy) {
                                    // vector of MonsterCards in Owner's GY.
                                    std::vector<MonsterCard *> monsterCardsInGY = owner->getPlayingField()->getMonsterCardsInGraveyard();

                                    // Terminate method if there is no MonsterCard in Owner's GY.
                                    if (monsterCardsInGY.empty()) {
                                        return;
                                    }

                                    // vector of MonsterCards of Owner's Hand
                                    std::vector<MonsterCard *> monsterCardsInHand;

                                    // Iterate through Owner's Hand
                                    for (Card *card: *owner->getHand()) {
                                        // If card is a MonsterCard, push it back to the vector
                                        if (auto *monsterCard = dynamic_cast<MonsterCard *>(card)) {
                                            monsterCardsInHand.push_back(monsterCard);
                                        }
                                    }

                                    // If it is guaranteed that Owner has MonsterCard in his hand,
                                    // find Weakest MonsterCard in terms of ATK or DEF point.
                                    // Then, discard WeakestCard from Owner's hand.
                                    if (!monsterCardsInHand.empty()) {
                                        MonsterCard *weakestMonsterCardInHand = monsterCardsInHand.at(0);
                                        for (MonsterCard *monsterCard: monsterCardsInHand) {
                                            int minPoint1 = std::min(weakestMonsterCardInHand->getAttackPoints(),
                                                                     weakestMonsterCardInHand->getDefensePoints());

                                            int minPoint2 = std::min(monsterCard->getAttackPoints(),
                                                                     monsterCard->getDefensePoints());

                                            if (minPoint1 > minPoint2) {
                                                weakestMonsterCardInHand = monsterCard;
                                            }
                                        }
                                        owner->discard(weakestMonsterCardInHand);
                                    }

                                        // If there is no MonsterCard in Owner's hand, discard the Card at 0th index.
                                    else {
                                        owner->discard(owner->getHand()->at(0));
                                    }

                                    // Find Strongest Monster in GY
                                    MonsterCard *strongestMonsterInGY = owner->getPlayingField()->getStrongestMonsterInGY();
                                    // Add Strongest Monster in GY to Owner's Hand.
                                    owner->addCardToHand(strongestMonsterInGY);
                                    // Remove Strongest Monster from GY
                                }, 25));


    // Trap Cards
    deck->addCard(new TrapCard("Straight Flush",
                               "Activate only when all of your opponent's Spell & Trap Card Zones are occupied. Destroy all cards in your opponent's Spell & Trap Card Zones.",
                               true,
                               [](Player *owner, Player *enemy) {
                                   int numOfFullCellInSpellTrapField = 0;
                                   for (int i = 0; i < enemy->getPlayingField()->getSpellTrapField().size(); ++i) {
                                       if (enemy->getPlayingField()->getSpellTrapField().at(i) != nullptr) {
                                           numOfFullCellInSpellTrapField++;
                                       }
                                   }

                                   if (numOfFullCellInSpellTrapField ==
                                       enemy->getPlayingField()->getSpellTrapField().size()) {
                                       for (int i = 0; i < enemy->getPlayingField()->getSpellTrapField().size(); ++i) {
                                           enemy->getPlayingField()->removeCardFromSpellTrapField(
                                                   enemy->getPlayingField()->getSpellTrapField().at(i));
                                       }
                                   }
                               }, 26));


    deck->addCard(new TrapCard("Mirror Force",
                               "When an opponent's monster declares an attack: Destroy all your opponent's Attack Position monsters.",
                               true,
                               [](Player *owner, Player *enemy) {
                                   for (MonsterCard *monsterCard: enemy->getPlayingField()->getMonsterField()) {
                                       if (monsterCard != nullptr && monsterCard->isAttackMode()) {
                                           enemy->getPlayingField()->removeCardFromMonsterField(monsterCard);
                                       }
                                   }
                               }, 27));

    deck->addCard(new TrapCard("Fairy Wind",
                               "Destroy as many face-up Spell/Trap Cards on the field as possible (other than this card), and if you do, each player takes damage equal to the total number of cards destroyed by this effect x 300.",
                               true,
                               [](Player *owner, Player *enemy) {
                                   for (int i = 0; i < owner->getPlayingField()->getSpellTrapField().size(); ++i) {
                                       if (owner->getPlayingField()->getSpellTrapField().at(i) != nullptr) {
                                           owner->getPlayingField()->removeCardFromSpellTrapField(
                                                   owner->getPlayingField()->getSpellTrapField().at(i));
                                           owner->decreaseLifePoints(300);
                                       }
                                   }

                                   for (int i = 0; i < enemy->getPlayingField()->getSpellTrapField().size(); ++i) {
                                       if (enemy->getPlayingField()->getSpellTrapField().at(i) != nullptr) {
                                           enemy->getPlayingField()->removeCardFromSpellTrapField(
                                                   enemy->getPlayingField()->getSpellTrapField().at(i));
                                           enemy->decreaseLifePoints(300);
                                       }
                                   }
                               }, 28));

    deck->shuffle();

    return deck;
}

YugiMuto::YugiMuto() : Player("Yugi Muto", initializeDeck()) {}

bool YugiMuto::hasAllPiecesOfExodia() {
    int countPieces = 0;

    for (Card *card: *getHand()) {
        if (card->getName() == "Right Arm of the Forbidden One" ||
            card->getName() == "Left Arm of the Forbidden One" ||
            card->getName() == "Right Leg of the Forbidden One" ||
            card->getName() == "Left Leg of the Forbidden One" ||
            card->getName() == "Exodia the Forbidden One") {
            countPieces++;
        }
    }
    return countPieces == 5;
}

YugiMuto::~YugiMuto() = default;
