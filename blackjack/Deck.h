#pragma once

#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include "Card.h"

class Deck
{
public:
  Deck();

  Card drawCard();

  bool isEmpty();

private:
  std::vector<Card> cards;

  void shuffleDeck();
};
