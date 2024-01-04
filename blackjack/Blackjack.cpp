#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <random>

using namespace std;

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

  Card(Rank r, Suit s) : rank(r), suit(s) {}

  int getValue()
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

  void displayCard(bool showAll)
  {
    if (showAll)
    {
      string rankStr;
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
        rankStr = to_string(rank);
      }

      string suitStr;
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

      cout << rankStr << " of " << suitStr;
    }
    else
    {
      cout << "Card face down";
    }
  }

private:
  Rank rank;
  Suit suit;
};

class Deck
{
public:
  Deck()
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

  Card drawCard()
  {
    Card drawnCard = cards.back();
    cards.pop_back();
    return drawnCard;
  }

  bool isEmpty()
  {
    return cards.empty();
  }

private:
  vector<Card> cards;

  void shuffleDeck()
  {
    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(cards.begin(), cards.end());
  }
};

class Player
{
public:
  void addCard(Card card)
  {
    hand.push_back(card);
  }

  int getScore()
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

  void displayHand(bool showAll)
  {
    for (size_t i = 0; i < hand.size(); ++i)
    {
      auto &card = hand[i];
      card.displayCard(showAll || (i == 0)); // Always display the first card face-up
      cout << ", ";
    }

    if (!showAll)
    {
      // Display total score only for the face-up card (dealer's second card)
      cout << "Total Score: " << hand[0].getValue() << endl;
    }
    else
    {
      cout << "Total Score: " << getScore() << endl;
    }
  }

  bool isBusted()
  {
    return getScore() > 21;
  }

  bool wantsToHit()
  {
    char choice;
    cout << "Do you want to hit? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
  }

private:
  vector<Card> hand;
};

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
  cout << "Player's hand: ";
  player.displayHand(true);
  cout << "Dealer's hand: ";
  dealer.displayHand(false); // Show only one card of the dealer
  cout << endl;

  // Player's turn
  cout << "Player's turn:" << endl;
  while (!player.isBusted() && player.wantsToHit())
  {
    player.addCard(deck.drawCard());
    player.displayHand(true);
  }

  // Dealer's turn
  cout << "\nDealer's turn:" << endl;
  dealer.displayHand(true); // Now display the entire dealer's hand
  while (dealer.getScore() < 17)
  {
    dealer.addCard(deck.drawCard());
    dealer.displayHand(true);
  }

  // Display final hands
  cout << "\nFinal hands:" << endl;
  cout << "Player's hand: ";
  player.displayHand(true);
  cout << "Dealer's hand: ";
  dealer.displayHand(true);

  // Determine the winner
  if (player.isBusted() || (!dealer.isBusted() && dealer.getScore() > player.getScore()))
  {
    cout << "\nDealer wins!" << endl;
  }
  else if (dealer.isBusted() || player.getScore() > dealer.getScore())
  {
    cout << "\nPlayer wins!" << endl;
  }
  else
  {
    cout << "\nIt's a tie!" << endl;
  }
}

int main()
{
  cout << "Welcome to Blackjack!" << endl;
  playBlackjack();
  return 0;
}
