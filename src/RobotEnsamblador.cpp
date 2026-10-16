#include "RobotEnsamblador.h"
#include <iostream>

RobotEnsamblador::RobotEnsamblador(
    int id,
    const std::string &nombre,
    int precision,
    float fuerza,
    int vidaUtilPinza)
    : Maquina(id, nombre),
      precisionPosicion(1),
      fuerzaPrensado(1.0f),
      pinza(vidaUtilPinza)
{
    setprecisionPosicion(precision);
    setfuerzaPrensado(fuerza);
}

void RobotEnsamblador::setprecisionPosicion(float p)
{
    if (p < 1.0f)
    {
        std::cout << "Error: Precisión fuera de rango (" << p << "). Se ajusta al mínimo seguro: 1." << std::endl;
        precisionPosicion = 1;
    }
    else if (p > 100.0f)
    {
        std::cout << "Error: Precisión excede el límite (" << p << "). Se fuerza al máximo permitido: 100." << std::endl;
        precisionPosicion = 100; // Corrección forzada
    }
    else
    {
        precisionPosicion = static_cast<int>(p);
        std::cout << "Precisión de posición asignada correctamente: " << precisionPosicion << std::endl;
    }
}

void RobotEnsamblador::setfuerzaPrensado(float f)
{
    if (f <= 0.0f)
    {
        std::cout << "Error: Fuerza inválida (" << f << " N). Se ajusta al mínimo seguro: 1.0 N." << std::endl;
        fuerzaPrensado = 1.0f;
    }
    else if (f > 5000.0f)
    {
        std::cout << "Error: Fuerza excede el límite (" << f << " N > 5000 N). Se fuerza al máximo permitido: 5000.0 N." << std::endl;
        fuerzaPrensado = 5000.0f; // Corrección forzada
    }
    else
    {
        fuerzaPrensado = f;
        std::cout << "Fuerza de prensado asignada correctamente: " << fuerzaPrensado << " N." << std::endl;
    }
}

void RobotEnsamblador::ajustarPrecision(int precision)
{
    if (precision < 1 || precision > 100)
    {
        std::cout << "Error: la precision debe estar entre 1 y 100." << std::endl;
        return;
    }

    precisionPosicion = precision;
    std::cout << "Precision configurada: " << precisionPosicion << std::endl;
}

void RobotEnsamblador::ajustarFuerzaPrensado(float fuerza)
{
    if (!(fuerza > 0.0f) || fuerza > 5000.0f)
    {
        std::cout << "Error: la fuerza debe ser mayor que 0 y no superar los 5000 N." << std::endl;
        return;
    }

    fuerzaPrensado = fuerza;
    std::cout << "Fuerza de prensado configurada: " << fuerzaPrensado << " N." << std::endl;
}

void RobotEnsamblador::ensamblarPiezas()
{
    if (!puedeProcesar())
    {
        std::cout << "El robot ensamblador no puede trabajar porque esta apagado o en falla." << std::endl;
        return;
    }

    std::cout << "Robot ensamblador: ensamblando componentes..." << std::endl;
    std::cout << "Precision: " << precisionPosicion << " | Fuerza: " << fuerzaPrensado << " N." << std::endl;
}

void RobotEnsamblador::procesarPieza()
{
    if (!puedeProcesar())
    {
        std::cout << "El robot ensamblador no puede procesar la pieza en este momento." << std::endl;
        return;
    }

    ensamblarPiezas();
    registrarPieza();
    agregarTiempo(8);

    bool pinzaDisponible = pinza.reducirVida();

    if (!pinzaDisponible)
    {
        reportarFalla();
        std::cout << "FALLA: la pinza del robot ensamblador se ha agotado." << std::endl;
    }
    else
    {
        std::cout << "Pieza ensamblada correctamente." << std::endl;
    }
}

void RobotEnsamblador::realizarMantenimiento()
{
    pinza.restablecerVida();
    registrarMantenimiento();
    std::cout << "Mantenimiento completado: la pinza fue restaurada." << std::endl;
}

void RobotEnsamblador::mostrarEstado() const
{
    Maquina::mostrarEstado();

    std::cout << "Estado del robot ensamblador:" << std::endl;
    std::cout << "  Precision: " << precisionPosicion << std::endl;
    std::cout << "  Fuerza de prensado: " << fuerzaPrensado << " N." << std::endl;

    pinza.mostrarEstado();
}
