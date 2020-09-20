#include "ColaP.h"

template <class Tipo>
ColaP<Tipo>::ColaP() {
     Frente=NULL;
     Final=NULL;
};

template <class Tipo>
bool ColaP<Tipo>::Vacia(){
     return Frente == NULL;
};

template <class Tipo>
bool ColaP<Tipo>::Llena(){
     nodo<Tipo> *p;
     p=new nodo<Tipo>;
     if (p==NULL)
        return true;
     else
    {   delete p;
        return false;
    }
};

template <class Tipo>
bool ColaP<Tipo>::Insertar(Tipo Valor, int prioridad){
     nodo<Tipo> *nuevo;
     if (!Llena())
     {
        nuevo=new nodo<Tipo>;
        nuevo->info=Valor;
        nuevo->priord=prioridad;
        nuevo->prox=NULL;
        if (Final==NULL) 
            Frente=nuevo;       
        else Final->prox=nuevo;
        Final=nuevo;
        return true;
      }
      else return false;
};


template <class Tipo>
int ColaP<Tipo>::Contar()
{
  nodo<Tipo> *f;
  int num=0;
  f=Frente;
  while (f!=NULL)
   {
        f=f->prox;
        num++;
   };
   return num;
};

//METODO NUEVO
//===========================================================================
template <class Tipo>
ColaP<Tipo>::~ColaP()
{
  nodo<Tipo> *f;
  while (!Vacia())
   {
        f=Frente->prox;
        delete Frente;
        Frente=f;
   };
};

template <class Tipo>
bool ColaP<Tipo>::Remover(Tipo &Valor,int &prioridad){
     nodo<Tipo> *primero;
     if (!Vacia())
     {
        primero=Frente;
        Valor=primero->info;
        prioridad=primero->priord;
        Frente=primero->prox;
        if (Frente==NULL)
            Final=NULL;
        delete primero;
        return true;
     }
     else
     return false;
};


template <class Tipo>
bool ColaP<Tipo>::RemoverEspecial(Apuntador p,Tipo &Valor,int &prioridad)
{
     nodo<Tipo> *aux;
     aux=p->prox;
     if (!Vacia())
     {
          Valor=aux->info;
          prioridad=aux->priord;
          p->prox=aux->prox;
          delete aux;
          return true;
     }
     else
          return false;
}


template <class Tipo>
bool ColaP<Tipo>::Atender(Tipo &Valor,int &prioridad){
     nodo<Tipo> *ant;
     Tipo val;
     int priori,booleano=0,result=false;
     if (!Vacia())
     {
         //if ((Frente==Final)||(Final==NULL))
          if(Frente->prox==NULL)
          {
               Remover(Valor,prioridad);
               result = true;
          }
          else
          {
               priori=Frente->priord;
               switch (priori)
               {
               case 0:
                    Remover(Valor,prioridad);
                    result=true;
                    break;
               case 1:
                    if(!VerifRemEsp(ant,Valor,prioridad,priori)) 
                         Remover(Valor,prioridad);
                    break;
               case 2:
                    if(!VerifRemEsp(ant,Valor,prioridad,priori)) 
                         Remover(Valor,prioridad);
                    break;
              case 3:
                    if(!VerifRemEsp(ant,Valor,prioridad,priori)) 
                         Remover(Valor,prioridad);
                    break;
               default:
                    break;
               }
          }
          return result;
     }
     else
          return result;
};


template <class Tipo>
nodo<Tipo>* ColaP<Tipo>::Verificar(int prioridad, int &booleano)
{
     nodo<Tipo> *aux =NULL,*act=Frente->prox;
     int pridI=act->priord,pridF=-1;
     booleano=0;
     while (act!=NULL)
     {
          if(act->prox!=NULL)//new -2
          {
               pridF=act->prox->priord;
          }
          if(pridI==prioridad)
          {
               booleano=1;
               aux=Frente;
               break;
          }
          else if(pridF==prioridad)
          {
               booleano=1;
               aux=act;
               break;
          }
          if(act->prox==NULL)
               break;
          act=act->prox;
     }
     return aux;
};



template <class Tipo>
bool ColaP<Tipo>::VerifRemEsp(Apuntador ant,Tipo &Valor,int &prioridad, int pdAct)
{
     bool result=false;
     if(pdAct>0)
     {
          int i=pdAct,pridBase,booleano=0;
          while (i>0)
          {
               pridBase=pdAct-i;
               ant=Verificar(pridBase,booleano);
               if (booleano==1)
               {
                    RemoverEspecial(ant,Valor,prioridad);
                    result=true;
                    break;
               }
               i--;
          };
          return result;
          
     }
     else
          return result;
     
}























/*
template <class Tipo>
bool ColaP<Tipo>::Atender(Tipo &Valor, int &prioridad){
     nodo<Tipo> *aux,*ant,*act;
     string change="no";
     int pridAct=0;
     if (!Vacia())
     {
          if ((Frente==Final)||(Final==NULL))
          {
               ////cout<<"aqui?";
               Remover(Valor,prioridad);
               return true;
          }
          else
          {
               aux=Frente;
               while(aux!=NULL)
               {
                    prioridad=aux->priord;
                    //PRIORIDAD 0
                    if (prioridad==0)
                    {
                         if(aux==Frente->prox)
                         {
                              act=NULL;
                              ant=Frente;
                         }
                         else if((aux!=Frente->prox)&&(aux!=Frente))
                              ant=ant->prox;
                         change="change";
                         break;
                    }
                    //FIN PRIORIDAD 0
                    //PRIORIDAD 1
                    else if ((prioridad==1)&&(pridAct!=1))
                    {
                         pridAct=1;
                         change="si";
                    }
                    //PRIORIDAD 2 Y 3
                    else if((prioridad!=1)&&(pridAct!=2)&&(pridAct!=1))
                    {
                         if(prioridad==2)
                         {
                              pridAct=2;
                              change="si";
                         }
                         //FIN P2
                         else if((prioridad==3)&&(pridAct!=3))
                         {
                              pridAct=3;
                              change="si";
                              
                         }
                         //FIN P3
                    }
                    //ANTERIOR
                    if(change=="si")
                    {
                         if (aux==Frente)
                              act=aux;
                         if(aux==Frente->prox)
                         {
                              act=NULL;
                              ant=Frente;
                         }
                         else if((aux!=Frente->prox)&&(aux!=Frente))
                         {
                              act=NULL;
                              ant=ant->prox;
                         }
                    }
                         

                    change="no";
                    if(aux->prox==NULL)
                         break;
                    aux=aux->prox;
               }
               if((aux==Frente)||(act==Frente))
               {
                    if(change=="change")
                    {
                         Frente=aux->prox;
                         prioridad=aux->priord;
                         Valor=aux->info;

                    }
                    else
                    {
                         act=Frente;
                         Frente=act->prox;  
                         prioridad=act->priord;
                         Valor=act->info;            
                    }

               }
               else
               {
                    if(change=="change")
                    {
                         ant->prox=aux->prox;
                         prioridad=aux->priord;
                         Valor=aux->info;
                    }
                    else if((aux==Final)&&(Frente->prox==Final)&&(Frente->priord==Final->priord))//new
                         Remover(Valor,prioridad);
                    else
                    {
                         act=ant->prox;
                         ant->prox=act->prox;
                         prioridad=act->priord;
                         Valor=act->info;                   
                    }
               }
               if (Frente==NULL)
                    Final=NULL;                    
               if((Frente==NULL)&&(Final==NULL))
               {}
               else
               {
                    if((Frente->priord==Final->priord)&&(Frente==Final))
                    {}
                    else
                    {
                         if(change=="change")
                              delete aux;
                         else
                              delete act;
                    }
               }
               return true;
          }
     }
     else
          return false;
};
*/
