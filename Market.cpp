#include "Market.h"
#include "Deck.h"
#include <iostream>

Market::Market(Deck &d):
 deck(d)
{
    for(int i = 0; i < 3; i++)
    {
        mktCards[i] = new Card("Camel");
    }

	mktCards[3] = d.getCard();
	mktCards[4] = d.getCard();
}

Card* Market::getCard(int index) {
        return mktCards[index];
}

Card* Market::takeCard(int index) {
        Card* tempCard = mktCards[index];
        mktCards[index] = deck.getCard();
        return tempCard;
}

Card* Market::swapCard(int index, Card* card) {
        Card* tempCard = mktCards[index];
        mktCards[index] = card;
        return tempCard;
}

void Market::printMarket() {
	for (int i = 0; i < 5; i++) {
                std::cout << i+1 << ". [" << mktCards[i]->getType() << "] ";
		//std::cout << i+1 << ". [" << Type.toString(mktCards[i]->getType()) << "] ";
	}
	std::cout << std::endl;
}

