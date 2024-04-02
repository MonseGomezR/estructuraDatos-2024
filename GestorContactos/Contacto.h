//
// Created by mgome on 19/03/2024.
//

#ifndef GESTORCONTACTOS_CONTACTO_H
#define GESTORCONTACTOS_CONTACTO_H

#include <iostream>
#include <utility>
using namespace std;

class Contacto {
private:
    string nombre;
    string lastname;
    int number;
public:
    Contacto() {
        nombre = "";
        lastname = "";
        number = 0;
    };

    Contacto(string n, string ln, int nu) {
        nombre = n;
        lastname = ln;
        number = nu;
    }

    string getName() const {return nombre;};
    string getLastName() const {return lastname;};
    int getNumber() const {return number;};

    void setName(string n) {nombre = std::move(n);}
    void setLastName(string ln) {lastname = std::move(ln);}
    void setNumber(int n) {number = n;};
};


#endif //GESTORCONTACTOS_CONTACTO_H
