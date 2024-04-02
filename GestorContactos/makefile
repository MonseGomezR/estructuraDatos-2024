CPP = g++
TARGET = compiled_solitaire


all: .all-post

.all-post: main.o Contacto.o AVLNode.o AVLTree.o GrupoContactos.o HashTable.o ExportManager.o ComandoManager.o ReporteManager.o
	$(CPP) main.o Contacto.o AVLNode.o AVLTree.o GrupoContactos.o HashTable.o ExportManager.o ComandoManager.o ReporteManager.o -o $(TARGET)

Contacto.o: Contacto.cpp Contacto.h
	$(CPP) -c Contacto.cpp
	
AVLNode.o: AVLNode.cpp AVLNode.h
	$(CPP) -c AVLNode.cpp
	
AVLTree.o: AVLTree.cpp AVLTree.h
	$(CPP) -c AVLTree.cpp
	
GrupoContactos.o: GrupoContactos.cpp GrupoContactos.h
	$(CPP) -c GrupoContactos.cpp
	
HashTable.o: HashTable.cpp HashTable.h
	$(CPP) -c HashTable.cpp
	
ExportManager.o: ExportManager.cpp ExportManager.h
	$(CPP) -c ExportManager.cpp

ComandoManager.o: ComandoManager.cpp ComandoManager.h
	$(CPP) -c ComandoManager.cpp

ReporteManager.o: ReporteManager.cpp ReporteManager.h
	$(CPP) -c ReporteManager.cpp

main.o: 
	$(CPP) -c main.cpp
 
clean:
	rm -f *.o $(TARGET)
