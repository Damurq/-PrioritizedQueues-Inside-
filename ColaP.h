#ifndef COLAP_H_
#define COLAP_H_
#include <iostream>
#include <string>

template <class Tipo>
class ColaP;

template <class Tipo>
class nodo
{
Tipo info;
int priord;
nodo<Tipo>* prox;
friend class ColaP<Tipo>;
};

template <class Tipo>
class ColaP
{
typedef nodo<Tipo>* Apuntador;// nwe3
private:// nwe3
nodo<Tipo> *Frente,*Final;
public:
ColaP();
bool Vacia();
bool Llena();
bool Insertar(Tipo Valor,int prioridad);
bool Atender(Tipo &Valor,int &prioridad);
bool Remover(Tipo &Valor,int &prioridad);
bool RemoverEspecial(Apuntador p,Tipo &Valor,int &prioridad);
nodo<Tipo>* Verificar(int prioridad, int &booleano);// nwe3
int Contar();
~ColaP();

bool VerifRemEsp(Apuntador ant,Tipo &Valor,int &prioridad,int pdAct);
};

#include "ColaP.cpp"
#endif
