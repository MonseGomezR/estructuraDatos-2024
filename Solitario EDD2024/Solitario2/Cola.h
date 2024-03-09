//
// Created by mgome.
//

#ifndef SOLITARIO2_COLA_H
#define SOLITARIO2_COLA_H

#include "Nodo.h"
#include "Carta.h"

class Cola {
private:
    Nodo *primero;
    Nodo *ultimo;
    int size;
public:
    Cola();
    ~Cola();
    void agregar(Carta v);
    Carta quitar();
    Carta quitarUltimo();
    bool empty() { return ultimo == nullptr;};
    int getSize() { return size;};
    Nodo *getPrimero() {return(primero); };
    Nodo *getUltimo() {return(ultimo); };
};


#endif //SOLITARIO2_COLA_H
