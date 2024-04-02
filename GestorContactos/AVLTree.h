//
// Created by mgome on 28/03/2024.
//

#ifndef GESTORCONTACTOS_AVLTREE_H
#define GESTORCONTACTOS_AVLTREE_H

#include <list>
#include "AVLNode.h"
#include "ExportManager.h"

class AVLTree {
private:
    AVLNode *raiz;

    int height(AVLNode *node);
    int balanceFactor(AVLNode *node);
    AVLNode* rotateRight(AVLNode *y);
    AVLNode* rotateLeft(AVLNode *x);

    AVLNode* insertHelper(AVLNode *node, const Contacto& data);

    list<Contacto> buscarPorNum(AVLNode *node, int data, list<Contacto> lista);
    list<Contacto> buscarPorNombre(AVLNode *node, string data, list<Contacto> lista);
    list<Contacto> buscarPorApellido(AVLNode *node, string data, list<Contacto> lista);

    void exportHelper(AVLNode *node, ExportManager em, string grupo, string ruta);
    int cantidad(AVLNode *node);

public:
    AVLTree() : raiz(nullptr) {}
    void agregar(const Contacto& data);

    list<Contacto> buscarNum(int data);
    list<Contacto> buscarNombre(string data);
    list<Contacto> buscarApellido(string data);

    void exportar(string grupo, string ruta);

    int cantidadManager();
};


#endif //GESTORCONTACTOS_AVLTREE_H
