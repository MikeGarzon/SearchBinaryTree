#ifndef STACK_H
#define STACK_H

class Stack
{public:
    Stack();
   ~Stack();
    void push(int v);
    int pop();
    int empty();
    int top();
 private:
    struct nodo
       {int clave; struct nodo *siguiente;};
    struct  nodo *cabeza, *z;
};
 
Stack::Stack()
{ cabeza = new nodo;  z=new nodo;
  cabeza->siguiente=z; z->siguiente =z;
}

Stack::~Stack()
{struct nodo *t=cabeza;
 while (t!=z)
       {cabeza=t;  t=t->siguiente;  delete cabeza;}
        delete z; //z=t
}

void Stack::push(int v)
{struct nodo *t=new nodo;
 t->clave = v;  t->siguiente=cabeza->siguiente;
cabeza->siguiente=t;
}

int Stack::pop()
{int x;
        struct nodo *t = cabeza->siguiente;
        cabeza->siguiente = t->siguiente; x=t->clave;
        delete t; return x;
}

int Stack::empty()
{return cabeza->siguiente == z;}

int Stack::top()
{return cabeza->siguiente->clave;}

#endif