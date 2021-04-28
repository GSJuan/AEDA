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
#include <iostream>

#define Clave   int

int main( void /* int argc, char* argv[]*/ ) {

    int size, function_type, menu, option, exit = 0, clave, i = 0;

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

}

FuncionDispersion<Clave> *pfd;
if(function_type == 0)
    pfd = new fdModulo<Clave>(size);
else if(function_type == 1)
    pfd = new fdPseudoaleatoria<Clave>(size);

TablaHash<Clave> tabla(size, pfd);

while (exit == 0) {

    std::cout << std::endl << "Introduzca el numero asociado a lo que desea hacer: " << std::endl;
    std::cout << "0: Salir " << std::endl;
    std::cout << "1: Buscar Clave" << std::endl;
    std::cout << "2: Comprobar la posibilidad de insertar una clave" << std::endl;
    std::cout << "3: Insertar una clave" << std::endl;
    std::cout << "4: Prueba con 10 000 claves enteras" << std::endl;
    std::cout << "5: Enumera el tamañdo de cada lista" << std::endl << std::endl;

    std::cout << "Introduca una opcion: ";

    std::cin >> option;
    std::cout << std::endl;
    
    switch (option) {

    case 0:
        std::cout << "Hasta la vista" << std::endl;
        exit = 1;
        break;
    
    case 1:
        std::cout << "Introduzca la clave: ";
        std::cin >> clave;
        if(tabla.Buscar(clave) == true)
            std::cout << "Elemento encontrado " << std::endl;
        else std::cout << "Elemento no encontrado " << std::endl;

        break;

    case 2:
        std::cout << "Introduzca la clave: ";
        std::cin >> clave;
        if(tabla.Insertar(clave) == true)
            std::cout << "Elemento insertable" << std::endl;
        else std::cout << "Elemento no insertable" << std::endl;
        break;

    case 3:
        std::cout << "Introduzca la clave: ";
        std::cin >> clave;
        tabla.AddKey(clave);
        std::cout << "elemento insertado con éxito" << std::endl;
        break;

    case 4:
        std::cout << "Generando e insertando claves" << std::endl;
        srand(time(NULL));
        while(i <= 10000) {
            clave = rand() % 1000001;
            tabla.AddKey(clave);
            i++;
        }
        std::cout << "La lista de mayor tamaño tiene " << tabla.BiggestListSize() << " elementos" << std::endl;
        break;
    
    case 5:
        for(int j = 0; j < tabla.GetvDatosSize(); j++){
            std::cout << "La lista en la posición " << j << " tiene " << tabla.ListSize(j) << " elementos" << std::endl;
        }
        break;

    default:
        std::cout << "Esa opción no es válida, introduzca otro valor: " << std::endl;
        break;
    
    }

}

return 0;
}
