#ifndef SIMULATION_HH
#define SIMULATION_HH

#include "Parser.hh"
#include "PluginManager.hh"
#include "Scene.hh"
#include <sstream>

/*!
 * \file
 * \brief Plik zawiera definicje klasy Simulation
 *
 * Plik zawiera definicję klasy Simulation
 */




/*!
 * \brief Modeluje pojecia Symulacji
 *
 *  Klasa udostepnia intefejs dla zarzadzania Symualacja
 *
 */
class Simulation
{
    private:
        /*!
        * \brief Parser plikow cmd raz xml
        *
        *  Obiekt ten parcuje pliki cmd oraz xml
        */
        std::shared_ptr<Parser> parser;
        /*!
        * \brief Manager pluginow
        *
        *  Manager pluginow 
        */
        std::shared_ptr<PluginManager> plugManager;
        /*!
        * \brief Vector ze sciezkami do pluginow.
        *
        *  Narazie hardcoded
        */
        std::vector<std::string> plugPaths;
         /*!
        * \brief Scena.
        *
        *  
        */
        std::shared_ptr<Scene> scene;
        /*!
        * \brief Wtyczka do serwera graficznego
        *
        *  
        */   
        int serverSocket;

        
    public:
        /*!
        * \brief Inicjuje symulacje
        * 
        *  Inicjuje symulacje
        */
        bool init(std::string cmdPath, std::string xmlPath);
         /*!
        * \brief Metoda wykonuje zadania w symulacji
        * 
        *   
        */
        bool exec(); 
        template <typename T>
        bool addMobileObject(std::string in_name, double in_rot_z, Vector3D in_pos)
        {
            T mobileObjectTest;
            MobileObject* mobileTest;
            if(!(mobileTest = dynamic_cast< MobileObject* >(&mobileObjectTest)))
            {
                std:: cout << "Podany typ " << typeid(mobileObjectTest).name() << "nie jest ObiektemMobilnym!!!"<< std::endl;
                return false;
            }
            std::shared_ptr<T> objectToAdd = std::make_shared<T>(in_name, in_rot_z, in_pos);
            scene->addMobileObject(objectToAdd);

            

            return true;
        }

        
};


#endif
