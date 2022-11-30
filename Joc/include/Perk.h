#ifndef PERK_H
#define PERK_H
#include <iostream>



using namespace std;

class Perk
{
    public:
        Perk();
        Perk(string _Name , string _Description , bool _isActive);

        string GetName() { return Name; }
        void SetName(string val) { Name = val; }
        string GetDescription() { return Description; }
        void SetDescription(string val) { Description = val; }
        void SetActiveState(bool state);
        bool GetActiveState();

    private:
        string Name;
        string Description;
        bool isActive;
};

#endif // PERK_H
