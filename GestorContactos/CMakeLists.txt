cmake_minimum_required(VERSION 3.27)
project(GestorContactos)

set(CMAKE_CXX_STANDARD 17)
set(GRAPHVIZ_DIR "C:/Program Files/Graphviz")

add_executable(GestorContactos main.cpp
        Contacto.cpp
        AVLNode.cpp
        AVLTree.cpp
        AVLTree.h
        GrupoContactos.cpp
        GrupoContactos.h
        HashTable.cpp
        HashTable.h
        ExportManager.cpp
        ExportManager.h
        ComandoManager.cpp
        ComandoManager.h
        ReporteManager.cpp
        ReporteManager.h
)

file(GLOB GVC_LIBS "${GRAPHVIZ_DIR}/lib/*.lib")
target_link_libraries(${CMAKE_PROJECT_NAME} ${GVC_LIBS})
include_directories("${GRAPHVIZ_DIR}/include/graphviz")
