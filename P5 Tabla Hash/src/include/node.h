// AUTHOR: Juan García Santos
// DATE: 6/04/2021
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 1.0
// SUBJECT: AEDA
// PRACTICE Nº: 5
// Compilation: make
// Execution: ./main
// Clase nodo de template para especificar la unidad de la lista 
// Actualmente no se usa por fallos en el codigo que no sé resolver
#pragma once

#include <iostream>

template <class Clave>
class Node {

private:

	Node<Clave>* next = NULL;
	Clave data;

public:

	Node();
	Node(const Clave&);
	~Node();

	void SetNext(Node<Clave>*);
	void SetData(const Clave&);

	inline Node<Clave>* GetNext(void) const {
        return next;
    }

	inline const Clave& GetData(void) const {
        return data;
    }
	    
};

template <class Clave>
Node<Clave>::Node(){
	next = NULL;
}

template <class Clave>
Node<Clave>::Node(const Clave& data_) {
    data = data_;
    next = NULL;
}

template <class Clave>
Node<Clave>::~Node(void) {}

template <class Clave>
void Node<Clave>::SetNext(Node<Clave>* next_) {
	next = next_;
}

template <class Clave>
void Node<Clave>::SetData(const Clave& data_) {
	data = data_;
}
