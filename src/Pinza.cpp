
#include "Pinza.h"
#include <iostream>

Pinza::Pinza(int vidaUtilInicial)
    : vidaUtilMaxima(vidaUtilInicial > 0 ? vidaUtilInicial : 1),
      vidaRestante(vidaUtilInicial > 0 ? vidaUtilInicial : 1)
{
    if (vidaUtilInicial <= 0)
    {
        std::cout << "Advertencia: la vida util de la pinza "
                  << "debe ser positiva. Se asigno 1."
                  << std::endl;
    }
}

bool Pinza::reducirVida()
{
    if (vidaRestante <= 0)
    {
        return false;
    }

    --vidaRestante;

    return vidaRestante > 0;
}

void Pinza::restablecerVida()
{
    vidaRestante = vidaUtilMaxima;
}

int Pinza::getVidaRestante() const
{
    return vidaRestante;
}

int Pinza::getVidaUtilMaxima() const
{
    return vidaUtilMaxima;
}

void Pinza::mostrarEstado() const
{
    std::cout << "  Vida util de la pinza: "
              << vidaRestante << " / "
              << vidaUtilMaxima << std::endl;

    if (vidaRestante == 0)
    {
        std::cout << "  Estado de la pinza: agotada"
                  << std::endl;
    }
    else
    {
        std::cout << "  Estado de la pinza: disponible"
                  << std::endl;
    }
}
