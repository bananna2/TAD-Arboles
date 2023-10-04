#ifndef __NODOBINARIO_H__
#define __NODOBINARIO_H__

#include <list>
#include <iterator>

template< class T >
class NodoBinario {
protected:
    T dato;
    NodoBinario<T>* izq;
    NodoBinario<T>* der;
public:
    NodoBinario();
    ~NodoBinario();

    T& getDato();
    void setDato(T& val);

    NodoBinario<T>* getIzq();
    NodoBinario<T>* getDer();

    void setIzq(NodoBinario<T>* izq);
    void setDer(NodoBinario<T>* der);

    bool isHoja();
};

#include "NodoBinario.hxx"

#endif