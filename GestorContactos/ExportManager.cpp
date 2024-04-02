//
// Created by mgome on 1/04/2024.
//

#include <fstream>
#include <iostream>
#include "ExportManager.h"
#include "Contacto.h"

using namespace std;

void ExportManager::exportarNuevoDoc(const Contacto &contacto, string grupo, string documento) {
    string nombreArchivo = documento + ".txt";
    ofstream archivo(nombreArchivo, ios::app);
    if(archivo.is_open()) {
        archivo << "Nombre=" << contacto.getName() << "\n";
        archivo << "Apellido=" << contacto.getLastName() << "\n";
        archivo << "Numero=" << contacto.getNumber() << "\n";
        archivo << "Grupo=" << grupo << "\n\n";
        archivo.close();
    }
}

void ExportManager::exportarDocGeneral(const Contacto &contacto, string grupo) {
    exportarNuevoDoc(contacto, grupo, "documentos");
}

void ExportManager::exportarLog(string log, string direccion) {
    string nombreArchivo = direccion + "log.txt";
    ofstream archivo(nombreArchivo, ios::app);
    if(archivo.is_open()) {
        archivo << log;
        archivo.close();
    }
}