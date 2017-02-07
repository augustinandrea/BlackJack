using namespace std;
#include <iostream>
#include <vector>
#include <cstdlib>
#include "BlackJack.h"

BlackJack::BlackJack(int playerw, int dealerw, int playerc, int dealerc) {
  
  deck = CardDeck();
  deck.shuffle();
  PlayerWin = 0;
  DealerWin = 0;
  for(int i = 0; i < 8; i++) {
    PlayerHand[i] = 0;
    DealerHand[i] = 0;
  }
  PlayerCard = 0;
  DealerCard = 0;
}

BlackJack::~BlackJack() { 
}

void BlackJack::DealerWon() {
  DealerWin++;
}

void BlackJack::PlayerWon() {
  PlayerWin++;
}

int BlackJack::getPlayerWon(){
  return PlayerWin;
}

int BlackJack::getDealerWon() {
  return DealerWin;
}


void BlackJack::getPlayerHand() { // gets the value of the player's and dealer's hands
    
  for(int i = 0; i < 8; i++) { // loop through hand and add card values
  
    if(PlayerHand[i]==11) 
      cout << "A ";
    else if(PlayerHand[i]==12)
      cout << "J ";
    else if(PlayerHand[i]==13)
      cout << "Q ";
    else if(PlayerHand[i]==14)
      cout << "K ";
    else if(PlayerHand[i] != 0)
      cout << PlayerHand[i] << " ";
  }
  
}

void BlackJack::getDealerHand() {

  for(int i = 0; i < 8; i++) { // loop through hand and add card values
  
    if(DealerHand[i]==11) 
      cout << "A ";
    else if(DealerHand[i]==12)
      cout << "J ";
    else if(DealerHand[i]==13)
      cout << "Q ";
    else if(DealerHand[i]==14)
      cout << "K ";
    else if(DealerHand[i] != 0)
      cout << DealerHand[i] << " ";
  }
  
}

int BlackJack::ValuePlayerHand() { // determine the values of the player's hand
  int total = 0;

  for(int i = 0; i < 8; i++) {
    
    if(PlayerHand[i] == 12) 
      total += 10;
    else if (PlayerHand[i] ==13)
      total += 10;
    else if (PlayerHand[i] ==14) 
      total += 10;
    else
      total += PlayerHand[i];
  }

  return total;
}
int BlackJack::ValueDealerHand() {
 int total = 0;

  for(int i = 0; i < 8; i++) {
    
    if(DealerHand[i] == 12) 
      total += 10;
    else if (DealerHand[i] ==13)
      total += 10;
    else if (DealerHand[i] == 14) 
      total += 10;
    else
      total += DealerHand[i];
  }

  return total;
}

void BlackJack::PlayerDraw(int i) {
  PlayerHand[PlayerCard] = deck.GetCard(i);
  PlayerCard++;
}
      

void BlackJack::DealerDraw(int i) {
  DealerHand[DealerCard] = deck.GetCard(i);
  DealerCard++;
}

void BlackJack::ResetDeck() { // resets the card deck after the previous hits 15 cards
  deck = CardDeck(52);
  deck.shuffle();
 
}

void BlackJack::ResetHands() {
  for(int i = 0; i < 0; i++) {
    PlayerHand[i] = 0;
    DealerHand[i] = 0;
  }
  PlayerCard = 0;
  DealerCard = 0;

}
