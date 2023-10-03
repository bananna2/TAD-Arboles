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
