#include "Card.h"

Card::Card(Rank r, Suit s) : rank(r), suit(s) {}

int Card::getValue()
{
  if (rank > 10)
  {
    return 10;
  }
  else
  {
    return rank;
  }
}

void Card::displayCard(bool showAll)
{
  if (showAll)
  {
    std::string rankStr;
    switch (rank)
    {
    case ACE:
      rankStr = "Ace";
      break;
    case JACK:
      rankStr = "Jack";
      break;
    case QUEEN:
      rankStr = "Queen";
      break;
    case KING:
      rankStr = "King";
      break;
    default:
      rankStr = std::to_string(rank);
    }

    std::string suitStr;
    switch (suit)
    {
    case CLUBS:
      suitStr = "Clubs";
      break;
    case DIAMONDS:
      suitStr = "Diamonds";
      break;
    case HEARTS:
      suitStr = "Hearts";
      break;
    case SPADES:
      suitStr = "Spades";
      break;
    }

    std::cout << rankStr << " of " << suitStr;
  }
  else
  {
    std::cout << "Card face down"; // handle dealers faced down card
  }
}
