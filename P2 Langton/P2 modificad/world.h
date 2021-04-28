// AUTHOR: Juan García Santos
// DATE: 02/01/2021
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 1.0
// SUBJECT: AEDA
// PRACTICE Nº: 1
// Clase "mundo" para definir el comportamiento y características de la malla

#include "vector.cpp"
#include <iostream>
#include "stdio.h"

#pragma once

class World {

private:

int row;
int column;
int size;
Vector<Vector<Cell>> world;



public:

World(); //Constructor por defect
World(int, int); //Constructor por tamaño
World(int, int, int, int);
~World();//Destructor

int GetRow(void); //devuelve el numero de filas total
int GetColumn(void); //devuelve el numero de columnas total
int GetSize(void); //devuelve el tamaño de la malla

int GetRowLowerLimit(void);
int GetColumnLowerLimit(int);

int GetRowUpperLimit(void);
int GetColumnUpperLimit(int);



char GetWorldState(int, int); //devuelve el "color" de una celda
bool GetWorldValue(int, int); //devuelve el estado booleano de una celda

void SetRowLowerLimit(int);
void SetColumnLowerLimit(int);

void SetRow(int);
void SetColumn(int);
void SetSize(int);

void SetWorldState(char, int, int); //establecer el color de una celda
void SetWorldValue(bool, int, int); //establecer el valor booleano de una celda

void PrintWorld(void); //imprime la malla sola
void PrintHorizontalWall(void); //imprime una pared horizontal

void RowUpResize(int);
void ColumnUpResize(int);

};