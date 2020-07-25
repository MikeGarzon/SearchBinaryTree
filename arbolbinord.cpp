#include "queue.h"
#include "stack.h"

/* INTEGRANTES:
    Maicol Andres Garzon Fonseca 20172020011
    Luis Felipe Corredor Espinosa 20171020056
 */


struct nodo{int info;
           nodo *izq, *der;};

class arbolbinord{nodo *raiz;
    cola *listInorden, *listPreorden, *listPosorden;
    public: arbolbinord(){raiz = NULL;
                        listInorden = new cola;
                        listPreorden = new cola;
                        listPosorden = new cola;}

        void insertar(int dato);
        bool buscar(int dato);
        int buscarRaiz(); // ESTE LO CREO PARA LA IMPRESION 
        nodo *buscarpadre(int dato, nodo *p);
        nodo *buscar_nodo(int dato, nodo *q);
        void eliminar(int dato); 
        void inorden(nodo *raiz); 
        void preorden(nodo *raiz); 
        void posorden(nodo *raiz); 
        void limpiar(nodo *r);
        ~arbolbinord();
};

void arbolbinord::insertar(int dato){
    nodo *nuevo, *padre, *hijo;
    if (raiz == NULL){
        raiz = new nodo;
        raiz->info = dato;
        raiz->der = NULL; raiz->izq= NULL;}
    else{
    padre = raiz;
    while(padre!=NULL){
        hijo = padre;
        if (dato < padre->info) padre = padre->izq;
        else padre = padre->der;
    }

    nuevo = new nodo;
    nuevo->info = dato; nuevo->der = NULL; nuevo->izq = NULL;

    if (dato<hijo->info) hijo->izq = nuevo;
    else hijo->der = nuevo;}
}

bool arbolbinord::buscar(int dato){
    nodo *buscado;
    buscado = raiz;
    while (buscado!=NULL){
        if(buscado->info == dato) return true;
        else{
            if(buscado->info>dato) buscado = buscado->izq;
            else buscado = buscado->der;
        }
    }
    return false;
}

nodo *arbolbinord::buscarpadre(int dato, nodo *p){
    nodo *padre = raiz;
    if (buscar(dato)==false) return NULL;
    else{
    while(padre!=NULL){
        if (padre->info==dato) return p;
        else{
        p = padre;
        if (dato < padre->info) padre = padre->izq;
        else padre = padre->der;}
    }
    return p;}
}

nodo *arbolbinord::buscar_nodo(int dato, nodo*q){
    q = raiz;
    while (q!=NULL){
        if(q->info == dato) return q;
        else{
            if(q->info>dato) q = q->izq;
            else q = q->der;
        }
    }
    return NULL;
}

int arbolbinord::buscarRaiz(){
    return raiz->info;
}

void arbolbinord::eliminar(int dato){
    nodo *d = buscar_nodo(dato,d);
    nodo *h = buscarpadre(dato,h);
    nodo *aux = NULL; 
    if((d->der == NULL) && (d->izq == NULL)){
        if (h->izq->info == dato){delete d; h->izq = NULL;}
        else {delete d; h->der = NULL;}
    }
    else if ((h->der->info == dato) && (d->izq == NULL)){
        aux = h->der;
        h->der = aux->der;
        delete aux; 
    }
    else if ((d->der == NULL) && (h->izq->info == dato)){
        aux = h->izq;
        h->izq = aux->izq;
        delete aux;
    }
    else if ((d->der != NULL) && (d->izq != NULL)){
        nodo *r;
        aux = d->der;
        while (aux->izq != NULL){aux = aux->izq;}
        r = buscarpadre(aux->info,r);
        d->info = aux ->info;
        r->izq = NULL;
        delete aux;
    }
}

void arbolbinord::inorden(nodo *raiz) { 
    stack<nodo *> s; 
    nodo *act = raiz; 
  
    while (act != NULL || s.empty() == false){ 
        while (act !=  NULL){
            s.push(act); 
            act = act->izq; 
        }
        act = s.top(); 
        s.pop(); 
  
        cout<<act->info<<" "; 
        act = act->der; 
    } 
} 

void arbolbinord::preorden(nodo *raiz) { 
    stack<nodo *> s;     
    s.push(raiz); 
    
    while (s.empty() == false){ 
        nodo *act = s.top(); 
        cout<<act->info<<" "; 
        s.pop(); 
        
        if (act->der) s.push(act->der); 
        if (act->izq) s.push(act->izq); 
    } 
} 

void arbolbinord::posorden(nodo* raiz) 
{   
    stack<nodo *> s1, s2; 
    s1.push(raiz); 
    nodo* act; 
  
    while (!s1.empty()) { 
        act = s1.top(); 
        s1.pop(); 
        s2.push(act); 
   
        if (act->izq) s1.push(act->izq); 
        if (act->der) s1.push(act->der); 
    } 
  
    while (!s2.empty()) { 
        act = s2.top(); 
        s2.pop(); 
        cout<<act->info<<" "; 
    } 
}

void arbolbinord::limpiar(nodo *r){
    if(r!= NULL){
        limpiar(r->izq);
        limpiar(r->der);
        delete r;
    }
}


arbolbinord::~arbolbinord(){
    limpiar(raiz); 
}

int main(){
    arbolbinord a;
    a.insertar(100);//->Raiz
    a.insertar(50); a.insertar(150); a.insertar(30); a.insertar(75);
    a.insertar(125); a.insertar(170); a.insertar(10); a.insertar(60);
    a.insertar(160); a.insertar(180); a.insertar(90);
    a.insertar(80); a.insertar(95);

    /*         ARBOL
    
                100
               /   \
              50   150
            /  \   /  \
           30  75 125 170
          /   / \     / \
        10   60 90  160 180
               / \
              80 95
    
    */
    
    cout<<"Antes de eliminar: "<<endl;
    cout<<"InOrden: ";
    a.inorden(a.buscar_nodo(a.buscarRaiz(),NULL));
    cout<<endl;
     cout<<"PreOrden: ";
    a.preorden(a.buscar_nodo(a.buscarRaiz(),NULL));
    cout<<endl;
    cout<<"PosOrden: ";
    a.posorden(a.buscar_nodo(a.buscarRaiz(),NULL));
    cout<<endl; 
    cout<<endl<<"Raiz: "<<a.buscarRaiz()<<endl;
    cout<<"---------------------------------------------------------------------------"<<endl;
    cout<<"------------------------------Eliminando-----------------------------------"<<endl;
    cout<<"---------------------------60--180--30--100--------------------------------"<<endl;

    a.eliminar(60); //Nodo hoja por izquierda
    a.eliminar(180); //Nodo hoja por derecha 
    a.eliminar(30); //Nodo con un hijo
    a.eliminar(100); //Nodo con dos hijos (raiz en ese caso)
    

    cout<<"---------------------------------------------------------------------------"<<endl;
    cout<<"-------------------------------Verifica------------------------------------"<<endl;
    //INGRESA UN DATO PARA BUSCAR 
    int b;
    cout<<"Ingresa una clave ";
    cin >>b; 
    cout<<"¿El nodo existe? -> "<<a.buscar(b)<<endl;

    //BUSCANDO PADRE 
    cout<<"Nodo padre: ";
    if (a.buscarpadre(b,NULL)!=NULL) cout<<a.buscarpadre(b,NULL)->info;
    else cout<<"Es nodo raiz, o no existe.";
    cout<<endl; 

    //BUSCANDO NODO
    cout<<"Retornado clave del nodo: ";
    if (a.buscar(b)!=false) cout<<a.buscar_nodo(b,NULL)->info;
    else cout<<"No existe ";
    cout<<endl;


    cout<<"Raiz: "<<a.buscarRaiz()<<endl;
    cout<<"---------------------------------------------------------------------------"<<endl;
    cout<<"------------------------------Impresiones----------------------------------"<<endl;
    cout<<"---------------------------------------------------------------------------"<<endl;

    cout<<"InOrden: ";
    a.inorden(a.buscar_nodo(a.buscarRaiz(),NULL));
    cout<<endl;
     cout<<"PreOrden: ";
    a.preorden(a.buscar_nodo(a.buscarRaiz(),NULL));
    cout<<endl;
    cout<<"PosOrden: ";
    a.posorden(a.buscar_nodo(a.buscarRaiz(),NULL));
    cout<<endl; 
    return 0;
}