#include "ArbolKD.h"

bool ArbolKD::insertar(Punto val) {
    if(this->isVacio()) {
        NodoKD* nodo = new NodoKD(val);
        this->raiz = nodo;
        return true;
    }
    
    bool insertado = false;
    bool duplicado = false;
    NodoKD* nodo = this->raiz;
    int contador = 1;
    
    while(!insertado && !duplicado) {
        if(nodo->getDato() == val) {
            duplicado = true;
            break;
        }
        
        int x1 = nodo->getDato().x;
        int y1 = nodo->getDato().y;
        int x2 = val.x;
        int y2 = val.y;
        NodoKD* hijo;
        
        if(contador%2 == 1) {
            
            if(x2 <= x1) {
                hijo = nodo->getIzq();
            } else {
                hijo = nodo->getDer();
            }
            
            
            if(hijo == NULL) {
                
                if(x2 <= x1) {
                    nodo->setIzq(new NodoKD(val));
                } else {
                    nodo->setDer(new NodoKD(val));
                }
                
                insertado = true;
                
            } else {
                nodo = hijo;
            }
                
        } else {
            
            if(y2 <= y1) {
                hijo = nodo->getIzq();
            } else {
                hijo = nodo->getDer();
            }
            
            
            if(hijo == NULL) {
                
                if(y2 <= y1) {
                    nodo->setIzq(new NodoKD(val));
                } else {
                    nodo->setDer(new NodoKD(val));
                }
                
                insertado = true;
                
            } else {
                nodo = hijo;
            }
        }
        
    }
    
    return insertado;
}
