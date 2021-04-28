// AUTHOR: Juan García Santos
// DATE: 02/01/2021
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 1.0
// SUBJECT: AEDA
// PRACTICE Nº: 1
// Clase Universe que define la relacion entre hormiga y mundo

#include "ant.h"
#include "world.h"

#pragma once

class Universe {

    private:

    int max_iter;
    int curr_iter;

    public:

    Universe();
    Universe(int);
    ~Universe();

    int GetMaxIter(void); //devuelve el numero maximo de iteraciones
    int GetCurrIter(void); //devuelve el numero actual de iteraciones

    void SetMaxIter(int);
    void SetCurrIter(int);

    void Loop(std::vector<Ant>, World&); //función que posee el algoritmo del movimiento de la hormiga de langton

    void PrintGrid(std::vector<Ant>, World&); //función de impresion del mundo con la hormiga
};