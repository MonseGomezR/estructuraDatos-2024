//
// Created by mgome on 1/04/2024.
//

#ifndef GESTORCONTACTOS_EXPORTMANAGER_H
#define GESTORCONTACTOS_EXPORTMANAGER_H


#include "Contacto.h"
#include <iostream>

using namespace std;

class ExportManager {
public:
    void exportarNuevoDoc(const Contacto &contacto, string grupo, string nameArchivo);
    void exportarDocGeneral(const Contacto &contacto, string grupo);
    void exportarLog(string log, string direccion);
};


#endif //GESTORCONTACTOS_EXPORTMANAGER_H
