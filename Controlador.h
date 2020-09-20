#ifndef CONTROLADOR_H_
#define CONTROLADOR_H_

#include <string>
#include <iostream>
#include "Cliente.h"
#include "ColaP.h"
#include "VGeneral.h"

class Controlador
{
   private:
      Cliente Clnt;
      ColaP<Cliente> ColClnt;
      VGeneral vg;
   public:
      Controlador();
      bool IncluirClnts();                                  //FUNCIONAL--NECESARIO
      void Imprimir(int tipo);                              //--NECESARIO
      void CurrentCustomer();                               //--NECESARIO
      bool VerifClnt(ColaP<Cliente> &ColaPA,string ced);      //--NECESARIO
      int TotalClnt(ColaP<Cliente> &ColClntAux);             //--NECESARIO
      int Tolal();
      void Imp_ONE_Clnt(Cliente ClntAux, int prid);                   //--NECESARIO
      bool Llenar(ColaP<Cliente> &Colaux, ColaP<Cliente> &Colaux2);

      void ShowPrid();
};

#include "Controlador.cpp"
#endif /* CONTROLADOR_H_ */
