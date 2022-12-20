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
        string GetNAME();
        string GetDESCRIPTION();
        unsigned short int GetAddMaxHealth();
        unsigned short int GetAddPhysicalDamage();
        unsigned short int GetAddMagicalDamage();
        unsigned short int GetAddPhysicalArmor();
        unsigned short int GetAddMagicalArmor();
        unsigned short int GetAddEvasion();
        void SetDROPEDSTATE(bool valoare);
        void SetNAME(string valoare);
        void SetDESCRIPTION(string valoare);


    private:

        string Name;
        string Description;
        unsigned short int DropChance;
        unsigned short int AddMaxHealth;
        unsigned short int AddPhysicalDamage;
        unsigned short int AddMagicalDamage;
        unsigned short int AddPhysicalArmor;
        unsigned short int AddMagicalArmor;
        unsigned short int AddEvasion;
        bool Droped=false;
};

#endif // ITEM_H
