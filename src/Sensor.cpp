#include "Sensor.h"

Sensor::Sensor(int limiteInicial)
{
    if (limiteInicial <= 0)
    {
        limiteInicial = 25; // Límite predeterminado alineado con la estación de inspección
    }
    limite = limiteInicial;
    vidaUtil = limiteInicial;
}

bool Sensor::reducirVida()
{
    if (vidaUtil > 0)
    {
        vidaUtil--;
    }
    // Retorna true si el sensor SIGUE operativo, o false si se agotó (vidaUtil == 0)
    return vidaUtil > 0;
}

void Sensor::restaurar()
{
    vidaUtil = limite;
}

int Sensor::getVidaUtil() const
{
    return vidaUtil;
}

int Sensor::getLimite() const
{
    return limite;
}