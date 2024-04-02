#ifndef GESTORCONTACTOS_REPORTEMANAGER_H
#define GESTORCONTACTOS_REPORTEMANAGER_H


#include <string>
#include "HashTable.h"
#include <iostream>

using namespace std;

class ReporteManager {
private:
    string log;
public:
    void datosSistema(HashTable contactos);
    void logSistema(string nuevaLinea);
    void mostrarLog();
    void exportarLog();
    void datosPorGrupo(string grupo, HashTable contactos);
};


#endif //GESTORCONTACTOS_REPORTEMANAGER_H
