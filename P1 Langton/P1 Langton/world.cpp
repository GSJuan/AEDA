
// AUTHOR: Juan García Santos
// DATE: 02/01/2021
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 1.0
// SUBJECT: AEDA
// PRACTICE Nº: 1
// Especificaciones de la clase mundo

#include "world.h"

//Constructores

World::World(){
    row = 10;
    column = 10;
    size = 100;
    world.resize(10);
    for(int i = 0; i < 10; i++){
        world[i].resize(10);
    }
}

World::World(int row_size, int column_size){
    row = row_size;
    column = column_size;
    size = row * column;
    world.resize(row_size);
        for(int i = 0; i < column_size; i++){
        world[i].resize(column_size);
    }
}


//Destructor

World::~World(){
}


//Getters y Setters

int World::GetRow() {
    return row;
}

int World::GetColumn() {
    return column;
}

int World::GetSize() {
    return size;
}

char World::GetWorldState(int i, int j) {
    return world[i].at(j).state;
}

bool World::GetWorldValue(int i, int j) {
    return world[i].at(j).value;
}

void World::SetRow(int row_) {
    row = row_;
}

void World::SetColumn(int column_) {
    column = column_;
}

void World::SetSize(int size_) {
    size = size_;
}

void World::SetWorldState(char state_, int i, int j) {
    world[i].at(j).state = state_;
    if(state_ == ' ')
        world[i].at(j).value = false;
    else
        world[i].at(j).value = true;

}

void World::SetWorldValue(bool value_, int i, int j) {
    world[i].at(j).value = value_;
    if(value_ == false)
        world[i].at(j).state = ' ';
    else
        world[i].at(j).state = 'X';
}


//Funciones de visualizacion del mundo

void World::PrintWorld(void) {
    PrintHorizontalWall();
    for(int i = 0; i < GetRow(); i++) {
        std::cout << "|";
        for(int j = 0; j < GetColumn(); j++) {
            std::cout <<  GetWorldState(i,j) ;
        }
        std::cout << "|" << std::endl;
    }
    PrintHorizontalWall();
}

void World::PrintHorizontalWall(void) {   
    for(int i = 0; i < GetColumn() + 2; i++){
        std::cout << "-";
    }
    std::cout << std::endl;
}