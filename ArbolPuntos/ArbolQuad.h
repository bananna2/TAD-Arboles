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
    NodoQuad* getRaiz();
    void setRaiz(NodoQuad* n_raiz);
    
    bool isVacio();
    bool insert(Punto val);
    
    void preOrden();
    void preOrden(NodoQuad* nodo);

    void posOrden();
    void posOrden(NodoQuad* nodo);

    void nivelOrden();
};

#endif
