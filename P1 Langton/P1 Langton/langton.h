// AUTHOR: Juan García Santos
// DATE: 02/01/2021
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 1.0
// SUBJECT: AEDA
// PRACTICE Nº: 1
// Clase Langton que define la relacion entre hormiga y mundo

#include "ant.h"
#include "world.h"

class Langton{

    private:

    int max_iter;
    int curr_iter;

    public:

    Langton();
    Langton(int);
    ~Langton();

    int GetMaxIter(void); //devuelve el numero maximo de iteraciones
    int GetCurrIter(void); //devuelve el numero actual de iteraciones

    void SetMaxIter(int);
    void SetCurrIter(int);

    void Algorithm(Ant&, World&); //función que posee el algoritmo del movimiento de la hormiga de langton

    void PrintGrid(Ant&, World&); //función de impresion del mundo con la hormiga
};