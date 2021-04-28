// AUTHOR: Juan García Santos
// DATE: 6/04/2021
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 1.0
// SUBJECT: AEDA
// PRACTICE Nº: 5
// Compilation: make
// Execution: ./main
// Clase lista de template (sll)
#pragma once
#include "node_struct.h"
template <class Clave> 
class List {

private:

    node<Clave>* head;

public:

    List();
    ~List();

    bool Search (Clave&) const;

    bool Insert(const Clave&);
    
    bool Empty() {
        if(head->next == NULL)
            return true;
       return false;
    }

    void InsertAfter(node<Clave>*, node <Clave>*);
    void InsertHead(node<Clave>*);

    int ListSize();

    node<Clave>* ExtractHead();
    node<Clave>* ExtractAfter(node<Clave>*);
};

template <class Clave>
List<Clave>::List(){
    head = new node<Clave>;
}

template <class Clave>
List<Clave>::~List() {
    while(Empty() == false) {
        node<Clave>* aux = new node<Clave>;
        aux = head;
        head = head->next;
        aux->next = NULL;
        delete aux;
    }
}

template <class Clave>
bool List<Clave>::Search(Clave& X) const{

    node<Clave>* aux = new node<Clave>;
    aux->data = head->data;
    aux->next = head->next;

    while(aux != NULL) {
        if(aux->data == X)
            return true;
        aux = aux->next;
    }
    return false;
}

template <class Clave>
bool List<Clave>::Insert(const Clave& X) {
    node<Clave>* aux = new node<Clave>;
    aux = head;
    
    while(aux != NULL) {
        if(aux->data == X)
            return false; 
        aux = aux->next;
    }
    return true;
}

template <class Clave>
void List<Clave>::InsertAfter(node<Clave>* previous, node<Clave>* node) {
    node->next = previous->next;
    previous->next = node;
}

template <class Clave>
void List<Clave>::InsertHead(node<Clave>* node) {
    node->next = head;
    head = node;
}

template <class Clave>
node<Clave>* List<Clave>::ExtractHead() {
    node<Clave>* aux = new node<Clave>;
    aux = head;
    head = head->next;
    return aux;
}

template <class Clave>
node<Clave>* List<Clave>::ExtractAfter(node<Clave>* previous) {
    node<Clave>* aux = new node<Clave>;
    aux = previous->next;
    previous->next = aux->next;
    aux->next = NULL;
    return aux;
}

template<class Clave>
int List<Clave>::ListSize(){
    int size = 0;
    node<Clave>* aux = new node<Clave>;
    aux->data = head->data;
    aux->next = head->next;

    while(aux != NULL) {
        size++;
        aux = aux->next;
    }
    return size;
}
 
