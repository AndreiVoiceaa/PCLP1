#ifndef HANDLERS_H
#define HANDLERS_H
#include <iostream>

using namespace std;

class Handlers
{
    public:
        Handlers();
    void ErrorHandler( int ErrorNumber);
    string InputHandler(string Question);
    const int InputErrorNumber=1;


};

#endif // HANDLERS_H
