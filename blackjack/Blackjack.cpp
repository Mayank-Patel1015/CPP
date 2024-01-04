// Blackjack by Mayank Patel;
// To run: g++ -std=c++11 -o blackjack Card.cpp Deck.cpp Player.cpp Blackjack.cpp Game.cpp
#include <iostream>
#include "Game.h"

int main()
{
  std::cout << "Welcome to Blackjack!" << std::endl;
  playBlackjack();
  return 0;
}
