// AUTHOR: Juan García Santos
// DATE: 11/04/2021
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 1.0
// SUBJECT: AEDA
// PRACTICE Nº: 6
// Compilation: make
// Execution: ./main
// Clase Vector de template (sll)

#include <vector>
#include <algorithm>
#pragma once

template <class Clave> 
class Vector {

private:

    std::vector<Clave> v;
    unsigned int max_size;

public:

    Vector();
    ~Vector();

    bool Buscar(const Clave&) const;

    bool Insertar(const Clave&);

    bool estaLleno() const;

    
    inline bool Empty() {
       return v.empty();
    }

    inline int GetSize() {
        return v.size(); 
    }

    inline int GetMaxSize() {
        return max_size;
    }

    inline void SetMaxSize(int size) {
        max_size = size;
    }

    void Resize(int size) {
        v.resize(size);
    }

    void PushBack(Clave&);
};

template <class Clave>
Vector<Clave>::Vector() {}

template <class Clave>
Vector<Clave>::~Vector() {}

template <class Clave>
bool Vector<Clave>::Buscar(const Clave& X) const{
    for(unsigned i = 0; i < max_; i++) {
        if(X == v[i])
            return true;
    }
    return false;
}

template <class Clave>
bool Vector<Clave>::Insertar(const Clave& X) {
    if (Buscar(X)||estaLleno()) {
        return false;
    }
    v.push_back(X);
    return true;
    
}

template <class Clave>
bool Vector<Clave>::estaLleno() const {
    return v.size() == max_size;
}