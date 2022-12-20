#ifndef ENEMY_H
#define ENEMY_H
#include <string>
#include "Item.h"
#include "Stats.h"
#include "Player.h"


class Enemy:public Stats
{
    public:
       Enemy();
       Enemy(unsigned short int _Maxhealth , unsigned short int _PhysicalDamage , unsigned short int _MagicalDamage , unsigned short int _PhysicalArmor,
        unsigned short int _MagicalArmor, unsigned short int _Evasion , unsigned short int _Level , int _Coins , int _Experience , string _Name);
       void Drop(Player &p);

       Item itemDroped;

};

#endif // ENEMY_H
