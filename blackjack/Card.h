#pragma once

#include <iostream>
#include <string>

class Card
{
public:
  enum Rank
  {
    ACE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING
  };
  enum Suit
  {
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES
  };

  Card(Rank r, Suit s);

  int getValue();

  void displayCard(bool showAll);

private:
  Rank rank;
  Suit suit;
};
