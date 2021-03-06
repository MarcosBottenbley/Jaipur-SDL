/**
 * Intermediate Programming Final Project
 * David Miller, Syed Hossain, Marcos Bottenbley, Andrew Zhu
 * dmill118@jhu.edi, shossai8@jhu.edu, mbotten1@jhu.edu, azhu8@jhu.edu
 */

#include "AI.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

AI::AI(std::string name) : Player(name) {}

Move* AI::get_move(Market& market, Bank& bank)
{
    Move* movePtr;

    //printStats();
    //market.print_market();
    cout << endl;

    //if hand is not full, take the first card in the market
    //(if the card is a camel, make_move will take all camels)
    if(hand.get_hand_size() != 7)
        movePtr =  take(market);
    else
    {
        movePtr = sell_one(market, bank);

        if (movePtr == 0)
            movePtr = sell_two(market, bank);
    }
    return movePtr;
}

Move* AI::take(Market& market)
{
    if(market.get_card(0)->get_type() == "Camel")
        cout << name << " takes the camels." << endl;
    else
        cout << name << " takes a " << market.get_card(0)->get_type() << " card." << endl;
    return new Take(market, hand, 0);
}

//if hand is full, go through the hand and sell the first card
//you find that isn't a valuable card (gold, silver, diamond)
Move* AI::sell_one(Market& market, Bank& bank)
{
    unsigned int i;
    std::string type;
    bool playerCards[7] {0};

    for (i = 0; i < hand.get_hand_size(); i++)
    {
        type = hand.card_at(i)->get_type();
        if (type != "Diamond" && type != "Gold" && type != "Silver")
        {
            playerCards[i] = !(playerCards[i]);
            cout << name << " sells a " << type << " card." << endl;
            return new Sell(market, hand, bank, playerCards);
        }
    }
    return 0;
}

//this code will only execute if the AI has a full hand of only valuables,
//it loops through every combination of two cards until it finds a valid one
//and sells them
Move* AI::sell_two(Market& market, Bank& bank)
{
    unsigned int i,j;
    std::string type1, type2;
    bool playerCards[7] {0};

    for (i = 0; i < hand.get_hand_size(); i++)
    {
        for (j = 0; j < hand.get_hand_size(); j++)
        {
            if (i == j)
                continue;

            type1 = hand.card_at(i)->get_type();
            type2 = hand.card_at(j)->get_type();

            if(type1 == type2)
            {
                playerCards[i] = !(playerCards[i]);
                playerCards[j] = !(playerCards[j]);
                cout << name << " sells two " << type1 << " cards." << endl;
                return new Sell(market, hand, bank, playerCards);
            }
        }
    }
    return 0;
}
