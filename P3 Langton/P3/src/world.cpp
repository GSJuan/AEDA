
// AUTHOR: Juan García Santos
// DATE: 16/03/2021
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 3.0
// SUBJECT: AEDA
// PRACTICE Nº: 3
// Compilation: make
// Execution: ./langton
// Especificaciones de la clase mundo

#include "include/world.h"

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

char World::GetWorldState(int i, int j) {
    return world[i][j].state;
}

bool World::GetWorldValue(int i, int j) {
    return world[i][j].value;
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

void World::ToggleWorldValue(int i, int j){
    
   if(world[i][j].value == false){
        world[i][j].value = true;
        world[i][j].state = 'X';
   }
   else {
        world[i][j].value = false;
        world[i][j].state = ' ';
   }  
}


void World::SetWorld(Vector<Vector<Cell>>& new_world){

    world.resize(new_world.GetSize());
    world.SetLowerLimit(new_world.GetLowerLimit());

    for(int i = world.GetLowerLimit(); i < world.GetUpperLimit(); i++){
        world[i].resize(new_world[i].GetSize());
        world[i].SetLowerLimit(new_world[i].GetLowerLimit());
        for(int j = world[i].GetLowerLimit(); j < world[i].GetUpperLimit(); j++){
            world[i][j] = new_world[i][j];
        }
    }
}
/*
void World::ReSize(std::vector<Ant>& ants) {
while(AntOut(ants)){
int up = 0, down = 0, left = 0, right = 0;

Vector<Vector<Cell>> new_world;

for(int i = 0; i < ants.size(); i++) {       
    
        if(ants[i].GetRow() >= world.GetUpperLimit()){
            up = 20; 
            comment_init new_world.resize(world.GetSize() + 20);
            new_world.SetLowerLimit(world.GetLowerLimit());
            for(int i = new_world.GetLowerLimit(); i < new_world.GetUpperLimit(); i++){
                new_world[i].resize(world[0].GetSize());
                new_world[i].SetLowerLimit(world[0].GetLowerLimit());
            } comment_end 
        }
        else if(ants[i].GetRow() < world.GetLowerLimit()) {
            up = 20;
            down = -20;
           comment_init new_world.resize(world.GetSize() + 20);
            new_world.SetLowerLimit(world.GetLowerLimit()- 20);
            for(int i = new_world.GetLowerLimit(); i < new_world.GetUpperLimit(); i++){
                new_world[i].resize(world[0].GetSize());
                new_world[i].SetLowerLimit(world[0].GetLowerLimit());
            } comment_end 
        }
        else if (ants[i].GetColumn() >= world[0].GetUpperLimit()){
            right = 20;
            comment_init new_world.resize(world.GetSize());
            new_world.SetLowerLimit(world.GetLowerLimit());
            for(int i = new_world.GetLowerLimit(); i < new_world.GetUpperLimit(); i++){
                    new_world[i].resize(world[0].GetSize() + 20);
                new_world[i].SetLowerLimit(world[0].GetLowerLimit());
            } comment_end 
        }
        else if(ants[i].GetColumn() < world[0].GetLowerLimit()){
            right = 20;
            left = -20;
           comment_init new_world.resize(world.GetSize());
            new_world.SetLowerLimit(world.GetLowerLimit());
            for(int i = new_world.GetLowerLimit(); i < new_world.GetUpperLimit(); i++){
                new_world[i].resize(world[0].GetSize() + 20);
                new_world[i].SetLowerLimit(world[0].GetLowerLimit() - 20);
            } comment_end                     
        }
}

    new_world.resize(world.GetSize() + up);
    new_world.SetLowerLimit(world.GetLowerLimit() + down);
    for(int i = new_world.GetLowerLimit(); i < new_world.GetUpperLimit(); i++){
        new_world[i].resize(world[0].GetSize() + right);
        new_world[i].SetLowerLimit(world[0].GetLowerLimit() + left);
    }

    for(int j = world.GetLowerLimit(); j < world.GetUpperLimit(); j++){
        for (int k = world[j].GetLowerLimit(); k < world[j].GetUpperLimit(); k++){
            new_world[j][k] = world[j][k];
        }
    }
    SetWorld(new_world);
}
}
*/


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

void World::Update(std::vector<Ant>& ant) {

    for(int i = 0; i < ant.size(); i++) {
        if ((GetWorldValue(ant[i].GetRow(), ant[i].GetColumn())) == false){ // casilla blanca
            SetWorldValue(true, ant[i].GetRow(), ant[i].GetColumn());
        }
        else {
            SetWorldValue(false, ant[i].GetRow(), ant[i].GetColumn()); //casilla negra
        } 
    }
}


void World::PrintGrid(std::vector<Ant>& ant){
    if(AntOut(ant) == true) {
        ReSize(ant);
    }
    int k = 0;
    PrintHorizontalWall();

        for(int i = world.GetLowerLimit(); i < world.GetUpperLimit(); i++) {
            std::cout << "|";
            for(int j = world[i].GetLowerLimit(); j < world[i].GetUpperLimit(); j++) {
                if((i != ant[k].GetRow()) || (j != ant[k].GetColumn()))
                std::cout << GetWorldState(i,j);
                else {
                    ant[k].PrintDirection();
                    if( k+1 < ant.size())
                    k++;
                    }
            }
            std::cout << "|" << std::endl;
        }
    PrintHorizontalWall();
}

bool World::AntOut(std::vector<Ant>& ant){
    bool condition = false;
    for(int i = 0; i < ant.size(); i++){
        if((ant[i].GetRow() >= world.GetUpperLimit()) || (ant[i].GetColumn() >= world[0].GetUpperLimit()) || (ant[i].GetRow() < world.GetLowerLimit()) || (ant[i].GetColumn() < world[0].GetLowerLimit())){
            condition = true;
        }
    }
    return condition;
}

bool World::AntOut(Ant& ant) {
    bool condition = false;
    if((ant.GetRow() >= world.GetUpperLimit()) || (ant.GetColumn() >= world.GetUpperLimit()) || (ant.GetRow() < world.GetLowerLimit()) || (ant.GetColumn() < world.GetLowerLimit()))
        condition = true;
    return condition;
}
