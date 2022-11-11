#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include<cstring>

using namespace std;


/*
 Item id list :

 1. Sabia (Stats)
 2.
 3.
 .....


*/



const unsigned short int LungimeMaximaNumePerk = 31;
const unsigned short int LungimeMaximaDescrierePerk = 256;
const unsigned short int LungimeMaximaVectorPerks = 10;




class stats
{
  public:
  unsigned short int health = 100;
  unsigned short int PhysicalDamage= 1;
  unsigned short int ExperienceDroped  = 0;
  unsigned short int MagicalDamage=0;
  unsigned short int MagicalArmor=0;
  unsigned short int PhysicalArmor=0;
  unsigned short int Level=1;
  unsigned short int Evasion=0;

  public: void ShowStats()
  {
      cout<<endl<<health<<endl<<PhysicalDamage<<endl<<ExperienceDroped<<endl<<MagicalDamage<<endl<<MagicalArmor<<endl<<PhysicalArmor<<endl<<Level<<endl<<Evasion ;
  }

  public:
  stats(unsigned short int _health , unsigned short int _damage , unsigned short int _armor)
  {
      health = _health;
      damage = _damage;
      armor = _armor;



  }
  stats(){


  }


};


class Player : public stats {

   public: void FunctieSpecifica()
   {
       cout<<"Acesta este clasa player-ului";

   }

   Player(unsigned short int _health , unsigned short int _damage , unsigned short int _armor)
   :stats(_health , _damage , _armor){


   }

   Player(){


   }

}player;


class Enemy : public stats {

   public: void FunctieSpecifica()
   {
       cout<<endl<<"Acesta este clasa Inamicului";

   }

    Enemy(unsigned short int _health , unsigned short int _damage , unsigned short int _armor)
    :stats(_health,_damage,_armor)
    {

    }

    Enemy(){


    }
}enemy;

struct Perk
{
    char Name[LungimeMaximaNumePerk];
    char Description[LungimeMaximaDescrierePerk];
    bool isActive = false;
    //Daca nivelul este 1 primeste perk-ul a(+descriere) / alege dintre perk-ul a si b (+descriere la fiecare)
    //Probabil afisam un vector cu integeri care rep perk-urile . Dupa alegerea unui perk se sterge din acesta indicele si se adauga in altul
    //iar la cresterea in nivel se adauga elemente in vector .


}perks[LungimeMaximaVectorPerks-1];


void LevelUp()
{
    unsigned short int indexare=0;
    unsigned short int x=0;
    unsigned short int alegere=0;
    unsigned short int level=1;//se inlocuieste cu PlayerStats.level

     TP:
     for(unsigned short int i=x; i<level+1 && level<=LungimeMaximaVectorPerks-1; i++)
     {

         cout<<++indexare<<"."<<perks[i].Name<<endl;
         cout<<perks[i].Description<<endl;
         if(i==level){
            cin>>alegere;
            if(alegere<1 || alegere>2)
            {
                indexare=0;
                system("cls");
                goto TP;
            }
            if(x!=alegere)
            {
                swap(perks[x] , perks[alegere+x-1]);

            }



         }
     }
      indexare=0;
      if(level<LungimeMaximaVectorPerks)
      x++;


    cout<<"Perk-uri detinute:"<<endl;
    for(unsigned short int i=0; i<=x; i++)
    {
      cout<<i+1<<"."<<perks[i].Name<<endl;

    }



}

void InitializareDate()
{

    //Perks

    strcpy(perks[0].Name , "Mirror Force");
    strcpy(perks[0].Description , "It reflects damage back to the attacker");

    strcpy(perks[1].Name , "Radiance");
    strcpy(perks[1].Description , "Does magical damage over time to the enemy");

    strcpy(perks[2].Name , "Bleed");
    strcpy(perks[2].Description , "Critical hits cause the enemy to bleed every round");


    //Items


    //Stats
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


void Animatie(int index)
{

    if(index==1)
    {


    const int delay = 60;
    system("pause");
    system("cls");
    cout<<endl;
    cout<<endl;
    cout<<endl;

cout<<"                          /@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@("<<endl;
Sleep(1000);
cout<<"                          /@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@("<<endl;
Sleep(1000);
cout<<"                          /@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@("<<endl;
Sleep(1000);
cout<<"                          /@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@("<<endl;
Sleep(delay);
cout<<"                                                                                                       "<<endl;
Sleep(delay);
cout<<"                          ,###########################################################################*"<<endl;
Sleep(delay);
cout<<"                          /@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@("<<endl;
Sleep(delay);
cout<<"                          /@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@("<<endl;
Sleep(delay);
cout<<"                          /@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@("<<endl;
Sleep(delay);
cout<<"                                                                                                       "<<endl;
Sleep(delay);
cout<<"                                                                                                       "<<endl;
Sleep(delay);
cout<<"                          /@@@@@@@@.    %@@@@@@@&    @@@@@@@@@@@@@@@@@@@@@@(     &@@@@@@@%    @@@@@@@@("<<endl;
Sleep(delay);
cout<<"                          /@@@@@@@@.    %@@@@@@@&    @@@@@@@@@@@@@@@@@@@@@@(     &@@@@@@@%    @@@@@@@@("<<endl;
Sleep(delay);
cout<<"                          /@@@@@@@@.    %@@@@@@@&    @@@@@@@@@@@@@@@@@@@@@@(     &@@@@@@@%    @@@@@@@@("<<endl;
Sleep(delay);
cout<<"                          /@@@@@@@@.    %@@@@@@@&    @@@@@@@.       @@@@@@@(     &@@@@@@@%    @@@@@@@@("<<endl;
Sleep(delay);
cout<<"                          /@@@@@@@@.    %@@@@@@@&    @@@@@@@.       @@@@@@@(     &@@@@@@@%    @@@@@@@@("<<endl;
Sleep(delay);
cout<<"                          /@@@@@@@@.    %@@@@@@@&    @@@@@@@.       @@@@@@@(     &@@@@@@@%    @@@@@@@@("<<endl;
Sleep(delay);
cout<<"                          /@@@@@@@@.    %@@@@@@@&    @@@@@@@@@@@@@@@@@@@@@@(     &@@@@@@@%    @@@@@@@@("<<endl;
Sleep(delay);
cout<<"                          /@@@@@@@@.    %@@@@@@@&    @@@@@@@@@@@@@@@@@@@@@@(     &@@@@@@@%    @@@@@@@@("<<endl;
Sleep(delay);
cout<<"                          /@@@@@@@@.    %@@@@@@@&    @@@@@@@@@@@@@@@@@@@@@@(     &@@@@@@@%    @@@@@@@@("<<endl;
Sleep(delay);
cout<<"                          /@@@@@@@@.    %@@@@@@@&                                &@@@@@@@%    @@@@@@@@("<<endl;
Sleep(delay);
cout<<"                          /@@@@@@@@.    %@@@@@@@&                                &@@@@@@@%    @@@@@@@@("<<endl;
Sleep(delay);
cout<<"                          /@@@@@@@@.    %@@@@@@@&    @@@@@@@@@    (@@@@@@@@      &@@@@@@@%    @@@@@@@@("<<endl;
Sleep(delay);
cout<<"                          /@@@@@@@@.    %@@@@@@@&    @@@@@@@@@    (@@@@@@@@      &@@@@@@@%    @@@@@@@@("<<endl;
Sleep(delay);
cout<<"                          /@@@@@@@@.    %@@@@@@@&    @@@@@@@@@    (@@@@@@@@      &@@@@@@@%    @@@@@@@@("<<endl;
Sleep(delay);
cout<<"                          /@@@@@@@@.    %@@@@@@@&    @@@@@@@@@    (@@@@@@@@      &@@@@@@@%    @@@@@@@@("<<endl;
Sleep(delay);
cout<<"                          /@@@@@@@@.    %@@@@@@@&    @@@@@@@@@    (@@@@@@@@      &@@@@@@@%    @@@@@@@@("<<endl;
Sleep(delay);
cout<<"                          /@@@@@@@@.    %@@@@@@@&    @@@@@@@@@    (@@@@@@@@      &@@@@@@@%    @@@@@@@@("<<endl;
Sleep(delay);
cout<<"                          /@@@@@@@@.    %@@@@@@@&    @@@@@@@@@    (@@@@@@@@      &@@@@@@@%    @@@@@@@@("<<endl;
Sleep(delay);
cout<<"                          /@@@@@@@@.    %@@@@@@@&    @@@@@@@@@    (@@@@@@@@      &@@@@@@@%    @@@@@@@@("<<endl;
Sleep(delay);
cout<<"                          .********     ,********    *********    .********      ********,    ********."<<endl;

cout<<endl;
cout<<endl;
cout<<endl;

Sleep(3000);
    }

}


int Combat(int damageAttacker , int armorDefender) //+alti factori posibili care modifica damage-ul
{
    //daca lvlup LevelUp();

   return damageAttacker;
}

void Shop()
{



}

void Start()
{


   FullScreen();
   InitializareDate();
   Animatie (1);

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
