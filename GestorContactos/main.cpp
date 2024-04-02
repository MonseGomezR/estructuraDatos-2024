#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>
#include "AVLTree.h"
#include "HashTable.h"
#include "ExportManager.h"
#include "ComandoManager.h"
#include "ReporteManager.h"

using namespace std;
static ReporteManager rm;

string extraerValor(const string& linea) {
    size_t pos = linea.find('=');
    return linea.substr(pos + 1);
}

void listarGrupos(HashTable &table) {
    auto tabla = table.getTable();
    for(int i = 0; i < HashTable::getCantidad(); i++) {
        if(tabla[i] != nullptr) {
            cout << tabla[i]->grupo->nombre << " ";
        }
    }

    cout << "\n  > ";
}

void cargarContactos(HashTable& tablaContactos) {
    ifstream archivoCarga("documentos.txt");

    string linea;
    string texto;
    string input;
    string valor;

    tablaContactos.agregarGrupo("Amigos");
    tablaContactos.agregarGrupo("Familia");
    tablaContactos.agregarGrupo("Trabajo");
    tablaContactos.agregarGrupo("Social");

    while (getline(archivoCarga, linea)) {
        Contacto nuevo;
        nuevo.setName(extraerValor(linea));

        if(getline(archivoCarga, linea)) {
            nuevo.setLastName(extraerValor(linea));

            if(getline(archivoCarga, linea)) {
                nuevo.setNumber(stoi(extraerValor(linea)));

                if(getline(archivoCarga, linea)) {
                    valor = extraerValor(linea);
                    transform(valor.begin(), valor.end(), valor.begin(), ::tolower);
                    if(tablaContactos.buscarGrupo(valor) == nullptr) {
                        tablaContactos.agregarGrupo(valor);
                    }
                    tablaContactos.agregarContacto(valor, nuevo);
                }
            }
        }
        getline(archivoCarga, linea);
    }
}

void terminal(HashTable& contactos) {
    ComandoManager cm;
    string input;
    string word;
    bool salida = false;

    do {
        cout << "Ingrese su consulta >>";
        getline(cin, input);
        transform(input.begin(), input.end(), input.begin(), ::tolower);
        stringstream ss(input);

        if (ss >> word && word == "find") {
            cm.procesarComandoBusqueda(input, contactos, rm);
        } else if (word == "add") {
            cm.procesarComandoAdd(input, contactos, rm);
        } else if (word == "exit") {
            salida = true;
        } else {
            cout << "La instruccion no coincide" << endl;
        }

    }
    while (!salida);
}

void reportes(HashTable& contactos) {

    char opcion;
    bool salida = false;
    string input;

    while (!salida) {
        cout << "Ingrese el reporte que desea consultar.\n1. Cantidad de contactos por grupo\n2. Cantidad de datos en el sistema\n3. Log de sistema\n0. Regresar\n  >";
        cin >> opcion;
        cin.ignore();
        switch (tolower(opcion)) {
            case '1':
                cout << "Ingrese el nombre del grupo que desea.\n  >";
                getline(cin, input);
                rm.datosPorGrupo(input, contactos);
                break;
            case '2':
                rm.datosSistema(contactos);
                break;
            case '3':
                rm.mostrarLog();
                break;
            case '0':
                salida = true;
                break;
            default:
                cout << "Ingrese una opcion valida \n\n\n";
                break;
        }
    }
}

void exportar(HashTable& contactos) {
    string input;
    string ruta;
    bool salida = false;

    while (!salida) {
        cout << "Ingrese el nombre del grupo que desea exportar sus contactos.\nGrupos actuales: ";
        listarGrupos(contactos);
        getline(cin, input);

        transform(input.begin(), input.end(), input.begin(), ::tolower);

        GrupoContactos* aux = contactos.buscarGrupo(input);
        if(aux != nullptr) {
            cout << "Ingrese la ruta donde desea guardar los archivos txt. \n  >";
            getline(cin, ruta);
            aux->contactos.exportar(input, ruta);
            rm.logSistema("Se ha exportado los contactos del grupo " + input + "' en '" + ruta + "'.");
            salida = true;
        }

    }
}



int main () {
    char opcion;
    bool salida = false;

    HashTable tablaContactos;
    cargarContactos(tablaContactos);

    while (!salida) {
        cout << "Ingrese una opcion\n1. Terminal de Comandos\n2. Reportes\n3. Exportar Contactos\n  >";
        cin >> opcion;
        cin.ignore();
        switch (tolower(opcion)) {
            case '1':
                terminal(tablaContactos);
                break;
            case '2':
                reportes(tablaContactos);
                break;
            case '3':
                exportar(tablaContactos);
                break;
            case '0':
                salida = true;
                break;
            default:
                cout << "Ingrese una opcion valida \n\n\n";
                break;
        }

    }


    return 0;
}
