//
// Created by mgome on 28/03/2024.
//

#include "HashTable.h"
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int HashTable::funcionHash(string key) {
    transform(key.begin(), key.end(), key.begin(), ::tolower);
    int hash = 0;
    for (char c : key) {
        hash += c;
    }
    return hash % cantidad;
}

HashTable::HashTable() : table{} {
    for (int i = 0; i < cantidad; ++i) {
        table[i] = nullptr;
    }
}

HashTable::~HashTable() {
    for (int i = 0; i < cantidad; ++i) {
        delete table[i];
    }
}

void HashTable::agregarGrupo(string nombreGrupo) {
    transform(nombreGrupo.begin(), nombreGrupo.end(), nombreGrupo.begin(), ::tolower);
    int index = funcionHash(nombreGrupo);
    auto* nGrupo = new GrupoContactos(nombreGrupo);
    auto* nNodo = new HashNode(nGrupo);

    if (table[index] == nullptr) {
        cout << "Grupo " << nombreGrupo << " agregado." << endl;
        table[index] = nNodo;
    } else {
        HashNode* actual = table[index];
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }

        if (actual->grupo->nombre != nombreGrupo) {
            cout << "Grupo " << nombreGrupo << " agregado. (Encadenado)";
            actual->siguiente = nNodo;
        }else {
            cout << "El grupo ya existe.";
            delete nGrupo;
            delete nNodo;
        }
    }
}

GrupoContactos* HashTable::buscarGrupo(string nombreGrupo) {
    int index = funcionHash(nombreGrupo);
    HashNode* actual = table[index];
    while (actual != nullptr) {
        if (actual->grupo->nombre == nombreGrupo) {
            return actual->grupo;
        }
        actual = actual->siguiente;
    }
    return nullptr;
}

void HashTable::agregarContacto(string nombreGrupo, const Contacto& contacto) {
    transform(nombreGrupo.begin(), nombreGrupo.end(), nombreGrupo.begin(), ::tolower);
    GrupoContactos* grupo = buscarGrupo(nombreGrupo);
    if (grupo != nullptr) {
        grupo->contactos.agregar(contacto);
        cout << "El contacto se ha agregado exitosamente" << endl;
    } else {
        cout << "El grupo '" << nombreGrupo << "' no existe." << endl;
    }
}

list<Contacto> HashTable::buscarPorNumero(string nombreGrupo, int contacto) {
    GrupoContactos* grupo = buscarGrupo(nombreGrupo);
    if (grupo != nullptr) {
        return grupo->contactos.buscarNum(contacto);
    }
    cout << "El grupo '" << nombreGrupo << "' no existe.\n\n";
    return {};
}

list<Contacto> HashTable::buscarPorNombre(string nombreGrupo, string contacto) {
    GrupoContactos* grupo = buscarGrupo(nombreGrupo);
    if (grupo != nullptr) {
        return grupo->contactos.buscarNombre(contacto);
    }
    cout << "El grupo '" << nombreGrupo << "' no existe.\n\n";
    return {};
}

list<Contacto> HashTable::buscarPorApellido(string nombreGrupo, string contacto) {
    GrupoContactos* grupo = buscarGrupo(nombreGrupo);
    if (grupo != nullptr) {
        return grupo->contactos.buscarApellido(contacto);
    }
    cout << "El grupo '" << nombreGrupo << "' no existe.\n\n";
    return {};
}

