#ifndef CLIENTE_H_
#define CLIENTE_H_

#include <iostream>
#include <string>

using namespace std;

class Cliente
{
private:
	string cedula,nombre;
public:
	//Constructor:
	Cliente();
	void SetCedula(string ced);
	void SetNombre(string nom);
	//void SetApellido(string ape);
	string GetCedula();
    string GetNombre();
    //string GetApellido();
};

#include "Cliente.cpp"
#endif /* Cliente_H_ */
