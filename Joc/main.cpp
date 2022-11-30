#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include <cstdlib>
#include <ctime>
#include <list>
#include <iterator>

#include "Stats.h"
#include "Player.h"
#include "Item.h"
#include "Enemy.h"
#include "Perk.h"
#include "Animator.h"
#include "Handlers.h"

using namespace std;


Player player;
Enemy enemy;
Animator Animation_handler;
Handlers MainHandle;
list<Perk> AllPerks;

const unsigned short int LogoAnimationIndex=1;
int StatPrice = 1;

unsigned short int RNG(unsigned short int minim,unsigned short int maxim)
{


  return minim + (rand() % maxim);

}


void InitializareDate()
{

    player = Player(100 , 10 , 5 , 0 , 0 , 20 , 1 , 0 , 0 , 100 , 0);


    //Perks

    AllPerks.push_back(Perk("Mirror Force" , "It reflects damage back to the attacker" , false));
    AllPerks.push_back(Perk("Radiance" , "Does magical damage over time to the enemy" , false));
    AllPerks.push_back(Perk("Bleed" , "Critical hits cause the enemy to bleed every round" , false));
    AllPerks.push_back(Perk("Tougness" , "Incresead armor and health" , false));
    //list<Perk>::iterator it = AllPerks.begin();
    //player.AddPerk(*it);
    //std::advance(it,1);

}


void Plot(unsigned short chapter)
{
    /*
    if(chapter==1)
    {
     cout<<"...."<<endl;

    }
    else if(chapter == 2)
    {
     cout<<"...."<<endl;

    }
    */

}


void ShowStatsBeforeCombat(Enemy _enemy)
{
 cout<<"                                                                                                        Player|"<<_enemy.GetName()<<" Health: "<<player.GetHEALTH()<<"|"<<_enemy.GetHEALTH()<<endl<<endl;
 cout<<"   Player|"<<_enemy.GetName()<<" Stats: "<<endl<<endl;
 cout<<"Maximum Health: "<<player.GetMAXHEALTH()<<"|"<<_enemy.GetMAXHEALTH()<<endl;
 cout<<"Physical Damage: "<<player.GetPHYSICALDAMAGE()<<"|"<<_enemy.GetPHYSICALDAMAGE()<<endl;
 cout<<"Magical Damage: "<<player.GetMAGICALDAMAGE()<<"|"<<_enemy.GetMAGICALDAMAGE()<<endl;
 cout<<"Physical Armor: "<<player.GetPHYSICALARMOR()<<"|"<<_enemy.GetPHYSICALARMOR()<<endl;
 cout<<"Magical Armor: "<<player.GetMAGICALARMOR()<<"|"<<_enemy.GetMAGICALARMOR()<<endl;
 cout<<"Evasion: "<<player.GetEVASION()<<"%|"<<_enemy.GetEVASION()<<"%"<<endl;
 cout<<"Level: "<<player.GetLevel()<<"|"<<_enemy.GetLevel()<<endl;
 cout<<"Experience: "<<player.GetExperience()<<endl;
 cout<<"Coins: "<<player.GetCoins()<<endl;

 cout<<endl;
 player.ShowInventory();
 cout<<endl;
 player.ShowPerks();

 cout<<"Combat Log: "<<endl<<endl;
}


void FullScreen()
{

   //system() este apelat pentru a folosi o comanda din sistemul de operare

   system("mode con COLS=700"); //comanda mode este utilizata pentru a vizualiza sau modifica un port sau o setare de afisare.

   SendMessage(GetConsoleWindow(),WM_SYSKEYDOWN,VK_RETURN,0x20000000); //Functie care transmite un mesaj catre fereastra si care necesita 4 parametrii:
                                                                       //un handle returnat de functia GetConsoleWindow(),
                                                                       //mesajul WM_SYSKEYDOWN (transmis pentru a activa fereastra),
                                                                       //un Virtual-Key (VK_RETURN - care reprezinta tasta enter),
                                                                       //lParam un parametru (pe 32 biti). Ultimii 2 parametrii depind de tipul
                                                                       //mesajului si furnizeaza informatii suplimentare referitoare la mesaj.



}


void Combat(Enemy _enemy)
{

    Grind:

        system("cls");
        player.RestoreHealth();
        _enemy.RestoreHealth();



    while(player.GetHEALTH()>0 && _enemy.GetHEALTH()>0)
    {

   ///Player Turn

   unsigned short int RandomNumber = RNG(1,100);

   if(RandomNumber>_enemy.GetEVASION())
   {

   _enemy.TakeDamage(player.ReturnStats());
   ShowStatsBeforeCombat(_enemy);
   cout<<_enemy.GetName()<<" a fost lovit cu "<<player.GetPHYSICALDAMAGE()<<" physical damage si  "<<player.GetMAGICALDAMAGE()<<" magical damage"<<endl<<endl;


   if(player.GetHEALTH()<=0)
    {
        player.Defeat();
        break;
    }
   else if(_enemy.GetHEALTH()<=0)
   {

       _enemy.Drop(player);
       break;
   }


   }else
   {
       ShowStatsBeforeCombat(_enemy);
       cout<<_enemy.GetName()<<" s-a ferit de atac"<<endl<<endl;


   }
   system("pause");
   system("cls");

   ///Enemy Turn

    RandomNumber = RNG(1,100);

    if(RandomNumber>player.GetEVASION())
    {
    player.TakeDamage(_enemy.ReturnStats());
    ShowStatsBeforeCombat(_enemy);
    cout<<"Player-ul a fost lovit cu "<<_enemy.GetPHYSICALDAMAGE()<<" physical damage si "<<_enemy.GetMAGICALDAMAGE()<<" magical damage"<<endl<<endl;
    if(player.GetHEALTH()<=0)
    {
        player.Defeat();
        break;
    }
   else if(_enemy.GetHEALTH()<=0)
   {

       _enemy.Drop(player);
       break;
   }

    }else
    {
     ShowStatsBeforeCombat(_enemy);
     cout<<"Player-ul s-a ferit de atac"<<endl<<endl;

    }
     system("pause");
     system("cls");



    }




    if(player.GetExperience()>=player.ExperienceLimit)
    {
        player.LevelUp(AllPerks , MainHandle);



    }



 while(player.GetCoins()>=StatPrice)
 {


   if(MainHandle.InputHandler("Doresti sa folosesti banii castigati pentru a imbunatati player-ul? (1-DA , 2-NU)"  , 2)==1)
   {



       system("cls");

       player.ShowStats();


       cout<<"Pret pentru upgrade: "<<StatPrice<<endl;
       cout<<"1. Maximum Health (+"<<player.BuyMaxHealthValue<<")"<<endl;
       cout<<"2. Physical Damage (+"<<player.BuyPhysicalDamageValue<<")"<<endl;
       cout<<"3. Magical Damage (+"<<player.BuyMagicalDamageValue<<")"<<endl;
       cout<<"4. Physical Armor (+"<<player.BuyPhysicalArmorValue<<")"<<endl;
       cout<<"5. Magical Armor (+"<<player.BuyMagicalArmorValue<<")"<<endl;

      player.BuyStats(MainHandle.InputHandler("Ce caracteristica doresti sa imbunatatesti?" , 5));
      player.SpendCoins(StatPrice);
      StatPrice++;

      system("cls");

   }else break;

 }

system("cls");

   if(MainHandle.InputHandler("Doresti sa lupti cu inamicul din nou? (1-DA , 2-NU)" , 2)==1)
        goto Grind;



}


void Start()
{


   FullScreen();
   srand((unsigned) time(NULL));
   InitializareDate();
  // Animation_handler.PlayAnimation(LogoAnimationIndex);

   PlaySound(TEXT("MainMusic.wav") , NULL , SND_FILENAME | SND_ASYNC | SND_LOOP);

}


int main()
{
    Start();
    //plot
    //tag
    //combat
    //daca pierde goto tag
    //plot2
    //tag2
    //combat
    //daca pierde intreaba la ce tag urmeaza sa se intoarca pentru a efectua lupta(daca merge la un tag in care povestea a fost spusa , sari peste)

    enemy = Enemy(80 , 2 , 10 ,0 ,0 , 19 , 2 , 10 , 24 , "Bear");
    enemy.itemDroped = Item("Potir" , "Ofera 3 physical damage" , 100 , 0 , 3 , 0 , 0 , 0 , 0);
    Combat(enemy);
    system("cls");
    enemy = Enemy(120 , 10 , 2 , 2 , 3 , 30 , 3 , 50 , 39 , "Giant Bear");
    enemy.itemDroped = Item("Bear Fur" , "Gives 20 max health" , 50 , 20 , 0 , 0 , 0 , 0 , 0 );
    Combat(enemy);
    system("cls");
    system("pause");

    return 0;
}
