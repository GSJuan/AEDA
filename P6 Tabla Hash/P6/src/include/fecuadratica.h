#include "fexploracion.h"
#pragma once

template<class Clave>
class feCuadratica: public FuncionExploracion<Clave> {

public:

    unsigned operator()(const Clave& k, unsigned i) const {
        return i*i;
    }

};