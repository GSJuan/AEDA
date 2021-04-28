// AUTHOR: Juan García Santos
// DATE: 02/01/2021
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 1.0
// SUBJECT: AEDA
// PRACTICE Nº: 1
// Compilation: g++ -o langton main.cpp ant.cpp world.cpp langton.cpp
// Execution: ./langton
// Este programa simula el comportamiento de la hormiga de langton en un formto de texto.

#include "langton.h"

int main( void /*int argc, char* argv[]*/ ) {

    int world_row, world_column, ant_row, ant_column, iterations;
    char direction;

    std::cout << "Introduzca eL numero de filas del mundo: " << std:: endl;
    std::cin >> world_row;

    std::cout << "Introduzca eL numero de columnas del mundo: " << std:: endl;
    std::cin >> world_column;

    std::cout << "Introduzca la fila inicial de la hormiga " << std:: endl;
    std::cin >> ant_row;

    std::cout << "Introduzca la columna inicial de la hormiga " << std:: endl;
    std::cin >> ant_column;

    std::cout << "Introduzca la dirección inicial de la hormiga (entre estas: ^ , < , > , V ) " << std:: endl;
    std::cin >> direction;

    /*std::cout << direction;
    while (direction != ( "^" || "<" || ">" || "V" )){
        std::cout << "carácter de dirección incorrecto" << std::endl;
        std::cout << "Introduzca la dirección inicial de la hormiga (entre estas: ^ , < , > , V ) " << std:: endl;
        std::cin >> direction;
    }*/

    std::cout << "Introduzca el numero máximo de iteraciones " << std:: endl;
    std::cin >> iterations;

    World grid(world_row, world_column);
    Ant ant(ant_row, ant_column, direction);
    Langton langton(iterations);
    langton.Algorithm(ant, grid);

    return 0;
}

//blanca = false = " "
//negra = true = "X"