#include "BandaTransportadora.h"
#include "Maquina.h"
#include <iostream>

BandaTransportadora::BandaTransportadora(float velocidad, float cargaMax, int id, std::string nombre, int vidaMotor)
    : Maquina(id, nombre),
      motor(vidaMotor)
{
    setvelocidadBanda(velocidad);
    setCapacidadCargaMax(cargaMax);
}

void BandaTransportadora::setvelocidadBanda(float v)
{
    if (v <= 0.0f)
    {
        std::cout << "Error. La velocidad tiene que ser mayor a 0 m/s." << std::endl;
    }
    else if (v > 5.0f)
    {
        std::cout << "Error: La velocidad no puede superar los 5 m/s." << std::endl;
    }
    else
    {
        velocidadBanda = v;
        std::cout << "Velocidad asignada correctamente: " << velocidadBanda << " m/s." << std::endl;
    }
}

float BandaTransportadora::getVelocidad() const
{
    return velocidadBanda;
}

void BandaTransportadora::setCapacidadCargaMax(float c)
{
    if (c <= 0.0f)
    {
        std::cout << "Error. El peso tiene que ser mayor a 0 Kgs." << std::endl;
    }
    else if (c > 10.0f)
    {
        std::cout << "Error: El peso no puede superar los 10 Kgs." << std::endl;
        capacidadCargaMax = 10.0f;
    }
    else
    {
        capacidadCargaMax = c;
        std::cout << "El peso fue aceptado correctamente: " << capacidadCargaMax << " Kgs." << std::endl;
    }
}

float BandaTransportadora::getCargaMax() const
{
    return capacidadCargaMax;
}

void BandaTransportadora::transportar(std::string objeto, std::string destino)
{
    if (!puedeProcesar())
    {
        std::cout << "No se puede transportar el objeto " << objeto << ". La banda está fuera de servicio." << std::endl;
        return;
    }

    std::cout << "Transportando " << objeto << " hacia " << destino << " a una velocidad de " << velocidadBanda << " m/s." << std::endl;
}

void BandaTransportadora::procesarPieza()
{
    if (!puedeProcesar())
    {
        std::cout << "La banda transportadora no puede procesar la pieza en este momento." << std::endl;
        return;
    }

    registrarPieza();
    agregarTiempo(10);

    bool motorOk = motor.reducirVida();

    if (!motorOk)
    {
        reportarFalla();
        std::cout << "Alerta: El motor de la banda transportadora ha agotado su vida util." << std::endl;
    }
    else
    {
        std::cout << "Pieza procesada exitosamente en la banda transportadora." << std::endl;
    }
}

void BandaTransportadora::realizarMantenimiento()
{
    motor.restablecerVida();
    registrarMantenimiento();

    std::cout << "Mantenimiento realizado exitosamente: Motor restaurado y estado de la banda actualizado." << std::endl;
}

void BandaTransportadora::mostrarEstado() const
{
    // Muestra primero los datos generales declarados en la interfaz base Maquina
    Maquina::mostrarEstado();

    // Muestra las propiedades específicas de la Banda
    std::cout << "Velocidad de la Banda: " << velocidadBanda << " m/s" << std::endl;
    std::cout << "Capacidad de Carga Máxima: " << capacidadCargaMax << " Kg" << std::endl;
}