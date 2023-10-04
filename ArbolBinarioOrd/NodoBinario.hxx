#include "NodoBinario.h"

template <class T>
NodoBinario<T>::NodoBinario(){
    dato = T();
    izq = der = nullptr;
}

template <class T>
NodoBinario<T>::~NodoBinario(){
    if (izq != NULL) {
        delete izq;
    }
    if (der != NULL) {
        delete der;
    }
}

template <class T>
T& NodoBinario<T>::getDato(){
    return dato;
}

template <class T>
void NodoBinario<T>::setDato(T& val){
    dato = val;
}

template <class T>
NodoBinario<T>* NodoBinario<T>::getIzq(){
    return izq;
}

template <class T>
void NodoBinario<T>::setIzq(NodoBinario<T>* izq){
    this->izq = izq;
}

template <class T>
NodoBinario<T>* NodoBinario<T>::getDer(){
    return der;
}

template <class T>
void NodoBinario<T>::setDer(NodoBinario<T>* der){
    this->der = der;
}

template <class T>
bool NodoBinario<T>::isHoja() {
    return (this->der == NULL) && (this->izq == NULL);
}
