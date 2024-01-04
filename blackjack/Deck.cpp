#include "Deck.h"

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

void Deck::shuffleDeck()
{
  srand(static_cast<unsigned int>(time(0)));
  std::random_shuffle(cards.begin(), cards.end());
}
