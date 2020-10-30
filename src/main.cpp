#include "Simulation.hh"
#include "Cuboid.hh"

using namespace std;

int main(int argc, char** argv)
{
  Simulation sim;
  
  if(argc < 2)
  {
    cout<< "Nie podano nazwy pliku cmd!!!";
    return 1;
  }

  if(argc < 3)
  {
    cout<< "Nie podano nazwy pliku xml!!!";
    return 1;
  }

  if(!sim.init(argv[1], argv[2]))
  {
    cout << "Nie udalo sie zainicjowac Symulacji!!!"<<endl;
    return 1;
  }
  
  if(!(sim.addMobileObject<Cuboid>("Ob_A", 0, Vector3D(0,0,0))))
  {
    cout << "Nie udalo sie dodac obiektu!!!"<<endl;
    return 1;
  }

  if(!(sim.addMobileObject<Cuboid>("Ob_B", 0, Vector3D(0,0,0))))
  {
    cout << "Nie udalo sie dodac obiektu!!!"<<endl;
    return 1;
  }

  if(!sim.exec())
  {
    cout << "Blad podczas wykonywania symulacji!!!"<<endl;
    return 1;
  }
    
  cout << "Program zakonczyl dzialanie bez problemow" << endl;
  return 0;

}
