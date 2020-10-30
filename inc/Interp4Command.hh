#ifndef  INTERP4COMMAND_HH
#define  INTERP4COMMAND_HH

#include <iostream>
#include "MobileObject.hh"
#include <memory>
/*!
 * \file
 * \brief Definicja klasy Interp4Command
 *
 * Plik zawiera definicję klasy Interp4Command ...
 */

/*!
 * \brief Modeluje abstrakcyjne polecenie dla robota mobilnego
 *
 *  Klasa modeluje ...
 */
 class Interp4Command {
  public:
   /*!
    * \brief Destruktor wirtualny ze wzgledu na klasy pochodne
    *
    *  
    */
   virtual ~Interp4Command() {}
   /*!
    * \brief
    */
   virtual void PrintCmd() const = 0;
   /*!
    * \brief
    */
   virtual void PrintSyntax() const = 0;
   /*!
    * \brief
    */
   virtual const char* GetCmdName() const = 0;
   /*!
    * \brief
    */
   virtual bool ExecCmd(  std::shared_ptr<MobileObject>  wObMob,  int serverSocket  ) const = 0;
   /*!
    * \brief
    */
   virtual bool ReadParams(std::istream& Strm_CmdsList) = 0;
    /*!
    * \brief
    */
   virtual std::string GetObjName() = 0;
 };




#endif
