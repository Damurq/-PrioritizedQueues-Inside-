#include "Controlador.h"

Controlador::Controlador()
{
};


//===============================================================================================
//INCLUIR UN CLIENTE-----------NECESARIO
//===============================================================================================
bool Controlador::IncluirClnts()
{
	if(!ColClnt.Llena())
	{
		int *resp,*prid;
		string *cedula;
		prid = new int;
		resp = new int;
		cedula = new string;
		vg.Limpiar();
		cout<<"=============================================================================="<<endl;
  		cout<<"----------------------------  DATOS DEL CLIENTE  -----------------------------"<<endl;
      	cout<<"=============================================================================="<<endl;
		do{
			*cedula =	vg.LeerString("\nIntroduzca Cedula:    ");
			if (!VerifClnt(ColClnt,*cedula))
			{
				Clnt.SetCedula(*cedula);
				Clnt.SetNombre(vg.LeerString("Intoduzca Nombre:     "));
				//Clnt.SetApellido(vg.LeerString("Introduzca Apellido:  "));
				*prid=vg.LeerValidarNro("Intoduzca Prioridad:  ",0,3);
				//INCLUIR
				ColClnt.Insertar(Clnt,*prid);
			}
			else
			{
				cout<<"\n=============================================================================="<<endl;
				vg.ImprimirMensaje("\t\tEL CLIENTE YA ESTA EN LA COLA");
				cout<<"\n==============================================================================\n"<<endl;
				vg.Pausa();
			}
			cout<<"\n=============================================================================="<<endl;
			*resp=vg.LeerValidarNro("\t\tDesea agregar otro Cliente a la cola 1[SI] 2[NO]: ",1,2);	
			cout<<"=============================================================================="<<endl;	
		}while(*resp==1);
		//Eliminar las variables dinamicas
		delete prid;
		delete resp;
		delete cedula;
		return true;
		}
	else
	{
		vg.Limpiar();
		cout<<"\n=============================================================================="<<endl;
		vg.ImprimirMensaje("\t\t LA COLAP ESTA LLENA");
		cout<<"\n=============================================================================="<<endl;
		return false;
		vg.Pausa();
	}
		
};



//===============================================================================================
//IMPRIMIR TODOS LOS ClienteS (1-IMPRIMIR Y VACIRA,2-IMPRIMIR)-----------FUNCIONAL
//===============================================================================================
void Controlador::Imprimir(int tipo)
{
	int prid;
	Cliente clntAux;
	ColaP<Cliente> ColClntAuX2;
	if(ColClnt.Vacia())
	{
		vg.Limpiar();
		cout<<"=============================================================================="<<endl;
  		cout<<"---------------------------  LA COLAP ESTA VACIA  ----------------------------"<<endl;
      	cout<<"=============================================================================="<<endl;
		vg.Pausa();
	}
	else
	{
		if((tipo==1)||(tipo==2))
		{
			if(Llenar(ColClnt,ColClntAuX2))
			{
				vg.Limpiar();
				cout<<"=============================================================================="<<endl;
				cout<<"----------------------------  ORDEN PARA ATENDER  ----------------------------"<<endl;
				//cout<<"Prioridad  Cedula\tNombre"<<endl;
				while (!ColClntAuX2.Vacia())
				{
					cout<<"=============================================================================="<<endl;
					if(tipo==1)
						ColClntAuX2.Atender(clntAux,prid);
					else if(tipo==2)
						ColClntAuX2.Remover(clntAux,prid);
					cout<<"\t\t\tPRIORIDAD:  "<<prid<<endl;
					cout<<"\t\t\tCEDULA:     "<<clntAux.GetCedula()<<endl;
					cout<<"\t\t\tNOMBRE:     "<<clntAux.GetNombre()<<endl;
				}
				//Llenar(ColClntAuX2,ColClnt);
				vg.Pausa();
			}
			else
			{
				vg.Limpiar();
				cout<<"=============================================================================="<<endl;
				cout<<"---------------------------  LA COLAP ESTA VACIA  ----------------------------"<<endl;
				cout<<"=============================================================================="<<endl;
				vg.Pausa();
			}
		}
		else if(tipo==3)
		{
			if(Llenar(ColClnt,ColClntAuX2))
			{
				vg.Limpiar();
				cout<<"=============================================================================="<<endl;
				cout<<"----------------------------  ORDEN PARA ATENDER  ----------------------------"<<endl;
				//cout<<"Prioridad  Cedula\tNombre"<<endl;
				while (!ColClntAuX2.Vacia())
				{
					cout<<"=============================================================================="<<endl;
					ColClntAuX2.Atender(clntAux,prid);
					cout<<"\t\t\tPRIORIDAD:  "<<prid<<endl;
					cout<<"\t\t\tCEDULA:     "<<clntAux.GetCedula()<<endl;
					cout<<"\t\t\tNOMBRE:     "<<clntAux.GetNombre()<<endl;
				}
				//Llenar(ColClntAuX2,ColClnt);
				Llenar(ColClnt,ColClntAuX2);
				vg.ImprimirLineasBlanco(2);
				cout<<"=============================================================================="<<endl;
				cout<<"------------------------------  COLA POR LLEGADA  ----------------------------"<<endl;
				while (!ColClntAuX2.Vacia())
				{
					cout<<"=============================================================================="<<endl;
					ColClntAuX2.Remover(clntAux,prid);
					cout<<"\t\t\tPRIORIDAD:  "<<prid<<endl;
					cout<<"\t\t\tCEDULA:     "<<clntAux.GetCedula()<<endl;
					cout<<"\t\t\tNOMBRE:     "<<clntAux.GetNombre()<<endl;
				}
				vg.Pausa();
			}
			else
			{
				vg.Limpiar();
				cout<<"=============================================================================="<<endl;
				cout<<"---------------------------  LA COLAP ESTA VACIA  ----------------------------"<<endl;
				cout<<"=============================================================================="<<endl;
				vg.Pausa();
			}	
		}
	}
};


//===============================================================================================
//MOSTRAR EL SIGUIENTE CLIENTE A PASAR EN TAQUILLA-----------NECESARIO
//===============================================================================================
void Controlador::CurrentCustomer()
{
	int prid,resp;
	Cliente ClntAux;
	vg.Limpiar();
	if(!ColClnt.Vacia())
	{
		do
		{
			ColClnt.Atender(ClntAux,prid);
			Imp_ONE_Clnt(ClntAux,prid);
			cout<<"\n=============================================================================="<<endl;
			resp=vg.LeerValidarNro("\t\tDesea atender otro Cliente  1[SI] 2[NO]: ",1,2);	
			cout<<"=============================================================================="<<endl;	
		} while ((!ColClnt.Vacia())&&(resp==1));
	}
	else
	{
		cout<<"=============================================================================="<<endl;
		cout<<"---------------------------  LA COLAP ESTA VACIA  ----------------------------"<<endl;
      	cout<<"=============================================================================="<<endl;
		cout<<endl;
		vg.Pausa();
	}
};


//===============================================================================================
//VERIFICAR SI UN CLIENTE ESTA EN LA COLAP-----------NECESARIO
//===============================================================================================
bool Controlador::VerifClnt(ColaP<Cliente> &ColaPA,string ced)
{
	ColaP<Cliente> ColClntAux;		
	Cliente clntAux;
	bool result=false;
	int *prioridad;
	prioridad = new int;
	while(!ColaPA.Vacia())
	{
		ColaPA.Remover(clntAux,*prioridad);
		if(clntAux.GetCedula()==ced)
			result=true;
		ColClntAux.Insertar(clntAux,*prioridad);
	};
	while(ColClntAux.Remover(clntAux,*prioridad))
	{
		ColaPA.Insertar(clntAux,*prioridad);
	};
	delete prioridad;
	return result;
};


//===============================================================================================
//CONTADOR DE CLIENTES -----------NECESARIO
//===============================================================================================
int Controlador::TotalClnt(ColaP<Cliente> &ColClntAux)
{
	int num,prid;
	num=0;
	Cliente clntAux;
	ColaP<Cliente> ColClntAux2;
	while(ColClntAux.Remover(clntAux,prid))
	{
		ColClntAux2.Insertar(clntAux,prid);
		num++;
	}
	while(ColClntAux2.Remover(clntAux,prid))
	{
		ColClntAux.Insertar(clntAux,prid);
	}
	return num;	
};


//===============================================================================================
//RETORNA EL CONTADOR DE ClienteS -----------FUNCIONAL
//===============================================================================================
int Controlador::Tolal()
{
	//return TotalClnt(ColClnt);	
	return ColClnt.Contar();
};


//===============================================================================================
//IMPRIMIR UN CLIENTE-----------NECESARIO
//===============================================================================================
void Controlador::Imp_ONE_Clnt(Cliente ClntAux, int prid)
{
	vg.Limpiar();
	cout<<"=============================================================================="<<endl;   	
	cout<<"-------------------  POR FAVOR DIRIGIRSE A LA TAQUILLA  ----------------------"<<endl;
	cout<<"=============================================================================="<<endl;	
	cout<<"\t-Prioridad:   "<<prid<<endl;
	cout<<"\t-Cedula:      "<<ClntAux.GetCedula()<<endl;
	cout<<"\t-Nombre:      "<<ClntAux.GetNombre()<<endl;
	vg.ImprimirLineasBlanco(1);
}

//===============================================================================================
//LLENAR UN Cola Y VACIAR OTRA -----------FUNCIONAL
//===============================================================================================
bool Controlador::Llenar(ColaP<Cliente> &Colaux, ColaP<Cliente> &Colaux2)
{
	Cliente clienteA;
	int p;
	ColaP<Cliente> Colauxil;
	if (!Colaux.Vacia())
	{
		while(!Colaux.Vacia())
		{
			Colaux.Remover(clienteA,p);
			Colauxil.Insertar(clienteA,p);
		}
		while(!Colauxil.Vacia())
		{
			Colauxil.Remover(clienteA,p);
			Colaux.Insertar(clienteA,p);
			Colaux2.Insertar(clienteA,p);
		}
		return true;
	}
	else
	{
		return false;
	}
};


void Controlador::ShowPrid()
{
	vg.Limpiar();
	cout<<"=============================================================================="<<endl;
	cout<<"-------------------------------  PRIORIDADES  --------------------------------"<<endl;
	cout<<"=============================================================================="<<endl;
	cout<<"\t\t\t0) VIP  "<<endl;
	cout<<"\t\t\t1) Tercera edad"<<endl;
	cout<<"\t\t\t2) Tarjeta viento o dueno de cuenta"<<endl;
	cout<<"\t\t\t3) No cliente del banco"<<endl;
	vg.Pausa();
}
