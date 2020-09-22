#include <iostream>
#include <iomanip>
#include<string>
#include "card.h"
#include "DeckOfCards.h"

using namespace std;
void four(int value[5], int &x)
{
	x = 0;
	if (value[0] == value[1] && value[0] == value[2] && value[0] == value[3] && value[0] == value[4])
	{
		cout << "Four of a kind" << endl;
		x = 1;
	}
}
//flush
void flush(int type[5], int &x)
{
	x = 0;
	if (type[0] == type[1] && type[0] == type[2] && type[0] == type[3] && type[0] == type[4])
	{
		cout << "Flush" << endl;
		x = 1;
	}
}
//straight
void straight(int &straightCheck, int &x)
{
	x = 0;
	if (straightCheck == 1)
	{
		cout << "Straight!" << endl;
		x = 1;
	}
}
//three of a kind
void three(int value[5], int &x)
{
	x = 0;
	if (value[0] == value[1] && (value[0] == value[2] || value[0] == value[3] || value[0] == value[4]) || value[1] == value[2] && (value[1] == value[3] || value[1] == value[4]) || value[2] == value[3] && value[2] == value[4])
	{
		cout << "Three of a kind!" << endl;
		x = 1;
	}
}
//two pair
void two(int &twoPairCheck, int &x)
{
	x = 0;
	if (twoPairCheck == 1)
	{
		cout << "Two pair" << endl;
		x = 1;
	}
}
//pair
void one(int &pairCheck, int &x)
{
	if (pairCheck == 1)
	{
		cout << "Pair" << endl;
		x = 1;
	}
}

int main()
{
	//object deck to access class DeckOfCards
	DeckOfCards deck;
	//access function shuffle cards in DeckOfCards class
	deck.shuffleCards();

	int straightCheck = 0, TwoPairCheck = 0, pairCheck=0, x;
	int counter = 0, temp[10];
	string cardStore[5];
	int value[5], type[5];

	//while loop, termiante when there are no more cards left from Class DeckOfCards
	while (counter < 50) {
		//counter to know when 5 card count is reached
		counter++;
		//access class card with object Theta, and access function dealCard
		Card theta = deck.dealCard();
		//assigns card (the 5 in a row) to an array called cardStore
		cardStore[counter % 5] = theta.toString();
		//outputs the cards to user
		cout << setw(20) << left << theta.toString();
		//if statements to assign a numerical value to cards value (assigned to array value) and type (assigned to array type)
		//The statement looks at the first character in the string (for value) and the fifth or sixth character (for type, sixth character if card is 10)
		if (cardStore[counter % 5][0] == '2')
			value[counter % 5] = 2;
		if (cardStore[counter % 5][0] == '3')
			value[counter % 5] = 3;
		if (cardStore[counter % 5][0] == '4')
			value[counter % 5] = 4;
		if (cardStore[counter % 5][0] == '5')
			value[counter % 5] = 5;
		if (cardStore[counter % 5][0] == '6')
			value[counter % 5] = 6;
		if (cardStore[counter % 5][0] == '7')
			value[counter % 5] = 7;
		if (cardStore[counter % 5][0] == '8')
			value[counter % 5] = 8;
		if (cardStore[counter % 5][0] == '9')
			value[counter % 5] = 9;
		if (cardStore[counter % 5][0] == '1')
		{
			value[counter % 5] = 10;
			//this was done because 10 takes more spaces than other numbers, so the letter of type would be on 6 rather 
			//than 5
			if (cardStore[counter % 5][6] == 'S')
				type[counter % 5] = 1;
			if (cardStore[counter % 5][6] == 'H')
				type[counter % 5] = 2;
			if (cardStore[counter % 5][6] == 'D')
				type[counter % 5] = 3;
			if (cardStore[counter % 5][6] == 'C')
				type[counter % 5] = 4;
		}
		if (cardStore[counter % 5][0] == 'J')
			value[counter % 5] = 11;
		if (cardStore[counter % 5][0] == 'Q')
			value[counter % 5] = 12;
		if (cardStore[counter % 5][0] == 'K')
			value[counter % 5] = 13;
		if (cardStore[counter % 5][0] == 'A')
			value[counter % 5] = 14;
		if (cardStore[counter % 5][0] != 1)
		{
			if (cardStore[counter % 5][5] == 'S')
				type[counter % 5] = 1;
			if (cardStore[counter % 5][5] == 'H')
				type[counter % 5] = 2;
			if (cardStore[counter % 5][5] == 'D')
				type[counter % 5] = 3;
			if (cardStore[counter % 5][5] == 'C')
				type[counter % 5] = 4;
		}
		//reached 5 cards if statement
		if (counter % 5 == 0)
		{
			//these values will be used to find if we got a straight, two pair, pair (differences
			temp[0] = abs(value[0] - value[1]);
			temp[1] = abs(value[0] - value[2]);
			temp[2] = abs(value[0] - value[3]);
			temp[3] = abs(value[1] - value[2]);
			temp[4] = abs(value[1] - value[3]);
			temp[5] = abs(value[2] - value[3]);
			temp[6] = abs(value[4] - value[0]);
			temp[7] = abs(value[4] - value[1]);
			temp[8] = abs(value[4] - value[2]);
			temp[9] = abs(value[4] - value[3]);
			//bunch of for statement to determine if we have a straight (if numbers aren't equal to each other and difference is less than 4, then straight
			//these statements disqualify sth from being straight
			straightCheck = 1;
			for (int i = 1; i < 5; i++)
			{
				if (value[0] == value[0 + i])
					straightCheck = 0;
			}
			for (int i = 1; i < 4; i++)
			{
				if (value[1] == value[0 + i])
					straightCheck = 0;
			}
			for (int i = 1; i < 3; i++)
			{
				if (value[2] == value[0 + i])
					straightCheck = 0;
			}
			if (value[3] != value[4])
				straightCheck = 0;

			for (int i = 0; i < 11; i++)
			{
				if (temp[i] == 0 || temp[i] > 4)
					straightCheck = 0;
			}
			//look for two pair
			for (int i = 0; i < 10; i++)
			{
				if (temp[i] == 0)
				{
					i++;
					for (i; i < 10; i++)
						if (temp[i] == 0)
							TwoPairCheck = 1;

				}
			}
			//look for one pair
			for (int i=0; i < 10; i++)
			{
				if (temp[i] == 0)
					pairCheck = 1;
			}
			
			//four of a kind?
			four(value, x);
			//flush?
			if (x != 1)
				flush(type, x);
			//straight?
			if (x != 1)
				straight(straightCheck, x);
			//three of a kind
			if (x != 1)
				three(value, x);
			//two pair
			if (x != 1)
				two(TwoPairCheck, x);
			//pair
			if (x != 1)
				one(pairCheck, x);
			if (x!=1)
				cout << endl;
			straightCheck = 1, TwoPairCheck=0, pairCheck=0;
		}
	}
}
