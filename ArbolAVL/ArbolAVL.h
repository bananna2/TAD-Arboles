#ifndef __ARBOLBAVL_H__
#define __ARBOLBAVL_H__

#include"NodoAVL.h"
#include<iostream>
#include<queue>
#include <list>

template< class T >
class ArbolAVL {
protected:
    NodoAVL<T>* raiz;
public:
    ArbolAVL();
    ~ArbolAVL();

    bool isVacio();

    T datoRaiz();

    bool insert(T n);

    bool erase(T n);
    
    void balanceo(NodoAVL<T>* nodo);
    void rotDer(NodoAVL<T>* nodo);
    void rotIzq(NodoAVL<T>* nodo);

    bool buscar(T n);

    int altura();
    int altura(NodoAVL<T>* nodo);

    unsigned int size();
    unsigned int size(NodoAVL<T>* nodo);

    void preOrden();
    void preOrden(NodoAVL<T>* nodo);

    std::list<T> inOrden();
    std::list<T> inOrden(NodoAVL<T>* nodo);

    void posOrden();
    void posOrden(NodoAVL<T>* nodo);

    void nivelOrden();
};

#include "ArbolAVL.hxx"

#endif