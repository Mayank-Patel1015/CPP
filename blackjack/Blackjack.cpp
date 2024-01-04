// Blackjack by Mayank Patel;
// To run: g++ -std=c++11 -o blackjack Card.cpp Deck.cpp Player.cpp Blackjack.cpp
#include <iostream>
#include "Deck.h"
#include "Player.h"

void playBlackjack();

int main()
{
  std::cout << "Welcome to Blackjack!" << std::endl;
  playBlackjack();
  return 0;
}

void playBlackjack()
{
  Deck deck;
  Player player;
  Player dealer;

  // Initial deal
  player.addCard(deck.drawCard());
  dealer.addCard(deck.drawCard());
  player.addCard(deck.drawCard());
  dealer.addCard(deck.drawCard());

  // Display initial hands
  std::cout << "Player's hand: ";
  player.displayHand(true);
  std::cout << "Dealer's hand: ";
  dealer.displayHand(false); // Show only one card of the dealer
  std::cout << std::endl;

  // Player's turn
  std::cout << "Player's turn:" << std::endl;
  while (!player.isBusted() && player.wantsToHit())
  {
    player.addCard(deck.drawCard());
    player.displayHand(true);
  }

  // Dealer's turn
  std::cout << "\nDealer's turn:" << std::endl;
  dealer.displayHand(true); // Now display the entire dealer's hand
  while (dealer.getScore() < 17)
  {
    dealer.addCard(deck.drawCard());
    dealer.displayHand(true);
  }

  // Display final hands
  std::cout << "\nFinal hands:" << std::endl;
  std::cout << "Player's hand: ";
  player.displayHand(true);
  std::cout << "Dealer's hand: ";
  dealer.displayHand(true);

  // Determine the winner
  if (player.isBusted() || (!dealer.isBusted() && dealer.getScore() > player.getScore()))
  {
    std::cout << "\nDealer wins!" << std::endl;
  }
  else if (dealer.isBusted() || player.getScore() > dealer.getScore())
  {
    std::cout << "\nPlayer wins!" << std::endl;
  }
  else
  {
    std::cout << "\nIt's a tie!" << std::endl;
  }
}