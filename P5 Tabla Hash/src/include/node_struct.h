// AUTHOR: Juan García Santos
// DATE: 6/04/2021
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 1.0
// SUBJECT: AEDA
// PRACTICE Nº: 5
// Compilation: make
// Execution: ./main
// Struct para definir un nodo de la clase lista
template <class Clave>
struct node {
    Clave data;
   struct node<Clave> *next = NULL;
};
