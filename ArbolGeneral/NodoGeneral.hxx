#include "NodoGeneral.h"

template< class T >
NodoGeneral<T>::NodoGeneral(){
    this->desc.clear();
}

template< class T >
NodoGeneral<T>::~NodoGeneral() {
    typename std::list< NodoGeneral<T>* >::iterator it;
    for (it = this->desc.begin(); it != this->desc.end(); it++) {
        delete *it;
    }
    this->desc.clear();
}

template< class T >
T& NodoGeneral<T>::getDato() {
    return this->dato;
}

template< class T >
void NodoGeneral<T>::setDato(T& val) {
    this->dato = val;
}

template< class T >
void NodoGeneral<T>::limpiarLista() {
    this->desc.clear();
}

template< class T >
void NodoGeneral<T>::addDesc(T& nval) {
    NodoGeneral<T> *nodo = new NodoGeneral();
    nodo->setDato(nval);
    this->desc.push_back(nodo);
}

template< class T >
bool NodoGeneral<T>::deleteDesc(T& val) {

    typename std::list< NodoGeneral<T>* >::iterator it;
    NodoGeneral<T> *aux;
    bool eliminado = false;

    for (it = this->desc.begin(); it != this->desc.end(); it++) {
        aux = *it;
        if(aux->getDato() == val) {
            break;
        }
    }


    if(it != this->desc.end()) {
        delete *it;
        this->desc.erase(it);
        eliminado = true;
    }

    return eliminado;
}

template< class T >
std::list<NodoGeneral<T>*> NodoGeneral<T>::getDesc() {
    return this->desc;
}

template< class T >
bool NodoGeneral<T>::isHoja() {
    return this->desc.size() == 0;
}