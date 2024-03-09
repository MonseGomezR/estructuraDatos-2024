//
// Created by mgome.
//

#include "ListaD.h"

ListaD::ListaD() {
    raiz = nullptr;
}
ListaD::~ListaD() {
    NodoLD *aux = raiz;
    NodoLD *bor;
    while (aux != nullptr)
    {
        bor = aux;
        aux = aux->getSiguiente();
        delete bor;
    }
}

int ListaD::cantidad() const{
    NodoLD *aux = raiz;
    int cant = 0;
    while (aux != nullptr) {
        cant++;
        aux = aux->getSiguiente();
    }
    return cant;
}

void ListaD::insertar(int pos, Carta x) {
    if (pos <= cantidad() + 1){
        NodoLD *nuevo = new NodoLD();
        nuevo->setValor(x);
        if (pos == 1) {
            nuevo->setSiguiente(raiz);
            if (raiz != nullptr)
                raiz->setAnterior(nuevo);
            raiz = nuevo;
            raiz->getValor().setVista(true);
        }
        else if (pos == cantidad() + 1) {
            NodoLD *aux = raiz;
            while (aux->getSiguiente() != nullptr) {
                aux = aux->getSiguiente();
            }

            aux->setSiguiente(nuevo);
            nuevo->setAnterior(aux);
            nuevo->setSiguiente(nullptr);
        } else {
            NodoLD *aux = raiz;
            for (int f = 1; f <= pos - 2; f++)
                aux = aux->getSiguiente();
            NodoLD *siguiente = aux->getSiguiente();
            aux->setSiguiente(nuevo);
            nuevo->setAnterior(aux);
            nuevo->setSiguiente(siguiente);
            siguiente->setAnterior(nuevo);
        }
    }
}

Carta ListaD::extraer(int pos) {
    if (pos <= cantidad()) {
        Carta informacion;
        NodoLD *bor;
        if (pos == 1) {
            informacion = raiz->getValor();
            bor = raiz;
            raiz = raiz->getSiguiente();
            if ((raiz != nullptr))
                raiz->setAnterior(nullptr);
        }
        else {
            NodoLD *reco;
            reco = raiz;
            for (int f = 1; f <= pos - 2; f++)
                reco = reco->getSiguiente();
            NodoLD *prox = reco->getSiguiente();
            bor = prox;
            reco->setSiguiente(prox->getSiguiente());
            NodoLD *siguiente = prox->getSiguiente();
            if (siguiente != nullptr)
                siguiente->setAnterior(reco);
            informacion = prox->getValor();
        }
        delete bor;
        
        return informacion;
    }
    else
        return {};
}

void ListaD::borrar(int pos) {
    if (pos <= cantidad()) {
        NodoLD *bor;
        if (pos == 1) {
            bor = raiz;
            raiz = raiz->getSiguiente();
            if (raiz != nullptr)
                raiz->setAnterior(nullptr);
        }
        else {
            NodoLD *reco;
            reco = raiz;
            for (int f = 1; f <= pos - 2; f++)
                reco = reco->getSiguiente();
            NodoLD *prox = reco->getSiguiente();
            bor = prox;
            reco->setSiguiente(prox->getSiguiente());
            NodoLD *siguiente = prox->getSiguiente();
            if (siguiente != nullptr)
                siguiente->setAnterior(reco);
        }
        delete bor;
        
    }
}

bool ListaD::vacia() {
    if (raiz == nullptr)
        return true;
    else
        return false;
}

NodoLD* ListaD::obtenerNodo(int pos) {
    if (pos <= cantidad()) {
        NodoLD *aux = raiz;
        for (int i = 1; i < pos; i++) {
            aux = aux->getSiguiente();
        }
        return aux;
    } else {
        return nullptr;
    }
}
