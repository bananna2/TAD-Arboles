#ifndef __ARBOLBINORD_H__
#define __ARBOLBINORD_H__

#include"NodoBinario.h"
#include<iostream>
#include<queue>

template< class T >
class ArbolBinarioOrd {
protected:
    NodoBinario<T>* raiz;
public:
    ArbolBinarioOrd();
    ~ArbolBinarioOrd();

    bool isVacio();

    T datoRaiz();

    bool insertNodo(T n);

    bool deleteNodo(T n);

    bool buscar(T n);

    int altura();
    int altura(NodoBinario<T>* nodo);

    unsigned int size();
    unsigned int size(NodoBinario<T>* nodo);

    void preOrden();
    void preOrden(NodoBinario<T>* nodo);

    void inOrden();
    void inOrden(NodoBinario<T>* nodo);

    void posOrden();
    void posOrden(NodoBinario<T>* nodo);

    void nivelOrden();
};

#include "ArbolBinarioOrd.hxx"

#endif