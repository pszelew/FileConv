#ifndef PLUGINMANAGER_HH
#define PLUGINMANAGER_HH

#include <iostream>
#include <string>
#include <sstream>
#include <cassert>
#include <cstdio>
#include <dlfcn.h>
#include <memory>
#include <map>
#include <vector>
#include "LibraryInterface.hh"
#include "Scene.hh"







/*!
 * \file
 * \brief Plik zawiera definicje klasy PluginManager
 *
 * Plik zawiera definicję klasy PluginManager
 */




/*!
 * \brief Modeluje pojecia managera wtyczek
 *
 *  Klasa udostepnia intefejs dla zarzadzania zaladowanymi wtyczkami. Przechowuje mape wczsytkich wczytanych bibliotek. 
 *  Klasa umozliwia 
 */
class PluginManager
{
    private:
        /*!
        * \brief Mapa wczytanych pluginow
        *
        *  Mapa wszystkich wczytanych pluginow
        */
        std::map<std::string, std::shared_ptr<LibraryInterface>> mapLibraries;
        /*!
        * \brief Wskaznik przechowujacy aktualna instancje komendy
        *
        *  Wskaznik na funkcje tworzaca instancje komendy
        */
        Interp4Command* cmdInstance;
    public:
        /*!
        * \brief Inicjuje interfejs biblioteki
        * 
        *  Inicjuje interfejs biblioteki...
        */
        bool init(std::vector<std::string> pluginPaths);
         /*!
        * \brief Metoda inicjuje instancje polecenia ze strumienia oraz wykonuje ja
        * 
        *   
        */
       bool exec(std::istream & commandsStream, std::shared_ptr<Scene> scene ,  int serverSocket); 
};


#endif
