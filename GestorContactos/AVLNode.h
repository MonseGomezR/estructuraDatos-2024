//
// Created by mgome on 27/03/2024.
//

#ifndef GESTORCONTACTOS_AVLNODE_H
#define GESTORCONTACTOS_AVLNODE_H


#include "Contacto.h"

class AVLNode {
public:
    Contacto data;
    AVLNode *left;
    AVLNode *right;
    int height;

    explicit AVLNode (const Contacto& d) {
        data = d;
        height = 1;
        left = nullptr;
        right = nullptr;
    }
};


#endif //GESTORCONTACTOS_AVLNODE_H
