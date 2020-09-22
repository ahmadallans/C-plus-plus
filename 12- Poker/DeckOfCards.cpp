#include <stdlib.h>
#include<time.h>
#include<cstdlib>
#include "DeckOfCards.h"

//initializes array deck to the value of of Card (here values are stored in order by going through the thirteen cards 4 times)
DeckOfCards::DeckOfCards()
{
	for (int counter1 = 0; counter1<4; counter1++)
		for (int counter2 = 0; counter2<13; counter2++)
			deck[counter1 * 13 + counter2] = Card(counter1, counter2);
	currentCard = 0;
}
//function to shuffle cards
void DeckOfCards::shuffleCards()
{
	//randomizes rand with time
	srand(time(0));
	for (int counter1 = 0; counter1<52; counter1++)
	{
		int num = rand() % 52;
		Card temper = deck[counter1];
		//assigns cards in deck to a random position in the same array
		deck[counter1] = deck[num];
		deck[num] = temper;
	}
}
//gives the card in order (shuffeled order of course)
Card DeckOfCards::dealCard()
{
	return deck[currentCard++];
}
//used to stop when cards are more than 52 (returns false if 52)
bool DeckOfCards::moreCards()
{
	return currentCard != 52;
}