#ifndef COMBAT_H
#define COMBAT_H
#include <iostream>
#include <list>
#include <iterator>
#include "Player.h"
#include "Enemy.h"
#include "Perk.h"
#include "Handlers.h"

using namespace std;

class Combat
{
    public:

        void ShowStatsBeforeCombat(Player &player , Enemy &_enemy);
        void Fight(Player &player , Enemy &_enemy , list<Perk> &_AllPerks);

        int StatPrice = 1;
        Handlers MainHandle;
};

#endif // COMBAT_H
