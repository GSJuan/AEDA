// AUTHOR: Juan García Santos
// DATE: 6/04/2021
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 1.0
// SUBJECT: AEDA
// PRACTICE Nº: 5
// Compilation: make
// Execution: ./main
// Clase base a partir de la cual especificar funciones de dispersion diferentes
#pragma once

template <class Clave>
class FuncionDispersion {

public:
    FuncionDispersion();
    ~FuncionDispersion();

    virtual unsigned operator()(const Clave& k) const = 0;

};

template<class Clave>
FuncionDispersion<Clave>::FuncionDispersion() {}

template<class Clave>
FuncionDispersion<Clave>::~FuncionDispersion() {}

