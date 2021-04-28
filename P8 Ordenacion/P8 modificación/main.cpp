// AUTHOR: Juan García Santos
// DATE: 23/04/2021
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 1.0
// SUBJECT: AEDA
// PRACTICE Nº: 8
// Compilation: g++ -o main -Wall main.cpp
// Execution: ./main
// Programa para testear diferentes algoritmos de ordenacion(selección, heapsort y mergesort)

#include <vector>

#include <random>
#include "miclave.h"
#define Element MiClave

int MiClave::contador = 0;

template <class Clave>
void PrintVector(std::vector<Clave>& vec, int low, int max) {
  std::cout << std::endl;
  for (int i = low; i <= max; i++) {
	  std::cout << " " << vec[i] << " ";
  }
  std::cout << std::endl << std::endl;
}

template<class Clave> 
void SelectionTrace(std::vector<Clave>& vec, unsigned size) {
  Clave x;
  int min;
  for (unsigned int i = 0; i < size-1; i++) {
    min = i ;
    for (unsigned int j = i + 1; j < size; j++) {
      std::cout << "Comparando " << vec[j] << " con " << vec[min] << std::endl;  
      if (vec[j] < vec[min]) {
        std::cout << " \a Como " << vec[j] << " es menor que " << vec[min] << " actualizamos el valor minimo" << std::endl;  
        min = j;  
      }
    }
    std::cout << std::endl << "Intercambiando el valor minimo " << vec[min] << " con " << vec[i] << std::endl;  
    x = vec[min];
    vec[min] = vec[i] ;
    vec[i] = x ;
    PrintVector(vec, 0, vec.size()-1);
  }
}


template<class Clave> 
void Selection(std::vector<Clave>& vec, unsigned size) {
  Clave x;
  int min;
  for (unsigned int i = 0; i < size-1; i++) {
    min = i ;
    for (unsigned int j = i + 1; j < size; j++)
      if (vec[j] < vec[min])
        min = j ;
    x = vec[min] ;
    vec[min] = vec[i] ;
    vec[i] = x ;
  }
}


template<class Clave>
void Mezcla(std::vector<Clave>& vec, int ini, int cen, int fin) {
std::vector<Clave> aux(vec.size());
  int i = ini, j = cen + 1, k = ini;
  while ((i <= cen) && (j <= fin)){
    if (vec[i] < vec[j]){
      aux[k] = vec[i] ;
      i++ ;
    }
    else{
      aux[k] = vec[j] ;
      j++ ;
    }
    k++ ;
  }

  if (i > cen)
    while (j <= fin){
      aux[k] = vec[j] ;
      j++;
      k++;
    }

  else
    while (i <= cen){
      aux[k] = vec[i] ;
      i++;
      k++;
    }

  for (int k = ini; k <= fin; k++)
    vec[k] = aux[k];
}


template<class Clave> 
void MergeSort(std::vector<Clave>& vec, int low, int max) {
  if (low < max){
    int cen = (low + max) / 2 ;
    MergeSort(vec, low, cen) ;
    MergeSort(vec, cen + 1, max) ;
    Mezcla(vec, low, cen, max) ;
  } 
}


template<class Clave>
void MezclaTrace(std::vector<Clave>& vec, int ini, int cen, int fin) {
std::vector<Clave> aux(vec.size());
  int i = ini, j = cen + 1, k = ini;
  while ((i <= cen) && (j <= fin)){
    std::cout << "Comparando " << vec[i] << " con " << vec[j] << std::endl;  
    if (vec[i] < vec[j]){
      std::cout << "\a Como " << vec[i] << " es menor que " << vec[j] << " lo almacenamos en el auxiliar" << std::endl;
      aux[k] = vec[i] ;
      i++ ;
    }
    else{
      std::cout << "\a Como " << vec[j] << " es mayor o igual que " << vec[i] << " lo almacenanmos en el exterior" << std::endl;
      aux[k] = vec[j] ;
      j++ ;
    }
    std::cout << std::endl << "Mostrando vector auxiliar: ";
    PrintVector(aux, 0, aux.size()-1);
    k++ ;
  }

  if (i > cen) {

    while (j <= fin){
      aux[k] = vec[j] ;
      j++;
      k++;
    }
  }
    
  else {
    while (i <= cen){
      aux[k] = vec[i] ;
      i++;
      k++;
    }
  }

  for (int k = ini; k <= fin; k++)
    vec[k] = aux[k];

  std::cout << "Mostrando vector mezclado: ";
  PrintVector(vec, 0, vec.size()-1);
}


template<class Clave> 
void MergeSortTrace(std::vector<Clave>& vec, int low, int max) {
  if (low < max){
    int cen = (low + max) / 2 ;
    MergeSortTrace(vec, low, cen) ;
    MergeSortTrace(vec, cen + 1, max) ;
    MezclaTrace(vec, low, cen, max) ;
  } 
}

template<class Clave> 
void baja(int i, std::vector<Clave>& vec, unsigned size) {
  Clave x;
  unsigned int h, h1, h2;
  while ( 2*i <= size ){
    h1 = 2*i;
    h2 = h1 + 1;
    if (h1 == size)
      h = h1;
    else if (vec[h1] > vec[h2])
      h = h1;
    else h = h2;

    if (vec[h] <= vec[i])
      break ;
    else {
      x = vec[i];
      vec[i] = vec[h];
      vec[h] = x;
      i = h ;
    } 
  }
}

template<class Clave> 
void HeapSort(std::vector<Clave>& vec, unsigned size) {
  Clave x;
  for (int i = (size-1)/2; i >= 0; i--)
    baja(i, vec, size-1);

  for (int j = size-1; j > 0; j--) {
    x = vec[0];
    vec[0] = vec[j];
    vec[j] = x;
    baja(0, vec, j-1) ;
  } 
}


template<class Clave> 
void bajaTrace(int i, std::vector<Clave>& vec, unsigned size) {
  Clave x;
  unsigned int h, h1, h2;

  while ( 2*i <= size ){
    h1 = 2*i;
    h2 = h1 + 1;
    if (h1 == size) 
      h = h1;      
    else if (vec[h1] > vec[h2])
      h = h1;
    else h = h2;

    if (vec[h] <= vec[i])
      break ;
    else {
      std::cout << "El nodo padre es: " << h << std::endl;
      std::cout << " \a Intercambiamos " << vec[i] << " con " << vec[h] << " para bajarlo " << std::endl;
      x = vec[i];
      vec[i] = vec[h];
      vec[h] = x;
      i = h ;
      PrintVector(vec, 0, vec.size()-1);
    } 
  }
}


template<class Clave> 
void HeapSortTrace(std::vector<Clave>& vec, unsigned size) {
  Clave x;
  for (int i = (size-1)/2; i >= 0; i--) {
    std::cout << "Configurando heap: " << std::endl;  
    bajaTrace(i, vec, size-1);
    std::cout << " " << std::endl;  
    PrintVector(vec, 0, vec.size()-1);
  }

  for (int j = size-1; j > 0; j--) {
    std::cout << "Intercambiando " << vec[0] << " con " << vec[j] << std::endl;
    x = vec[0];
    vec[0] = vec[j];
    vec[j] = x;
    PrintVector(vec, 0, vec.size()-1);
    bajaTrace(0, vec, j-1) ;
  } 
}


int main( void /* int argc, char* argv[]*/ ) {

    int size, function_type, menu, element, traza, manual;
    std::cout << "¿Desea el comportamiento por defecto (0) o personalizar la experiencia(1)" << std::endl << "Introduzca 0 o 1: ";
    std::cin >> menu;
    while((menu < 0) || (menu > 1)){
        std::cin >> menu;
        if((menu < 0) || (menu > 1)){
            std::cout << "¡Eso no era un 1 o 0! Ojito cuidado. " << std::endl << "Introduzca 0 o 1: ";
        }
    }

  if (menu == 0){
      size = 8;
      function_type = 1;
      manual = 0;
      traza = 0;
  }

  else if(menu == 1) {
      
    std::cout << "Introduzca el tamaño de la vecuencia a ordenar:";
      std::cin >> size;
      while (size <= 0){
          std::cout << "Eso era menor o igual que 0. Ojito Cuidado" << std::endl;
          std::cout << "Introduzca el tamaño de la vecuencia a ordenar: " << std:: endl;
          std::cin >> size;
      }
  
      std::cout << "Introduzca el tipo de algoritmo de ordenación (0 Seleccion, 1 MergeSort, 2 HeapSort): ";
      std::cin >> function_type; 
      while ((function_type > 2) && (function_type < 0)){
          std::cout << "Eso no era un 0, 1 o 2. Ojito Cuidado" << std::endl;
          std::cout << "Introduzca el tipo de algoritmo de ordenación (0 Seleccion, 1 MergeSort, 2 HeapSort): " << std:: endl;
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
        if(traza == 0)  {
          SelectionTrace(vec, vec.size());
        }
        else Selection(vec, vec.size());
      
        std::cout << "Ordenación realizada, mostrando vector ordenado: " << std:: endl;
        PrintVector(vec, 0, vec.size()-1);
        std::cout << "Mostrando numero de comparaciones realizadas: " << std:: endl;
        std:: cout << MiClave::contador << std::endl;
        break;
      
      case 1:
        if(traza == 0)
          MergeSortTrace(vec, 0, vec.size());
        else { 
          MergeSort(vec, 0, vec.size());
        }
        std::cout << "Ordenación realizada, mostrando vector ordenado: " << std:: endl;
        PrintVector(vec, 0, vec.size()-1);
        std::cout << "Mostrando numero de comparaciones realizadas: " << std:: endl;
        std:: cout << MiClave::contador << std::endl;
        
        

        break;
  
      case 2:
        if(traza == 0) {
           HeapSortTrace(vec, vec.size());
        }
         
        else HeapSort(vec, vec.size());

        std::cout << "Ordenación realizada, mostrando vector ordenado: " << std:: endl;
        PrintVector(vec, 0, vec.size()-1);
        std::cout << "Mostrando numero de comparaciones realizadas: " << std:: endl;
        std:: cout << MiClave::contador << std::endl;

        break;
  
      default:
        std::cout << "Esa opción no es válida, introduzca otro valor: " << std::endl;
        break;
      }
  return 0;
}