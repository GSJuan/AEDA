// AUTHOR: Juan García Santos
// DATE: 6/04/2021
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 1.0
// SUBJECT: AEDA
// PRACTICE Nº: 5
// Compilation: make
// Execution: ./main
// Clase heredada para especificar la funcion pseudoaleatoria
#include "fdispersion.h"
#include <cstdlib>
#pragma once

template <class Clave>
class fdPseudoaleatoria: public FuncionDispersion<Clave> {

public:

    fdPseudoaleatoria(const unsigned n): nDatos(n) {}

    unsigned operator()(const Clave&) const;

private:

    unsigned nDatos;

};

template<class Clave>
unsigned fdPseudoaleatoria<Clave>::operator()(const Clave& k) const {
    srand(k);
    return rand() % nDatos;
}
