#include "LibraryInterface.hh"


LibraryInterface::~LibraryInterface()
{
  dlclose(libHandler);
}






bool LibraryInterface::init(std::string fileName)
{
  const char* (*cmdNameFcn)(void);
  void *fun;


  libHandler = dlopen(fileName.c_str(),RTLD_LAZY);
  if (!libHandler) 
  {
    std::cerr << "!!! Brak biblioteki: " << fileName << std::endl;
    return false;
  }

  fun = dlsym(libHandler,"CreateCmd");

  if (!fun) 
  {
    std::cerr << "!!! Nie znaleziono funkcji CreateCmd dla "<< fileName << std::endl;
    return false;
  }

  createCmd = reinterpret_cast<Interp4Command* (*)(void)>(fun);

  fun = dlsym(libHandler,"GetCmdName");
  
  if (!fun) 
  {
    std::cerr << "!!! Nie znaleziono funkcji GetCmdName dla "<< fileName << std::endl;
    return false;
  }
  
  cmdNameFcn = reinterpret_cast<const char* (*)(void)>(fun);

  cmdName = cmdNameFcn();
  
  return true;
}
 



  