#ifndef STATS_H
#define STATS_H
#include <list>
#include "Perk.h"


using namespace std;

class Stats
{
  public:

  void ShowStats();
  Stats();
  Stats(unsigned short int _Maxhealth , unsigned short int _PhysicalDamage , unsigned short int _MagicalDamage , unsigned short int _PhysicalArmor,
        unsigned short int _MagicalArmor , unsigned short int _Evasion , unsigned short int _Level , int _Coins , int _Experience );

  void AddStat(unsigned short int AddMaxHealth,
  unsigned short int AddPhysicalDamage,
  unsigned short int AddMagicalDamage,
  unsigned short int AddPhysicalArmor,
  unsigned short int AddMagicalArmor,
  unsigned short int AddEvasion);

  void AddCoins( int valoare);
  void AddExperience( int valoare);
  void AddLevel(unsigned short int valoare);
  void RestoreHealth();
  void SetExperience(int valoare);
  int GetExperience();
  int GetCoins();
  unsigned short int GetLevel();
  unsigned short int GetMAXHEALTH();
  unsigned short int GetPHYSICALDAMAGE();
  unsigned short int GetMAGICALDAMAGE();
  unsigned short int GetPHYSICALARMOR();
  unsigned short int GetMAGICALARMOR();
  unsigned short int GetEVASION();
  short int GetHEALTH();
  void AddPerk(Perk perk);
  void ShowPerks();
  void TakeDamage(Stats* Atacator);
  void DrainHealth(unsigned short int PhysicalAmount , unsigned short int MagicalAmount);
  Stats* ReturnStats();

  list<Perk> perks;




  protected:
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


};

#endif // STATS_H
