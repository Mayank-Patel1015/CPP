#include "Player.h"

void Player::addCard(Card card)
{
  hand.push_back(card);
}

int Player::getScore()
{
  int score = 0;
  int numAces = 0;

  for (auto &card : hand)
  {
    score += card.getValue();
    if (card.getValue() == Card::ACE)
    {
      ++numAces;
    }
  }

  // Handle Aces to maximize score without busting
  while (numAces > 0 && score + 10 <= 21)
  {
    score += 10;
    --numAces;
  }

  return score;
}

void Player::displayHand(bool showAll)
{
  for (size_t i = 0; i < hand.size(); ++i)
  {
    auto &card = hand[i];
    card.displayCard(showAll || (i == 0)); // Always display the first card face-up
    std::cout << ", ";
  }

  if (!showAll)
  {
    // Display total score only for the face-up card (dealer's first card)
    std::cout << "Total Score: " << hand[0].getValue() << std::endl;
  }
  else
  {
    std::cout << "Total Score: " << getScore() << std::endl;
  }
}

bool Player::isBusted()
{
  return getScore() > 21;
}

bool Player::wantsToHit()
{
  if (getScore() == 21)
  {
    std::cout << "21 achieved, skipping turn" << std::endl;
    return false;
  }
  char choice;
  std::cout << "Do you want to hit? (y/n): ";
  std::cin >> choice;
  return (choice == 'y' || choice == 'Y');
}
