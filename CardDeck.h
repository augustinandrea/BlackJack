#include <iostream>
#include <cstdlib>

using namespace std;

#ifndef CARDDECK_H
#define CARDDECK_H


class CardDeck {
  friend ostream &operator<<(ostream &, const CardDeck &); // overloading the operator to display the deck

 public:
  CardDeck(const CardDeck &); //copy constructor
  ~CardDeck();
  CardDeck(int = 52);
  int getSize();
  void shuffle(); // shuffles the card deck
  int GetCard(int);
  

 private:
  int * deck;
  int size;
  
};

#endif
