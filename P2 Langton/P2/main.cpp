// AUTHOR: Juan García Santos
// DATE: 02/01/2021
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 1.0
// SUBJECT: AEDA
// PRACTICE Nº: 1
// Compilation: g++ main.cpp universe.cpp world.cpp ant.cpp  -o test
// Execution: ./langton
// Este programa simula el comportamiento de la hormiga de langton en un formto de texto.

#include "universe.h"

int main( void /*int argc, char* argv[]*/ ) {

    /*int world_row, world_column, iterations, direction;

    std::cout << "Introduzca eL numero de filas del mundo: " << std:: endl;
    std::cin >> world_row;

    std::cout << "Introduzca eL numero de columnas del mundo: " << std:: endl;
    std::cin >> world_column;

    std::cout << "Introduzca la dirección inicial de la hormiga (entre estas: 0,1,2,3,4,5,6,7,8) " << std:: endl;
    std::cin >> direction;

    /*std::cout << direction;
    while (direction != ( "^" || "<" || ">" || "V" )){
        std::cout << "carácter de dirección incorrecto" << std::endl;
        std::cout << "Introduzca la dirección inicial de la hormiga (entre estas: ^ , < , > , V ) " << std:: endl;
        std::cin >> direction;
    }*/
/*
    std::cout << "Introduzca el numero máximo de iteraciones " << std:: endl;
    std::cin >> iterations;*/

    World grid(-3, 3, -3, 3);
    Ant ant(2, 2, 5);
    Universe universe(10);
    universe.Loop(ant, grid);

    return 0;
}

//blanca = false = " "
//negra = true = "X"
