//
// Created by mgome on 2/04/2024.
//

#ifndef GESTORCONTACTOS_COMANDOMANAGER_H
#define GESTORCONTACTOS_COMANDOMANAGER_H


#include "HashTable.h"
#include "ExportManager.h"
#include "ReporteManager.h"
#include <iostream>

using namespace std;

class ComandoManager {
private:
public:
    ExportManager em;

    string word, grupo, donde, valor;
    size_t pos;

    void procesarComandoBusqueda(string input, HashTable contactos, ReporteManager &reporte);
    void procesarComandoAdd(string input, HashTable& contactos, ReporteManager &reporte);

    void agregarIndividual(HashTable& contactos, stringstream& ss, ReporteManager &reporte);
    void agregarGrupo(HashTable& contactos, stringstream& ss, ReporteManager &reporte);
};


#endif //GESTORCONTACTOS_COMANDOMANAGER_H
