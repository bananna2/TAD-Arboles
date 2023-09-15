#ifndef __ARBOLGENERAL_H__
#define __ARBOLGENERAL_H__

#include "NodoGeneral.h"
#include<iostream>
#include<list>
#include<queue>
#include <iterator>

template< class T >
class ArbolGeneral {
protected:
    NodoGeneral<T>* raiz;
public:
    ArbolGeneral();
    ArbolGeneral(T val);
    ~ArbolGeneral();

    bool isVacio();

    NodoGeneral<T>* getRaiz();
    void setRaiz(NodoGeneral<T>* nraiz);

    bool insertNodo(T padre, T n);
    bool insertNodo(T padre, T n, NodoGeneral<T>* nodo);

    bool deleteNodo(T n);
    bool deleteNodo(T n, NodoGeneral<T>* nodo);

    bool buscar(T n);
    bool buscar(T n, NodoGeneral<T>* nodo);

    int altura();
    int altura(NodoGeneral<T>* nodo);

    unsigned int size();
    unsigned int size(NodoGeneral<T>* nodo);

    void preOrden();
    void preOrden(NodoGeneral<T>* nodo);

    void posOrden();
    void posOrden(NodoGeneral<T>* nodo);

    void nivelOrden();
};

#include "ArbolGeneral.hxx"

#endif