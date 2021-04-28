// AUTHOR: Juan García Santos
// DATE: 02/01/2021
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 1.0
// SUBJECT: AEDA
// PRACTICE Nº: 1
// Especificaciones de la clase Universe
#include "universe.h"

//Constructores y destructor
Universe::Universe() {
    max_iter = 10;
    curr_iter = 0;
}

Universe::Universe(int iter){
    max_iter = iter;
    curr_iter = 0;
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

void Universe::Loop(Ant& ant, World& grid) {

    for (int i = 1; i <= GetMaxIter(); i++){

        SetCurrIter(i);
        std::cout << "Iteración numero: " << GetCurrIter() << std:: endl;
        
        if((ant.GetRow() < grid.GetRowUpperLimit()) && (ant.GetColumn() < grid.GetColumnUpperLimit(0)) && (ant.GetRow() >= grid.GetRowLowerLimit()) && (ant.GetColumn() >= grid.GetColumnLowerLimit(0))){ 
            PrintGrid(ant, grid);

            if ((grid.GetWorldValue(ant.GetRow(), ant.GetColumn())) == false){ // casilla blanca
                grid.SetWorldValue(true, ant.GetRow(), ant.GetColumn());
                ant.Turn45L();
                ant.Update();
            }
            else {
                grid.SetWorldValue(false, ant.GetRow(), ant.GetColumn()); //casilla negra
                ant.Turn45R();
                ant.Update();
            }
        }
        else{
            if(ant.GetRow() >= grid.GetRowUpperLimit()){
                grid.RowUpResize(50);
                std::cout << grid.GetColumnLowerLimit(0) << grid.GetColumnUpperLimit(0) << grid.GetRowLowerLimit() << grid.GetRowUpperLimit();
            }
            else if(ant.GetRow() < grid.GetRowLowerLimit()) {
                grid.RowUpResize(50);
                grid.SetRowLowerLimit(grid.GetRowLowerLimit()-50);
            }
            else if (ant.GetColumn() >= grid.GetColumnUpperLimit(0)){
                grid.ColumnUpResize(50);
            }
            else if(ant.GetColumn() < grid.GetColumnLowerLimit(0)){
                grid.ColumnUpResize(50);
                grid.SetColumnLowerLimit(grid.GetColumnLowerLimit(0) + 50);   
            }
        }

        
    }
}

void Universe::PrintGrid(Ant& ant, World& grid){
    grid.PrintHorizontalWall();
        for(int i = grid.GetRowLowerLimit(); i < grid.GetRowUpperLimit(); i++) {
            std::cout << "|";
            for(int j = grid.GetColumnLowerLimit(i); j < grid.GetColumnUpperLimit(i); j++) {
                if((i != ant.GetRow()) || (j != ant.GetColumn()))
                std::cout <<  grid.GetWorldState(i,j);
                else ant.PrintDirection();
            }
            std::cout << "|" << std::endl;
        }
    grid.PrintHorizontalWall();
}