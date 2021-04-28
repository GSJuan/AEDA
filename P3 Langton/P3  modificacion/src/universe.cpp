// AUTHOR: Juan García Santos
// DATE: 16/03/2021
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 3.0
// SUBJECT: AEDA
// PRACTICE Nº: 3
// Compilation: make
// Execution: ./langton
// Especificaciones de la clase Universe

#include "include/universe.h"

//Constructores y destructor
Universe::Universe() {
    max_iter = 10;
    curr_iter = 0;
}

Universe::Universe(int iter){
    max_iter = iter;
    curr_iter = 0;
}

Universe::Universe(World* world, const std::vector<Ant>& ant_list, int iterations){
    max_iter = iterations;
    curr_iter = 0;
    ants = ant_list;
    grid = world;
}

Universe::~Universe() {
}

int Universe::GetMaxIter(void) {
    return max_iter;
}

int Universe::GetCurrIter(void) {
    return curr_iter;
}

void Universe::SetMaxIter(int iteration) {
    max_iter = iteration;
}
   
void Universe::SetCurrIter(int iteration) {
    curr_iter = iteration;
}

void Universe::Loop(void) {
    int counter = 0; //modificacion
    Sort(); 
    grid->PrintGrid(ants);
    std::cout << "Current iteration: " << GetCurrIter() << std::endl;
    PrintData();
    
    for (int i = 0; i < GetMaxIter(); i++){
       // grid.Update(ants);
       SetCurrIter(i+1);
        for(int j = 0; j < ants.size(); j++){
            ants[j].Update(*grid);
            if(grid->AntOut(ants[j])) {
                counter ++; // modificacion
            }
        }
        Sort();
        grid->PrintGrid(ants);
        std::cout << "Current times an ant has gone out: " << counter << " time/s" << std::endl;//modificacion
        std::cout << "Current iteration" << GetCurrIter() << std::endl;
        PrintData();
    }
}

void Universe::Sort(void) {

std::vector<Ant> temp;


while(ants.size() > 0) {
int min_row = 999, min_col = 999, min = 0;

    for (int i = 0; i < ants.size(); i++) {
        if(ants[i].GetRow() < min_row) {
            min_row = ants[i].GetRow();
            min_col = ants[i].GetColumn();
            min = i;
        }
        else if(ants[i].GetRow() == min_row){
            if(ants[i].GetColumn() < min_col){
                min_row = ants[i].GetRow();
                min_col = ants[i].GetColumn();
                min = i;
            }
        }
    }
    temp.push_back(ants[min]);
    ants.erase(ants.begin() + min);
}
ants = temp;
}

void Universe::PrintData(void) {
    for(int i = 0; i < ants.size(); i++){
        std::cout << "Ant " << i+1 << ": X = " << ants[i].GetRow() << " Y = " << ants[i].GetColumn() << " Direction: " ;
        ants[i].PrintDirection();
        std::cout << std::endl;
    }
    
}