//
// Created by mgome on 4/03/2024.
//

#ifndef SOLITARIO2_NODO_H
#define SOLITARIO2_NODO_H


#include "Carta.h"

class Nodo {
private:
    Carta valor;
    Nodo *siguiente;
    
public:
    Nodo(Carta v, Nodo *sig) {
        valor = v;
        siguiente = sig;
    }
    Nodo() {
        valor = Carta();
        siguiente = nullptr;
    }
    Carta getValor() {return (valor);}
    Nodo *getSiguiente() {return(siguiente); };
    void setSiguiente(Nodo *v) {siguiente = v;};
    void setValor(Carta v) {valor = v;};
};


#endif //SOLITARIO2_NODO_H
