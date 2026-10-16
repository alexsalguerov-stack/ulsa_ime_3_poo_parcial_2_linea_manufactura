#ifndef PLANTA_H
#define PLANTA_H

#include <vector>
#include <string>
#include "Maquina.h"

class Planta
{
private:
    std::vector<Maquina *> linea;

public:
    Planta() {}

    void registrarMaquina(Maquina *m) {
        linea.push_back(m);
    }

    int procesarLote(int cantidad);
    void generarReporte();
};

#endif