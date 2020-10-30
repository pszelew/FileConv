#ifndef LIBRARYINTERFACE_HH
#define LIBRARYINTERFACE_HH

#include <iostream>
#include <string>
#include <sstream>
#include <cassert>
#include <cstdio>
#include <dlfcn.h>
#include <memory>
#include "Interp4Command.hh"






/*!
 * \file
 * \brief Definicja klasy LibraryInterface
 *
 * Plik zawiera definicję klasy LibraryInterface ...
 */




/*!
 * \brief Modeluje interfejs wczytanej biblioteki dzielonej
 *
 *  Klasa modeluje interfejs wczytanej biblioteki dzielonej...
 */
class LibraryInterface
{
    private:
        /*!
        * \brief Uchwyt do biblioteki dzielonej
        *
        *  Uchwyt do biblioteki dzielonej
        */
        void* libHandler;
        /*!
        * \brief Wskaznik na funkcje tworzaca instancje komendy
        *
        *  Wskaznik na funkcje tworzaca instancje komendy
        */
        Interp4Command* (*createCmd)(void);
         /*!
        * \brief Nazwa komendy
        *
        *  Nazwa komendy
        */
        std::string cmdName;
        
    public:

        LibraryInterface(){}

        ~LibraryInterface();
        
        /*!
        * \brief Inicjuje interfejs biblioteki
        * 
        *  Inicjuje interfejs biblioteki...
        */
        bool init(std::string fileName);


        std::string GetName(){return cmdName;}
        
        Interp4Command* CreateCmd(){ return createCmd(); }
};


#endif
