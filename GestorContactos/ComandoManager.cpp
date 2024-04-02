//
// Created by mgome on 2/04/2024.
//

#include "ComandoManager.h"
#include <sstream>
#include <algorithm>
#include "HashTable.h"

using namespace std;

string limpiarValor(string& valor) {
    size_t pos;

    if ((pos = valor.find('(')) != string::npos) {
        valor = valor.substr(pos + 1);
    }

    if ((pos = valor.find(')')) != string::npos) {
        valor = valor.substr(0, pos);
    }

    if ((pos = valor.find(',')) != string::npos) {
        valor = valor.substr(0, pos);
    }
    return valor;
}

void ComandoManager::procesarComandoBusqueda(string input, HashTable contactos, ReporteManager& reporte) {
    list<Contacto> aux;
    string log;
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    stringstream ss(input);

    ss >> word;
    if (word != "find") return;

    ss >> word;
    if (word != "contact") return;

    ss >> word;
    if (word != "in") return;

    ss >> grupo;
    if (grupo.empty()) return;

    ss >> word;
    if (word != "contact-field") return;

    ss >> word;
    pos = word.find('=');
    if (pos == string::npos) return;

    donde = word.substr(0, pos);
    valor = word.substr(pos + 1);

    log += "Se ha buscado contactos en el grupo '" + grupo + "' con indice ";

    if (donde == "nombre") {
        aux = contactos.buscarPorNombre(grupo, valor);
        log += "Nombre = " + valor + ". Devolviendo " + to_string(aux.size()) + " resultados.";
    } else if (donde == "apellido") {
        contactos.buscarPorApellido(grupo, valor);
        log += "Apellido = " + valor + ". Devolviendo " + to_string(aux.size()) + " resultados.";
    } else if (donde == "numero") {
        contactos.buscarPorNumero(grupo, stoi(valor));
        log += "Numero = " + valor + ". ";
    }

    log += "Devolviendo " + to_string(aux.size()) + " resultados.";
    reporte.logSistema(log);
}

void ComandoManager::procesarComandoAdd(string input, HashTable& contactos, ReporteManager &reporte) {
    stringstream ss(input);
    string aux;

    ss >> word;
    if (word != "add") return;

    ss >> word;

    if(word == "new-group") {
        return agregarGrupo(contactos, ss, reporte);
    }else if (word == "contact") {
        return agregarIndividual(contactos, ss, reporte);
    }
    else return;
}

void ComandoManager::agregarIndividual(HashTable& contactos, stringstream& ss, ReporteManager &reporte) {
    Contacto nuevo;
    ss >> word;
    if (word != "in") return;

    ss >> grupo;
    if (grupo.empty()) return;

    ss >> word;
    if (word != "fields") return;

    if (ss >> word) nuevo.setName(limpiarValor(word));
    if (ss >> word) nuevo.setLastName(limpiarValor(word));
    if (ss >> word) nuevo.setNumber(stoi(limpiarValor(word)));

    contactos.agregarContacto(grupo, nuevo);
    reporte.logSistema("Se ha agregado un nuevo contacto al grupo " + grupo + ".");
    em.exportarDocGeneral(nuevo, grupo);
    reporte.logSistema("Se agrego el nuevo contacto al archivo base de importacion");
}

void ComandoManager::agregarGrupo(HashTable& contactos, stringstream& ss, ReporteManager &reporte) {
    Contacto nuevo;

    ss >> grupo;
    if (grupo.empty()) return;

    ss >> word;
    if(word != "fields") return;

    while (ss >> word) {
        word = limpiarValor(word);

        if (word == "nombre") {
            if (ss >> word) {
                nuevo.setName(limpiarValor(word));
            }
        } else if (word == "apellido") {
            if (ss >> word) {
                nuevo.setLastName(limpiarValor(word));
            }
        } else if (word == "celular" || word == "telefono") {
            if (ss >> word) {
                nuevo.setNumber(stoi(limpiarValor(word)));
            }
        }
    }
    contactos.agregarGrupo(grupo);
    reporte.logSistema("Se ha creado un nuevo grupo '" + grupo + "'.");
    contactos.agregarContacto(grupo, nuevo);
    reporte.logSistema("Se ha agregado un nuevo contacto al grupo " + grupo + ".");
    em.exportarDocGeneral(nuevo, grupo);
    reporte.logSistema("Se agrego el nuevo contacto al archivo base de importacion");
}
