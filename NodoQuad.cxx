#include "NodoQuad.h"

Punto NodoQuad::getDato() {
  return this->dato;
}


void NodoQuad::setDato(Punto val) {
  this->dato = val;
}


NodoQuad* NodoQuad::getHijo1() {
  return this->hijo1;
}


NodoQuad* NodoQuad::getHijo2() {
  return this->hijo2;
}


NodoQuad* NodoQuad::getHijo3() {
  return this->hijo3;
}


NodoQuad* NodoQuad::getHijo4() {
  return this->hijo4;
}


void NodoQuad::setHijo1(NodoQuad* s1) {
  this->hijo1 = s1;
}


void NodoQuad::setHijo2(NodoQuad* s2) {
  this->hijo2 = s2;
}


void NodoQuad::setHijo3(NodoQuad* s3) {
  this->hijo3 = s3;
}


void NodoQuad::setHijo4(NodoQuad* s4) {
  this->hijo4 = s4;
}


bool NodoQuad::isHoja() {
  return (this->hijo1 == nullptr) && (this->hijo2 == nullptr) && (this->hijo3 == nullptr) && (this->hijo4 == nullptr);
}
