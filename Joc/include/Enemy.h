#ifndef ENEMY_H
#define ENEMY_H
#include "Item.h"
#include "Stats.h"
#include "Player.h"


class Enemy:public Stats
{
    public:
       Enemy();
       Enemy(unsigned short int _Maxhealth , unsigned short int _PhysicalDamage , unsigned short int _MagicalDamage , unsigned short int _PhysicalArmor,
        unsigned short int _MagicalArmor, unsigned short int _Evasion , unsigned short int _Level , int _Coins , int _Experience , string _EnemyName);
       void TakeDamage(unsigned short int PlayerPhysicalDamage, unsigned short int PlayerMagicalDamage);
       string EnemyName;
};

#endif // ENEMY_H
