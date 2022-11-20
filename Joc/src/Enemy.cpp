#include "Enemy.h"



Enemy::Enemy()
{
    EnemyName="inamic";
}

Enemy::Enemy(unsigned short int _Maxhealth , unsigned short int _PhysicalDamage , unsigned short int _MagicalDamage , unsigned short int _PhysicalArmor,
        unsigned short int _MagicalArmor, unsigned short int _Evasion , unsigned short int _Level , int _Coins , int _Experience , string _EnemyName)
   :Stats(_Maxhealth , _PhysicalDamage , _MagicalDamage , _PhysicalArmor , _MagicalArmor , _Evasion ,  _Level ,  _Coins ,  _Experience ){
    EnemyName=_EnemyName;

   }

   void Enemy:: TakeDamage(unsigned short int PlayerPhysicalDamage, unsigned short int PlayerMagicalDamage)
   {
       this->health-=PlayerMagicalDamage;
       this->health-=PlayerPhysicalDamage;

   }



