#include "Player.h"
#include <windows.h>
#include <winuser.h>
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




   void Player::Defeat()
   {
      cout<<endl<<"Ai pierdut!"<<endl;
      system("pause");
      PostMessage(GetConsoleWindow(), WM_CLOSE, 0, 0); //inchide consola


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


   void Player :: LevelUp(list<Perk> &p , Handlers _MainHandle)
{


    int AdditionalXP=GetExperience()-ExperienceLimit;
    AddLevel(1);
    SetExperience(AdditionalXP);
    ExperienceLimit=ExperienceLimit*2-ExperienceLimit/2;
    cout<<"Ai crescut un nivel !! "<<endl<<"Nivel actual: "<<GetLevel()<<" , mai ai "<<ExperienceLimit<<" XP pana la urmatorul nivel."<<endl<<endl;



    unsigned short int i=0;
    unsigned short int pi=0;
    unsigned short int ui=0;
    list<Perk>::iterator it = p.begin();


    for(it; it!=p.end(); ++it)
    {

        i++;
        if(i<=GetLevel() && it->GetActiveState()==false)
        {

        if(pi==0)
        pi=i;
        else
        ui=i;

        cout<<it->GetName()<<": "<<it->GetDescription()<<endl<<endl;
        }


    }


    if(pi<ui)
    {


    if(_MainHandle.InputHandler("Alege Perk-ul (1 sau 2)" , 2)==1)
            {

             it = p.begin();
              std::advance(it , pi-1);
              AddPerk(*it);


            }
            else{
                 it = p.begin();
                std::advance(it , ui-1);
                AddPerk(*it);
            }



    }else
    {
        if(pi!=0)
        {


              it = p.begin();
              std::advance(it , pi-1);
              AddPerk(*it);

        }
    }

    it->SetActiveState(true);


}


void Player :: BuyStats(Handlers _MainHandle , int &_StatPrice)
{

    while(GetCoins()>=_StatPrice)
   {


   if(_MainHandle.InputHandler("Doresti sa folosesti banii castigati pentru a imbunatati player-ul? (1-DA , 2-NU)"  , 2)==1)
   {



       system("cls");

       ShowStats();


       cout<<"Pret pentru upgrade: "<<_StatPrice<<endl;
       cout<<"1. Maximum Health (+"<<BuyMaxHealthValue<<")"<<endl;
       cout<<"2. Physical Damage (+"<<BuyPhysicalDamageValue<<")"<<endl;
       cout<<"3. Magical Damage (+"<<BuyMagicalDamageValue<<")"<<endl;
       cout<<"4. Physical Armor (+"<<BuyPhysicalArmorValue<<")"<<endl;
       cout<<"5. Magical Armor (+"<<BuyMagicalArmorValue<<")"<<endl;

      unsigned short int index = _MainHandle.InputHandler("Ce caracteristica doresti sa imbunatatesti?" , 5);

       if(index==1)AddStat(BuyMaxHealthValue ,0 ,0 ,0 ,0 ,0);
       else if(index==2)AddStat(0 , BuyPhysicalDamageValue ,0 ,0 ,0 ,0);
       else if (index==3)AddStat(0 , 0 , BuyMagicalDamageValue ,0 ,0 ,0);
       else if (index==4)AddStat(0 , 0 , 0 , BuyPhysicalArmorValue ,0 ,0);
       else if (index==5)AddStat(0 , 0 , 0 , 0 , BuyMagicalArmorValue ,0);

      SpendCoins(_StatPrice);
      _StatPrice++;

      system("cls");

   }else break;

 }

}

