#include <system_error> // e.what()
#include <cstdlib>      // system(clear), rand
#include "include/arbolB.h"
#define Clave int

int main(int argc, char* argv[]) {
    int opt;
    Clave clave;
    nodeB<Clave>* res;
    BTree<Clave> arbol;

    do {        
        std::cout << "[0] Salir.\n";
        std::cout << "[1] Insertar clave.\n";
        std::cout << "[2] Buscar clave.\n";
        std::cout << std::endl;
        std::cout << "Opción: ";
        std::cin >> opt;


        

        switch(opt) {
            case 1:
                std::cout << "Insertar Clave: ";
                std::cin >> clave;
                arbol.InsertaEquil(clave);
                arbol.ImprimirArbol();
                break;

            case 2:
                std::cout << "Buscar Clave: ";
                std::cin >> clave;
                res = arbol.buscar(clave);
                if(res) std::cout << "Resultado: " << res << std::endl;
                else  std::cout << "[.] No se encontró el valor." << std::endl;
                break;

            case 0: 
                std::cout << "\nSaliendo... " << std::endl;
                break;

            default:
                std::cout <<"\nEsa no es una opción valida." << std::endl;
                break;
        }
    } while(opt != 0);
    
    return 0;
}