#pragma once
#include "Card.h"

class DeckOfCards {
private:
	Card deck[52];
	int currentCard;
public:
	DeckOfCards();
	void shuffleCards();
	Card dealCard();
	bool moreCards();
};

