#pragma once

#include <iostream>
#include <vector>
#include "Card.h"

class Player
{
public:
  void addCard(Card card);

  int getScore();

  void displayHand(bool showAll);

  bool isBusted();

  bool wantsToHit();

private:
  std::vector<Card> hand;
};
