#ifndef __ARBOLQUAD_H__
#define __ARBOLQUAD_H__

#include "NodoQuad.h"
#include "Punto.h"

class ArbolQuad {
protected:
    NodoQuad* raiz;
    
public:
    ArbolQuad();
    ArbolQuad(Punto val);
    ~ArbolQuad();
    
    Punto datoRaiz();
    NodoQuad* obtenerRaiz();
    void fijarRaiz(NodoQuad* n_raiz);
    
    bool isVacio();
    bool insert(Punto val);
    
    void preOrden();
    void inOrden();
    void posOrden();
    void nivelOrden();
};

#endif
