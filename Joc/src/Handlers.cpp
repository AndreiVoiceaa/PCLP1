#include "Handlers.h"

Handlers::Handlers()
{

}

void Handlers :: ErrorHandler( int ErrorNumber)
{
    cout<<endl;
    if(ErrorNumber==InputErrorNumber)
    {

       cout<<"Input Gresit"<<" -ErrorNumber ("<<ErrorNumber<<")"<<endl<<endl;

    }

}


unsigned short int Handlers :: InputHandler(string Question , unsigned short int Number_of_Answers)
{



    string mesaj;
    cout<<Question<<endl<<endl;


    ReiaRaspuns:

    getline(cin , mesaj);
    string::const_iterator it = mesaj.begin();

    if(*it=='0' || mesaj.size() == 0)
    {
      ErrorHandler(InputErrorNumber);
      goto ReiaRaspuns;


    }

    for(it; it != mesaj.end(); ++it)
      if(isdigit(*it)==0 )
      {
          ErrorHandler(InputErrorNumber);
          goto ReiaRaspuns;


      }

    if(!(stoi(mesaj)>=1 && stoi(mesaj)<=Number_of_Answers))
    {
         ErrorHandler(InputErrorNumber);
          goto ReiaRaspuns;

    }


    return stoi(mesaj);

}


