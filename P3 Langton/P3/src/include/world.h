// AUTHOR: Juan García Santos
// DATE: 16/03/2021
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 3.0
// SUBJECT: AEDA
// PRACTICE Nº: 3
// Compilation: make
// Execution: ./langton
// Clase "mundo" para definir el comportamiento y características de la malla
#include "ant.h"
#include "vector.h"

#include <iostream>
#include "stdio.h"

#pragma once

class World {

protected:

int row;
int column;
int size;
Vector<Vector<Cell>> world;



public:

World(); //Constructor por defecto
World(int, int); //Constructor por tamaño
explicit World(int, int, int, int);
virtual ~World();//Destructor

inline int GetRow() {
    return row;
} //devuelve el numero de filas total

inline int GetColumn() {
    return column;
} //devuelve el numero de columnas total

inline int GetSize() {
    return size;
}//devuelve el tamaño de la malla

inline Vector<Vector<Cell>>& GetWorld(void){
    return world;
}//pasa el mundo por referencia

char GetWorldState(int, int); //devuelve el "color" de una celda
bool GetWorldValue(int, int); //devuelve el estado booleano de una celda

void SetRow(int);
void SetColumn(int);
void SetSize(int);

void SetWorldState(char, int, int); //establecer el color de una celda
void SetWorldValue(bool, int, int); //establecer el valor booleano de una celda
void ToggleWorldValue(int, int);
void SetWorld(Vector<Vector<Cell>>&);

virtual void ReSize(std::vector<Ant>&) = 0;

void PrintWorld(void); //imprime la malla sola
void PrintHorizontalWall(void); //imprime una pared horizontal
void Update(std::vector<Ant>&); //función que actualiza las casillas donde están las hormigas
void PrintGrid(std::vector<Ant>&); //imprime el mundo con hormigas

bool AntOut(std::vector<Ant>&);
bool AntOut(Ant&);

};