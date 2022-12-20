#include "Stats.h"


using namespace std;

Stats::Stats()
{
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
     Name="default_name";

  }


Stats::Stats(unsigned short int _Maxhealth , unsigned short int _PhysicalDamage , unsigned short int _MagicalDamage , unsigned short int _PhysicalArmor,
        unsigned short int _MagicalArmor , unsigned short int _Evasion , unsigned short int _Level , int _Coins , int _Experience , string _Name)
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
      Name=_Name;

}

void Stats :: DrainHealth(unsigned short int PhysicalAmount , unsigned short int MagicalAmount)
{
      health = health - (PhysicalAmount + MagicalAmount);
}

string Stats::GetName()
{
    return Name;
}

unsigned short int Stats :: GetMAXHEALTH()
{
      return Maxhealth;
}

int Stats:: GetCoins()
{
    return Coins;
}

int Stats:: GetExperience()
{
    return Experience;
}

short int Stats :: GetHEALTH()
{
      return health;
}

unsigned short int Stats :: GetLevel()
{
    return Level;
}

unsigned short int Stats :: GetPHYSICALDAMAGE()
{
      return PhysicalDamage;
}

unsigned short int Stats :: GetMAGICALDAMAGE()
{
    return MagicalDamage;
}

unsigned short int Stats :: GetPHYSICALARMOR()
{
    return PhysicalArmor;
}

unsigned short int Stats :: GetMAGICALARMOR()
{
    return MagicalArmor;
}

unsigned short int Stats :: GetEVASION()
{
    return Evasion;
}

void Stats::SetName(string _Name)
{
    Name=_Name;
}

void Stats :: SetExperience( int valoare)
{
    Experience=valoare;
}

void Stats :: AddExperience(int valoare)
{
    Experience+=valoare;
}

void Stats :: AddLevel(unsigned short int valoare)
{
    Level+=valoare;
}

void Stats :: AddCoins( int valoare)
{
    Coins+=valoare;
}

void Stats :: SpendCoins (int valoare)
{
    Coins-=valoare;
}

void Stats::RestoreHealth()
{
      health=Maxhealth;
}

void Stats:: AddStat(unsigned short int AddMaxHealth,
    unsigned short int AddPhysicalDamage,
    unsigned short int AddMagicalDamage,
    unsigned short int AddPhysicalArmor,
    unsigned short int AddMagicalArmor,
    unsigned short int AddEvasion)
{
    Maxhealth+=AddMaxHealth;
    PhysicalDamage+=AddPhysicalDamage;
    MagicalDamage+=AddMagicalDamage;
    PhysicalArmor+=AddPhysicalArmor;
    MagicalArmor+=AddMagicalArmor;
    Evasion += AddEvasion;
}


void Stats :: AddPerk(Perk perk)
{
    perks.push_back(perk);
}

void Stats :: ShowPerks()
{
    cout<<"Perks: "<<endl<<endl;
    for(list<Perk>::iterator it = perks.begin(); it!=perks.end(); ++it)
    cout<<it->GetName()<<": "<<it->GetDescription()<<endl;
    cout<<endl;
}


void Stats::ShowStats()
{
      cout<<endl<<"Maxhealth: "<<Maxhealth<<endl<<"PhysicalDamage: "<<PhysicalDamage<<endl<<"MagicalDamage: "<<MagicalDamage<<endl<<"PhysicalArmor: "
      <<PhysicalArmor<<endl<<"MagicalArmor: "<<MagicalArmor<<endl<<"Evasion: "<<Evasion<<"%"<<endl<<"Level : "<<Level<<endl<<"Exp: "<<Experience<<endl<<"Coins: "<<Coins<<endl<<endl;
}



void Stats :: TakeDamage(Stats* Atacator)
{
    const unsigned short int RadianceDamage=10;
    unsigned short int TotalPhysicalDamage = Atacator->GetPHYSICALDAMAGE();
    unsigned short int TotalMagicalDamage = Atacator->GetMAGICALDAMAGE();

    ///Atacator perks
    for(list<Perk>::iterator it = Atacator->perks.begin(); it!=Atacator->perks.end(); ++it)
        if(it->GetName()=="Radiance")
        {
            TotalMagicalDamage+=RadianceDamage;
            //cout<<"+"<<RadianceDamage<<" (Radiance Damage)"<<endl;
        }


    ///Aparator perks
    for(list<Perk>::iterator it = perks.begin(); it!=perks.end(); ++it)
        if(it->GetName()=="Mirror Force")
        {

            Atacator->DrainHealth( TotalPhysicalDamage , TotalMagicalDamage);
            //cout<<Atacator->GetName()<<" a fost lovit cu "<<TotalPhysicalDamage+TotalMagicalDamage<<" damage ca efect al perk-ului mirror force"<<endl;

        }

    health=health-(TotalPhysicalDamage + TotalMagicalDamage);
    //cout<<Atacator->GetName()<<" a lovit cu "<<TotalPhysicalDamage + TotalMagicalDamage<<" damage total"<<endl;

}

Stats* Stats :: ReturnStats()
{
    return this;
}




