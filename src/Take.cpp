/**
 * Intermediate Programming Final Project
 * David Miller, Syed Hossain, Marcos Bottenbley, Andrew Zhu
 * dmill118@jhu.edi, shossai8@jhu.edu, mbotten1@jhu.edu, azhu8@jhu.edu
 */

#include "Take.h"

Take::Take(Market & m, Hand & h, unsigned int i) : Move(m,h), index(i)
{}

Take::~Take()
{}

int Take::make_move ()
{
    InvalidMoveEx ime1 ("ERROR: invalid selection");
    InvalidMoveEx ime2 ("ERROR: hand is full. The hand is limited to 7 cards");
    if (index > 4)
    {
        throw ime1;
    }
    if(hand.get_hand_size() == 7)
    {
        throw ime2;
    }

    if (market.get_card(index)->is_camel())
    {
        for (int x = 0; x < 5; x++)
        {
            if (market.get_card(x)->is_camel())
            {
                hand.add_card(market.take_card(x));   //take camel from market
            }
        }
        return 0;
    }

    hand.add_card (market.take_card (index));

    return 0;
}
