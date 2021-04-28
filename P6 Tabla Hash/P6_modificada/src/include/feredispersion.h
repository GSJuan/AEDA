#include "fexploracion.h"
#include <stdlib.h>

#pragma once

template<class Clave>
class feRedispersion: public FuncionExploracion<Clave> {

private:


public:

    unsigned operator()(const Clave& k, unsigned i) const {
        srand(k);
        int value;
        for(unsigned j = 0; j <= i; j++){
            value = rand();
        }
        return value;
    }
};