#pragma once
#include <iostream>
template <class Clave>
class nodeB {

public:
// Constructor:
nodeB(const int dat, nodeB *izq = NULL, nodeB *der=NULL) : dato(dat), izdo(izq), dcho(der) {}

friend std::ostream& operator<<(std::ostream& os, nodeB<Clave>* node) {
    os << "[" << node->dato << "] ";
    return os;
}

//Miembros: 
Clave dato; // dato: Cualquier tipo de
nodeB<Clave>* izdo; // valor a almacenar
nodeB<Clave>* dcho;

};
