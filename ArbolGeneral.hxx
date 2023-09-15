#include "ArbolGeneral.h"

template< class T >
ArbolGeneral<T>::ArbolGeneral() {
    this->raiz = NULL;
}

template< class T >
ArbolGeneral<T>::ArbolGeneral(T val) {
    NodoGeneral<T>* nodo = new NodoGeneral<T>;
    nodo->fijarDato(val);
    this->raiz = nodo;
}

template< class T >
ArbolGeneral<T>::~ArbolGeneral() {
    delete this->raiz;
    this->raiz = NULL;
}

template< class T >
bool ArbolGeneral<T>::isVacio() {
    return this->raiz == NULL;
}

template< class T >
NodoGeneral<T>* ArbolGeneral<T>::getRaiz() {
    return this->raiz;
}

template< class T >
void ArbolGeneral<T>::setRaiz(NodoGeneral<T>* nraiz) {
    this->raiz = nraiz;
}

template< class T >
bool ArbolGeneral<T>::insertNodo(T padre, T n) {
    if(this->isVacio()){
        NodoGeneral<T>* nodo = new NodoGeneral<T>;
        nodo->setDato(n);
        this->raiz = nodo;
        return true;
    }

    return this->insertNodo(padre, n, this->raiz);
}

template< class T >
bool ArbolGeneral<T>::insertNodo(T padre, T n, NodoGeneral<T>* nodo) {
    if(nodo->getDato() == padre) {
        nodo->addDesc(n);
        return true;
    }

    typename std::list< NodoGeneral<T>* >::iterator it;
    typename std::list< NodoGeneral<T>* >::iterator itE;

    NodoGeneral<T> *aux;
    std::list<NodoGeneral<T>*> auxList = nodo->getDesc();

    it = auxList.begin();
    itE = auxList.end();

    for( ; it != itE; it++) {
        aux = *it;
        if(this->insertNodo(padre, n, aux)) {
            return true;
        }
    }

    return false;
}

template< class T >
bool ArbolGeneral<T>::deleteNodo(T n) {
    if(this->isVacio()){
        return false;
    }

    if(this->raiz->getDato() == n) {
        delete this->raiz;
        this->raiz = NULL;
        return true;
    }

    return this->deleteNodo(n, this->raiz);
}

template< class T >
bool ArbolGeneral<T>::deleteNodo(T n, NodoGeneral<T>* nodo) {

    if(nodo->deleteDesc(n)) {
        return true;
    }

    typename std::list< NodoGeneral<T>* >::iterator it;
    typename std::list< NodoGeneral<T>* >::iterator itE;

    NodoGeneral<T> *aux;
    std::list<NodoGeneral<T>*> auxList = nodo->getDesc();

    it = auxList.begin();
    itE = auxList.end();

    for( ; it != itE; it++) {
        aux = *it;
        if(this->deleteNodo(n, aux)) {
            return true;
        }
    }

    return false;
}

template< class T >
bool ArbolGeneral<T>::buscar(T n) {
    if(this->isVacio()){
        return false;
    }

    return this->buscar(n, this->raiz);
}

template< class T >
bool ArbolGeneral<T>::buscar(T n, NodoGeneral<T> *nodo) {
    if(nodo->getDato() == n) {
        return true;
    }

    typename std::list< NodoGeneral<T>* >::iterator it;
    typename std::list< NodoGeneral<T>* >::iterator itE;

    NodoGeneral<T> *aux;
    std::list<NodoGeneral<T>*> auxList = nodo->getDesc();

    it = auxList.begin();
    itE = auxList.end();

    for( ; it != itE; it++) {
        aux = *it;
        if(this->buscar(n, aux)) {
            return true;
        }
    }

    return false;
}

template< class T >
int ArbolGeneral<T>::altura() {
    if (this->isVacio()) {
        return -1;
    }

    return this->altura(this->raiz);
}

template< class T >
int ArbolGeneral<T>::altura(NodoGeneral<T>* nodo) {
    int alt = -1;

    if(nodo->isHoja()) {
        alt = 0;
    } else {
        int alth;
        typename std::list< NodoGeneral<T>* >::iterator it;
        typename std::list< NodoGeneral<T>* >::iterator itE;

        NodoGeneral<T> *aux;
        std::list<NodoGeneral<T>*> auxList = nodo->getDesc();

        it = auxList.begin();
        itE = auxList.end();

        for( ; it != itE; it++) {
            aux = *it;
            alth = this->altura(aux);
            if (alt < alth+1) {
                alt = alth+1;
            }
        }
    }

    return alt;
}

template< class T >
unsigned int ArbolGeneral<T>::size() {
    if(this->isVacio()){
        return 0;
    }

    return this->size(this->raiz) + 1;
}

template< class T >
unsigned int ArbolGeneral<T>::size(NodoGeneral<T> *nodo) {
    unsigned int tam = nodo->getDesc().size();

    typename std::list< NodoGeneral<T>* >::iterator it;
    typename std::list< NodoGeneral<T>* >::iterator itE;

    NodoGeneral<T> *aux;
    std::list<NodoGeneral<T>*> auxList = nodo->getDesc();

    it = auxList.begin();
    itE = auxList.end();

    for( ; it != itE; it++) {
        aux = *it;
        tam += this->size(aux);
    }

    return tam;
}

template< class T >
void ArbolGeneral<T>::preOrden() {
    if(!this->isVacio()) {
        this->preOrden(this->raiz);
    }
}

template< class T >
void ArbolGeneral<T>::preOrden(NodoGeneral<T>* nodo) {
    std::cout << nodo->getDato() << " ";

    typename std::list< NodoGeneral<T>* >::iterator it;
    typename std::list< NodoGeneral<T>* >::iterator itE;

    std::list<NodoGeneral<T>*> auxList = nodo->getDesc();

    it = auxList.begin();
    itE = auxList.end();

    for( ; it != itE; it++) {
        this->preOrden(*it);
    }
}


template< class T >
void ArbolGeneral<T>::posOrden() {
    if(!this->isVacio()) {
        this->posOrden(this->raiz);
    }
}

template< class T >
void ArbolGeneral<T>::posOrden(NodoGeneral<T> *nodo) {
    typename std::list< NodoGeneral<T>* >::iterator it;
    typename std::list< NodoGeneral<T>* >::iterator itE;

    std::list<NodoGeneral<T>*> auxList = nodo->getDesc();

    it = auxList.begin();
    itE = auxList.end();

    for( ; it != itE; it++) {
        this->posOrden(*it);
    }

    std::cout << nodo->getDato() << " ";
}

template< class T >
void ArbolGeneral<T>::nivelOrden() {
    if(!this->isVacio()) {
        std::queue< NodoGeneral<T>* > niveles;
        niveles.push(this->raiz);
        NodoGeneral<T>* aux;

        std::cout << this->raiz->getDato() << " ";

        while(!niveles.empty()) {
            aux = niveles.front();
            niveles.pop();

            typename std::list< NodoGeneral<T>* >::iterator it;
            typename std::list< NodoGeneral<T>* >::iterator itE;

            NodoGeneral<T> *aux2;
            std::list<NodoGeneral<T>*> auxList = aux->getDesc();

            it = auxList.begin();
            itE = auxList.end();

            for( ; it != itE; it++) {
                aux2 = *it;
                std::cout << aux2->getDato() << " ";
                niveles.push(aux2);
            }
        }
    }
}