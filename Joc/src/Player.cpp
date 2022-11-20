#include "Player.h"
#include <windows.h>
#include <iostream>

using namespace std;


Player::Player(unsigned short int _Maxhealth , unsigned short int _PhysicalDamage , unsigned short int _MagicalDamage , unsigned short int _PhysicalArmor,
        unsigned short int _MagicalArmor , unsigned short int _Evasion , unsigned short int _Level , int _Coins , int _Experience , int _ExperienceLimit ,
        unsigned short int _ItemNumber)
   :Stats(_Maxhealth , _PhysicalDamage , _MagicalDamage , _PhysicalArmor , _MagicalArmor, _Evasion ,  _Level ,  _Coins ,  _Experience ){

       ExperienceLimit=_ExperienceLimit;
       ItemNumber=_ItemNumber;
   }

Player::Player(){
       ExperienceLimit=100;
       ItemNumber=0;

   }


   void Player :: TakeDamage(unsigned short int EnemyPhysicalDamage , unsigned short int EnemyMagicalDamage)
   {
       this->health-=EnemyMagicalDamage;
       this->health-=EnemyPhysicalDamage;


   }

   void Player::Defeat()
   {
       system("exit");

   }

   void Player::IncrementItemNumber()
   {

       ItemNumber++;

   }

   unsigned short int Player:: GetItemNumber()
   {


       return ItemNumber;

   }

   void Player:: AddItem(string _Name , string _Description)
   {
       ItemNumber++;
       Inventory[ItemNumber].SetNAME(_Name);
       Inventory[ItemNumber].SetDESCRIPTION(_Description);


   }

   void Player::ShowInventory()
   {
      cout<<"Inventory : "<<endl<<endl;
      for(unsigned short int i=1 ; i<=ItemNumber; i++)
          cout<<i<<". "<<Inventory[i].GetNAME()<<": "<<Inventory[i].GetDESCRIPTION()<<endl;



   }
