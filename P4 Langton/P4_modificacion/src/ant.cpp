
// AUTHOR: Juan García Santos
// DATE: 21/03/2021
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 4.0
// SUBJECT: AEDA
// PRACTICE Nº: 4
// Compilation: make
// Execution: ./langton
// Especificaciones de la clase hormiga

#include "include/ant.h"
#include "include/world.h"

//Constructores
Ant::Ant(){
    row_pos = 0;
    column_pos = 0;
    direction = 1;
}

Ant::Ant(int i, int j, int direction_){
    row_pos = i;
    column_pos = j;
    direction = direction_;
}

//Destructor
Ant::~Ant(){
}

//Getters y setters
int Ant::GetRow(void) {
    return row_pos;
}

int Ant::GetColumn(void) {
    return column_pos;
}

int Ant::GetDirection(void) {
    return direction;
}

void Ant::SetRow(int row) {
    row_pos = row;
}

void Ant::SetColumn(int column) {
    column_pos = column;
}

void Ant::SetDirection(int next_direction) {
    direction = next_direction;
}

//Funciones de movimiento antiguas de la hormiga
/*
void Ant::Turn90R(void) {
    if(direction == 1)
        direction = 3;
    else if (direction == 3)
        direction = 5;
    else if(direction == 5)
        direction = 7;
    else direction = 1;
}

void Ant::Turn90L(void) {
    if(direction == 1)
        direction = 7;
    else if (direction == 7)
        direction = 5;
    else if(direction == 3)
        direction = 3;
    else direction = 1;
}

void Ant::Turn45R(void) {
    if((direction >= 1) && (direction < 8))
        direction++;
    else if (direction == 8)
        direction = 1;
    else std::cout << "aquí ha habido un error, direction = " << direction << std::endl;
}

void Ant::Turn45L(void){
    if((direction <= 8) && (direction > 1))
        direction--;
    else if(direction == 1)
        direction = 8;
    else std::cout << "aquí ha habido un error, direction = " << direction << std::endl;

}
*/

void Ant::Update(World& grid) {
    try{
       Turn45(grid.GetWorldValue(GetRow(), GetColumn()));
    grid.ToggleWorldValue(GetRow(), GetColumn());
    Move(); 
    }
    catch (MyException& e){
        throw e;
    }
}

void Ant::PrintDirection(void){
    int direction = GetDirection();
    switch(direction){
        case 1: std::cout << "\u2191";
        break;

        case 2: std::cout << "\u2197";
        break;

        case 3: std::cout << "\u2192";
        break;

        case 4: std::cout << "\u2198";
        break;

        case 5: std::cout << "\u2193";
        break;

        case 6: std::cout << "\u2199";
        break;

        case 7: std::cout << "\u2190";
        break;

        case 8: std::cout << "\u2196";
        break;
    }
}