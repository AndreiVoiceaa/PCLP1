#include <iostream>
#include <windows.h>
#include <mmsystem.h>

using namespace std;


/*
 Item id list :

 1. Sabia (Stats)
 2.
 3.
 .....


*/

/*
 Perk id list :

 1. ArmorBoost (effect)
 2.
 3.
 .....


*/



struct stats
{
  int health = 100;
  int damage = 1;
  int armor  = 0;

   struct
   {
     int coins = 0;
     int experience = 0;
     int itemId = 0;


   }drop;

  //noroc (critical hits , evasion)

}PlayerStats,EnemyStats;

void Perks()
{
    //Daca nivelul este 1 primeste perk-ul a(+descriere) / alege dintre perk-ul a si b (+descriere la fiecare)
    //Probabil afisam un vector cu integeri care rep perk-urile . Dupa alegerea unui perk se sterge din acesta indicele si se adauga in altul
    //iar la cresterea in nivel se adauga elemente in vector .


}

void Plot(int chapter)
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


void Inventory()
{

    //vector cu itemele stocate


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


int Combat(int damageAttacker , int armorDefender) //+alti factori posibili care modifica damage-ul
{


   return damageAttacker;
}

void Shop()
{



}

void Start()
{

   FullScreen();

   PlaySound(TEXT("MainMusic.wav") , NULL , SND_FILENAME | SND_ASYNC | SND_LOOP);
   //Funcția PlaySound redă un sunet specificat de numele fișierului, resursa sau evenimentul de sistem dat.
   //TEXT Identifică un șir ca Unicode atunci când UNICODE este definit de o directivă de preprocesor în timpul compilării.
   //În caz contrar, macro-ul identifică un șir ca șir ANSI. Unicode este formatul standard de facto de codificare și interpretare
   //a datelor binare în format text, având drept țel final să cuprindă toate caracterele din toate limbile globului.
   //SND_FILENAME = Dacă fișierul nu poate fi găsit, funcția redă sunetul implicit, cu excepția cazului în care este setat indicatorul SND_NODEFAULT.
   //SND_ASYNC = Sunetul este redat asincron și PlaySound revine imediat după începerea sunetului.


}


int main()
{



    Start();
    system("pause");


    return 0;
}
