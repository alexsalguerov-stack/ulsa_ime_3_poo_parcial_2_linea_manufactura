#ifndef BANDATRANSPORTADORA_H
#define BANDATRANSPORTADORA_H

#include "Maquina.h"
#include "Motor.h"
#include <string>

class BandaTransportadora : public Maquina
{
private:
    float velocidadBanda;
    float capacidadCargaMax;
    Motor motor;

public:
    // Constructor con el orden correcto de parámetros
    BandaTransportadora(float velocidad, float cargaMax, int id, std::string nombre, int vidaMotor);

    // Getters y Setters
    void setvelocidadBanda(float v);
    float getVelocidad() const;

    void setCapacidadCargaMax(float c); // Se quitó el 'const'
    float getCargaMax() const;

    // Métodos de operación
    void transportar(std::string objeto, std::string destino);
    void procesarPieza();
    void realizarMantenimiento();
    void mostrarEstado() const;
};

#endif