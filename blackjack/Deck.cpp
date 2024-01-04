#include "Deck.h"
#include <random>
#include <algorithm>

// Create New Deck then shuffle it
Deck::Deck()
{
  for (int s = Card::CLUBS; s <= Card::SPADES; ++s)
  {
    for (int r = Card::ACE; r <= Card::KING; ++r)
    {
      cards.push_back(Card(static_cast<Card::Rank>(r), static_cast<Card::Suit>(s)));
    }
  }
  shuffleDeck();
}

Card Deck::drawCard()
{
  Card drawnCard = cards.back();
  cards.pop_back();
  return drawnCard;
}

bool Deck::isEmpty()
{
  return cards.empty();
}

// StackOverflow shuffle solution since the previous implementation was always shuffling the cards in the same way.
void Deck::shuffleDeck()
{
  std::random_device rd;
  std::mt19937 gen(rd());
  std::shuffle(cards.begin(), cards.end(), gen);
}