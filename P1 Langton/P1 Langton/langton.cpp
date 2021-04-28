// AUTHOR: Juan García Santos
// DATE: 02/01/2021
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 1.0
// SUBJECT: AEDA
// PRACTICE Nº: 1
// Especificaciones de la clase langton
#include "langton.h"

//Constructores y destructor
Langton::Langton() {
    max_iter = 10;
    curr_iter = 0;
}

Langton::Langton(int iter){
    max_iter = iter;
    curr_iter = 0;
}

Langton::~Langton() {
}

int Langton::GetMaxIter(void) {
    return max_iter;
}

int Langton::GetCurrIter(void) {
    return curr_iter;
}

void Langton::SetMaxIter(int iteration) {
    max_iter = iteration;
}
   
void Langton::SetCurrIter(int iteration) {
    curr_iter = iteration;
}

void Langton::Algorithm(Ant& ant, World& grid) {

    for (int i = 0; i <= GetMaxIter(); i++){
        std::cout << "Iteración numero: " << GetCurrIter() << std:: endl;
        PrintGrid(ant, grid);
        SetCurrIter(i);
        if((ant.GetRow() < grid.GetRow()) && (ant.GetColumn() < grid.GetColumn()) && (ant.GetRow() >= 0) && (ant.GetColumn() >= 0)){ 

            if ((grid.GetWorldValue(ant.GetRow(), ant.GetColumn())) == false){
                grid.SetWorldValue(true, ant.GetRow(), ant.GetColumn());
                ant.Turn90L();
                ant.Update();
            }
            else {
                grid.SetWorldValue(false, ant.GetRow(), ant.GetColumn());
                ant.Turn90R();
                ant.Update();
            }
        }
        else{
            std:: cout << std::endl << "La hormiga se ha salido" << std::endl;
            break;
        }
    }
}

void Langton::PrintGrid(Ant& ant, World& grid){

grid.PrintHorizontalWall();
    for(int i = 0; i < grid.GetRow(); i++) {
        std::cout << "|";
        for(int j = 0; j < grid.GetColumn(); j++) {
            if((i != ant.GetRow()) || (j != ant.GetColumn()))
            std::cout <<  grid.GetWorldState(i,j);
            else std::cout << ant.GetDirection();
        }
        std::cout << "|" << std::endl;
    }
grid.PrintHorizontalWall();
}