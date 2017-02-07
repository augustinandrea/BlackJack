#include <iostream>
#include <vector>
#include "CardDeck.h"
#ifndef BLACKJACK_H
#define BLACKJACK_H
using namespace std;

class BlackJack {

 public:
  BlackJack(int=0, int=0, int=0, int=0); // constructor
  ~BlackJack(); // deconstructor

  void PlayerDraw(int); //
  void DealerDraw(int); //

  int getPlayerWon();
  int getDealerWon();
  void DealerWon();
  void PlayerWon();

  void getPlayerHand(); //
  void getDealerHand(); //
  int ValuePlayerHand(); //
  int ValueDealerHand(); //
  
  void ResetDeck(); //
  void ResetHands(); //       

 private:
  CardDeck deck;
  int PlayerCard;
  int DealerCard;
  int PlayerHand[8];
  int DealerHand[8];
  int PlayerWin;
  int DealerWin;


};

#endif
