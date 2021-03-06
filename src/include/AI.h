/**
 * Intermediate Programming Final Project
 * David Miller, Syed Hossain, Marcos Bottenbley, Andrew Zhu
 * dmill118@jhu.edi, shossai8@jhu.edu, mbotten1@jhu.edu, azhu8@jhu.edu
 */

#pragma once

#include "Player.h"
#include "Take.h"
#include "Trade.h"
#include "Sell.h"
#include <string>

class AI : public Player
{
public:
    AI (std::string name);

    Move* get_move (Market &market, Bank &bank);
private:
    Move* take(Market& market);
    Move* sell_one(Market& market, Bank& bank);
    Move* sell_two(Market& market, Bank& bank);

    void pause();
};
