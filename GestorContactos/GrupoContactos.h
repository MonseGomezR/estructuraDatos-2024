//
// Created by mgome on 28/03/2024.
//

#ifndef GESTORCONTACTOS_GRUPOCONTACTOS_H
#define GESTORCONTACTOS_GRUPOCONTACTOS_H
#include <iostream>
#include "AVLTree.h"
using namespace std;

class GrupoContactos {
public:
    string nombre;
    AVLTree contactos;

    explicit GrupoContactos(string nombreGrupo) {
        nombre = nombreGrupo;
    }
};

#endif //GESTORCONTACTOS_GRUPOCONTACTOS_H
