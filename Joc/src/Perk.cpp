#include "Perk.h"


Perk::Perk()
{
    Name="Default Perk";
    Description="Default Description";
    isActive=false;
}

Perk::Perk(string _Name , string _Description , bool _isActive)
{
    Name=_Name;
    Description=_Description;
    isActive=_isActive;
}

void Perk :: SetActiveState(bool state)
{

    isActive=state;

}

bool Perk :: GetActiveState()
{

    return isActive;

}






