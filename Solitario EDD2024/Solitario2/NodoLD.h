//
// Created by mgome.
//

#ifndef SOLITARIO2_NODOLD_H
#define SOLITARIO2_NODOLD_H


#include "Carta.h"

class NodoLD {
private:
    Carta valor;
    NodoLD *siguiente;
    NodoLD *anterior;

public:
    NodoLD(Carta v, NodoLD *sig, NodoLD *ant) {
        valor = v;
        siguiente = sig;
    }
    NodoLD() {
        valor = Carta();
        siguiente = nullptr;
        anterior = nullptr;
    }

    Carta getValor() {return (valor);}
    void setValor(Carta v) {valor = v;}

    NodoLD *getSiguiente() {return(siguiente); };
    void setSiguiente(NodoLD *s) {siguiente = s;};

    NodoLD *getAnterior() {return(anterior); };
    void setAnterior(NodoLD *a) {anterior = a;};
};


#endif //SOLITARIO2_NODOLD_H
