//
// Created by mgome.
//

#ifndef SOLITARIO2_PILA_H
#define SOLITARIO2_PILA_H

#include "Nodo.h"
#include "Carta.h"

class Pila {
private:
    Nodo *tope;
    int size;
public:
    Pila();
    ~Pila();
    void push(Carta v);
    Carta pop();
    int getSize() {return size;}
    Nodo *getTope() {return(tope); };
    bool vacia() {return tope == nullptr;};
};

#endif //SOLITARIO2_PILA_H
