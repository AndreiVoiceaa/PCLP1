#include "Item.h"



Item::Item()
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


Item::Item(string _Name , string _Description , unsigned short int _DropChance ,unsigned short int _AddMaxHealth ,unsigned short int _AddPhysicalDamage ,unsigned short int _AddMagicalDamage ,unsigned short int _AddPhysicalArmor ,
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

unsigned short int Item:: GetDROPCHANCE()
{

    return DropChance;

}

void Item:: SetDROPEDSTATE(bool valoare)
{

    Droped=valoare;

}

bool Item:: GetDROPEDSTATE()
{

    return Droped;

}

void Item:: SetNAME(string valoare)
{

    Name=valoare;

}

string Item:: GetNAME()
{
    return Name;
}

void Item:: SetDESCRIPTION(string valoare)
{

    Description=valoare;

}

string Item:: GetDESCRIPTION()
{
    return Description;
}


unsigned short int Item :: GetAddMaxHealth()
{

    return AddMaxHealth;

}

unsigned short int Item :: GetAddPhysicalDamage()
{

    return AddPhysicalDamage;

}

unsigned short int Item :: GetAddMagicalDamage()
{

    return AddMagicalDamage;

}

unsigned short int Item :: GetAddPhysicalArmor()
{

    return AddPhysicalArmor;

}

unsigned short int Item :: GetAddMagicalArmor()
{

    return AddMagicalArmor;

}

unsigned short int Item :: GetAddEvasion()
{

    return AddEvasion;

}



