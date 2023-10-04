#include "ArbolBinarioOrd.h"

template< class T >
ArbolBinarioOrd<T>::ArbolBinarioOrd() {
    this->raiz = NULL;
}

template< class T >
ArbolBinarioOrd<T>::~ArbolBinarioOrd() {
    if (this->raiz != NULL) {
        delete this->raiz;
        this->raiz = NULL;
    }
}

template< class T >
bool ArbolBinarioOrd<T>::isVacio() {
    return this->raiz == NULL;
}

template< class T >
T ArbolBinarioOrd<T>::datoRaiz() {
    return (this->raiz)->getDato();
}

template< class T >
bool ArbolBinarioOrd<T>::insertNodo(T n) {

    if(isVacio()) {
        NodoBinario<T> *nuevaRaiz = new NodoBinario<T>();
        nuevaRaiz->setDato(n);
        this->raiz = nuevaRaiz;
        return true;
    }

    NodoBinario<T> *nodo = this->raiz;
    NodoBinario<T> *padre = this->raiz;
    bool insertado = false;
    bool duplicado = false;

    while (nodo != NULL) {
        padre = nodo;
        if (n < nodo->getDato()) {
            nodo = nodo->getIzq();
        } else if (n > nodo->getDato()) {
            nodo = nodo->getDer();
        } else {
            duplicado = true;
            break;
        }
    }

    if(!duplicado) {
        NodoBinario<T>* nuevo = new NodoBinario<T>();
        nuevo->setDato(n);

        if(nuevo != NULL) {
            if (n < padre->getDato()) {
                padre->setIzq(nuevo);
            }else {
                padre->setDer(nuevo);
            }

            insertado = true;
        }
    }

    return insertado;
}

template< class T >
bool ArbolBinarioOrd<T>::deleteNodo(T n) {
    NodoBinario<T> *nodo = this->raiz;
    NodoBinario<T> *padre = this->raiz;
    bool eliminado = false;
    bool encontrado = false;

    while (nodo != NULL && !encontrado) {
        if (n < nodo->getDato()) {
            padre = nodo;
            nodo = nodo->getIzq();
        } else if (n > nodo->getDato()) {
            padre = nodo;
            nodo = nodo->getDer();
        } else {
            encontrado = true;
        }
    }

    if(encontrado) {
        // No tiene hijos
        // Tiene un hijo
        // Tiene dos hijos
        if(nodo->isHoja()) {
            delete nodo;

            if (n < padre->getDato()) {
                padre->setIzq(NULL);
            } else {
                padre->setDer(NULL);
            }

            eliminado = true;
        } else if((nodo->getDer() != NULL) != (nodo->getIzq() != NULL)) {
            NodoBinario<T>* nuevoHijo;

            if (nodo->getDer() != NULL) {
                nuevoHijo = nodo->getDer();
                nodo->setDer(NULL);
            } else {
                nuevoHijo = nodo->getIzq();
                nodo->setIzq(NULL);
            }

            delete nodo;

            if (n < padre->getDato()) {
                padre->setIzq(nuevoHijo);
            } else {
                padre->setDer(nuevoHijo);
            }

            eliminado = true;
        } else {
            bool maximo = false;
            NodoBinario<T>* nuevoPadre = nodo;
            NodoBinario<T>* nuevoHijo = nodo->getIzq();

            // Encontrar hijo maximo del arbol derecho
            while (!maximo) {
                if(nuevoHijo->getDer() == NULL) {
                    maximo = true;
                } else {
                    nuevoPadre = nuevoHijo;
                    nuevoHijo = nuevoHijo->getDer();
                }
            }

            // Si el primer nood a la izquierda es ya el mayor del subarbol izquierdo
            // Si el ulitmo nodo tiene un hijo a la izquierda
            // Si el ultimo nodo es hoja
            if (nuevoPadre == nodo) {
                // Agarra el hijo derecho del nodo a eliminar
                nuevoHijo->setDer(nuevoPadre->getDer());
                nuevoPadre->setDer(NULL);

                // El padre mayor se le asigna el nuevoHijo
                if (n < padre->getDato()) {
                    padre->setIzq(nuevoHijo);
                } else {
                    padre->setDer(nuevoHijo);
                }

                // Al padre viejo se le quita las referencias restantes
                nuevoPadre->setIzq(NULL);
                delete nuevoPadre;

            } else {

                if(nuevoHijo->getIzq() != NULL) {
                    // Reubica al hijo izquierdo del nuevoHijo
                    nuevoPadre->setDer(nuevoHijo->getIzq());
                } else {
                    // Si no, solo corta la relacion con el nuevoHijo
                    nuevoPadre->setDer(NULL);
                }

                // Ubica a los dos nuevos hijos del nuevoHijo
                nuevoHijo->setDer(nodo->getDer());
                nodo->setDer(NULL);
                nuevoHijo->setIzq(nodo->getIzq());
                nodo->setIzq(NULL);

                // Al padre mayor se le reubica el apuntdor
                if (n < padre->getDato()) {
                    padre->setIzq(nuevoHijo);
                } else {
                    padre->setDer(nuevoHijo);
                }

                delete nodo;
            }

            eliminado = true;
        }
    }

    return eliminado;
}

template< class T >
bool ArbolBinarioOrd<T>::buscar(T n) {
    NodoBinario<T>* nodo = this->raiz;
    bool encontrado = false;

    while (nodo != NULL && !encontrado) {
        if (n < nodo->getDato()) {
            nodo = nodo->getIzq();
        } else if (n > nodo->getDato()) {
            nodo = nodo->getDer();
        } else {
            encontrado = true;
        }
    }

    return encontrado;
}

template< class T >
int ArbolBinarioOrd<T>::altura() {
    if (this->isVacio()) {
        return -1;
    }

    return this->altura(this->raiz);
}

template< class T >
int ArbolBinarioOrd<T>::altura(NodoBinario<T>* nodo) {
    int alt;

    if(nodo->isHoja()) {
        alt = 0;
    } else {
        int valIzq = -1;
        int valDer = -1;

        if(nodo->getIzq() != NULL) {
            valIzq = this->altura(nodo->getIzq());
        }

        if(nodo->getDer() != NULL) {
            valDer = this->altura(nodo->getDer());
        }

        if(valIzq > valDer) {
            alt = valIzq + 1;
        } else {
            alt = valDer + 1;
        }
    }

    return alt;
}

template< class T >
unsigned int ArbolBinarioOrd<T>::size() {
    if(this->isVacio()){
        return 0;
    }

    return this->size(this->raiz);
}

template< class T >
unsigned int ArbolBinarioOrd<T>::size(NodoBinario<T> *nodo) {
    unsigned int tam = 0;

    if (nodo->getIzq() != NULL) {
        tam += this->size(nodo->getIzq());
    }

    if (nodo->getDer() != NULL) {
        tam += this->size(nodo->getDer());
    }

    return tam + 1;
}

template< class T >
void ArbolBinarioOrd<T>::preOrden() {
    if(!this->isVacio()) {
        this->preOrden(this->raiz);
    }
}

template< class T >
void ArbolBinarioOrd<T>::preOrden(NodoBinario<T>* nodo) {
    std::cout << nodo->getDato() << " ";

    if (nodo->getIzq() != NULL) {
        this->preOrden(nodo->getIzq());
    }

    if (nodo->getDer() != NULL) {
        this->preOrden(nodo->getDer());
    }
}

template< class T >
void ArbolBinarioOrd<T>::inOrden() {
    if (!this->isVacio()) {
        this->inOrden(this->raiz);
    }
}

template< class T >
void ArbolBinarioOrd<T>::inOrden(NodoBinario<T> *nodo) {
    if (nodo != NULL) {
        this->inOrden(nodo->getIzq());
        std::cout << nodo->getDato() << " ";
        this->inOrden(nodo->getDer());
    }
}

template< class T >
void ArbolBinarioOrd<T>::posOrden() {
    if(!this->isVacio()) {
        this->posOrden(this->raiz);
    }
}

template< class T >
void ArbolBinarioOrd<T>::posOrden(NodoBinario<T> *nodo) {
    if (nodo->getIzq() != NULL) {
        this->posOrden(nodo->getIzq());
    }

    if (nodo->getDer() != NULL) {
        this->posOrden(nodo->getDer());
    }

    std::cout << nodo->getDato() << " ";
}

template< class T >
void ArbolBinarioOrd<T>::nivelOrden() {
    if (!this->isVacio()) {
        std::queue<NodoBinario<T>*> cola;
        cola.push(this->raiz);
        NodoBinario<T>* nodo;

        while(!cola.empty()) {
            nodo = cola.front();
            cola.pop();
            std::cout << nodo->getDato() << " ";

            if (nodo->getIzq() != NULL) {
                cola.push(nodo->getIzq());
            }

            if (nodo->getDer() != NULL) {
                cola.push(nodo->getDer());
            }

        }

    }
}