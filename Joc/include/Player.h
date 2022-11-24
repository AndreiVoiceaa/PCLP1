#ifndef PLAYER_H
#define PLAYER_H
#include "Stats.h"
#include "Item.h"
#include "Perk.h"




class Player:public Stats
{
    public:
    Player(unsigned short int _Maxhealth , unsigned short int _PhysicalDamage , unsigned short int _MagicalDamage , unsigned short int _PhysicalArmor,
        unsigned short int _MagicalArmor , unsigned short int _Evasion , unsigned short int _Level , int _Coins , int _Experience , int _ExperienceLimit ,
        unsigned short int _ItemNumber);

    Player();
    void TakeDamage(unsigned short int EnemyPhysicalDamage , unsigned short int EnemyMagicalDamage);
    void Defeat();
    void ShowInventory();
    void IncrementItemNumber();
    unsigned short int GetItemNumber();
    void AddItem(string _Name , string _Description);



    int ExperienceLimit;

    private:
        unsigned short int ItemNumber;
        constexpr static unsigned short int InventoryLength=10;
        Item Inventory[InventoryLength];



};

#endif // PLAYER_H
