#ifndef CORTADORALASER_H
#define CORTADORALASER_H

#include <iostream>
#include <string>
#include "Maquina.h"
#include "Lente.h"

class CortadoraLaser : public Maquina
{

private:
    Lente lente;
    float potenciaLaser;
    float velocidadCorte;

public:
    CortadoraLaser(
        int id,
        string nombre,
        float potencia,
        float velocidad);

    void ajustarPotencia();

    void grabarDetalle(string patron);

    void procesarPieza();

    void realizarMantenimiento();

    void mostrarEstado() const;

    void setpotenciaLaser(float p);
    void setvelocidadCorte(float p);
};

#endif