#ifndef PERK_H
#define PERK_H
#include <iostream>

using namespace std;

class Perk
{
    public:

        Perk();
        Perk(string _Name , string _Description , bool _isActive);

        bool GetActiveState();
        string GetName() { return Name; }
        string GetDescription() { return Description; }
        void SetName(string val) { Name = val; }
        void SetDescription(string val) { Description = val; }
        void SetActiveState(bool state);


    private:

        string Name;
        string Description;
        bool isActive;
};

#endif // PERK_H
