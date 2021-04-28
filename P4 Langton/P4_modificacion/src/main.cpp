// AUTHOR: Juan García Santos
// DATE: 21/03/2021
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 4.0
// SUBJECT: AEDA
// PRACTICE Nº: 4
// Compilation: make
// Execution: ./langton
// Este programa simula el comportamiento de la hormiga de langton en un formto de texto.

#include "include/universe.h"

int main( void /* int argc, char* argv[]*/ ) {
    int row_min, row_max, col_min, col_max, iterations, direction, ant_quantity, ant_row, ant_col, world_type, menu, ant_type;
    std::cout << "¿Desea el comportamiento por defecto del mundo(0), o personalizar la experiencia(1)?" << std::endl << "Introduzca 0 o 1: ";
    std::cin >> menu;
    while((menu != 0) && (menu != 1)){
        std::cin >> menu;
        if((menu != 0) && (menu != 1)){
            std::cout << "¡Eso no era un 1 o un 0! Ojito cuidado. " << std::endl << "Introduzca 0 o 1: ";
        }
    }

if (menu == 0){
    row_min = -4;
    row_max = 4;
    col_min = -4;
    col_max = 4;
    iterations = 10;
    world_type = 0;
}
else if(menu == 1) {
    
    std::cout << "Introduzca el indice menor de las filas del mundo (se aceptan indices negativos ;D ): ";
    std::cin >> row_min;
    while (row_min >= 0){
        std::cout << "Eso era mayor o igual que 0. Ojito Cuidado" << std::endl;
        std::cout << "Introduzca el indice menor de las filas del mundo(menor que 0): " << std:: endl;
        std::cin >> row_min;
    }
    std::cout << std::endl <<"Introduzca el indice mayor de las filas del mundo(mayor o igual que 0): " << std:: endl;
    std::cin >> row_max;
    while (row_max < 0){
        std::cout << "Eso no era mayor o igual que 0. Ojito Cuidado" << std::endl;
        std::cout << "Introduzca el indice mayor de las filas del mundo(mayor o igual que 0): " << std:: endl;
        std::cin >> row_max;
    }

    std::cout << "Introduzca el indice menor de las columna del mundo (se aceptan indices negativos ;D): ";
    std::cin >> col_min;
    while (col_min >= 0){
        std::cout << "Eso era mayor o igual que 0. Ojito Cuidado" << std::endl;
        std::cout << "Introduzca el indice menor de las columnas del mundo(menor que 0): " << std:: endl;
        std::cin >> col_min;
    }
    std::cout << std::endl << "Introduzca el indice mayor de las columnas del mundo(mayor o igual que 0): " << std:: endl;
    std::cin >> col_max;
    while (col_max < 0){
        std::cout << "Eso no era mayor que 0. Ojito Cuidado" << std::endl;
        std::cout << "Introduzca el indice mayor de las columnas del mundo(mayor o igual que 0): " << std:: endl;
        std::cin >> col_max;
    }

    std::cout << "Introduzca el numero de iteraciones(mayor que 0): " << std:: endl;
    std::cin >> iterations;
    while (iterations <= 0){
        std::cout << "Eso no era mayor que 0. Ojito Cuidado" << std::endl;
        std::cout << "Introduzca el numero de iteraciones(mayor que 0): " << std:: endl;
        std::cin >> iterations;
    }

    std::cout << "Introduzca el tipo de mundo (0 infinito, 1 finito): ";
    std::cin >> world_type;
    while (world_type != ( 1 || 0 )){
        std::cout << "Eso no era un 0 o un 1. Ojito Cuidado" << std::endl;
        std::cout << "Introduca el tipo de mundo (0 infinito, 1 finito): " << std:: endl;
        std::cin >> world_type;
    }

}

World *pWorld;
if(world_type == 0)
pWorld = new InfiniteWorld(row_min, row_max, col_min, col_max);

else
pWorld = new FiniteWorld(row_min, row_max, col_min, col_max);

std::vector<Ant*> ants;

std::cout << "Introduzca la cantidad de hormigas que desea introducir: ";
std::cin >> ant_quantity;
while (ant_quantity <= 0) {
    std::cout << "Eso no era mayor que 0. Ojito Cuidado" << std::endl;
    std::cout << "Introduzca la cantidad de hormigas que desea introducir: " << std:: endl;
    std::cin >> ant_quantity;
    } 

for(int i = 0; i < ant_quantity; i++) {
Ant *pant;

    std::cout << "Introduzca el tipo de la hormiga " << i+1 << " (0 = normal, 1 = invertida, 2 = modificada): ";
    std::cin >> ant_type;
    while ((ant_type < 0) || (ant_type > 2)) {
        std::cout << "El tipo de hormiga indicada no existe. Ojito Cuidado" << std::endl;
        std::cout << "Introduzca un tipo de hormiga válido (0 = normal, 1 = invertida, 2 = modificada):  " <<  std:: endl;
    std::cin >> ant_type;
    }

    std::cout << "Introduzca la coordenada X de la hormiga " << i+1 << ": ";
    std::cin >> ant_row;
    while ((ant_row < row_min) || (ant_row > row_max)) {
        std::cout << "Esa coordenada X no está dentro del mundo previamente definido. Ojito Cuidado" << std::endl;
        std::cout << "Introduzca una coordenada entre " << row_min << " y " << row_max << std:: endl;
    std::cin >> ant_row;
    }

    std::cout << "Introduzca la coordenada Y de la hormiga " << i+1 << ": ";
    std::cin >> ant_col;
    while ((ant_col < col_min) || (ant_col > col_max)) {
        std::cout << "Esa coordenada Y no está dentro del mundo previamente definido. Ojito Cuidado" << std::endl;
        std::cout << "Introduzca una coordenada entre " << col_min << " y " << col_max << std:: endl;
        std::cin >> ant_row;
    }
    
    std::cout << "Introduzca la dirección inicial de la hormiga (entre estas: 1, 2, 3, 4, 5, 6, 7, 8) " << std:: endl;
    std::cin >> direction;
    while ((direction < 1) || (direction > 8)) {
        std::cout << "carácter de dirección incorrecto" << std::endl;
        std::cout << "Introduzca la dirección inicial de la hormiga (entre estas: 1, 2, 3, 4, 5, 6, 7, 8) " << std:: endl;
        std::cin >> direction;
    }

    if(ant_type == 0)
        pant = new LangtonAnt (ant_row, ant_col, direction);
    else if(ant_type == 1)
        pant = new InversedAnt (ant_row, ant_col, direction);
    else if(ant_type == 2)
        pant = new ModifiedAnt (ant_row, ant_col, direction);

    ants.push_back(pant);
}

Universe universe(pWorld, ants, iterations);
universe.Loop();

return 0;
}

//blanca = false = " "
//negra = true = "X"