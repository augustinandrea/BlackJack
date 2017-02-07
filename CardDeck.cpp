// Andrea Augustin
#include "CardDeck.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

CardDeck::CardDeck(int s) { //constructor
  size = (s > 0 ? s : 52);
  deck = new int [ size ];
  int value = 2;
  
  for(int i = 0; i < size; i++) {
    deck[i] = value;
    value++;
    if(value ==15) {
      value = 2;
    }
  }
}

CardDeck::~CardDeck() {
  delete [] deck;

}

CardDeck::CardDeck(const CardDeck &copy) { // copy constructor
  deck = new int [ size ];
  
  for (int i = 0; i < size; i++) {
    deck[i] = copy.deck[i];
  }

}

int CardDeck::getSize() { //get the size(number) of the cards

  return size;
}

void CardDeck::shuffle() { // shuffle the deck
  int j;
  int temp;
  
  for ( int i = 0; i < size; i++){
    
    j = i + rand() % (size - i);
    
    temp = deck[j];
    deck[j] = deck[i];
    deck[i] = temp;
  }
  
}

int CardDeck::GetCard(int card) { //returns the card within the deck array
  return deck[card];

}

ostream &operator<<(ostream &out, const CardDeck &d) { //                                                           

  for(int i = 0; i < d.size; i++) {
    out << d.deck[i] << " " ;
  }
  out << endl;
  return out;
}


