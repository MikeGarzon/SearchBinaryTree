#ifndef QUEUE_H     
#define QUEUE_H 
#include <cstdlib>
#include<bits/stdc++.h>
#include <iostream>


using namespace std;

struct NODO{int dato;
            NODO *sig;};

class cola{NODO *cab,*fin;
      public: cola(){cab=fin=NULL;}
      void InsCola(int i);
      int AtenderCola();
      void ImprimirCola();
      bool ColaVacia();
      bool buscardato(int i);
      ~cola();
};

bool cola::buscardato(int i){
     NODO *aux;
     aux=cab;
     while(aux!=NULL){
          if (aux->dato!=i) aux = aux ->sig;
          else return true;
     }
     return false;
}

void cola::InsCola(int i){
     NODO *nuevo;
     nuevo= new NODO;
     nuevo->dato=i;
     nuevo->sig= NULL;
     if (cab==NULL)
         {cab=nuevo;}
     else {fin->sig = nuevo;}
     fin=nuevo;
}

int cola::AtenderCola()
{   int x;
    NODO *aux = cab; 
    cab=aux->sig;
    x=aux->dato;
    delete aux;
    return x;
}

void cola::ImprimirCola(){
     NODO *aux;
     aux=cab;
     while(aux!=NULL){
       cout<<aux->dato<<" ";
       aux=aux->sig;} 
}

bool cola::ColaVacia(){
     return (cab==NULL);
}

cola::~cola(){
     NODO *aux;
     while(cab!=NULL)
       {aux= cab;
        cab=aux->sig;
        delete aux;}
     delete cab;
}


#endif