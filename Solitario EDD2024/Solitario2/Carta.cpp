//
// Created by mgome.
//

#include "Carta.h"
using namespace std;

Carta::Carta(string valor, string tipo) {
    this->valor = valor;
    if (valor == "1") {
        this->valor = "A";
    } else if (valor == "11") {
        this->valor = "J";
    } else if (valor == "12") {
        this->valor = "Q";
    } else if (valor == "13") {
        this->valor = "K";
    }
    this->valorNeto = stoi(valor);
    if (tipo == "1") {
        this->tipo = "C";
        this->color = "R";
        this->printTipo = "♡";
    } else if (tipo == "2") {
        this->tipo = "D";
        this->color = "R";
        this->printTipo = "♢";
    } else if (tipo == "3") {
        this->tipo = "T";
        this->color = "B";
        this->printTipo = "♣";
    } else if (tipo == "4") {
        this->tipo = "P";
        this->color = "B";
        this->printTipo = "♠";
    }
    this->vista = false;
}

Carta::Carta() {
    valor = "-1";
    tipo = "-1";
    vista = false;
    valorNeto = -1;
}

string Carta::getValor() {
    return valor;
}

string Carta::getPrintTipo() {
    return printTipo;
}

string Carta::getTipo() {
    return tipo;
}

bool Carta::isVista() {
    return vista;
}

int Carta::getValorNeto() {
    return valorNeto;
}

string Carta::getColor() {
    return color;
}

void Carta::setVista(bool vista) {
    this->vista = vista;
}


