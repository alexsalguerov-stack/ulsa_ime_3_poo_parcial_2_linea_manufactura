#ifndef PLANTA_H
#define PLANTA_H

#include <vector>
#include <string>
#include "Maquina.h"

class Planta
{
private:
    int piezasTerminadas;

    std::vector<Maquina *> maquinas;

public:
    Planta();

    void agregarMaquina(Maquina *maquina);

    void procesarLote(int cantidadPiezas);

    void mostrarReporte() const;
};

#endif