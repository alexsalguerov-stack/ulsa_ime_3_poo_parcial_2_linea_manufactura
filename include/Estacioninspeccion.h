#ifndef ESTACION_INSPECCION_H
#define ESTACION_INSPECCION_H

#include <string>
#include "Maquina.h"
#include "Sensor.h"


class EstacionInspeccion : public Maquina {
private:
    Sensor sensor;             
    float toleranciaError;      
    int medicionesRealizadas;   
    int segundosPorPieza;       

public:
    EstacionInspeccion(int id, std::string nombre, float tolerancia,
                       int limiteSensor, int segundos);

   
    bool medirTolerancia(float valor);
    bool inspeccionarCalidad();


    bool procesarPieza();
    void realizarMantenimiento();

    void mostrarEstado() const;

    float getToleranciaError() const;
    int getMedicionesRealizadas() const;
    int getSegundosPorPieza() const;
};

#endif