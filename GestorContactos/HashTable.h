//
// Created by mgome on 28/03/2024.
//

#ifndef GESTORCONTACTOS_HASHTABLE_H
#define GESTORCONTACTOS_HASHTABLE_H

#include <list>
#include "GrupoContactos.h"

class HashTable {
private:
    struct HashNode {
        GrupoContactos* grupo;
        HashNode* siguiente;

        explicit HashNode(GrupoContactos* g) : grupo(g), siguiente(nullptr) {}
    };

    static const int cantidad = 10;
    HashNode* table[cantidad];

    static int funcionHash(string key);
public:
    HashTable();
    ~HashTable();
    void agregarGrupo(string nombreGrupo);
    GrupoContactos* buscarGrupo(string nombreGrupo);

    void agregarContacto(string nombreGrupo, const Contacto& contacto);
    list<Contacto> buscarPorNumero(string nombreGrupo, int contacto);
    list<Contacto> buscarPorNombre(string nombreGrupo, string contacto);
    list<Contacto> buscarPorApellido(string nombreGrupo, string contacto);

    static int getCantidad() {return cantidad;};
    auto* getTable() {return table;}
};

#endif //GESTORCONTACTOS_HASHTABLE_H
