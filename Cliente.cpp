
#include "Cliente.h"

//Constructor:
Cliente::Cliente()
{
}

//Set y get
void Cliente::SetCedula(string ced){
   cedula = ced;
}
   
void Cliente::SetNombre(string nomb){
   nombre = nomb;
}  


string Cliente::GetCedula(){
   return cedula;
}     

string Cliente::GetNombre(){
   return nombre;
}        
