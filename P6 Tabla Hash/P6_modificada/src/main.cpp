// AUTHOR: Juan García Santos
// DATE: 6/04/2021
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 1.0
// SUBJECT: AEDA
// PRACTICE Nº: 5
// Compilation: make
// Execution: ./main
// Menú para probar tabla hash

#include "include/tabla_hash.h"
#include "include/alumno.h"
#include <iostream>

#define Clave   Alumno

int main( void /* int argc, char* argv[]*/ ) {

    int size, function_type, exploration_type, menu, sinonimos, option, exit = 0, i = 0;
    unsigned int max_iter;
    Alumno alumno;
    std::string nombre, alu;

    std::cout << "¿Desea el comportamiento por defecto de la tabla(0), o personalizar la experiencia(1)?" << std::endl << "Introduzca 0 o 1: ";
    std::cin >> menu;
    while((menu != 0) && (menu != 1)){
        std::cin >> menu;
        if((menu != 0) && (menu != 1)){
            std::cout << "¡Eso no era un 1 o un 0! Ojito cuidado. " << std::endl << "Introduzca 0 o 1: ";
        }
    }

if (menu == 0){
    size = 1009;
    function_type = 0;
    exploration_type = 0;
    sinonimos = 20;
    max_iter = 1000;
}
else if(menu == 1) {
    
    std::cout << "Introduzca el tamaño de la tabla hash (siemre mejor un numero primo o con pocos divisores):";
    std::cin >> size;
    while (size <= 0){
        std::cout << "Eso era menor o igual que 0. Ojito Cuidado" << std::endl;
        std::cout << "Introduzca el tamaño de la tabla (siempre mejor un numero primo o con pocos divisores): " << std:: endl;
        std::cin >> size;
    }

    std::cout << "Introduzca el tipo de funcion de dispersion (0 modulo, 1 pseudoaleatoria): ";
    std::cin >> function_type; 
    while ((function_type > 1) && (function_type < 0)){
        std::cout << "Eso no era un 0 o un 1. Ojito Cuidado" << std::endl;
        std::cout << "Introduzca el tipo de funcion de dispersion (0 modulo, 1 pseudoaleatoria): " << std:: endl;
        std::cin >> function_type;
    }

    std::cout << "Introduzca el tipo de funcion de exploración (0 lineal, 1 cuadrática, 2 doble dispersión, 3 redispersión): ";
    std::cin >> exploration_type; 
    while ((exploration_type > 3) && (exploration_type < 0)){
        std::cout << "Eso no era un numero entre cero y 3. Ojito Cuidado" << std::endl;
        std::cout << "Introduzca el tipo de funcion de exploración (0 lineal, 1 cuadrática, 2 doble dispersión, 3 redispersión): " << std:: endl;
        std::cin >> exploration_type;
    }

    std::cout << "Introduzca el numero máximo de sinonimos: ";
    std::cin >> sinonimos; 
    while (sinonimos < 0){
        std::cout << "Eso no era mayor que 0. Ojito Cuidado" << std::endl;
        std::cout << "Introduzca el numero máximo de sinonimos: " << std:: endl;
        std::cin >> sinonimos;
    }

    std::cout << "Introduzca el numero máximo de iteraciones para la funcion de exploracion: ";
    std::cin >> max_iter; 
    while (max_iter < 0){
        std::cout << "Eso no era mayor que 0. Ojito Cuidado" << std::endl;
        std::cout << "Introduzca el numero máximo de iteraciones para la funcion de exploracion: " << std:: endl;
        std::cin >> max_iter;
    }

}

FuncionDispersion<Clave>* pfd;
FuncionExploracion<Clave>* pfe;

if(function_type == 0)
    pfd = new fdModulo<Clave>(size);
else if(function_type == 1)
    pfd = new fdPseudoaleatoria<Clave>(size);

if(exploration_type == 0)
    pfe = new feLineal<Clave>();
else if(exploration_type == 1)
    pfe = new feCuadratica<Clave>();
else if(exploration_type == 2)
    pfe = new feDobleDispersion<Clave>(pfd);
else if(exploration_type == 3)
    pfe = new feRedispersion<Clave>();

TablaHash<Clave> tabla(size, sinonimos, pfd, pfe);

while (exit == 0) {

    std::cout << std::endl << "Introduzca el numero asociado a lo que desea hacer: " << std::endl;
    std::cout << "0: Salir " << std::endl;
    std::cout << "1: Buscar Alumno" << std::endl;
    std::cout << "2: Insertar un Alumno" << std::endl;
    //std::cout << "3: Prueba con 10 000 claves enteras" << std::endl << std::endl;

    std::cout << "Introduca una opcion: ";

    std::cin >> option;
    std::cout << std::endl;
    
    switch (option) {

    case 0:
        std::cout << "Hasta la vista" << std::endl;
        exit = 1;
        break;
    
    case 1:
        std::cout << "Introduzca el nombre: ";
        std::cin >> nombre;

        std::cout << "Introduzca el alu: ";
        std::cin >> alu;

        alumno.SetAlu(alu);
        alumno.SetName(nombre);

        if(tabla.Search(alumno, max_iter) == true)
            std::cout << std::endl << "Elemento encontrado " << std::endl;
        else std::cout  << std::endl << "Elemento no encontrado " << std::endl;
        break;

    case 2:
        std::cout << "Introduzca el nombre: ";
        std::cin >> nombre;

        std::cout << "Introduzca el alu: ";
        std::cin >> alu;

        alumno.SetAlu(alu);
        alumno.SetName(nombre);
        
        if(tabla.Insert(alumno, max_iter) == true)
            std::cout << std::endl  << "Elemento insertado" << std::endl;
        else std::cout  << std::endl << "Elemento no insertado" << std::endl;
        break;

    /*case 3:
        std::cout << "Generando e insertando claves" << std::endl;
        srand(time(NULL));
        while(i <= 10000) {
            alu = rand() % 100000;
            alumno.SetAlu(alu);
            tabla.Insert(alumno, max_iter);
            i++;
        }
        std::cout << "El vector de mayor tamaño tiene " << tabla.BiggestSize() << " elementos" << std::endl;
        break;*/

    default:
        std::cout << "Esa opción no es válida, introduzca otro valor: " << std::endl;
        break;

    }
}

return 0;
}
