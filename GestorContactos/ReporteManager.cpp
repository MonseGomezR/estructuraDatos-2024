//
// Created by mgome on 2/04/2024.
//

#include "ReporteManager.h"
#include <chrono>
#include "HashTable.h"

void ReporteManager::datosPorGrupo(string grupo, HashTable contactos) {
    int cantidad = 0;
    GrupoContactos* aux = contactos.buscarGrupo(grupo);
    if(aux != nullptr) {
        cantidad = aux->contactos.cantidadManager();
        cout << "El grupo " << grupo << " tiene " << cantidad << " contacto(s).\n\n\n";
    }else {
        cout << "El grupo solicitado no existe.\n\n\n";
    }
}

void ReporteManager::datosSistema(HashTable contactos) {

}

void ReporteManager::logSistema(string nuevaLinea) {
    auto now = chrono::system_clock::now();
    time_t end_time = chrono::system_clock::to_time_t(now);

    log += "[LOG]:: " + nuevaLinea + "      " + ctime(&end_time) + "\n";
}

void ReporteManager::mostrarLog() {
    cout << log;
}

void ReporteManager::exportarLog() {
    ExportManager em;
    string direccion;
    cout << "Ingrese la direccion donde guardar el archivo log.\n  >";
    getline(cin, direccion);
    em.exportarLog(log, direccion);
}