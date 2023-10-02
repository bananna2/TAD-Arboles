#ifndef __NodoAVL_H__
#define __NodoAVL_H__

template< class T >
class NodoAVL {
protected:
    NodoAVL<T>* papa;
    T dato;
    NodoAVL<T>* izq;
    NodoAVL<T>* der;
public:
    NodoAVL();
    ~NodoAVL();

    T& getDato();
    void setDato(T& val);

    NodoAVL<T>* getPapa();
    NodoAVL<T>* getIzq();
    NodoAVL<T>* getDer();

    void setPapa(NodoAVL<T>* papa);
    void setIzq(NodoAVL<T>* izq);
    void setDer(NodoAVL<T>* der);

    bool isHoja();
};

#include "NodoAVL.hxx"

#endif