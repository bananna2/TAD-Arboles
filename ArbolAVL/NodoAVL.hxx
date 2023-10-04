#include "NodoAVL.h"

template <class T>
NodoAVL<T>::NodoAVL(){
    dato = T();
    this->izq = this->der = this->papa = nullptr;
}

template <class T>
NodoAVL<T>::~NodoAVL(){
    if (izq != NULL) {
        delete izq;
    }
    if (der != NULL) {
        delete der;
    }
    if (papa != NULL) {
        papa = NULL;
    }
}

template <class T>
T& NodoAVL<T>::getDato(){
    return dato;
}

template <class T>
void NodoAVL<T>::setDato(T& val){
    dato = val;
}

template <class T>
NodoAVL<T>* NodoAVL<T>::getPapa() {
    return this->papa;
}

template <class T>
void NodoAVL<T>::setPapa(NodoAVL<T> *papa) {
    this->papa = papa;
}

template <class T>
NodoAVL<T>* NodoAVL<T>::getIzq(){
    return izq;
}

template <class T>
void NodoAVL<T>::setIzq(NodoAVL<T>* izq){
    this->izq = izq;
}

template <class T>
NodoAVL<T>* NodoAVL<T>::getDer(){
    return der;
}

template <class T>
void NodoAVL<T>::setDer(NodoAVL<T>* der){
    this->der = der;
}

template <class T>
bool NodoAVL<T>::isHoja() {
    return (this->der == NULL) && (this->izq == NULL);
}
