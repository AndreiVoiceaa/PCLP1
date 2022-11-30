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



   void Enemy :: Drop(Player &p)
   {

     system("cls");
     p.AddCoins(GetCoins());
     p.AddExperience(GetExperience());

     unsigned short int RandomNumber = 1 + (rand() % 100);


     if(RandomNumber<=itemDroped.GetDROPCHANCE())
     {

     if(itemDroped.GetDROPEDSTATE()==false)
     {
         cout<<"Ai primit: "<<itemDroped.GetNAME()<<endl<<endl;
         cout<<"Descriere: "<<itemDroped.GetDESCRIPTION()<<endl<<endl<<"+ Coins: "<<GetCoins()<<" si "<<GetExperience()<<" XP"<<endl<<endl;

         p.AddItem(itemDroped.GetNAME() , itemDroped.GetDESCRIPTION());
         p.AddStat(itemDroped.GetAddMaxHealth() , itemDroped.GetAddPhysicalDamage() , itemDroped.GetAddMagicalDamage() ,
                        itemDroped.GetAddPhysicalArmor() , itemDroped.GetAddMagicalArmor() , itemDroped.GetAddEvasion() );
         itemDroped.SetDROPEDSTATE(true);



     } else cout<<"Ai obtinut deja item-ul acestui inamic!"<<endl<<endl<<"Dar ai primit: "<<GetCoins()<<" Coins si "<<GetExperience()<<" XP"<<endl<<endl;

     }
     else
     {
         cout<<"Nu ai obtinut niciun item in urma luptei"<<endl<<endl<<"Dar ai primit: "<<GetCoins()<<" Coins si "<<GetExperience()<<" XP"<<endl<<endl;

     }
   }


   string Enemy :: GetName()
   {

       return EnemyName;

   }




