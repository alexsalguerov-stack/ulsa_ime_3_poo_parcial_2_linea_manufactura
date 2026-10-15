
#include "RobotEnsamblador.h"
#include <iostream>

RobotEnsamblador::RobotEnsamblador(
    int id,
    const std::string& nombre,
    int precision,
    float fuerza,
    int vidaUtilPinza
)
    : Maquina(id, nombre),
      precisionPosicion(1),
      fuerzaPrensado(1.0f),
      pinza(vidaUtilPinza)
{
    ajustarPrecision(precision);
    ajustarFuerzaPrensado(fuerza);
}

void RobotEnsamblador::ajustarPrecision(int precision)
{
    // Rango permitido: de 1 a 100.
    if (precision < 1 || precision > 100)
    {
        std::cout << "Error: la precision debe estar "
                  << "entre 1 y 100."
                  << std::endl;
        return;
    }

    precisionPosicion = precision;

    std::cout << "Precision configurada: "
              << precisionPosicion << std::endl;
}

void RobotEnsamblador::ajustarFuerzaPrensado(float fuerza)
{
    // Rango permitido: mayor que 0 y hasta 5000 N.
    if (!(fuerza > 0.0f) || fuerza > 5000.0f)
    {
        std::cout << "Error: la fuerza debe ser mayor que 0 "
                  << "y no superar los 5000 N."
                  << std::endl;
        return;
    }

    fuerzaPrensado = fuerza;

    std::cout << "Fuerza de prensado configurada: "
              << fuerzaPrensado << " N."
              << std::endl;
}

void RobotEnsamblador::ensamblarPiezas()
{
    if (!puedeProcesar())
    {
        std::cout << "El robot ensamblador no puede trabajar "
                  << "porque esta apagado o en falla."
                  << std::endl;
        return;
    }

    std::cout << "Robot ensamblador: ensamblando componentes..."
              << std::endl;

    std::cout << "Precision: " << precisionPosicion
              << " | Fuerza: " << fuerzaPrensado
              << " N." << std::endl;
}

void RobotEnsamblador::procesarPieza()
{
    if (!puedeProcesar())
    {
        std::cout << "El robot ensamblador no puede procesar "
                  << "la pieza en este momento."
                  << std::endl;
        return;
    }

    // Ejecutar la operacion del robot.
    ensamblarPiezas();

    // Registrar el trabajo en la clase base.
    registrarPieza();
    agregarTiempo(20);

    // Consumir vida util de la pinza.
    bool pinzaDisponible = pinza.reducirVida();

    if (!pinzaDisponible)
    {
        reportarFalla();

        std::cout << "FALLA: la pinza del robot "
                  << "ensamblador se ha agotado."
                  << std::endl;
    }
    else
    {
        std::cout << "Pieza ensamblada correctamente."
                  << std::endl;
    }
}

void RobotEnsamblador::realizarMantenimiento()
{
    if (!estaEnFalla())
    {
        std::cout << "El robot no esta en falla; "
                  << "no necesita mantenimiento."
                  << std::endl;
        return;
    }

    pinza.restablecerVida();

    // Quita la falla y suma un paro mediante la clase base.
    registrarMantenimiento();

    std::cout << "Mantenimiento completado: "
              << "la pinza fue restaurada."
              << std::endl;
}

void RobotEnsamblador::mostrarEstado() const
{
    // Reutilizar la implementacion de la clase base.
    Maquina::mostrarEstado();

    std::cout << "Estado del robot ensamblador:"
              << std::endl;

    std::cout << "  Precision: "
              << precisionPosicion << std::endl;

    std::cout << "  Fuerza de prensado: "
              << fuerzaPrensado << " N."
              << std::endl;

    pinza.mostrarEstado();
}
