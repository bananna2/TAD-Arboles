#include "ArbolAVL.h"

template< class T >
ArbolAVL<T>::ArbolAVL() {
    this->raiz = NULL;
}

template< class T >
ArbolAVL<T>::~ArbolAVL() {
    if (this->raiz != NULL) {
        delete this->raiz;
        this->raiz = NULL;
    }
}

template< class T >
bool ArbolAVL<T>::isVacio() {
    return this->raiz == NULL;
}

template< class T >
T ArbolAVL<T>::datoRaiz() {
    return (this->raiz)->getDato();
}

template< class T >
bool ArbolAVL<T>::insert(T n) {

    if(isVacio()) {
        NodoAVL<T> *nuevaRaiz = new NodoAVL<T>();
        nuevaRaiz->setDato(n);
        this->raiz = nuevaRaiz;
        return true;
    }

    NodoAVL<T> *nodo = this->raiz;
    NodoAVL<T> *padre = this->raiz;
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
        NodoAVL<T>* nuevo = new NodoAVL<T>();
        nuevo->setDato(n);
        nuevo->setPapa(padre);

        if(nuevo != NULL) {
            if (n < padre->getDato()) {
                padre->setIzq(nuevo);
            }else {
                padre->setDer(nuevo);
            }

            insertado = true;
            this->balanceo(nuevo);
        }
    }

    return insertado;
}

template< class T >
bool ArbolAVL<T>::erase(T n) {
    NodoAVL<T> *nodo = this->raiz;
    NodoAVL<T> *padre = this->raiz;
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
            balanceo(padre);
        } else if((nodo->getDer() != NULL) != (nodo->getIzq() != NULL)) {
            NodoAVL<T>* nuevoHijo;

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

            nuevoHijo->setPapa(padre);

            eliminado = true;
            balanceo(nuevoHijo);
        } else {
            bool maximo = false;
            NodoAVL<T>* nuevoPadre = nodo;
            NodoAVL<T>* nuevoHijo = nodo->getIzq();

            // Encontrar hijo maximo del arbol derecho
            while (!maximo) {
                if(nuevoHijo->getDer() == NULL) {
                    maximo = true;
                } else {
                    nuevoPadre = nuevoHijo;
                    nuevoHijo = nuevoHijo->getDer();
                }
            }

            // Si el primer nodo a la izquierda es ya el mayor del subarbol izquierdo
            // Si el ulitmo nodo tiene un hijo a la izquierda
            // Si el ultimo nodo es hoja
            if (nuevoPadre == nodo) {
                // Agarra el hijo derecho del nodo a eliminar
                nuevoHijo->setDer(nuevoPadre->getDer());
                nuevoHijo->getDer()->setPapa(nuevoHijo);
                nuevoPadre->setDer(NULL);

                // El padre mayor se le asigna el nuevoHijo
                if (n < padre->getDato()) {
                    padre->setIzq(nuevoHijo);
                } else {
                    padre->setDer(nuevoHijo);
                }

                nuevoHijo->setPapa(padre);

                // Al padre viejo se le quita las referencias restantes
                nuevoPadre->setIzq(NULL);
                delete nuevoPadre;
                balanceo(nuevoHijo);

            } else {

                if(nuevoHijo->getIzq() != NULL) {
                    // Reubica al hijo izquierdo del nuevoHijo
                    nuevoPadre->setDer(nuevoHijo->getIzq());
                    nuevoPadre->getDer()->setPapa(nuevoPadre);
                } else {
                    // Si no, solo corta la relacion con el nuevoHijo
                    nuevoPadre->setDer(NULL);
                }

                // Ubica a los dos nuevos hijos del nuevoHijo
                nuevoHijo->setDer(nodo->getDer());
                nuevoHijo->getDer()->setPapa(nuevoHijo);
                nodo->setDer(NULL);
                nuevoHijo->setIzq(nodo->getIzq());
                nuevoHijo->getIzq()->setPapa(nuevoHijo);
                nodo->setIzq(NULL);

                // Al padre mayor se le reubica el apuntdor
                if (n < padre->getDato()) {
                    padre->setIzq(nuevoHijo);
                } else {
                    padre->setDer(nuevoHijo);
                }
                nuevoHijo->setPapa(padre);

                delete nodo;
                balanceo(nuevoPadre);
            }

            eliminado = true;
        }
    }

    return eliminado;
}

template< class T >
void ArbolAVL<T>::balanceo(NodoAVL<T> *nodo) {
    int altIzq;
    int altDer;
    while(nodo != NULL) {
        if(nodo->getIzq() != NULL) {
            altIzq = this->altura(nodo->getIzq()) + 1;
        } else {
            altIzq = 0;
        }

        if(nodo->getDer() != NULL) {
            altDer = this->altura(nodo->getDer()) + 1;
        } else {
            altDer = 0;
        }

        if (altIzq - altDer <= -2) {
            // La pata derecha es más grande
            NodoAVL<T>* n = nodo->getDer();

            if (this->altura(n->getIzq()) > this->altura(n->getDer())) {
                // Si la pata derecha-izquierda es más grande, se hade rotDer-rotIzq - doblerota2
                NodoAVL<T>* n1 = nodo;
                this->rotDer(n1->getDer());
                this->rotIzq(n1);
            } else {
                // Si la pata derecha-derecha es más grande, se hace rotIzq
                this->rotIzq(nodo);
            }

        } else if(altIzq - altDer >= 2) {
            // La pata izquierda es más grande
            NodoAVL<T>* n = nodo->getIzq();



            if (this->altura(n->getIzq()) < this->altura(n->getDer())) {
                // Si la pata izquierda-derecha es más grande se hace, rotIzq-rotDer - doblerota1
                NodoAVL<T>* n1 = nodo;
                this->rotIzq(n1->getIzq());
                this->rotDer(n1);
            } else {
                // Si la pata izquierda-izquierda es más grande se hace, rotDer
                this->rotDer(nodo);
            }

        }

        nodo = nodo->getPapa();
    }
}

template< class T >
void ArbolAVL<T>::rotDer(NodoAVL<T> *nodo) {
    NodoAVL<T>* n2 = nodo;
    NodoAVL<T>* n1 = nodo->getIzq();
    // Si no hay padre significa que n2 es la raiz
    NodoAVL<T>* nPapa = n2->getPapa();

    n2->setIzq(n1->getDer());
    n1->setDer(n2);

    if(n2->getIzq() != NULL) {
        (n2->getIzq())->setPapa(n2);
    }

    n2->setPapa(n1);
    n1->setPapa(nPapa);

    if(nPapa == NULL) {
        this->raiz = n1;
    } else {

        if (nPapa->getDer() == nodo) {
            nPapa->setDer(n1);
        } else {
            nPapa->setIzq(n1);
        }

    }
}

template< class T >
void ArbolAVL<T>::rotIzq(NodoAVL<T> *nodo) {
    NodoAVL<T>* n1 = nodo;
    NodoAVL<T>* n2 = nodo->getDer();
    // Si no hay padre significa que n2 es la raiz
    NodoAVL<T>* nPapa = n1->getPapa();

    n1->setDer(n2->getIzq());
    n2->setIzq(n1);

    if (n1->getDer() != NULL) {
        (n1->getDer())->setPapa(n1);
    }
    n1->setPapa(n2);
    n2->setPapa(nPapa);

    if(nPapa == NULL) {
        this->raiz = n2;
    } else {
        if (nPapa->getDer() == nodo) {
            nPapa->setDer(n2);
        } else {
            nPapa->setIzq(n2);
        }
    }
}

template< class T >
bool ArbolAVL<T>::buscar(T n) {
    NodoAVL<T>* nodo = this->raiz;
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
int ArbolAVL<T>::altura() {
    if (this->isVacio()) {
        return -1;
    }

    return this->altura(this->raiz);
}

template< class T >
int ArbolAVL<T>::altura(NodoAVL<T>* nodo) {

    if(nodo == NULL) {
        return -1;
    }

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
unsigned int ArbolAVL<T>::size() {
    if(this->isVacio()){
        return 0;
    }

    return this->size(this->raiz);
}

template< class T >
unsigned int ArbolAVL<T>::size(NodoAVL<T> *nodo) {
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
void ArbolAVL<T>::preOrden() {
    if(!this->isVacio()) {
        this->preOrden(this->raiz);
    }
}

template< class T >
void ArbolAVL<T>::preOrden(NodoAVL<T>* nodo) {
    std::cout << nodo->getDato() << " ";

    if (nodo->getIzq() != NULL) {
        this->preOrden(nodo->getIzq());
    }

    if (nodo->getDer() != NULL) {
        this->preOrden(nodo->getDer());
    }
}

template< class T >
std::list<T> ArbolAVL<T>::inOrden() {
    if (!this->isVacio()) {
        return this->inOrden(this->raiz);
    } else {
        std::list<T> vacia;
        return vacia;
    }
}

template< class T >
std::list<T> ArbolAVL<T>::inOrden(NodoAVL<T> *nodo) {
    std::list<T> lista;
    if (nodo != NULL) {
        lista.splice(lista.end(), this->inOrden(nodo->getIzq()));
        lista.push_back(nodo->getDato());
        lista.splice(lista.end(), this->inOrden(nodo->getDer()));
    }
    return lista;
}

template< class T >
void ArbolAVL<T>::posOrden() {
    if(!this->isVacio()) {
        this->posOrden(this->raiz);
    }
}

template< class T >
void ArbolAVL<T>::posOrden(NodoAVL<T> *nodo) {
    if (nodo->getIzq() != NULL) {
        this->posOrden(nodo->getIzq());
    }

    if (nodo->getDer() != NULL) {
        this->posOrden(nodo->getDer());
    }

    std::cout << nodo->getDato() << " ";
}

template< class T >
void ArbolAVL<T>::nivelOrden() {
    if (!this->isVacio()) {
        std::queue<NodoAVL<T>*> cola;
        cola.push(this->raiz);
        NodoAVL<T>* nodo;

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