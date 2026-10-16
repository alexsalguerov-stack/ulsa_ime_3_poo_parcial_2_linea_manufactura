#include "Maquina.h"
#include <iostream>

Maquina::Maquina(int _id, const std::string &_nombre)
{
    id = _id;
    nombre = _nombre;
    piezasProcesadas = 0;
    paros = 0;
    tiempoTrabajado = 0;
    enFalla = false;
    encendida = false;
}

int Maquina::getId() const
{
    return id;
}

std::string Maquina::getNombre() const
{
    return nombre;
}

int Maquina::getPiezasProcesadas() const
{
    return piezasProcesadas;
}

int Maquina::getTiempoTrabajado() const
{
    return tiempoTrabajado;
}

int Maquina::getParos() const
{
    return paros;
}

void Maquina::encender()
{
    encendida = true;
    std::cout << "La maquina " << nombre << " ha sido encendida." << std::endl;
}

void Maquina::apagar()
{
    encendida = false;
    std::cout << "La maquina " << nombre << " ha sido apagada." << std::endl;
}

bool Maquina::estaEncendida() const
{
    return encendida;
}

bool Maquina::estaEnFalla() const
{
    return enFalla;
}

bool Maquina::puedeProcesar() const
{
    if (encendida && !enFalla)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Maquina::registrarPieza()
{
    piezasProcesadas++;
}

void Maquina::reportarFalla()
{
    enFalla = true;
}

void Maquina::agregarTiempo(int segundos)
{
    if (segundos > 0)
    {
        tiempoTrabajado += segundos;
    }
}

void Maquina::registrarMantenimiento()
{
    enFalla = false;
    paros++;
}

void Maquina::mostrarEstado() const
{
    std::cout << "=== Estado actual de la Maquina ===" << std::endl;
    std::cout << "ID: " << id << std::endl;
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Encendida: " << (encendida ? "Si" : "No") << std::endl;
    std::cout << "En Falla: " << (enFalla ? "Si" : "No") << std::endl;
    std::cout << "Piezas procesadas: " << piezasProcesadas << std::endl;
    std::cout << "Tiempo trabajado: " << tiempoTrabajado << " segundos" << std::endl;
    std::cout << "Paros por mantenimiento: " << paros << std::endl;
}

void Maquina::procesarPieza()
{
    // Metodo base: no hace nada por defecto, es implementado por las clases hijas.
}
