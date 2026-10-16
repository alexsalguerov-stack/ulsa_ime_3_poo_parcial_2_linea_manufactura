#include "EstacionInspeccion.h"
#include <iostream>

using namespace std;

EstacionInspeccion::EstacionInspeccion(int id, string nombre, float tolerancia,
                                       int limiteSensor, int segundos)
    : Maquina(id, nombre), sensor(limiteSensor)
{ // Inicializa el objeto sensor
    settoleranciasError(tolerancia);

    if (segundos <= 0)
    {
        cout << "Error: Segundos por pieza inválidos (" << segundos << "). Se ajusta al estándar de seguridad: 25 s." << endl;
        segundosPorPieza = 25;
    }
    else
    {
        segundosPorPieza = segundos;
    }

    medicionesRealizadas = 0;
}

void EstacionInspeccion::settoleranciasError(float t)
{
    if (t < 0.001f)
    {
        cout << "Error: Tolerancia demasiado estricta (" << t << "). Se ajusta al mínimo seguro: 0.001 mm." << endl;
        toleranciaError = 0.001f;
    }
    else if (t > 1.0f)
    {
        cout << "Error: Tolerancia demasiado alta (" << t << " mm). Se fuerza al máximo permitido: 1.0 mm." << endl;
        toleranciaError = 1.0f; // Corrección forzada
    }
    else
    {
        toleranciaError = t;
        cout << "Tolerancia de error asignada correctamente: " << toleranciaError << " mm." << endl;
    }
}

void EstacionInspeccion::setmedicionesRealizadas(int m)
{
    if (m < 0)
    {
        medicionesRealizadas = 0;
    }
    else
    {
        medicionesRealizadas = m;
    }
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
