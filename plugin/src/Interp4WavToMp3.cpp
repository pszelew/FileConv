#include <iostream>
#include "Interp4Move.hh"

using namespace std;

Interp4Move::Interp4Move():  obj_name(""), vel(0), dist(0)
{
}

Interp4Move::~Interp4Move()
{

}

Interp4Command* Interp4Move::CreateCmd()
{
    return new Interp4Move();
}



void Interp4Move::PrintCmd() const
{
   cout << this->GetCmdName() << " " << obj_name << " " << vel << " " << dist << endl;
}


void Interp4Move::PrintSyntax() const
{
    /*Wyswietl skladnie polecenia*/
    cout << "   Move nazwa_obiektu vel[m/s] dist[m/s]" << endl;
}


const char* Interp4Move::GetCmdName() const
{
    /*Wyswietla nazwe polecenia*/
    return "Move";
}

bool Interp4Move::ExecCmd(std::shared_ptr<MobileObject>  wObMob,  int serverSocket) const
{
   /* Wykonuje polecenie oraz wizualizuje jego realizacje */
   std::cout<< "Polecenie Move wykonuje sie!!!"<< endl;
   return true;
}

bool Interp4Move::ReadParams(std::istream& Strm_CmdsList)
{
    if(!(Strm_CmdsList >> obj_name))
    {
        std::cout << "Nie wczytano poprawnie nazwy obiektu ktory ma sie poruszyc"<< endl;
        return 1;
    }

    if(!(Strm_CmdsList >> vel))
    {
        std::cout << "Nie wczytano poprawnie predkosci"<< endl;
        return 1;
    }

    if(!(Strm_CmdsList >> dist))
    {
        std::cout << "Nie wczytano poprawnie dystansu"<< endl;
        return 1;
    }
    

    return true;
}


////////////////////////////////////////////wtyczka/////////////////////////////////////////////

extern "C"
{
    const char * GetCmdName(void);
    
    Interp4Command* CreateCmd(void);
}

const char* GetCmdName(void)
{
    return "Move";
}


Interp4Command* CreateCmd(void)
{
    return Interp4Move::CreateCmd();
}