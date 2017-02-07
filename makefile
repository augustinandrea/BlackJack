GameMain: GameMain.o CardDeck.o BlackJack.o
	g++ GameMain.o CardDeck.o BlackJack.o -o GameMain

GameMain.o: GameMain.cpp
	g++ -g -c GameMain.cpp -o GameMain.o

CardDeck.o: CardDeck.cpp CardDeck.h
	g++ -g -c CardDeck.cpp

BlackJack.o: BlackJack.cpp BlackJack.h
	g++ -g -c BlackJack.cpp

clean:
	rm -f *.o GameMain

