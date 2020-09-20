#include "Controlador.h"
#include "VGeneral.h"
#include <string>
#include <iostream>


int main()
{
   int valor,valor2;
   string ced;
   Controlador c;
   VGeneral vg;
   do{
   vg.Limpiar();
   cout<<"=============================================================================="<<endl;
   cout<<"-----------------------------  MENU DE OPCIONES  -----------------------------"<<endl;
   cout<<"=============================================================================="<<endl;
   cout<<"\n1-) Agregar cliente a la cola"<<endl;
   cout<<"2-) Pasar cliente a taquilla "<<endl;
   cout<<"3-) Mostrar cola"<<endl;
   cout<<"4-) Total de clientes en cola"<<endl;
   cout<<"5-) Mostrar prioridades"<<endl;
   cout<<"6-) Salir\n"<<endl;
   cout<<"=============================================================================="<<endl;
   valor= vg.LeerValidarNro("\n Opcion seleccionada : ",1,7);
   switch (valor)
   {
	   case 1:
	      c.IncluirClnts();
	      break;
	   case 2:
	      c.CurrentCustomer();
	      break;
	   case 3:
         vg.Limpiar();   	
         cout<<"=============================================================================="<<endl;   	
         cout<<"---------------------------  SUB-MENU DE OPCIONES  ---------------------------"<<endl;
         cout<<"=============================================================================="<<endl;
         cout<<"1-) Imprimir cola por prioridad"<<endl;
         cout<<"2-) Imprimir cola por orden de llegada"<<endl;
         cout<<"3-) Imprimir ambas"<<endl;
         cout<<"4-) Atras\n"<<endl;
         valor2= vg.LeerValidarNro(" Opcion seleccionada : ",1,4);
         if(valor2==1)
            c.Imprimir(valor2);
         else if(valor2==2)
            c.Imprimir(valor2);
         else if(valor2==3)
            c.Imprimir(valor2);
         break;
	   case 4:
	      cout<<"\n Total de clientes en cola hasta el momento: "<<c.Tolal()<<"\n "<<endl;
	      vg.Pausa();
	      break;
      case 5:
         c.ShowPrid();
         break;
	   default:
      	break;
   }
   }while(valor!=6);   
   return 0;
}
