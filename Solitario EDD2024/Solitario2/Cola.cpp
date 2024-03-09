//
// Created by mgome.
//

#include "Cola.h"

Cola::Cola() {
    primero = nullptr;
    ultimo = nullptr;
    size = 0;
}
Cola::~Cola(){
    Nodo *aux;
    Nodo *borrar;
    aux = primero;
    while (aux != nullptr) {
        borrar = aux;
        aux = aux->getSiguiente();
        delete borrar;
    }
}

void Cola::agregar(Carta v) {
    Nodo *n = new Nodo();
    n->setValor(v);
    n->setSiguiente(nullptr);

    if(ultimo != nullptr) {
        ultimo->setSiguiente(n);
    }

    ultimo = n;

    if(primero == nullptr) {
        primero = n;
    }
    size++;
}
Carta Cola::quitar(){
    if(primero == nullptr) {
        return {};
    }

    Nodo* temp = primero;
    Carta info = primero->getValor();
    primero = primero->getSiguiente();

    if(primero == nullptr) {
        ultimo = nullptr;
    }
    size--;
    delete temp;
    return info;
}
Carta Cola::quitarUltimo() {
    if (ultimo != nullptr) {
        Carta informacion = ultimo->getValor();
        Nodo *aux = primero;
        if (primero == ultimo) {
            delete ultimo;
            primero = nullptr;
            ultimo = nullptr;
        } else {
            while (aux->getSiguiente() != ultimo) {
                aux = aux->getSiguiente();
            }
            delete ultimo;
            ultimo = aux;
            ultimo->setSiguiente(nullptr);
        }
        size--;
        return informacion;
    } else {
        return {};
    }
}
