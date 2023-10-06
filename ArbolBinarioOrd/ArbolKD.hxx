#ifndef ARBOL_KD_H#define ARBOL_KD_H
#include "NodoKD.h"
class ArbolKD {
private:
    NodoKD* raiz;
public:    ArbolKD();
    ~ArbolKD();
    bool isVacio() const;  
    bool insertar(Punto val);
   
};
#endif // ARBOL_KD_H
