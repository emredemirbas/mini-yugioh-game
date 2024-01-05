# Mini Yu-Gi-Oh! Game
 A turn-based card game project inspired by the Yu-Gi-Oh! Trading Card Game, implemented in C++.
 
![samplecards](https://github.com/emredemirbas/MiniYuGiOhGame/assets/103829617/2b866768-daa3-405e-8b92-f6cdeccb162d)

![1](https://github.com/emredemirbas/MiniYuGiOhGame/assets/103829617/5930879e-46d0-4126-ae65-321adf2eb435)

![2](https://github.com/emredemirbas/MiniYuGiOhGame/assets/103829617/489d2eaf-0ff9-4d81-a3c4-73164cfaae5f)

![3](https://github.com/emredemirbas/MiniYuGiOhGame/assets/103829617/59582d62-4f6d-47c5-906c-0adc60ae718b)

![4](https://github.com/emredemirbas/MiniYuGiOhGame/assets/103829617/03b41584-372b-4171-b9f8-f64cfff14c29)

![5](https://github.com/emredemirbas/MiniYuGiOhGame/assets/103829617/1c16e8ea-0912-4639-842f-20078eb887ee)

![6](https://github.com/emredemirbas/MiniYuGiOhGame/assets/103829617/c905de2f-9a3e-4821-a6d5-bd26d345a1f1)

![7](https://github.com/emredemirbas/MiniYuGiOhGame/assets/103829617/495fde33-a9f2-4df5-a914-ae06b0c1fd0c)

![8](https://github.com/emredemirbas/MiniYuGiOhGame/assets/103829617/378bfe9f-6a2d-470e-80e7-1e6d1f6fa954)

![9](https://github.com/emredemirbas/MiniYuGiOhGame/assets/103829617/7b496772-21b8-4dca-9fa6-f909422dbc03)

![10](https://github.com/emredemirbas/MiniYuGiOhGame/assets/103829617/fb7a1a42-b96c-49f6-aa5f-579d0929c607)


Phases of The Game

1. Draw Phase
• Draw Phase is at the very beginning of each turn. The turn player draws one card from the top of their deck during this time.

2. Main Phase
• Main Phase is a phase that occurs right after Draw Phase. In this phase, player must choose a card to play from his/her hand (with left click). 
User should left click on the card that he/she wants to play.

• Option 1: If current player chooses a monster card to play, this monster card will be played in ATK mode if ATK point > DEF point.
Otherwise, this monster will be played in defense mode.

• Option 2: If the current player decides to use a spell card, the special ability of that spell card is activated as soon as it is played.

• Option 3: If the current player prefers to use a trap card, it will be placed in his/her field in face-down position. So that opposing player would not know
which trap card have been played. Unique functionality of this trap card will be activated when the current player receives attack by the opposing player in battle phase.

• User is also able to change mode of one of his/her active monster(optional). Maximum one monster is allowed in each main phase. 
User should right click on that monster if he/she wants to change mode one of the monsters.

3. Battle Phase

• Battle phase is the third and last phase of the player's turn. In this phase, you can declare attacks.
 
• You should choose an attacker monster from your monster field (with left click). If there are no monsters in opponent's monster zone, a direct attack is declared. Which means, inflicting damage equal to the attacking monster's ATK points.

• But if there are monster(s) in your opponent's field, you should choose a target right after you choose an attacker from your field.

Note that Battle Phase of a player is automatically skipped in following cases:

• If it's the first or second round, the Battle Phase is automatically skipped, adding an extra layer of strategy to early-game play.

• If current player has no attacking monster in his field (means that his monster field may be fully empty or there are monsters that in defense mode.)

• When the current player declares an attack in this phase but opposing player has a trap card in his/her field, then unique functionality of this trap card will be activated and opposing player will block the attack of current player.

![11](https://github.com/emredemirbas/MiniYuGiOhGame/assets/103829617/9956872b-4d9c-42e3-a5bd-ef9d983f6535)

How to win the duel?

1. Life Point Victory
• Each player starts with a 8000 life points.

• The primary goal is to reduce your opponent's life points to zero.

• You achieve this by successfully attacking your opponent's monsters or declaring direct attacks during the Battle Phase.

• Additionally, certain card effects may reduce or increase life points.

2. Deck Exhaustion

• Also, you win if your opponent doesn't have any cards left in their deck, along with reducing their life points to zero.

• If a player tries to draw a card and has none left in their deck, the other player wins.

3. Exodia Victory
• There's a legendary win condition known as "Exodia."

• If a player successfully assembles all five pieces of Exodia in their hand (Head, Right Leg, Left Leg, Right Arm, Left Arm) at the same time, that player immediately wins the duel.

• It's a rare and powerful strategy, so keep an eye on the cards you and your opponent draw. 

Note that only Yugi Moto has Exodia cards in our game.

How to run the game?

1) Install exec folder.

2) run MiniYuGiOhGame.exe




