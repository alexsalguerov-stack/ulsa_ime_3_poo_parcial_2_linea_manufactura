#include "3DP.h"
#include <iostream>

Impresora3D::Impresora3D(int id, const std::string &nombre) : Maquina(id, nombre)
{
    extrusor = new Extrusor(15);
    settempBoquilla(200.0f);
    settempExtrusor(20.0f);
    setvelocidadImpresion(1.0f);
}

Impresora3D::~Impresora3D()
{
    delete extrusor;
}

void Impresora3D::settempBoquilla(float temp)
{
    if (temp < 20.0f)
    {
        std::cout << "Error: Temperatura de boquilla muy baja (" << temp << " °C). Se ajusta al mínimo ambiente: 20.0 °C." << std::endl;
        tempBoquilla = 20.0f;
    }
    else if (temp > 300.0f)
    {
        std::cout << "Error: Temperatura de boquilla excede el límite de seguridad (" << temp << " °C). Se fuerza al máximo: 300.0 °C." << std::endl;
        tempBoquilla = 300.0f; // Corrección forzada
    }
    else
    {
        tempBoquilla = temp;
        std::cout << "Temperatura de boquilla asignada correctamente: " << tempBoquilla << " °C." << std::endl;
    }
}

void Impresora3D::settempExtrusor(float t)
{
    if (t < 20.0f)
    {
        std::cout << "Error: Temperatura de extrusor muy baja (" << t << " °C). Se ajusta al ambiente: 20.0 °C." << std::endl;
        tempExtrusor = 20.0f;
    }
    else if (t > 250.0f)
    {
        std::cout << "Error: Temperatura de extrusor excede el límite (" << t << " °C). Se fuerza al máximo: 250.0 °C." << std::endl;
        tempExtrusor = 250.0f; // Corrección forzada
    }
    else
    {
        tempExtrusor = t;
        std::cout << "Temperatura del extrusor asignada correctamente: " << tempExtrusor << " °C." << std::endl;
    }
}

void Impresora3D::setvelocidadImpresion(float v)
{
    if (v <= 0.0f)
    {
        std::cout << "Error: Velocidad de impresión inválida (" << v << "). Se ajusta al mínimo seguro: 0.1 m/s." << std::endl;
        velocidadImpresion = 0.1f;
    }
    else if (v > 5.0f)
    {
        std::cout << "Error: Velocidad excede el límite (" << v << " m/s). Se fuerza al máximo permitido: 5.0 m/s." << std::endl;
        velocidadImpresion = 5.0f; // Corrección forzada
    }
    else
    {
        velocidadImpresion = v;
        std::cout << "Velocidad de impresión asignada correctamente: " << velocidadImpresion << " m/s." << std::endl;
    }
}

void Impresora3D::calentarBoquilla(float temp)
{
    tempBoquilla = temp;
    std::cout << "Impresora 3D: Calentando boquilla a " << temp << " grados..." << std::endl;
}

void Impresora3D::fabricarPieza(const std::string &id)
{
    std::cout << "Impresora 3D: Iniciando fabricacion de pieza " << id << std::endl;
    procesarPieza();
}

void Impresora3D::procesarPieza()
{
    if (!puedeProcesar())
    {
        std::cout << "Impresora 3D: No puede procesar (Apagada o en Falla)." << std::endl;
        return;
    }

    // Verificar desgaste del componente
    if (!extrusor->reducirVida())
    {
        reportarFalla();
        std::cout << "Impresora 3D: Falla en la operación, vida útil del extrusor agotada, mantenimiento requerido." << std::endl;
        return;
    }

    // Si no hay falla, procesar tiempo y pieza
    agregarTiempo(180); // 180s
    registrarPieza();
    std::cout << "Impresora 3D: Pieza fabricada exitosamente." << std::endl;
}

void Impresora3D::realizarMantenimiento()
{
    extrusor->restaurarVida();
    registrarMantenimiento();
    std::cout << "Impresora 3D: Mantenimiento realizado. El extrusor ha sido reemplazado." << std::endl;
}
