#include "Handlers.h"

Handlers::Handlers()
{
    //ctor
}

void Handlers :: ErrorHandler( int ErrorNumber)
{
    cout<<endl;
    if(ErrorNumber==InputErrorNumber)
    {

       cout<<"Input Gresit"<<" -ErrorNumber ("<<ErrorNumber<<")"<<endl<<endl;

    }



     // system("cls");


}


string Handlers :: InputHandler(string Question)
{


    cout<<Question<<endl<<endl;
    ReiaRaspuns:
    try {
    string Raspuns=" ";
    cin>>Raspuns;
    if(Raspuns=="1")
        return Raspuns;
    else if(Raspuns!="2")
    {
        throw (InputErrorNumber);
    }

    return Raspuns;

    }
    catch ( int MesajEroare) {

    ErrorHandler(MesajEroare);
    goto ReiaRaspuns;


    }



}


