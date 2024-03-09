//
// Created by mgome.
//

#include "Pila.h"

Pila::Pila() {
    tope = nullptr;
    size = 0;
}
Pila::~Pila(){
    Nodo *aux;
    while(tope!=nullptr) {
        aux = tope;
        tope = (*tope).getSiguiente();
        delete aux;
    }
}

void Pila::push(Carta v){
    Nodo *n = new Nodo(v, tope);
    tope = n;
}
Carta Pila::pop(){
    Carta v;
    if(tope == nullptr) return {"0", "0"};
    Nodo *n = tope;
    tope = (*n).getSiguiente();
    v = (*n).getValor();
    delete n;
    return v;
}

