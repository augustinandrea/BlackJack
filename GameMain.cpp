#include <iostream>
#include <vector>
#include <cstdlib>
#include "BlackJack.h"

using namespace std;

int main() {
 
  srand(time(NULL));
  char HitStay; // Hit or stay for a hand
  char PlayEnd;
  int count; // current number of cards in the hand
  BlackJack game (0, 0, 0, 0); // Initialize BlackJack
  
  while (true) {

    cout << "Would you like to play(p) or quit(q)? " << endl;
    cin >> PlayEnd;
    if (PlayEnd == 'q') {
      break;
    }

    game.PlayerDraw(count); // The first two cards the player is given
    count++;
    game.PlayerDraw(count);
    count++;

    cout << "Your hand: "; //The player's hand at the start of the game
    game.getPlayerHand();
    cout << endl;
    
    while (HitStay != 's') { //The player continues to draw cards
      cout << "Would you like to hit or stay? (h/s) " << endl;
      cin >> HitStay;
      
      if (HitStay == 's'){ // if the player chooses to stay their hand
	break;
      }
      if (HitStay == 'h') {
	game.PlayerDraw(count);
	count++;
	cout << "Your hand: "; // new hand for the player
	game.getPlayerHand();
	cout << endl;
      }
    }
    
    while( game.ValueDealerHand() < 17) { // The dealer has to draw more cards
      game.DealerDraw(count);
      count++;
    }
        
    cout << "Dealer's hand: "; // the new cards that the dealer has
    game.getDealerHand();
    cout << endl;
    
    if (game.ValueDealerHand() <= 21 && game.ValuePlayerHand() <=21) { //for determining the winner of the game
      
      if(game.ValueDealerHand() >= game.ValuePlayerHand() ) { // If the dealer wins
	game.DealerWon();
	cout << "The dealer won!" << endl;

      }
      else  { // The player wins
	game.PlayerWon();
	cout << "You win!" << endl;
	
      }
      
    }
    else if (game.ValuePlayerHand() > 21) { //The player busts, and the dealer therefore automatically wins
      game.DealerWon();
      cout << "You busted! The dealer won!" << endl;

    }
    else  { // The dealer busts, and players automatically wins
      game.PlayerWon();
      cout << "The dealer busted! You win!" << endl; 
    } 
    
    if (count >= 15) { //if the deck of cards has at least 15 cards left in it
      game.ResetDeck();
      count = 0;
    }
    
    game.ResetHands(); // start a new game 
    cout << "Player Wins total: " << game.getPlayerWon() << endl;
    cout << "Dealer Wins total: " << game.getDealerWon() << endl;
  }
  cout << "End of game." << endl;
  
}


