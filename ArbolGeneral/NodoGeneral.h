#ifndef __NODOGENERAL_H__
#define __NODOGENERAL_H__

#include <list>
#include <iterator>

template< class T >
class NodoGeneral {
protected:
    T dato;
    std::list<NodoGeneral<T>*> desc;
public:
    NodoGeneral();
    ~NodoGeneral();
    T& getDato();
    void setDato(T& val);
    void limpiarLista();
    void addDesc(T& nval);
    bool deleteDesc(T& val);
    std::list<NodoGeneral<T>*> getDesc();
    bool isHoja();
};

#include "NodoGeneral.hxx"

#endif