
#ifndef ROBOTENSAMBLADOR_H
#define ROBOTENSAMBLADOR_H

#include "Maquina.h"
#include "Pinza.h"
#include <string>

class RobotEnsamblador : public Maquina
{
private:
    // Atributos propios del robot
    int precisionPosicion;
    float fuerzaPrensado;

    // Composición: el robot tiene una pinza
    Pinza pinza;

public:
    // Constructor
    RobotEnsamblador(
        int id,
        const std::string &nombre,
        int precision,
        float fuerza,
        int vidaUtilPinza);

    // Métodos propios para configurar el robot
    void ajustarPrecision(int precision);
    void ajustarFuerzaPrensado(float fuerza);

    // Operación del robot
    void ensamblarPiezas();
    void procesarPieza();

    // Mantenimiento del robot y su componente
    void realizarMantenimiento();

    // Muestra el estado general y los datos propios del robot
    void mostrarEstado() const;
    void setprecisionPosicion(float p);
    void setfuerzaPrensado(float f);
};

#endif
