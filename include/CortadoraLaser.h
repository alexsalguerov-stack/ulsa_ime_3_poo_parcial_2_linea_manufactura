#ifndef CORTADORALASER_H
#define CORTADORALASER_H

#include <iostream>
#include <string>
#include "Maquina.h"
#include "Lente.h"

using namespace std;

class CortadoraLaser : public Maquina {

private:

    Lente lente;
    float potenciaLaser;
    float velocidadCorte;

public:

    CortadoraLaser(
        int id,
        string nombre,
        float potencia,
        float velocidad
    );

    void ajustarPotencia(float p);

    void grabarDetalle(string patron);

    void procesarPieza();

    void realizarMantenimiento();

    void mostrarEstado();
};

#endif