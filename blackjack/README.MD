# Create a Blackjack (21) game to show proficency in C++ concepts

## How to play:
### Clone repo
### navigate to blackjack file in terminal
### run command in terminal: g++ -std=c++11 Blackjack.cpp Card.cpp Deck.cpp Game.cpp Player.cpp 

## MVP:
### Play the game with no cash and no extra rules (just beat the dealer) 1 player

## Goal:
### Full Blackjack game with betting upto 7 players (Casino max) per hand
### Assumption (below)

## Assumptions (may be implemented in stretch goals):
### No splitting
### No insurance
### No extra payouts based on blackjack
### Dealer will never hit on 17 including a soft 17 (Ace + 6)

## Classes (begining concept):
### Player
### Dealer / House
### Hand (May )
### Deck
### Card
### Game

## Classes (end):
### main
### Game (acts as dealer)
### Deck
### Card
### Player (creates dealer and palyer hand since functionality is same)

## Structure (begining):
### Main calls Game with num players playing
### Game creates a new Deck
### Deck calls the card class 52 times to create all 52 card combinations then shuffles them
### Game calls Dealer / House to play the round
### Players bet
### Dealer / House deals initial 2 cards to each Hand (dealer has one card not showing)
### Hand class handles busts / blackjack
### After hand is checked dealer asks player if they would like to hit till they stand then repeats for next player
### Dealer hits until hand >= 16
### If bust payout all players who didnt bust
### If dealer didnt bust payout those that have higher score (& not busted) and take from those who have lower score. 

## Structure (end):
### Main calls Game
### Game initializes deck, player, dealer (another player class object)
### Deck shuffles after creation
### Game deals out initial two cards calling the deck class to draw a card
### Game calls player class to displayHand (and total_score) and dealer to display hand 
### Game asks player for next step if not busted
### Game deals cards to dealer till score is 17+
### Game determines winner

## Complications / issues along the way / implementation:

### Found it hard to code with all the header and cpp files so created all the classes in main class.
### DONE: seperate the classes into seperate header/cpp files after getting it working.
### Had difficulty with only displaying one card from the dealer.
### Fix: Created a flag to signify player was not done playing (showAll/displayHand).
### Could not figure out how to properly shuffle the deck so resorted to stack overflow
### When calculating the score with an Ace, was getting a bug where the game would think a player busted after a hit on a hand containing an Ace but a lower score that didn't bust was possible.
### Fixed this by having the default score add 1 for an ace and adding 10 till we were out of aces or score + 10 > 21
### Added: skip player turn if 21
