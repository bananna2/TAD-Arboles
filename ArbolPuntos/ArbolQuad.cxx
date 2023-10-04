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
    return this->raiz->getDato();
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
    if(this->isVacio()) {
        NodoQuad* nodo = new NodoQuad(val);
        this->raiz = nodo;
        return true;
    }
    
    bool insertado = false;
    bool duplicado = false;
    NodoQuad* nodo = this->raiz;

    while(!insertado && !duplicado) {
        if(nodo->getDato() == val) {
            duplicado = true;
            break;
        }

        int x1 = nodo->getDato().x;
        int x2 = val.x;
        int y1 = nodo->getDato().y;
        int y2 = val.y;
        
        if(x2 <= x1 && y2 > y1) {

            if(nodo->getHijo1() == NULL) {
                nodo->setHijo1(new NodoQuad(val));
                insertado = true;
            } else {
                nodo = nodo->getHijo1();
            }
            
        } else if(x2 > x1 && y2 > y1) {
            
            if(nodo->getHijo2() == NULL) {
                nodo->setHijo2(new NodoQuad(val));
                insertado = true;
            } else {
                nodo = nodo->getHijo2();
            }
            
        } else if(x2 <= x1 && y2 <= y1) {

            if(nodo->getHijo3() == NULL) {
                nodo->setHijo3(new NodoQuad(val));
                insertado = true;
            } else {
                nodo = nodo->getHijo3();
            }
            
        } else {
            
            if(nodo->getHijo4() == NULL) {
                nodo->setHijo4(new NodoQuad(val));
                insertado = true;
            } else {
                nodo = nodo->getHijo4();
            }
            
        }
        
    }

    return insertado;
}

void ArbolQuad::preOrden() {
    if(!this->isVacio()) { 
        this->preOrden(this->raiz); 
    }
}

void ArbolQuad::preOrden(NodoQuad* nodo) { 
     std::cout << nodo->getDato() << " "; 
  
     if (nodo->getHijo1() != NULL) { 
         this->preOrden(nodo->getHijo1()); 
     }
    
     if (nodo->getHijo2() != NULL) { 
         this->preOrden(nodo->getHijo2()); 
     }
    
     if (nodo->getHijo3() != NULL) { 
         this->preOrden(nodo->getHijo3()); 
     }
    
     if (nodo->getHijo4() != NULL) { 
         this->preOrden(nodo->getHijo4()); 
     }
 }

void ArbolQuad::posOrden() {
    if(!this->isVacio()) { 
        this->posOrden(this->raiz); 
    }
}

void ArbolQuad::posOrden(NodoQuad* nodo) { 
  
    if (nodo->getHijo1() != NULL) { 
         this->posOrden(nodo->getHijo1()); 
    }
    
    if (nodo->getHijo2() != NULL) { 
         this->posOrden(nodo->getHijo2()); 
    }
    
    if (nodo->getHijo3() != NULL) { 
         this->posOrden(nodo->getHijo3()); 
    }
    
    if (nodo->getHijo4() != NULL) { 
         this->posOrden(nodo->getHijo4()); 
    }
    
    std::cout << nodo->getDato() << " "; 
 }

void ArbolQuad::nivelOrden() {
    if (!this->isVacio()) { 
         std::queue<NodoQuad *> cola; 
         cola.push(this->raiz); 
         NodoQuad* nodo; 
  
         while(!cola.empty()) { 
            nodo = cola.front(); 
            cola.pop(); 
            std::cout << nodo->getDato() << " "; 
  
            if (nodo->getHijo1() != NULL) { 
                 cola.push(nodo->getHijo1()); 
            }
            
            if (nodo->getHijo2() != NULL) { 
                 cola.push(nodo->getHijo2()); 
            }
            
            if (nodo->getHijo3() != NULL) { 
                 cola.push(nodo->getHijo3()); 
            }
            
            if (nodo->getHijo4() != NULL) { 
                 cola.push(nodo->getHijo4()); 
            }
  
         } 
  
     }
}
