#include "Trade.h"

Trade::Trade(Market &m, Hand &h, bool *pc, bool *mc, int c):
 Move(m,h), camels(c)
{
	pIndexes = getIndexes(pc, 7);
	mIndexes = getIndexes(mc, 5);
}

Trade::~Trade()
{}

int Trade::makeMove()
{
	InvalidMoveEx ime1("ERROR: Did not pick an equal amount of cards from the market and the hand\n");
	InvalidMoveEx ime2("ERROR: Did not pick the right amount of cards\n");

	int size = mIndexes.size();
	int size2 = pIndexes.size();

	if(size != size2+camels)//checks to see if amount of cards are equal
		throw ime1;
	else if(size > 5 || size < 2) //checks to see that they didn't pick either too many or too little cards
		throw ime2;

	Card * temp = 0;

	for(int x = size2-1; x >= 0; x--) {
		temp = hand.removeCard(pIndexes[x]);		//remove backmost hand card
		temp = market.swapCard(mIndexes[x+camels], temp);	//put in market and take out market card
		hand.addCard(temp);			//add market card to player's hand

	}

	for(int i = 0; i < camels; i++) {
		temp = hand.getCamel();
		temp = market.swapCard(mIndexes[i], temp);
		hand.addCard(temp);
	}

	return 0;
}
