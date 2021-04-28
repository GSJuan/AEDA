// AUTHOR: Juan García Santos
// DATE: 6/04/2021
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 1.0
// SUBJECT: AEDA
// PRACTICE Nº: 5
// Compilation: make
// Execution: ./main
// Clase heredada para especificar la funcion modulo
#include "fdispersion.h"
#pragma once
template <class Clave>
class fdModulo: public FuncionDispersion<Clave> {

public:

fdModulo(const unsigned n): nDatos(n){}


unsigned operator()(const Clave& k) const;

private:

unsigned nDatos;

};

template<class Clave>
unsigned fdModulo<Clave>::operator()(const Clave& k) const {
    return k % nDatos;
}
