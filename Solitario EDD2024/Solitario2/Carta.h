//
// Created by mgome.
//

#ifndef SOLITARIO2_CARTA_H
#define SOLITARIO2_CARTA_H
#include <iostream>
using namespace std;

class Carta {
private:
    string valor;
    string tipo;
    string color;
    string printTipo;
    bool vista;
    int valorNeto;

public:
    Carta(string valor, string tipo);

    Carta();

    string getValor();
    string getPrintTipo();
    string getTipo();
    string getColor();
    bool isVista();
    int getValorNeto();
    void setVista(bool boolean);
};


#endif //SOLITARIO2_CARTA_H
