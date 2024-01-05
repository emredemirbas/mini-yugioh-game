#include "SetoKaiba.h"

Deck *SetoKaiba::initializeDeck() {
    Deck *deck = new Deck();

    deck->addCard(new MonsterCard("Blue-Eyes White Dragon",
                                  "This legendary dragon is a powerful engine of destruction. Virtually invincible, very few have faced this awesome creature and lived to tell the tale.",
                                  3000, 2500, 8, DRAGON, 29));

    deck->addCard(new MonsterCard("Blue-Eyes White Dragon",
                                  "This legendary dragon is a powerful engine of destruction. Virtually invincible, very few have faced this awesome creature and lived to tell the tale.",
                                  3000, 2500, 8, DRAGON, 30));

    deck->addCard(new MonsterCard("Blue-Eyes White Dragon",
                                  "This legendary dragon is a powerful engine of destruction. Virtually invincible, very few have faced this awesome creature and lived to tell the tale.",
                                  3000, 2500, 8, DRAGON, 31));

    deck->addCard(new MonsterCard("Luster Dragon ",
                                  "This dragon feeds on emerald. Enchanted by this monster even when attacked, few people live to tell of its beauty. ",
                                  2400, 1400, 4, DRAGON, 32));

    deck->addCard(new MonsterCard("Ryu-Kishin Powered",
                                  "A gargoyle enhanced by the powers of darkness. Very sharp talons make it a worthy opponent. ",
                                  1600, 1200, 4, FIEND, 33));

    deck->addCard(new MonsterCard("X-Head Cannon ",
                                  "A monster with a mighty cannon barrel, it is able to integrate its attacks. It attacks in many ways by combining and separating with other monsters. ",
                                  1800, 1500, 4, MACHINE, 34));

    deck->addCard(new MonsterCard("Vorse Raider ",
                                  "This wicked Beast-Warrior does every horrid thing imaginable,and loves it! His axe bears the marks of his countless victims. ",
                                  1900, 1200, 4, BEAST_WARRIOR, 35));

    deck->addCard(new MonsterCard("Battle Ox",
                                  "A monster with tremendous power, it destroys enemies with a swing of its axe.", 1700,
                                  1000, 4, BEAST_WARRIOR, 36));

    deck->addCard(
            new MonsterCard("Judge Man", "This club-wielding warrior battles to the end and will never surrender.",
                            2200, 1500, 6, WARRIOR, 37));

    deck->addCard(new MonsterCard("Swordstalker",
                                  "A monster formed by the vengeful souls of those who passed away in battle.", 2000,
                                  1600, 6, WARRIOR, 38));

    deck->addCard(new MonsterCard("Gyakutenno Megami",
                                  "This fairy uses her mystical power to protect the weak and provide spiritual support.",
                                  1800, 2000, 6, FAIRY, 39));

    deck->addCard(
            new MonsterCard("Rude Kaiser", "With an axe in each hand, this monster delivers heavy damage.", 1800, 1600,
                            5, BEAST_WARRIOR, 40));

    deck->addCard(new MonsterCard("La Jinn the Mystical Genie of the Lamp",
                                  "A genie of the lamp that is at the beck and call of its master.", 1800, 1000, 4,
                                  FIEND, 41));

    deck->addCard(new MonsterCard("Rogue Doll",
                                  "A deadly doll gifted with mystical power, it is particularly powerful when attacking against dark forces.",
                                  1600, 1000, 4, SPELLCASTER, 42));

    deck->addCard(new MonsterCard("Skull Red Bird",
                                  "This monster swoops down and attacks with a rain of knives stored in its wings.",
                                  1550, 1200, 4, WINGED_BEAST, 43));

    deck->addCard(new MonsterCard("Kojikocy", "A man-hunter with powerful arms that can crush boulders.", 1500, 1200, 4,
                                  WARRIOR, 44));

    deck->addCard(new MonsterCard("Koumori Dragon",
                                  "A vicious, fire-breathing dragon whose wicked flame corrupts the souls of its victims.",
                                  1500, 1200, 4, DRAGON, 45));

    deck->addCard(new MonsterCard("Pale Beast",
                                  "With skin tinged a bluish-white, this strange creature is a fearsome sight to behold.",
                                  1500, 1200, 4, BEAST, 46));

    deck->addCard(
            new MonsterCard("Destroyer Golem", "A golem with a massive right hand for crushing its victims.", 1500,
                            1000, 4, ROCK, 47));

    deck->addCard(
            new MonsterCard("Mystic Clown", "Nothing can stop the mad attack of this powerful creature.", 1500, 1000, 4,
                            FIEND, 48));


    // Spell Cards
    deck->addCard(new SpellCard("Sword of Deep-Seated",
                                "The equipped monster gains 500 ATK/DEF.",
                                [](Player *owner, Player *enemy) {
                                    MonsterCard *strongest = owner->getPlayingField()->getStrongestMonsterInField();

                                    // if there is no MonsterCard in owner's field, terminate method.
                                    if (strongest == nullptr) {
                                        return;
                                    }
                                    strongest->setAttackPoints(strongest->getAttackPoints() + 500);
                                    strongest->setDefensePoints(strongest->getDefensePoints() + 500);
                                    strongest->setActivePoints(strongest->getActivePoints() + 500);
                                }, 49));

    deck->addCard(new SpellCard("Warrior Elimination",
                                "Destroy all Warrior monsters on the field.",
                                [](Player *owner, Player *enemy) {
                                    for (MonsterCard *monsterCard: owner->getPlayingField()->getMonsterField()) {
                                        if (monsterCard && monsterCard->getType() == MonsterType::WARRIOR) {
                                            owner->getPlayingField()->removeCardFromMonsterField(monsterCard);
                                        }
                                    }

                                    for (MonsterCard *monsterCard: enemy->getPlayingField()->getMonsterField()) {
                                        if (monsterCard && monsterCard->getType() == MonsterType::WARRIOR) {
                                            enemy->getPlayingField()->removeCardFromMonsterField(monsterCard);
                                        }
                                    }
                                }, 50));

    deck->addCard(new SpellCard("Earthquake",
                                "Change all face-up monsters on the field to Defense Position.",
                                [](Player *owner, Player *enemy) {
                                    for (MonsterCard *monsterCard: owner->getPlayingField()->getMonsterField()) {
                                        if (monsterCard && monsterCard->isFacedUp()) {
                                            monsterCard->setMode(false);
                                            monsterCard->setActivePoints(monsterCard->getDefensePoints());
                                        }
                                    }

                                    for (MonsterCard *monsterCard: enemy->getPlayingField()->getMonsterField()) {
                                        if (monsterCard && monsterCard->isFacedUp()) {
                                            monsterCard->setMode(false);
                                            monsterCard->setActivePoints(monsterCard->getDefensePoints());
                                        }
                                    }
                                }, 51));

    deck->addCard(new SpellCard("Flash of the Forbidden Spell",
                                "Activate only when all of your opponent's Monster Card Zones are occupied by monsters. Destroy all monsters on your opponent's side of the field.",
                                [](Player *owner, Player *enemy) {
                                    bool allZonesOccupied = true; // assumption
                                    for (MonsterCard *monsterCard: enemy->getPlayingField()->getMonsterField()) {
                                        if (monsterCard == nullptr) {
                                            allZonesOccupied = false;
                                            break;
                                        }
                                    }

                                    if (!allZonesOccupied) {
                                        return;
                                    }

                                    for (MonsterCard *monsterCard: enemy->getPlayingField()->getMonsterField()) {
                                        enemy->getPlayingField()->removeCardFromMonsterField(monsterCard);
                                    }
                                }, 52));

    // UPDATED (31.12.23)
    deck->addCard(new SpellCard("Dark Factory of Mass Production",
                                "Target 2 Monsters in your Graveyard; add them to your hand.",
                                [](Player *owner, Player *enemy) {
                                    std::vector<MonsterCard *> monsterCardsInGraveyard = owner->getPlayingField()->getMonsterCardsInGraveyard();

                                    if (monsterCardsInGraveyard.empty()) {
                                        return;
                                    }

                                    for (int i = 0; i < 2; i++) {
                                        MonsterCard *strongest = owner->getPlayingField()->getStrongestMonsterInGY();
                                        if (strongest) {
                                            owner->addCardToHand(new MonsterCard(*strongest));
                                            owner->getPlayingField()->removeMonsterCardFromGraveyard(strongest);
                                        }
                                    }
                                }, 54));

    deck->addCard(new SpellCard("Monster Reborn", "Target 1 monster in either Graveyard; Special Summon it.",
                                [](Player *owner, Player *enemy) {
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
                                }, 55));

    deck->addCard(new SpellCard("Ookazi", "Inflict 800 damage to your opponent.", [](Player *owner, Player *enemy) {
        enemy->decreaseLifePoints(800);
    }, 56));

    deck->addCard(new SpellCard("Fissure",
                                "Destroy the 1 face-up monster your opponent controls that has the lowest ATK (your choice, if tied).",
                                [](Player *owner, Player *enemy) {
                                    bool isThereFaceUpMonsterInEnemyField = false;
                                    for (MonsterCard *monsterCard: enemy->getPlayingField()->getMonsterField()) {
                                        if (monsterCard != nullptr && monsterCard->isFacedUp()) {
                                            isThereFaceUpMonsterInEnemyField = true;
                                            break;
                                        }
                                    }
                                    // If there is no Face Up MonsterCard in Enemy Field, terminate the method.
                                    if (!isThereFaceUpMonsterInEnemyField) {
                                        return;
                                    }
                                    // Remove Monster that has lowest Attack Points.
                                    MonsterCard *monsterWithLowestAtk = enemy->getPlayingField()->getWeakestMonsterInField();
                                    enemy->getPlayingField()->removeCardFromMonsterField(monsterWithLowestAtk);
                                }, 57));

    deck->addCard(new SpellCard("Hammer Shot",
                                "Destroy 1 face-up Attack Position monster with the highest ATK. (If it is a tie, you get to choose.)",
                                [](Player *owner, Player *enemy) {
                                    // terminate the method if there is no Attacking MonsterCard in PlayingField of enemy
                                    if (!enemy->getPlayingField()->isThereAttackingMonsterInField()) {
                                        return;
                                    }
                                    // destroy monsterWithHighestAtk
                                    MonsterCard *monsterWithHighestAtk = enemy->getPlayingField()->getStrongestMonsterInField();
                                    enemy->getPlayingField()->removeCardFromMonsterField(monsterWithHighestAtk);
                                }, 58));


    deck->addCard(
            new TrapCard("Just Desserts", "Inflict 500 damage to your opponent for each monster they control.",
                         true,
                         [](Player *owner, Player *enemy) {
                             int count = 0;
                             for (int i = 0; i < enemy->getPlayingField()->getMonsterField().size(); ++i) {
                                 if (enemy->getPlayingField()->getMonsterField().at(i) != nullptr) {
                                     count++;
                                 }
                             }
                             enemy->decreaseLifePoints(count * 500);
                         }, 59));

    deck->addCard(new TrapCard("Two-Pronged Attack",
                               "Select and destroy 2 of your monsters and 1 of your opponent's monsters.",
                               true,
                               [](Player *owner, Player *enemy) {
                                   std::vector<MonsterCard *> monstersOfOwner;
                                   for (MonsterCard *monsterCard: owner->getPlayingField()->getMonsterField()) {
                                       if (monsterCard) {
                                           monstersOfOwner.push_back(monsterCard);
                                       }
                                   }
                                   std::vector<MonsterCard *> monstersOfEnemy;
                                   for (MonsterCard *monsterCard: enemy->getPlayingField()->getMonsterField()) {
                                       if (monsterCard) {
                                           monstersOfEnemy.push_back(monsterCard);
                                       }
                                   }

                                   if (monstersOfOwner.size() < 2 || monstersOfEnemy.size() < 1) {
                                       return;
                                   }

                                   for (int i = 0; i < 2; i++) {
                                       MonsterCard *weakestMonsterOfOwner = owner->getPlayingField()->getWeakestMonsterInField();
                                       owner->getPlayingField()->removeCardFromMonsterField(weakestMonsterOfOwner);
                                   }

                                   MonsterCard *strongestMonsterOfEnemy = enemy->getPlayingField()->getStrongestMonsterInField();
                                   enemy->getPlayingField()->removeCardFromMonsterField(strongestMonsterOfEnemy);
                               }, 60));

    deck->addCard(
            new TrapCard("Zero Gravity", "Change the battle positions of all face-up monsters on the field.",
                         true,
                         [](Player *owner, Player *enemy) {
                             for (int i = 0; i < owner->getPlayingField()->getMonsterField().size(); ++i) {
                                 if (owner->getPlayingField()->getMonsterField().at(i) != nullptr &&
                                     owner->getPlayingField()->getMonsterField().at(i)->isFacedUp()) {
                                     owner->getPlayingField()->getMonsterField().at(i)->changeMode();
                                 }
                             }

                             for (int i = 0; i < enemy->getPlayingField()->getMonsterField().size(); ++i) {
                                 if (enemy->getPlayingField()->getMonsterField().at(i) != nullptr &&
                                     enemy->getPlayingField()->getMonsterField().at(i)->isFacedUp()) {
                                     owner->getPlayingField()->getMonsterField().at(i)->changeMode();
                                 }
                             }
                         }, 61));


    deck->shuffle();

    return deck;
}

SetoKaiba::SetoKaiba() : Player("Seto Kaiba", initializeDeck()) {

}

bool SetoKaiba::hasThreeBlueEyesWhiteDragon() {
    int count = 0;
    for (Card *card: *this->getHand()) {
        if (card && card->getName() == "Blue-Eyes White Dragon") {
            count++;
        }
    }
    return count == 3;
}

void SetoKaiba::summonBlueEyesUltimateDragon() {
    // remove those 3 BEWD from the hand
    for (int i = (int) this->getHand()->size() - 1; i >= 0; i--) {
        Card *currentCard = this->getHand()->at(i);
        if (currentCard && currentCard->getName() == "Blue-Eyes White Dragon") {
            removeCardFromHand(currentCard);
        }
    }

    // summon BEUD
    this->getPlayingField()->addCardToPlayingField(new MonsterCard("Blue-Eyes Ultimate Dragon",
                                                                   "\"Blue-Eyes White Dragon\" + \"Blue-Eyes White Dragon\" + \"Blue-Eyes White Dragon\"",
                                                                   4500, 3800, 12, DRAGON, 62));
}

SetoKaiba::~SetoKaiba() = default;



