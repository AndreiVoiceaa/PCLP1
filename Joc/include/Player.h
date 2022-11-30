#ifndef PLAYER_H
#define PLAYER_H
#include <list>
#include <iterator>

#include "Handlers.h"
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


    void Defeat();
    void ShowInventory();
    void IncrementItemNumber();
    unsigned short int GetItemNumber();
    void AddItem(string _Name , string _Description);
    void LevelUp(list<Perk> &p , Handlers _MainHandle);
    void BuyStats(unsigned short int index);
    int ExperienceLimit;


    static constexpr unsigned short int BuyMaxHealthValue = 10;
    static constexpr unsigned short int BuyPhysicalDamageValue = 1;
    static constexpr unsigned short int BuyMagicalDamageValue = 1;
    static constexpr unsigned short int BuyPhysicalArmorValue = 1;
    static constexpr unsigned short int BuyMagicalArmorValue = 1;


    private:
        unsigned short int ItemNumber;
        constexpr static unsigned short int InventoryLength=10;
        Item Inventory[InventoryLength];



};


#endif // PLAYER_H
