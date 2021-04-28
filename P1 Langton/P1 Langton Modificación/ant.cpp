
// AUTHOR: Juan García Santos
// DATE: 02/01/2021
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 1.0
// SUBJECT: AEDA
// PRACTICE Nº: 1
// Especificaciones de la clase hormiga

#include "ant.h"

//Constructores
Ant::Ant(){
    row_pos = 0;
    column_pos = 0;
    direction = '>';
}

Ant::Ant(int i, int j, char direction_){
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

char Ant::GetDirection(void) {
    return direction;
}

void Ant::SetRow(int row) {
    row_pos = row;
}

void Ant::SetColumn(int column) {
    column_pos = column;
}

void Ant::SetDirection(char next_direction) {
    direction = next_direction;
}

//Funciones de movimiento de la hormiga
void Ant::Update(void) {
    if(direction == '^')
        row_pos += -1;
    else if (direction == '>')
        column_pos += 1;
    else if(direction == 'V')
        row_pos += 1;
    else column_pos += -1;

}

void Ant::Turn90R(void) {
    if(direction == '^')
        direction = '>';
    else if (direction == '>')
        direction = 'V';
    else if(direction == 'V')
        direction = '<';
    else direction = '^';
}

void Ant::Turn90L(void) {
    if(direction == '^')
        direction = '<';
    else if (direction == '<')
        direction = 'V';
    else if(direction == 'V')
        direction = '>';
    else direction = '^';
}