
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
    world = Vector<Vector<Cell>> (-10,10);
    for(int i = 0; i < 10; i++){
        world[i].resize(10);
    }
}
std::vector<int> a;
World::World(int row_size, int column_size){
    row = row_size;
    column = column_size;
    size = row * column;
    world.resize(row_size);
        for(int i = 0; i < column_size; i++){
        world[i].resize(column_size);
    }
}

World::World(int row_min, int row_max, int col_min, int col_max){
row = row_max - row_min;
column = col_max - col_min;
size = row * column;
world.resize(row);
world.SetLowerLimit(row_min);
for(int i = world.GetLowerLimit(); i < world.GetUpperLimit(); i++){
    world[i].resize(column);
    world[i].SetLowerLimit(col_min);
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
    return world[i][j].state;
}

bool World::GetWorldValue(int i, int j) {
    return world[i][j].value;
}


int World::GetRowLowerLimit(){
    return world.GetLowerLimit();
}

int World::GetRowUpperLimit(){
    return world.GetUpperLimit();
}

int World::GetColumnLowerLimit(int i){
    return world[i].GetLowerLimit();
}

int World::GetColumnUpperLimit(int i){
    return world[i].GetUpperLimit();
}

void World::SetRowLowerLimit(int lim){
    world.SetLowerLimit(lim);
}

void World::SetColumnLowerLimit(int lim){
    for (int i = world.GetLowerLimit(); i < world.GetUpperLimit(); i++)
    {
       world[i].SetLowerLimit(lim); 
    }
    
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
    world[i][j].state = state_;
    if(state_ == ' ')
        world[i][j].value = false;
    else
        world[i][j].value = true;
}

void World::SetWorldValue(bool value_, int i, int j) {
    world[i][j].value = value_;
    if(value_ == false)
        world[i][j].state = ' ';
    else
        world[i][j].state = 'X';
}


//Funciones de visualizacion del mundo

void World::PrintWorld(void) {
    PrintHorizontalWall();
    for(int i = world.GetLowerLimit(); i < world.GetUpperLimit(); i++) {
        std::cout << "|";
        for(int j = world[i].GetLowerLimit(); j < world[i].GetUpperLimit(); j++) {
            std::cout <<  GetWorldState(i,j) ;
        }
        std::cout << "|" << std::endl;
    }
    PrintHorizontalWall();
}

void World::PrintHorizontalWall(void) {   
    for(int i = world[0].GetLowerLimit(); i < world[0].GetUpperLimit() + 2; i++){
        std::cout << "-";
    }
    std::cout << std::endl;
}

void World::RowUpResize(int sz){
    int og_sz = world.GetSize();
    world.resize(sz + og_sz);
}

void World::ColumnUpResize(int sz){
    int og_sz = world[0].GetSize();

    for (int i = world.GetLowerLimit(); i < world.GetUpperLimit(); i++){
        world[i].resize(sz + og_sz);
    }
}