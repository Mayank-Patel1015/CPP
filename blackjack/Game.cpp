#include <iostream>
#include "Deck.h"
#include "Player.h"

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
  // Display the entire dealer's hand since player(s) are done playing
  dealer.displayHand(true);
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
  // Only in the case of player not busting do we need to check if dealer busted.
  else if (dealer.isBusted() || player.getScore() > dealer.getScore())
  {
    std::cout << "\nPlayer wins!" << std::endl;
  }
  else
  {
    std::cout << "\nIt's a tie!" << std::endl;
  }
}
