#include "fexploracion.h"
#include "fdispersion.h"
#pragma once

template<class Clave>
class feDobleDispersion: public FuncionExploracion<Clave> {

private:
    FuncionDispersion<Clave>* fd;

public:

    feDobleDispersion(FuncionDispersion<Clave>* pfd) {
        fd = pfd;
    }

    unsigned operator()(const Clave& k, unsigned i) const {
        return fd->operator()(k) * i;
    }
};