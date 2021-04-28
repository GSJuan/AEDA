// AUTHOR: Juan García Santos
// DATE: 6/04/2021
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 1.0
// SUBJECT: AEDA
// PRACTICE Nº: 5
// Compilation: make
// Execution: ./main
// Clase tabla hash para definir el comportamiento de la misma.
#include "fdmodulo.h"
#include "fdpseudoaleatoria.h"
#include "felineal.h"
#include "fecuadratica.h"
#include "fedoble_dispersion.h"
#include "feredispersion.h"
#include "vector.h"

#pragma once

template <class Clave> 
class TablaHash {
protected:

    FuncionDispersion<Clave>* fd;
    FuncionExploracion<Clave>* fe;
    int nDatos;
    std::vector<Vector<Clave>*> vDatos;
    int nSinonimos;

public:

    TablaHash(int size, int sinonimos, FuncionDispersion<Clave>* pfd, FuncionExploracion<Clave>* pfe){
        fd = pfd;
        fe = pfe;
        nSinonimos = sinonimos;
        nDatos = size;
        vDatos.resize(size);
        for(unsigned i = 0; i < vDatos.size(); i++) {
            vDatos[i] = new Vector<Clave> ;
            vDatos[i]->SetMaxSize(size);
        }
    }

    ~TablaHash() {}

    int GetvDatosSize() {
        return vDatos.size();
    }

    bool Search(const Clave& X, const unsigned i) const {
        unsigned j = 0;
        int index = fd->operator()(X);
        bool condition = true;
        if(vDatos[index]->Buscar(X) == false) {
            do {
                condition = vDatos[(index + fe->operator()(X, j)) % nDatos]->Buscar(X);
                j++;
            } while ((condition == false) && (i >= j));
        }
        return condition;
    }

    bool Insert(const Clave& X, const unsigned i) {
        unsigned j = 0;
        int index = fd->operator()(X);
        bool condition = true;
        if(vDatos[index]->Insertar(X) == false) { //si no se puede insertar, ya sea porque ese vector esta lleno o tiene el elemento dentro
            if(Search(X, i) == false) { // si no está en la tabla
                do { //asumimos que esta lleno asi que buscamos nueva posicion
                    condition = vDatos[(index + fe->operator()(X, j)) % nDatos]->Insertar(X);
                    j++;
                } while ((condition == false) && (i >= j));
            }
            else condition = false; //si está en alguna parte de la tabla
        }
        return condition;
    }

    int BiggestSize() {
        int max = -1;
        for(unsigned i = 0; i < vDatos.size(); i++){
            if(vDatos[i]->GetSize() > max)
                max = vDatos[i]->GetSize();
        }
        return max;
    }

    bool IsFull (const Clave& X) {
        int index = fd->operator()(X);
        return vDatos[index]->estaLleno();
    }

    int VectorSize(int &index) {
        return vDatos[index]->GetSize();
    }
    
};
