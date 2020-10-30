#include "PluginManager.hh"
bool PluginManager::init(std::vector<std::string> pluginPaths)
{
    std::vector<std::string>::iterator it;

    for(it = pluginPaths.begin(); it < pluginPaths.end(); it++)
    {
        std::shared_ptr<LibraryInterface> tempLibrary = std::make_shared<LibraryInterface>();
        if(!tempLibrary->init(*it))
        {
            std::cout << "Nie udalo sie zainicjowac biblioteki!!!: "<< *it<< std::endl;
            return false;
        }
        mapLibraries.insert(std::make_pair(tempLibrary->GetName(), tempLibrary));
    }

    return true;

}

bool PluginManager::exec(std::istream & commandsStream, std::shared_ptr<Scene> scene,  int serverSocket)
{
    std::string keyWord;
    std::string robotName;
    std::shared_ptr<LibraryInterface> libraryHandler;
    std::shared_ptr<MobileObject> tempMobileObject;

    while(commandsStream >> keyWord)
    {
        std::map<std::string, std::shared_ptr<LibraryInterface>>::iterator it = mapLibraries.find(keyWord);

        if(it == mapLibraries.end())
        {
            std::cout << "Nie znaleziono wtyczki dla polecenia: " << keyWord << std::endl;
            return false;
        }
        //std::cout << "Znaleziono wtyczke dla polecenia: " << KeyWord << std::endl;


        libraryHandler = it->second;

        cmdInstance = libraryHandler->CreateCmd();

        cmdInstance->ReadParams(commandsStream);   

        std::cout<< cmdInstance->GetCmdName()<< std::endl;
    
        cmdInstance->PrintSyntax();

        if(cmdInstance->GetObjName()!="")
        {
            if(!(scene->FindMobileObject(cmdInstance->GetObjName(), tempMobileObject)))
            {
                std::cout << "Nie znaleziono takiego obiektu mobilnego: " << cmdInstance->GetObjName() << std::endl;
                return false;
            }
        }
        cmdInstance->ExecCmd(tempMobileObject, serverSocket);

        cmdInstance->PrintCmd();
    
        delete(cmdInstance);
    }
    return true;

}