#ifndef __NODOQUAD_H__
#define __NODOQUAD_H__

#include "Punto.h"

class NodoQuad {
protected:
    Punto dato;
    NodoQuad* hijo1;
    NodoQuad* hijo2;
    NodoQuad* hijo3;
    NodoQuad* hijo4;
    
public:
    NodoQuad();
    NodoQuad(Punto val);
    ~NodoQuad();
    
    Punto getDato();
    void setDato(Punto val);
    
    NodoQuad* getHijo1();
    NodoQuad* getHijo2();
    NodoQuad* getHijo3();
    NodoQuad* getHijo4();
    void setHijo1(NodoQuad* s1);
    void setHijo2(NodoQuad* s2);
    void setHijo3(NodoQuad* s3);
    void setHijo4(NodoQuad* s4);
    bool isHoja();
};

#endif
