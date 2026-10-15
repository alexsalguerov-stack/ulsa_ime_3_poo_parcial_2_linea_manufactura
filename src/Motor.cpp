#include "Motor.h"
#include <iostream>

Motor::Motor(int vidaInicial)
{
    if (vidaInicial <= 0)
    {
        vidaUtil = 100; // Valor por defecto seguro si ingresan un dato inválido
    }
    else
    {
        vidaUtil = vidaInicial;
    }
    vidaActual = vidaUtil;
}

bool Motor::reducirVida()
{
    if (vidaActual > 0)
    {
        vidaActual--;
    }
    return vidaActual > 0; // Regresa true si aún tiene vida, false si llegó a 0
}

bool Motor::restablecerVida()
{
    vidaActual = vidaUtil;
    std::cout << "Motor restaurado al 100% de su capacidad (" << vidaUtil << " ciclos)." << std::endl;
}

int Motor::getVidaActual() const
{
    return vidaActual;
}

bool Motor::sigueVivo() const
{
    return vidaActual > 0;
}