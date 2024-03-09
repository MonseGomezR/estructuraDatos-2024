//
// Created by mgome.
//

#ifndef SOLITARIO2_LISTAD_H
#define SOLITARIO2_LISTAD_H


#include "NodoLD.h"

class ListaD {
private:
    NodoLD *raiz;
public:
    ListaD();
    ~ListaD();
    int cantidad() const;
    void insertar(int pos, Carta x);
    void borrar(int pos);
    bool vacia();
    int posMayor();
    Carta extraer(int pos);
    NodoLD *getPrimero() {return(raiz); };
    NodoLD *obtenerNodo(int pos);
};


#endif //SOLITARIO2_LISTAD_H
