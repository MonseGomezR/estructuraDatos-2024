cmake_minimum_required(VERSION 3.27)
project(Solitario2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Solitario2 main.cpp
        Nodo.cpp
        Carta.cpp
        Pila.cpp
        ListaD.cpp
        NodoLD.cpp
        Cola.cpp)
