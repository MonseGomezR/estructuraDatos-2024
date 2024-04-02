//
// Created by mgome on 28/03/2024.
//

#include <algorithm>
#include <list>
#include <sstream>
#include "AVLTree.h"
#include "ReporteManager.h"

using namespace std;


void printContacto(const Contacto& contacto) {
    cout << ".-----------------------------.\n";
    cout << "| Contacto " << endl;
    cout << "| Nombre: " << contacto.getName() << endl;
    cout << "| Apellido: " << contacto.getName() << endl;
    cout << "| Numero: " << contacto.getNumber() << endl;
    cout << "*-----------------------------*\n\n";
}

int AVLTree::height(AVLNode *node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

int AVLTree::balanceFactor(AVLNode *node) {
    if (node == nullptr) return 0;
    return height(node->left) - height(node->right);
}

AVLNode* AVLTree::rotateRight(AVLNode *y) {
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

AVLNode* AVLTree::rotateLeft(AVLNode *x) {
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

AVLNode* AVLTree::insertHelper(AVLNode *node, const Contacto& data){
    if(node == nullptr){
        return new AVLNode(data);
    }

    if (data.getName() < node->data.getName()){
        node->left = insertHelper(node->left, data);
    }else if(data.getName() > node->data.getName()){
        node->right = insertHelper(node->right, data);
    }else{
        if(data.getLastName() < node->data.getLastName()){
            node->left = insertHelper(node->left, data);
        }else if(data.getLastName() > node->data.getLastName()){
            node->right = insertHelper(node->right, data);
        }else{
            return node;
        }
    }
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = balanceFactor(node);

    if(balance > 1 && data.getName() < node->left->data.getName()){
        return rotateRight(node);
    }else if(balance > 1 && data.getName() == node->left->data.getName() && data.getLastName() < node->left->data.getLastName()) {
        return rotateRight(node);
    }

    if(balance < -1 && data.getName() > node->right->data.getName()){
        return rotateLeft(node);
    }else if(balance < -1 && data.getName() == node->right->data.getName() && data.getLastName() > node->right->data.getLastName()) {
        return rotateLeft(node);
    }

    if(balance > 1 && data.getName() > node->left->data.getName()){
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }else if(balance > 1 && data.getName() == node->left->data.getName() && data.getLastName() > node->left->data.getLastName()) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if(balance < -1 && data.getName() < node->right->data.getName()){
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }else if(balance < -1 && data.getName() == node->right->data.getName() && data.getLastName() < node->right->data.getLastName()) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}


void AVLTree::agregar(const Contacto& data) {
    raiz = insertHelper(raiz, data);
}

list<Contacto> AVLTree::buscarPorNum(AVLNode *node, int data, list<Contacto> lista) {
    stringstream ss;
    string numBusqueda;
    string numContacto;

    if (node == nullptr) {
        return lista;
    }
    buscarPorNum(node->left, data, lista);

    ss << data;
    ss >> numBusqueda;

    ss << node->data.getNumber();
    ss >> numContacto;

    if (numContacto.find(numBusqueda) != string::npos) {
        printContacto(node->data);
        lista.push_back(node->data);
    }

    buscarPorNum(node->right, data, lista);
    return lista;

}

list<Contacto> AVLTree::buscarPorNombre(AVLNode *node, string data, list<Contacto> lista) {
    if (node == nullptr) {
        return lista;
    }

    buscarPorNombre(node->left, data, lista);

    string nombre = node->data.getName();

    transform(nombre.begin(), nombre.end(), nombre.begin(), ::tolower);
    transform(data.begin(), data.end(), data.begin(), ::tolower);

    if (nombre.find(data) != string::npos) {
        printContacto(node->data);
        lista.push_back(node->data);
    }

    buscarPorNombre(node->right, data, lista);
    return lista;
}

list<Contacto> AVLTree::buscarPorApellido(AVLNode *node, string data, list<Contacto> lista) {
    if (node == nullptr) {
        return lista;
    }
    buscarPorApellido(node->left, data, lista);

    string apellido = node->data.getLastName();

    transform(apellido.begin(), apellido.end(), apellido.begin(), ::tolower);
    transform(data.begin(), data.end(), data.begin(), ::tolower);

    if (apellido.find(data) != string::npos) {
        printContacto(node->data);
        lista.push_back(node->data);
    }

    buscarPorApellido(node->right, data, lista);
    return lista;
}

list<Contacto> AVLTree::buscarNum(int data) {
    list<Contacto> aux;
    return buscarPorNum(raiz, data, aux);
}

list<Contacto> AVLTree::buscarNombre(string data) {
    list<Contacto> aux;
    return buscarPorNombre(raiz, data, aux);
}

list<Contacto> AVLTree::buscarApellido(string data) {
    list<Contacto> aux;
    return buscarPorApellido(raiz, data, aux);
}

void AVLTree::exportHelper(AVLNode *node, ExportManager em, string grupo, string ruta) {
    if (node == nullptr) return;
    exportHelper(node->left, em, grupo, ruta);
    em.exportarNuevoDoc(node->data, grupo, ruta + grupo + node->data.getName() + node->data.getLastName());
    exportHelper(node->right, em, grupo, ruta);
}

void AVLTree::exportar(string grupo, string ruta) {
    ExportManager em;
    exportHelper(raiz, em, grupo, ruta);
    cout << endl;
}

int AVLTree::cantidadManager() {
    return cantidad(raiz);
}

int AVLTree::cantidad(AVLNode* node) {
    if (node == nullptr) {
        return 0;
    }

    if (node->left == nullptr && node->right == nullptr) {
        return 1;
    }

    // Recursivamente contar las hojas de ambos subárboles.
    return cantidad(node->left) + cantidad(node->right);
}

