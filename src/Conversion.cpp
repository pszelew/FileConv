#include "Simulation.hh"

bool Simulation::init(std::string cmdPath, std::string xmlPath)
{    
    parser = std::make_shared<Parser>(cmdPath, xmlPath);
    plugManager = std::make_shared<PluginManager>();

    
    plugPaths.push_back("Interp4Move.so");
    
    plugPaths.push_back("Interp4Pause.so");
    
    plugPaths.push_back("Interp4Rotate.so");
    
    plugPaths.push_back("Interp4Set.so");
    
    serverSocket = 3;

    if(!plugManager->init(plugPaths))
    {
        std::cout << "Nie udalo sie zainicjowac Managera Pluginow!!!"<< std::endl;
        return false; 
    }

    scene = std::make_shared<Scene>();
     
    return true;
}

bool Simulation::exec()
{
    std::istringstream stream;
    std::string robotName;
    parser->ParseCmd(stream);
    
    
    if(!(plugManager->exec(stream, scene, serverSocket)))
    {
        std::cout << "Wystapil problem przy uruchamianiu symulacji!!!"<< std::endl;
        return false;
    }
    return true;

}
