// AUTHOR: Juan García Santos
// DATE: 02/01/2021
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 2.0
// SUBJECT: AEDA
// PRACTICE Nº: 2
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

void Universe::Loop(std::vector<Ant> ant, World& grid) {

    for (int i = 1; i <= GetMaxIter(); i++){

        SetCurrIter(i);
        std::cout << "Iteración numero: " << GetCurrIter() << std:: endl;

        for(int j = 0; j < ant.size(); j++){

        if((ant[j].GetRow() < grid.GetRowUpperLimit()) && (ant[j].GetColumn() < grid.GetColumnUpperLimit(0)) && (ant[j].GetRow() >= grid.GetRowLowerLimit()) && (ant[j].GetColumn() >= grid.GetColumnLowerLimit(0))){ 
            PrintGrid(ant, grid);

            if ((grid.GetWorldValue(ant[j].GetRow(), ant[j].GetColumn())) == false){ // casilla blanca
                grid.SetWorldValue(true, ant[j].GetRow(), ant[j].GetColumn());
                ant[j].Turn45L();
                ant[j].Update();
            }
            else {
                grid.SetWorldValue(false, ant[j].GetRow(), ant[j].GetColumn()); //casilla negra
                ant[j].Turn45R();
                ant[j].Update();
            }
        }
        else{
            if(ant[j].GetRow() >= grid.GetRowUpperLimit()){
                grid.RowUpResize(50);
                std::cout << grid.GetColumnLowerLimit(0) << grid.GetColumnUpperLimit(0) << grid.GetRowLowerLimit() << grid.GetRowUpperLimit();
            }
            else if(ant[j].GetRow() < grid.GetRowLowerLimit()) {
                grid.RowUpResize(50);
                grid.SetRowLowerLimit(grid.GetRowLowerLimit()-50);
            }
            else if (ant[j].GetColumn() >= grid.GetColumnUpperLimit(0)){
                grid.ColumnUpResize(50);
            }
            else if(ant[j].GetColumn() < grid.GetColumnLowerLimit(0)){
                grid.ColumnUpResize(50);
                grid.SetColumnLowerLimit(grid.GetColumnLowerLimit(0) + 50);   
            }
        }

        }

        
    }
}

void Universe::PrintGrid(std::vector<Ant> ant, World& grid){
    int k = 1;
    grid.PrintHorizontalWall();

        for(int i = grid.GetRowLowerLimit(); i < grid.GetRowUpperLimit(); i++) {
            std::cout << "|";
            for(int j = grid.GetColumnLowerLimit(i); j < grid.GetColumnUpperLimit(i); j++) {
                if((i != ant[k].GetRow()) || (j != ant[k].GetColumn()))
                std::cout <<  grid.GetWorldState(i,j);
                else {
                    ant[k].PrintDirection();
                    k--;
                    }
            }
            std::cout << "|" << std::endl;
        }
    grid.PrintHorizontalWall();
}