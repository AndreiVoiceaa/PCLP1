#ifndef HANDLERS_H
#define HANDLERS_H
#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

class Handlers
{
    public:

    void ErrorHandler( int ErrorNumber);
    unsigned short int InputHandler(string Question , unsigned short int NumarRaspunsuri);

    const int InputErrorNumber=1;

};

#endif // HANDLERS_H
