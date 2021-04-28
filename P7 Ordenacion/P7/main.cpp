// AUTHOR: Juan García Santos
// DATE: 17/04/2021
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 1.0
// SUBJECT: AEDA
// PRACTICE Nº: 7
// Compilation: g++ -o main -Wall main.cpp
// Execution: ./main
// Menú para probar tabla hash

#include <vector>
#include <iostream>
#include <random>
#define Element int


template <class Clave>
void PrintVector(std::vector<Clave>& vec, int low, int max) {
  std::cout << std::endl;
  for (int i = low; i <= max; i++) {
	  std::cout << " " << vec[i] << " ";
  }
  std::cout << std::endl << std::endl;
}

template<class Clave> 
void InsertionTrace(std::vector<Clave>& vec, unsigned size) {
  int j;
  Clave clave;
  for (unsigned int i = 1; i < size; i++) {
	clave = vec[i];
	j = i - 1;
	while (j >= 0 && vec[j] > clave) {
	  std::cout << vec[j] << " > " << clave << std::endl;
	  vec[j + 1] = vec[j];
	  j--;
	}
	std::cout << vec[j + 1] << " cambiado con " << clave << std::endl; 
	vec[j + 1] = clave;
	PrintVector(vec, 0, vec.size()-1);	
  }
}

template<class Clave> 
void Insertion(std::vector<Clave>& vec, unsigned size) {
  int j = 0;
  Clave clave;
  for (unsigned int i = 1; i < size; i++) {
	clave = vec[i];
	j = i - 1;
	while ((clave < vec[j]) && (j >= 0)) {
	  vec[j + 1] = vec[j];
	  j--;
	}
	vec[j + 1] = clave;
  }
}

template<class Clave> 
void QuickSort(std::vector<Clave>& vec, int low, int max) {
  Clave clave;
  int i = low, f = max;
  int p = vec[(i+f)/2];
  while (i <= f){
    while (vec[i] < p) i++ ;
    while (vec[f] > p) f-- ;
    if (i <= f) {
      clave = vec[f];
      vec[f] = vec[i];
      vec[i] = clave;
      i++ ;
      f-- ;
     }
  } ;
  if (low < f) QuickSort(vec, low, f) ;
  if (i < max) QuickSort(vec, i, max) ;
}

template<class Clave> 
void QuickSortTrace(std::vector<Clave>& vec, int low, int max) {
  Clave clave;
  int i = low, f = max;
  int p = vec[(i+f)/2];
  std::cout << "Trozo desde [" << low << "] hasta [" << max << "] con pivote " << p << std::endl;
  PrintVector(vec, low, max);
   while (i <= f){
     while (vec[i] < p) i++ ;
     while (vec[f] > p) f-- ;
     if (i <= f) {
       std::cout << "Elementos intercambiados: " << vec[i] << " con " << vec[f] << " con pivote " << p << std::endl;
       clave = vec[f];
       vec[f] = vec[i];
       vec[i] = clave;
       i++;
       f--;
       PrintVector(vec, low, max);
     }
   };
  if (low < f) QuickSortTrace(vec, low, f) ;
  if (i < max) QuickSortTrace(vec, i, max) ;
}

template<class Clave>
void DeltaSort(std::vector<Clave>& vec, int d, int n ) {

  for (int i = d; i < n; i++){
    Clave clave = vec[i] ;
    int j = i ;
    while ((j >= d) && (clave < vec[j-d])){
      vec[j] = vec[j-d] ;
      j = j - d ;
    };
    vec[j] = clave ;
  }
}

template<class Clave> 
void ShellSort(std::vector<Clave>& vec, unsigned size) {

float alpha;
  std::cout << "Introduzca un valor de alpha entre cero y 1: ";
  std::cin >> alpha; 
  while ((alpha < 0) && (alpha > 1)){
      std::cout << "Eso no estaba entre cero y 1. Ojito Cuidado" << std::endl;
      std::cout << "Introduzca un valor de alpha entre cero y 1: " << std:: endl;
      std::cin >> alpha;
  }
  int del = size * alpha ;
  while (del > 1){
    del = del * alpha ;
    DeltaSort(vec, del, size);
  };
}

template<class Clave>
void DeltaSortTrace(std::vector<Clave>& vec, int d, int n ) {

  for (int i = d; i < n; i++){
    Clave clave = vec[i] ;
    int j = i ;
    while ((j >= d) && (clave < vec[j-d])){
    std::cout << "desplazando " << vec[j-d] << " a la posicion " << j << std::endl;
      vec[j] = vec[j-d] ;
      j = j - d ;
    };
    if(vec[j] == clave)
        std::cout << "No se realiza desplazamiento ya que " << clave << " no es menor que " << vec[j-d] << std::endl;
    vec[j] = clave ;
    PrintVector(vec, 0, vec.size()-1);
  }
}

template<class Clave> 
void ShellSortTrace(std::vector<Clave>& vec, unsigned size) {

float alpha;
    std::cout << "Introduzca un valor de alpha entre cero y 1: ";
    std::cin >> alpha; 
    while ((alpha < 0) && (alpha > 1)){
        std::cout << "Eso no estaba entre cero y 1. Ojito Cuidado" << std::endl;
        std::cout << "Introduzca un valor de alpha entre cero y 1: " << std:: endl;
        std::cin >> alpha;
    }
  int del = size * alpha ;
  while (del > 1){
    del = del * alpha ;
    std::cout << "Con delta: " << del << std::endl;
    DeltaSortTrace(vec, del, size);
  };
}



int main( void /* int argc, char* argv[]*/ ) {

    int size, function_type, menu, element, traza, manual;
    std::cout << "¿Desea el comportamiento por defecto (0), o personalizar la experiencia(1)?" << std::endl << "Introduzca 0 o 1: ";
    std::cin >> menu;
    while((menu != 0) && (menu != 1)){
        std::cin >> menu;
        if((menu != 0) && (menu != 1)){
            std::cout << "¡Eso no era un 1 o un 0! Ojito cuidado. " << std::endl << "Introduzca 0 o 1: ";
        }
    }

if (menu == 0){
    size = 20;
    function_type = 2;
    manual = 0;
    traza = 0;
}
else if(menu == 1) {
    
    std::cout << "Introduzca el tamaño de la secuencia a ordenar:";
    std::cin >> size;
    while (size <= 0){
        std::cout << "Eso era menor o igual que 0. Ojito Cuidado" << std::endl;
        std::cout << "Introduzca el tamaño de la secuencia a ordenar: " << std:: endl;
        std::cin >> size;
    }

    std::cout << "Introduzca el tipo de algoritmo de ordenación (0 insercion, 1 QuickSort, 2 ShellSort): ";
    std::cin >> function_type; 
    while ((function_type > 2) && (function_type < 0)){
        std::cout << "Eso no era un 0, 1 o 2. Ojito Cuidado" << std::endl;
        std::cout << "Introduzca el tipo de algoritmo de ordenación (0 insercion, 1 QuickSort, 2 ShellSort): " << std:: endl;
        std::cin >> function_type;
    }

    std::cout << "Introduzca si desea general los valores de forma aleatoria(0), o introducirlos manualmente(1): ";
    std::cin >> manual; 
    while ((manual < 0) && (manual > 1)){
        std::cout << "Eso no estaba entre cero y 1. Ojito Cuidado" << std::endl;
        std::cout << "Introduzca si desea general los valores de forma aleatoria(0), o introducirlos manualmente(1): " << std:: endl;
        std::cin >> manual;
    }

    std::cout << "Introduzca si desea ver la traza de ejecucion(0), o no(1): ";
    std::cin >> traza; 
    while ((traza < 0) && (traza > 1)){
        std::cout << "Eso no estaba entre cero y 1. Ojito Cuidado" << std::endl;
        std::cout << "Introduzca si desea ver la traza de ejecucion(0), o no(1): " << std:: endl;
        std::cin >> traza;
    }

}

std::vector<Element> vec(size);

if (manual == 0) {
  srand(time(NULL));
  for(unsigned int i = 0; i < vec.size(); i++){
    vec[i] = rand() % 1000 + 1;
  }
}

else {
  for(unsigned int i = 0; i < vec.size(); i++){
    std::cout << "Introduzca el elemento número " << i << " del vector: " ;
    std::cin >> element;
    vec[i] = element;
    std::cout << std::endl;
  }

}
std::cout << "Mostrando vector sin ordenar: " << std:: endl;
PrintVector(vec, 0, vec.size()-1);

    switch (function_type) {

    case 0:
        if(traza == 0)
          InsertionTrace(vec, vec.size());
        else Insertion(vec, vec.size());

        std::cout << "Ordenación realizada, mostrando vector ordenado: " << std:: endl;
        PrintVector(vec, 0, vec.size()-1);

        break;
    
    case 1:
        if(traza == 0)
          QuickSortTrace(vec, 0, vec.size()-1);
        else QuickSort(vec, 0, vec.size()-1);

        std::cout << "Ordenación realizada, mostrando vector ordenado: " << std:: endl;
        PrintVector(vec, 0, vec.size()-1);

        break;

    case 2:
        if(traza == 0) 
          ShellSortTrace(vec, vec.size());
        else ShellSort(vec, vec.size());

        std::cout << "Ordenación realizada, mostrando vector ordenado: " << std:: endl;
        PrintVector(vec, 0, vec.size()-1);

        break;

    default:
        std::cout << "Esa opción no es válida, introduzca otro valor: " << std::endl;
        break;
    }
return 0;
}