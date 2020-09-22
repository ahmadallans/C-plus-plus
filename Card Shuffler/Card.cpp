#include "Card.h"
using namespace std;
//gives faces and suits arrays
const string Card::faces[] = { "2", "3", "4", "5", "6", "7", "8", "9","10","J", "Q", "K", "A" };
const string Card::suits[] = { "Spade", "Heart", "Diamond", "Club" };

//constructor
Card::Card()
{
	face = 0;
	suit = 0;
}

Card::Card(int suit, int face)
{
	this->face = face;
	this->suit = suit;
}
//returns value when called
string Card::toString()
{
	return Card::faces[face] + " of " + Card::suits[suit];
}
