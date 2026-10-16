#include "EstacionInspeccion.h"
#include <iostream>

using namespace std;

EstacionInspeccion::EstacionInspeccion(int id, string nombre, float tolerancia,
                                       int limiteSensor, int segundos)
    : Maquina(id, nombre), sensor(limiteSensor)
{ // Inicializa el objeto sensor
    if (tolerancia <= 0)
    {
        tolerancia = 0.05f;
    }
    if (segundos <= 0)
    {
        segundos = 25; // 25s por pieza según la tabla de la planta
    }
    toleranciaError = tolerancia;
    segundosPorPieza = segundos;
    medicionesRealizadas = 0;
}

bool EstacionInspeccion::medirTolerancia(float valor)
{
    if (valor < 0)
    {
        valor = -valor;
    }
    return valor <= toleranciaError;
}

bool EstacionInspeccion::inspeccionarCalidad()
{
    medicionesRealizadas++;
    int resto = medicionesRealizadas % 4;
    float desviacion = resto * 0.01f;
    return medirTolerancia(desviacion);
}

void EstacionInspeccion::procesarPieza()
{
    if (!puedeProcesar())
    {
        cout << "[Estacion de inspeccion] Operacion rechazada: debe estar encendida y sin falla." << endl;
        return;
    }

    bool aprobada = inspeccionarCalidad();
    if (aprobada)
    {
        cout << "[Inspeccion] Pieza " << medicionesRealizadas << ": dentro de tolerancia" << endl;
    }
    else
    {
        cout << "[Inspeccion] Pieza " << medicionesRealizadas << ": FUERA de tolerancia" << endl;
    }

    registrarPieza();
    agregarTiempo(segundosPorPieza);

    if (!sensor.reducirVida())
    {
        reportarFalla();
        cout << "[Inspeccion] El sensor se descalibro: maquina en falla." << endl;
    }
}

void EstacionInspeccion::realizarMantenimiento()
{
    sensor.restaurar();
    registrarMantenimiento();
    cout << "[Inspeccion] Sensor recalibrado." << endl;
}

void EstacionInspeccion::mostrarEstado() const
{
    Maquina::mostrarEstado();
    cout << "  Tolerancia de error: " << toleranciaError << " mm" << endl;
    cout << "  Mediciones realizadas: " << medicionesRealizadas << endl;
    cout << "  Segundos por pieza: " << segundosPorPieza << " s" << endl;
    cout << "  Vida del sensor: " << sensor.getVidaUtil() << "/" << sensor.getLimite() << endl;
}

float EstacionInspeccion::getToleranciaError() const
{
    return toleranciaError;
}

int EstacionInspeccion::getMedicionesRealizadas() const
{
    return medicionesRealizadas;
}

int EstacionInspeccion::getSegundosPorPieza() const
{
    return segundosPorPieza;
}