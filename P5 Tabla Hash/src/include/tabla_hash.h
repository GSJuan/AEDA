// AUTHOR: Juan García Santos
// DATE: 6/04/2021
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 1.0
// SUBJECT: AEDA
// PRACTICE Nº: 5
// Compilation: make
// Execution: ./main
// Clase tabla hash para definir el comportamiento de la misma.
#include "fmodulo.h"
#include "fpseudoaleatoria.h"
#include "list.h"
#include <vector>
#pragma once

template <class Clave> 
class TablaHash {
private:

    FuncionDispersion<Clave>* fd;
    int nDatos;
    std::vector<List<Clave>*> vDatos;

public:

    TablaHash(int size, FuncionDispersion<Clave>* pointer){
        fd = pointer;
        nDatos = size;
        vDatos.resize(size);
        for(int i = 0; i < vDatos.size(); i++) {
            vDatos[i] = new List<Clave>;
        }
    }

    ~TablaHash() {}

    int GetvDatosSize(){
        return vDatos.size();
    }

    void AddKey(Clave& X){
        if(Insertar(X) == true) {
            int index = fd->operator()(X);
            node<Clave>* nodo = new node<Clave>;
            nodo->data = X;
            vDatos[index]->InsertHead(nodo);
        }
    }

    bool Buscar(Clave& X) const {
        int index = fd->operator()(X);
        return vDatos[index]->Search(X);
    }

    bool Insertar(const Clave& X) {
        int index = fd->operator()(X);
        return vDatos[index]->Insert(X);
    }

    int BiggestListSize(){
        int max = -1;
        for(int i = 0; i < vDatos.size(); i++){
            if(vDatos[i]->ListSize() > max)
                max = vDatos[i]->ListSize();
        }
        return max;
    }
    int ListSize(int &index){
        return vDatos[index]->ListSize();
    }
};
