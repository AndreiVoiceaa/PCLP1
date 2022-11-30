#ifndef ITEM_H
#define ITEM_H
#include <iostream>

using namespace std;

class Item
{

public:
    Item();
    Item(string _Name , string _Description , unsigned short int _DropChance ,unsigned short int _AddMaxHealth ,unsigned short int _AddPhysicalDamage ,unsigned short int _AddMagicalDamage ,unsigned short int _AddPhysicalArmor ,
    unsigned short int _AddMagicalArmor ,unsigned short int _AddEvasion);
    unsigned short int  GetDROPCHANCE();
    bool GetDROPEDSTATE();
    void SetDROPEDSTATE(bool valoare);
    string GetNAME();
    void SetNAME(string valoare);
    string GetDESCRIPTION();
    void SetDESCRIPTION(string valoare);
    unsigned short int GetAddMaxHealth();
    unsigned short int GetAddPhysicalDamage();
    unsigned short int GetAddMagicalDamage();
    unsigned short int GetAddPhysicalArmor();
    unsigned short int GetAddMagicalArmor();
    unsigned short int GetAddEvasion();

private:
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
};

#endif // ITEM_H
