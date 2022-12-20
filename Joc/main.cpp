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
#include "Combat.h"

using namespace std;

Player player;
Enemy Bear , Giant_Bear;
Animator Animation_handler;
list<Perk> AllPerks;
HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
Combat CombatSystem;

const unsigned short int LogoAnimationIndex=1;


void InitializareDate()
{
    system("color D");

    player = Player(100 , 10 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , "Player" , 100 , 0);
    Bear = Enemy(50 , 2 , 0 , 0 , 0 , 0 , 1 , 1 , 45 , "Bear");
    Bear.itemDroped = Item("Potirul Aventurierului Incepator" , "+2 Magical Damage , +1 Physical Armor , +1 Magical Armor , +1 Evasion" , 100 , 0 , 0 , 2 , 1 , 1 , 1);
    Giant_Bear = Enemy(60 , 3 , 1 , 1 , 0 , 5 , 1 , 1 , 55 , "Giant Bear");
    Giant_Bear.itemDroped = Item("Bear Fur" , "Gives 20 max health" , 50 , 20 , 0 , 0 , 0 , 0 , 0 );


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

    Introducere:
    //Plot(1);

    Capitol1:
    //Plot(2);
    CombatSystem.Fight(player,Bear,AllPerks);

    Capirol2:
    //Plot(3);
    CombatSystem.Fight(player,Giant_Bear,AllPerks);

    return 0;
}
