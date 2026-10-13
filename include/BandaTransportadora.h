#ifndef BANDATRANSPORTADORA_H
#define BANDATRANSPORTADORA_H

#include "MAQUINA.H"
#include "Motor.h"
#include <string>

class BandaTransportadora : public Maquina
{
private:
    float velocidadBanda;
    float capacidadCargaMax;
    Motor motor;

public:
    BandaTransportadora(float velocidad, float cargaMax, int id, std::string nombre, int vidaMotor);
    void ajustarVelocidad(float v);
    float getVelocidad() const;

    void setCapacidadCargaMax(float c) const;
    float getCargaMax() const;

    void ajustarVelocidad(float v);
    void transportar(std::string objeto, std::string destino);

    void procesarPieza();
    void registMantenimiento();
    void mostrarEstado();
};

#endif
