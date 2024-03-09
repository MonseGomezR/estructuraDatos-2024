CPP = g++
TARGET = compiled_solitaire


all: .all-post

.all-post: main.o Carta.o Cola.o ListaD.o Nodo.o NodoLD.o Pila.o
	$(CPP) main.o Carta.o Cola.o ListaD.o Nodo.o NodoLD.o Pila.o -o $(TARGET)

Carta.o: Carta.cpp Carta.h
	$(CPP) -c Carta.cpp
	
Cola.o: Cola.cpp Cola.h
	$(CPP) -c Cola.cpp
	
ListaD.o: ListaD.cpp ListaD.h
	$(CPP) -c ListaD.cpp
	
Nodo.o: Nodo.cpp Nodo.h
	$(CPP) -c Nodo.cpp
	
NodoLD.o: NodoLD.cpp NodoLD.h
	$(CPP) -c NodoLD.cpp
	
Pila.o: Pila.cpp Pila.h
	$(CPP) -c Pila.cpp


main.o: 
	$(CPP) -c main.cpp
 
clean:
	rm -f *.o $(TARGET)
