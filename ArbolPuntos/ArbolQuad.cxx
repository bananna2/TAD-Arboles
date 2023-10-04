#include "ArbolQuad.h"

ArbolQuad::ArbolQuad() {
    this->raiz = NULL;
}


ArbolQuad::ArbolQuad(Punto val) {
    NodoQuad* nodo = new NodoQuad(val);
    this->raiz = nodo;
}


ArbolQuad::~ArbolQuad() {
    delete this->raiz;
    this->raiz = NULL;
}

Punto ArbolQuad::datoRaiz() {
    if(!this->isVacio()) {
        return this->raiz->getDato();
    }
    return NULL;
}

NodoQuad* ArbolQuad::getRaiz() {
    return this->raiz;
}

void ArbolQuad::setRaiz(NodoQuad* n_raiz) {
    this->raiz = n_raiz;
}

bool ArbolQuad::isVacio() {
    return this->raiz == NULL;   
}

bool ArbolQuad::insert(Punto val) {
    return false;
}

void ArbolQuad::preOrden() {
    
}

void ArbolQuad::posOrden() {
    
}

void ArbolQuad::nivelOrden() {

}
