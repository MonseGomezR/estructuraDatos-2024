#include <iostream>
#include <vector>
#include <random>
#include "Pila.h"
#include "ListaD.h"
#include "Cola.h"

using namespace std;

int main(){
    vector<Carta> cartas;
    for(int i = 1; i <= 4; i++) {
        for(int j = 1; j <= 13; j++) {
            string valor = std::to_string(j);
            string tipo = std::to_string(i);
            Carta aux = Carta(valor, tipo);
            cartas.emplace_back(aux);
        }
    }

    vector<ListaD> tablero(7);

    Cola deposito;

    int index = 1;
    int numPila;
    int random;
    random_device rd;
    Carta aux;


    while (!cartas.empty()) {
        uniform_int_distribution<int> dist(0,cartas.size());
        random = dist(rd);
        aux = cartas[random];
        if(index == 1) {
            numPila = 0;
        }else if (index < 4) {
            numPila = 1;
        }else if (index < 7) {
            numPila = 2;
        }else if (index < 11) {
            numPila = 3;
        }else if (index < 16) {
            numPila = 4;
        }else if (index < 22) {
            numPila = 5;
        }else if (index < 29) {
            numPila = 6;
        }else {
            break;
        }
        if(index == 1 || index == 2 || index == 4 || index == 7 ||index == 11 || index == 16 || index == 22)  {
            aux.setVista(true);
        }
        tablero[numPila].insertar(tablero[numPila].cantidad() + 1, aux);
        cartas.erase(cartas.begin() + random);
        index++;
    }

    for(int i = 0; i < tablero.size(); i++) {
        tablero[i].getPrimero()->getValor().setVista(true);
    }


    while (!cartas.empty()) {
        uniform_int_distribution<int> dist(0,cartas.size());
        random = dist(rd);
        aux = cartas[random];
        deposito.agregar(aux);
        cartas.erase(cartas.begin() + random);
    }


    vector<Pila> base(4);
    Cola descarte;
    ListaD pilaOrigen;
    ListaD pilaDestino;
    ListaD pilaAuxiliar;

    Carta cAuxOrigen;
    Carta cAuxDestino;
    Carta cartaAuxiliar1;
    Carta cartaAuxiliar2;

    bool endGame = false;
    char op;
    char cOrigen;
    char cDestino;
    int origen;
    int destino;
    int cantidad;
    int pilaMayor = 0;
    bool validInput = false;

    NodoLD* auxiliar;

    while (!endGame) {
        cout << "-1-\t-2-\t-3-\t-4-\t-5-\t-6-\t-7-\t\t";
        cout << "-8-\t-9-\t-A-\t-B-" << endl;

        for (const auto& pila : tablero) {
            if(pila.cantidad() > pilaMayor) {
                pilaMayor = pila.cantidad();
            }
        }

        for(int i = 1; i <= pilaMayor ; i++) {
            for (auto & pila : tablero) {
                if(pila.obtenerNodo(i) != nullptr){
                    aux = pila.obtenerNodo(pila.cantidad() - (i-1))->getValor();
                    if(aux.isVista()) {
                        cout << aux.getValor() << "-" << aux.getTipo() << "\t";
                    }else {
                        cout << "?-?\t";
                    }
                }else {
                    cout << " \t";
                }
            }

            if (i == 1){
                cout << "\t\t";
                for (auto & pila : base) {
                    if(pila.getTope() != nullptr) {
                        aux = pila.getTope()->getValor();
                        cout << aux.getValor() << "-" << aux.getTipo() << "\t";
                    }
                }
            }

            cout << endl;
        }

        cout << "-S-\t-D-" << endl;
        if(!deposito.empty()) {
            cout << deposito.getSize() << "\t";
        }else {
            cout << "0\t";
        }
        if(!descarte.empty()) {
            aux = descarte.getUltimo()->getValor();
            cout << aux.getValor() << "-" << aux.getTipo() << "\t";
        }
        validInput = false;
        cout << endl;
        while (!validInput) {
            cout << "Ingrese opcion (1: Mover Carta / 2:Sacar del Deposito):  ";
            cin >> op;
            switch (op) {
                case '1':
                    cout << endl;
                    while (!validInput) {
                        cout << "Ingrese el origen (1-7: Tablero / 'd': Descarte):  ";
                        cin >> cOrigen;
                        cout << "Ingrese el destino (1-7: Tablero / 8, 9 , 'a', 'b': Bases):  ";
                        cin >> cDestino;
                        switch (cOrigen) {
                            case '1':
                            case '2':
                            case '3':
                            case '4':
                            case '5':
                            case '6':
                            case '7':
                                origen = cOrigen - '0';
                                validInput = true;
                                break;
                            case 'd':
                            case 'D':
                                origen = 8;
                                validInput = true;
                                break;
                            default:
                                cout << "Opcion de origen invalida" << endl;
                                break;
                        }
                        validInput = false;
                        switch (cDestino) {
                            case '1':
                            case '2':
                            case '3':
                            case '4':
                            case '5':
                            case '6':
                            case '7':
                            case '8':
                            case '9':
                                destino = cDestino - '0';
                                validInput = true;
                                break;
                            case 'a':
                            case 'A':
                                destino = 10;
                                validInput = true;
                                break;
                            case 'b':
                            case 'B':
                                destino = 11;
                                validInput = true;
                                break;
                            default:
                                cout << "Opcion de destino invalida" << endl;
                                break;
                        }
                    }

                    if(destino >= 1 && destino <= 7) {
                        if(origen >= 1 && origen <= 7) {
                            pilaOrigen = tablero[origen-1];
                            pilaDestino = tablero[destino-1];
                            if(!pilaOrigen.vacia()) {
                                cAuxOrigen = pilaOrigen.getPrimero()->getValor();
                                if(!pilaDestino.vacia()) {
                                    cAuxDestino = pilaDestino.getPrimero()->getValor();
                                    if(cAuxOrigen.getValorNeto() == cAuxDestino.getValorNeto() - 1) {
                                        if(cAuxOrigen.getColor() != cAuxDestino.getColor()) {
                                            pilaDestino.insertar(1, pilaOrigen.extraer(1));
                                            if(!pilaOrigen.vacia()){
                                                cartaAuxiliar1 = pilaOrigen.extraer(1);
                                                cartaAuxiliar1.setVista(true);
                                                pilaOrigen.insertar(1, cartaAuxiliar1);
                                            }
                                            tablero[origen-1] = pilaOrigen;
                                            tablero[destino-1] = pilaDestino;
                                            validInput = true;
                                        }else {
                                            cout << "Mismo color" << endl;
                                        }
                                    }else {
                                        if(pilaOrigen.cantidad() > 1) {
                                            auxiliar = pilaOrigen.getPrimero();
                                            cantidad = 1;
                                            while (auxiliar->getSiguiente() != nullptr) {
                                                cartaAuxiliar1 = auxiliar->getValor();
                                                cartaAuxiliar2 = auxiliar->getSiguiente()->getValor();

                                                if(cartaAuxiliar1.getValorNeto() == cartaAuxiliar2.getValorNeto() - 1) {
                                                    cantidad++;
                                                    auxiliar = auxiliar->getSiguiente();
                                                }else {
                                                    break;
                                                }
                                            }

                                            if(cantidad != 1) {
                                                for(int i = 1; i <= cantidad; i++) {
                                                    pilaAuxiliar.insertar(pilaAuxiliar.cantidad(), pilaAuxiliar.obtenerNodo(i)->getValor());
                                                }
                                                cartaAuxiliar1 = pilaAuxiliar.obtenerNodo(pilaAuxiliar.cantidad())->getValor();
                                                if(cAuxDestino.getValorNeto() == cartaAuxiliar1.getValorNeto() + 1) {
                                                    if(cAuxDestino.getColor() != cartaAuxiliar1.getColor()) {
                                                        for(int i = 1; i <= cantidad; i++) {
                                                            pilaOrigen.extraer(i);
                                                            pilaDestino.insertar(i, pilaAuxiliar.extraer(i));
                                                        }
                                                        if(!pilaOrigen.vacia()){
                                                            cartaAuxiliar1 = pilaOrigen.extraer(1);
                                                            cartaAuxiliar1.setVista(true);
                                                            pilaOrigen.insertar(1, cartaAuxiliar1);
                                                        }
                                                        tablero[origen - 1] = pilaOrigen;
                                                        tablero[destino - 1] = pilaDestino;
                                                        validInput = true;
                                                    }else {
                                                        cout << "Mismo color pila" << endl;
                                                    }
                                                }else {
                                                    cout << "Valor invalido pila" << endl;
                                                }
                                            }else {
                                                cout << "Movimiento invalido" << endl;
                                            }
                                        }else {
                                            cout << "Movimiento invalido (1)" << endl;
                                        }
                                    }
                                }else {
                                    cout << "Opcion de destino invalida" << endl;
                                }
                            }else {
                                cout << "Pila origen vacia" << endl;
                            }
                        }else if(origen == 8) {
                            pilaDestino = tablero[destino-1];
                            if(!descarte.empty()) {
                                cAuxOrigen = descarte.getUltimo()->getValor();
                                if(!pilaDestino.vacia()) {
                                    cAuxDestino = pilaDestino.getPrimero()->getValor();
                                    if(cAuxOrigen.getValorNeto() == (cAuxDestino.getValorNeto() - 1)) {//La primera carta del destino es mayor a la carta de origen por 1?
                                        if (cAuxOrigen.getColor() != cAuxDestino.getColor()) {
                                            cartaAuxiliar1 = descarte.quitarUltimo();
                                            cartaAuxiliar1.setVista(true);
                                            pilaDestino.insertar(1, cartaAuxiliar1);
                                            tablero[destino - 1] = pilaDestino;
                                            validInput = true;
                                        }else {
                                            cout << "Color invalido" << endl;
                                        }

                                    }else {
                                        cout << "Movimiento no valido" << endl;
                                    }
                                }else {
                                    if(cAuxOrigen.getValorNeto() == 13) {
                                        cartaAuxiliar1 = descarte.quitarUltimo();
                                        cartaAuxiliar1.setVista(true);
                                        pilaDestino.insertar(1, cartaAuxiliar1);
                                        tablero[destino-1] = pilaDestino;
                                        validInput = true;
                                    }else {
                                        cout << "Solo se puede mover el rey a una pila vacía." << endl;
                                    }
                                }
                            }else {
                                cout << "No hay cartas en la pila de sobrantes." << endl;
                            }
                        }
                    }else {
                        if(origen != 8) {
                            pilaOrigen = tablero[origen-1];
                            cAuxOrigen = pilaOrigen.getPrimero()->getValor();

                            int index = 0;
                            switch (destino) {
                                case 8:
                                    index = 0;
                                    break;
                                case 9:
                                    index = 1;
                                    break;
                                case 10:
                                    index = 2;
                                    break;
                                case 11:
                                    index = 3;
                                    break;
                            }

                            if(base[index].vacia() && cAuxOrigen.getValorNeto() == 1) {
                                base[index].push(pilaOrigen.extraer(1));
                                tablero[origen-1] = pilaOrigen;
                                cartaAuxiliar1 = pilaOrigen.extraer(1);
                                cartaAuxiliar1.setVista(true);
                                pilaOrigen.insertar(1, cartaAuxiliar1);
                                validInput = true;
                            }else {
                                Carta carta = base[index].getTope()->getValor();
                                if(carta.getValorNeto() == cAuxOrigen.getValorNeto() - 1) {
                                    if(carta.getTipo() == cAuxOrigen.getTipo()) {
                                        base[index].push(pilaOrigen.extraer(1));
                                        tablero[origen-1] = pilaOrigen;
                                        cartaAuxiliar1 = pilaOrigen.extraer(1);
                                        cartaAuxiliar1.setVista(true);
                                        pilaOrigen.insertar(1, cartaAuxiliar1);
                                        validInput = true;
                                    }else {
                                        cout << "Guardado invalido, no coincide los simbolos" << endl;
                                    }
                                }else {
                                    cout << "Guardado Invalido, no coincide los valores" << endl;
                                }
                            }
                        }else {
                            if(!descarte.empty()) {
                                cAuxOrigen = descarte.getUltimo()->getValor();

                                int index = 0;
                                switch (destino) {
                                    case 8:
                                        index = 0;
                                        break;
                                    case 9:
                                        index = 1;
                                        break;
                                    case 10:
                                        index = 2;
                                        break;
                                    case 11:
                                        index = 3;
                                        break;
                                }

                                if(base[index].vacia() && cAuxOrigen.getValorNeto() == 1) {
                                    base[index].push(descarte.quitarUltimo());
                                    validInput = true;
                                }else if (!base[index].vacia()){
                                    Carta carta = base[index].getTope()->getValor();
                                    if(carta.getValorNeto() == cAuxOrigen.getValorNeto() - 1) {
                                        if(carta.getTipo() == cAuxOrigen.getTipo()) {
                                            base[index].push(descarte.quitarUltimo());
                                            validInput = true;
                                        }else {
                                            cout << "Guardado invalido, no coincide los simbolos" << endl;
                                            validInput = false;
                                        }
                                    }else {
                                        cout << "Guardado Invalido, no coincide los valores" << endl;
                                        validInput = false;
                                    }
                                }
                            }else {
                                cout << "No hay cartas en la pila de sobrantes." << endl;
                                validInput = false;
                            }
                        }
                    }
                    break;
                case '2':
                    if(deposito.empty()) {
                        while (!descarte.empty()) {
                            aux = descarte.quitar();
                            deposito.agregar(aux);
                        }
                    }
                    aux = deposito.quitar();
                    descarte.agregar(aux);
                    cout << "Saco carta: " << aux.getValor() << "-" << aux.getTipo() << endl;
                    op = '0';
                    validInput = true;
                    break;
                default:
                    cout << "Opcion Invalida" << endl;
                    break;
            }
        }
    }

    return 0;
}
