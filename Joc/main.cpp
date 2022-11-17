#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include <cstdlib>
#include <ctime>

using namespace std;


/*
 Item id list :

 1. Sabia (Stats)
 2.
 3.
 .....


*/




const unsigned short int LungimeMaximaVectorPerks = 10;
const unsigned short int LungimeMaximaInventar = 10;



void ErrorHandler( int ErrorNumber)
{

    if(ErrorNumber==1)
    {

       cout<<"Input Gresit"<<" -ErrorNumber ("<<ErrorNumber<<")"<<endl<<endl;

    }



       system("pause");
       system("cls");


}


string HandleInput(string Question)
{

    ReiaRaspuns:
    cout<<Question<<endl<<endl;
    try {
    string Raspuns=" ";
    cin>>Raspuns;
    if(Raspuns=="1")
        return Raspuns;
    else if(Raspuns!="2")
    {
        throw (1);
    }

    return Raspuns;

    }
    catch ( int MesajEroare) {

    ErrorHandler(MesajEroare);
    goto ReiaRaspuns;


    }



}


class stats
{
  public:
  short int health;
  unsigned short int Maxhealth;
  unsigned short int PhysicalDamage;
  unsigned short int MagicalDamage;
  unsigned short int MagicalArmor;
  unsigned short int PhysicalArmor;
  unsigned short int Level;
  unsigned short int Evasion;
  int Coins;
  int Experience;

  public: void ShowStats()
  {
      cout<<endl<<"Maxhealth: "<<Maxhealth<<endl<<"PhysicalDamage: "<<PhysicalDamage<<endl<<"MagicalDamage: "<<MagicalDamage<<endl<<"MagicalArmor: "
      <<MagicalArmor<<endl<<"PhysicalArmor: "<<PhysicalArmor<<endl<<"Level : "<<Level<<endl<<"Coins: "<<Coins<<endl<<"Exp: "<<Experience<<endl;



  }

  public:
  stats(unsigned short int _Maxhealth , unsigned short int _PhysicalDamage , unsigned short int _MagicalDamage , unsigned short int _PhysicalArmor,
        unsigned short int _MagicalArmor , unsigned short int _Evasion , unsigned short int _Level , int _Coins , int _Experience )
  {
      Maxhealth = _Maxhealth;
      PhysicalDamage = _PhysicalDamage;
      MagicalDamage = _MagicalDamage;
      PhysicalArmor = _PhysicalArmor;
      MagicalArmor = _MagicalArmor;
      Evasion = _Evasion;
      Level = _Level;
      Coins=_Coins;
      Experience=_Experience;
      health=Maxhealth;



  }
  stats(){
     health=100;
     Maxhealth=100;
     PhysicalDamage=1;
     MagicalDamage=1;
     PhysicalArmor=0;
     MagicalArmor=0;
     Evasion=0;
     Level=1;
     Evasion=0;
     Coins=0;
     Experience=0;

  }


};


class Player : public stats {

  public:
   int ExperienceLimit;

   public: void TakeDamage(unsigned short int EnemyPhysicalDamage , unsigned short int EnemyMagicalDamage)
   {
       this->health-=EnemyMagicalDamage;
       this->health-=EnemyPhysicalDamage;


   }

   public: void Defeat()
   {
       system("exit");

   }

   Player(unsigned short int _Maxhealth , unsigned short int _PhysicalDamage , unsigned short int _MagicalDamage , unsigned short int _PhysicalArmor,
        unsigned short int _MagicalArmor , unsigned short int _Evasion , unsigned short int _Level , int _Coins , int _Experience , int _ExperienceLimit)
   :stats(_Maxhealth , _PhysicalDamage , _MagicalDamage , _PhysicalArmor , _MagicalArmor, _Evasion ,  _Level ,  _Coins ,  _Experience ){

       ExperienceLimit=_ExperienceLimit;
   }

   Player(){
       ExperienceLimit=100;

   }

}player;


class Item
{
    public:
    string Name;
    string Description;
    unsigned short int DropChance;
    bool Droped=false;
    unsigned short int AddMaxHealth;
    unsigned short int AddPhysicalDamage;
    unsigned short int AddMagicalDamage;
    unsigned short int AddPhysicalArmor;
    unsigned short int AddMagicalArmor;
    unsigned short int AddEvasion;



    public:
        void AddStat()

        {
             player.Maxhealth+=AddMaxHealth;
             player.PhysicalDamage+=AddPhysicalDamage;
             player.MagicalDamage+=AddMagicalDamage;
             player.PhysicalArmor+=AddPhysicalArmor;
             player.MagicalArmor+=AddMagicalArmor;
             player.Evasion += AddEvasion;

        }


    Item(string _Name , string _Description , unsigned short int _DropChance ,unsigned short int _AddMaxHealth ,unsigned short int _AddPhysicalDamage ,unsigned short int _AddMagicalDamage ,unsigned short int _AddPhysicalArmor ,
         unsigned short int _AddMagicalArmor ,unsigned short int _AddEvasion)
    {
        Name=_Name;
        Description=_Description;
        DropChance=_DropChance;
        AddMaxHealth=_AddMaxHealth;
        AddPhysicalDamage=_AddPhysicalDamage;
        AddMagicalDamage=_AddMagicalDamage;
        AddPhysicalArmor=_AddPhysicalArmor;
        AddMagicalArmor=_AddMagicalArmor;
        AddEvasion=_AddEvasion;


    }

     Item()
     {

         DropChance=0;
         AddMaxHealth=0;
         AddPhysicalDamage=0;
         AddMagicalDamage=0;
         AddPhysicalArmor=0;
         AddMagicalArmor=0;
         AddEvasion=0;
         Name="Default item name";
         Description="Default item description";


     }



};

Item Inventory[LungimeMaximaInventar];
int ItemNumber=0;


class Enemy : public stats {

   public:
       Item itemDroped;
       string EnemyName;


   public: void TakeDamage(unsigned short int PlayerPhysicalDamage, unsigned short int PlayerMagicalDamage)
   {
       this->health-=PlayerMagicalDamage;
       this->health-=PlayerPhysicalDamage;

   }


   public: void Defeat()
   {

       //Probabilitati

       Drop();
   }

   public: void Drop()
   {

     player.Coins+=this->Coins;
     player.Experience+=this->Experience;



     unsigned short int RandomNumber = 1 + (rand() % 100);


     if(RandomNumber<=itemDroped.DropChance)
     {



     if(itemDroped.Droped==false)
     {
         cout<<"Ai primit: "<<itemDroped.Name<<endl<<endl;
         cout<<"Descriere: "<<itemDroped.Description<<endl<<endl<<"+ Coins: "<<this->Coins<<" si "<<this->Experience<<" XP"<<endl<<endl;
         ItemNumber++;
         Inventory[ItemNumber].Name = itemDroped.Name;
         Inventory[ItemNumber].Description = itemDroped.Description;
         itemDroped.AddStat();
         itemDroped.Droped=true;



     } else cout<<"Ai obtinut deja item-ul acestui inamic!"<<endl<<endl<<"Dar ai primit: "<<this->Coins<<" Coins si "<<this->Experience<<" XP"<<endl<<endl;

     }
     else
     {
         cout<<"Nu ai obtinut niciun item in urma luptei"<<endl<<endl<<"Dar ai primit: "<<this->Coins<<" Coins si "<<this->Experience<<" XP"<<endl<<endl;

     }
   }

    Enemy(unsigned short int _Maxhealth , unsigned short int _PhysicalDamage , unsigned short int _MagicalDamage , unsigned short int _PhysicalArmor,
        unsigned short int _MagicalArmor, unsigned short int _Evasion , unsigned short int _Level , int _Coins , int _Experience , string _EnemyName)
   :stats(_Maxhealth , _PhysicalDamage , _MagicalDamage , _PhysicalArmor , _MagicalArmor , _Evasion ,  _Level ,  _Coins ,  _Experience ){
    EnemyName=_EnemyName;

   }

    Enemy(){
    EnemyName="inamic";

    }
}enemy;

struct Perk
{
    string Name;
    string Description;
    //Daca nivelul este 1 primeste perk-ul a(+descriere) / alege dintre perk-ul a si b (+descriere la fiecare)
    //Probabil afisam un vector cu integeri care rep perk-urile . Dupa alegerea unui perk se sterge din acesta indicele si se adauga in altul
    //iar la cresterea in nivel se adauga elemente in vector .


}perks[LungimeMaximaVectorPerks-1];




void LevelUp()
{

    int AdditionalXP=player.Experience-player.ExperienceLimit;
    player.Level++;
    player.Experience=0+AdditionalXP;
    player.ExperienceLimit=player.ExperienceLimit*2-player.ExperienceLimit/2;
    cout<<"Ai crescut un nivel !! "<<endl<<"Nivel actual: "<<player.Level<<" , mai ai "<<player.ExperienceLimit<<" XP pana la urmatorul nivel."<<endl<<endl;

    /*
    unsigned short int indexare=0;
    unsigned short int x=0;
    unsigned short int alegere=0;


     TP:
     for(unsigned short int i=x; i<player.Level+1 && player.Level<=LungimeMaximaVectorPerks-1; i++)
     {

         cout<<++indexare<<"."<<perks[i].Name<<endl;
         cout<<perks[i].Description<<endl;
         if(i==player.Level){
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
      if(player.Level<LungimeMaximaVectorPerks)
      x++;


    cout<<"Perk-uri detinute:"<<endl;
    for(unsigned short int i=0; i<=x; i++)
    {
      cout<<i+1<<"."<<perks[i].Name<<endl;

    }

 */

}

void InitializareDate()
{
    //initializare player
    player = Player(100 , 50 , 0 , 0 , 0 , 80 , 1 , 0 , 0 , 100);
    //inamicul este initializat inainte de lupta
    enemy = Enemy(80 , 2 , 0 ,0 ,0 , 19 , 2 , 10 , 24 , "Bear");

    enemy.itemDroped = Item("Potir" , "Ofera 3 physical damage" , 100 , 0 , 3 , 0 , 0 , 0 , 0);



    //Perks



    perks[0].Name = "Mirror Force";
    perks[0].Description = "It reflects damage back to the attacker";

    perks[1].Name = "Radiance";
    perks[1].Description = "Does magical damage over time to the enemy";

    perks[2].Name = "Bleed";
    perks[2].Description = "Critical hits cause the enemy to bleed every round";


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


void ShowStatsBeforeCombat(Enemy _enemy)
{
 cout<<"                                                                                                        Player|"<<_enemy.EnemyName<<" Health: "<<player.health<<"|"<<_enemy.health<<endl<<endl;
 cout<<"   Player|"<<_enemy.EnemyName<<" Stats: "<<endl<<endl;
 cout<<"Maximum Health: "<<player.Maxhealth<<"|"<<_enemy.Maxhealth<<endl;
 cout<<"Physical Damage: "<<player.PhysicalDamage<<"|"<<_enemy.PhysicalDamage<<endl;
 cout<<"Magical Damage: "<<player.MagicalDamage<<"|"<<_enemy.MagicalDamage<<endl;
 cout<<"Physical Armor: "<<player.PhysicalArmor<<"|"<<_enemy.PhysicalArmor<<endl;
 cout<<"Magical Armor: "<<player.MagicalArmor<<"|"<<_enemy.MagicalArmor<<endl;
 cout<<"Evasion: "<<player.Evasion<<"%|"<<_enemy.Evasion<<"%"<<endl;
 cout<<"Level: "<<player.Level<<"|"<<_enemy.Level<<endl;
 cout<<"Experience: "<<player.Experience<<endl;
 cout<<"Coins: "<<player.Coins<<endl;

 cout<<endl;

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

    system("cls");
    cout<<endl;
    cout<<endl;
    cout<<endl;
cout<<"                              "<<endl;
cout<<"                              "<<endl;
cout<<"                              "<<endl;
cout<<"                              "<<endl;
cout<<"                              "<<endl;
cout<<"                              "<<endl;
cout<<"                              "<<endl;
cout<<"                              "<<endl;

cout<<"                                                                     /@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@("<<endl;
Sleep(1000);
cout<<"                                                                     /@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@("<<endl;
Sleep(1000);
cout<<"                                                                     /@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@("<<endl;
Sleep(1000);
cout<<"                                                                     /@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@("<<endl;
Sleep(delay);
cout<<"                                                                                                       "<<endl;
Sleep(delay);
cout<<"                                                                     ,###########################################################################*"<<endl;
Sleep(delay);
cout<<"                                                                     /@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@("<<endl;
Sleep(delay);
cout<<"                                                                     /@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@("<<endl;
Sleep(delay);
cout<<"                                                                     /@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@("<<endl;
Sleep(delay);
cout<<"                                                                                                       "<<endl;
Sleep(delay);
cout<<"                                                                                                       "<<endl;
Sleep(delay);
cout<<"                                                                     /@@@@@@@@.    %@@@@@@@&    @@@@@@@@@@@@@@@@@@@@@@(     &@@@@@@@%    @@@@@@@@("<<endl;
Sleep(delay);
cout<<"                                                                     /@@@@@@@@.    %@@@@@@@&    @@@@@@@@@@@@@@@@@@@@@@(     &@@@@@@@%    @@@@@@@@("<<endl;
Sleep(delay);
cout<<"                                                                     /@@@@@@@@.    %@@@@@@@&    @@@@@@@@@@@@@@@@@@@@@@(     &@@@@@@@%    @@@@@@@@("<<endl;
Sleep(delay);
cout<<"                                                                     /@@@@@@@@.    %@@@@@@@&    @@@@@@@.       @@@@@@@(     &@@@@@@@%    @@@@@@@@("<<endl;
Sleep(delay);
cout<<"                                                                     /@@@@@@@@.    %@@@@@@@&    @@@@@@@.       @@@@@@@(     &@@@@@@@%    @@@@@@@@("<<endl;
Sleep(delay);
cout<<"                                                                     /@@@@@@@@.    %@@@@@@@&    @@@@@@@.       @@@@@@@(     &@@@@@@@%    @@@@@@@@("<<endl;
Sleep(delay);
cout<<"                                                                     /@@@@@@@@.    %@@@@@@@&    @@@@@@@@@@@@@@@@@@@@@@(     &@@@@@@@%    @@@@@@@@("<<endl;
Sleep(delay);
cout<<"                                                                     /@@@@@@@@.    %@@@@@@@&    @@@@@@@@@@@@@@@@@@@@@@(     &@@@@@@@%    @@@@@@@@("<<endl;
Sleep(delay);
cout<<"                                                                     /@@@@@@@@.    %@@@@@@@&    @@@@@@@@@@@@@@@@@@@@@@(     &@@@@@@@%    @@@@@@@@("<<endl;
Sleep(delay);
cout<<"                                                                     /@@@@@@@@.    %@@@@@@@&                                &@@@@@@@%    @@@@@@@@("<<endl;
Sleep(delay);
cout<<"                                                                     /@@@@@@@@.    %@@@@@@@&                                &@@@@@@@%    @@@@@@@@("<<endl;
Sleep(delay);
cout<<"                                                                     /@@@@@@@@.    %@@@@@@@&    @@@@@@@@@    (@@@@@@@@      &@@@@@@@%    @@@@@@@@("<<endl;
Sleep(delay);
cout<<"                                                                     /@@@@@@@@.    %@@@@@@@&    @@@@@@@@@    (@@@@@@@@      &@@@@@@@%    @@@@@@@@("<<endl;
Sleep(delay);
cout<<"                                                                     /@@@@@@@@.    %@@@@@@@&    @@@@@@@@@    (@@@@@@@@      &@@@@@@@%    @@@@@@@@("<<endl;
Sleep(delay);
cout<<"                                                                     /@@@@@@@@.    %@@@@@@@&    @@@@@@@@@    (@@@@@@@@      &@@@@@@@%    @@@@@@@@("<<endl;
Sleep(delay);
cout<<"                                                                     /@@@@@@@@.    %@@@@@@@&    @@@@@@@@@    (@@@@@@@@      &@@@@@@@%    @@@@@@@@("<<endl;
Sleep(delay);
cout<<"                                                                     /@@@@@@@@.    %@@@@@@@&    @@@@@@@@@    (@@@@@@@@      &@@@@@@@%    @@@@@@@@("<<endl;
Sleep(delay);
cout<<"                                                                     /@@@@@@@@.    %@@@@@@@&    @@@@@@@@@    (@@@@@@@@      &@@@@@@@%    @@@@@@@@("<<endl;
Sleep(delay);
cout<<"                                                                     /@@@@@@@@.    %@@@@@@@&    @@@@@@@@@    (@@@@@@@@      &@@@@@@@%    @@@@@@@@("<<endl;
Sleep(delay);
cout<<"                                                                     .********     ,********    *********    .********      ********,    ********."<<endl;

cout<<endl;
cout<<endl;
cout<<endl;

Sleep(3000);
system("cls");
    }

}




void Combat(Enemy _enemy) //+alti factori posibili care modifica damage-ul
{

    Grind:

        system("cls");
        player.health=player.Maxhealth;
        _enemy.health=_enemy.Maxhealth;



    while(player.health>0 && _enemy.health>0)
    {

   ///Player Turn

   unsigned short int RandomNumber = 1 + (rand() % 100);
   cout<<RandomNumber<<endl;

   if(RandomNumber>_enemy.Evasion)
   {


   _enemy.TakeDamage(player.PhysicalDamage , player.MagicalDamage);
   ShowStatsBeforeCombat(_enemy);
   cout<<_enemy.EnemyName<<" a fost lovit cu "<<player.PhysicalDamage<<" physical damage si  "<<player.MagicalDamage<<" magical damage"<<endl<<endl;
   if(_enemy.health<=0)
   {
       _enemy.Defeat();
       break;
   }


   }else
   {
       ShowStatsBeforeCombat(_enemy);
       cout<<_enemy.EnemyName<<" s-a ferit de atac"<<endl<<endl;


   }
   system("pause");
   system("cls");

   ///Enemy Turn

    RandomNumber = 1 + (rand() % 100);
    cout<<RandomNumber<<endl;

    if(RandomNumber>player.Evasion)
    {
    player.TakeDamage(_enemy.PhysicalDamage , _enemy.MagicalDamage);
    ShowStatsBeforeCombat(_enemy);
    cout<<"Player-ul a fost lovit cu "<<_enemy.PhysicalDamage<<" physical damage si "<<_enemy.MagicalDamage<<" magical damage"<<endl<<endl;
    if(player.health<=0)
    {
        player.Defeat();
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


    if(player.Experience>=player.ExperienceLimit)
    {
        LevelUp();



    }


   if(HandleInput("Doresti sa lupti cu inamicul din nou? (1-DA , 2-NU)")=="1")
        goto Grind;








}




void Shop()
{



}

void Start()
{


   FullScreen();
   srand((unsigned) time(NULL)); //folosim srand pentru a nu genera de fiecare data aceleasi numere aleatorii
   InitializareDate();
  // Animatie (1);

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


    Combat(enemy);




    return 0;
}
