#include "CortadoraLaser.h"
#include <iostream>

using namespace std;

CortadoraLaser::CortadoraLaser(
    int id,
    string nombre,
    float potencia,
    float velocidad)
    : Maquina(id, nombre), lente(30) // Inicializa el lente con 30 usos predeterminados
{
    setpotenciaLaser(potencia);
    setvelocidadCorte(velocidad);
}

void CortadoraLaser::setpotenciaLaser(float p)
{
    if (p < 0.0f)
    {
        cout << "Error: Potencia negativa (" << p << "%). Se ajusta a 0.0%." << endl;
        potenciaLaser = 0.0f;
    }
    else if (p > 100.0f)
    {
        cout << "Error: Potencia excede el 100% (" << p << "%). Se fuerza al límite máximo: 100.0%." << endl;
        potenciaLaser = 100.0f; // Corrección forzada
    }
    else
    {
        potenciaLaser = p;
        cout << "Potencia del láser asignada correctamente: " << potenciaLaser << "%." << endl;
    }
}

void CortadoraLaser::setvelocidadCorte(float v)
{
    if (v <= 0.0f)
    {
        cout << "Error: Velocidad de corte inválida (" << v << "). Se ajusta a 0.1 m/s." << endl;
        velocidadCorte = 0.1f;
    }
    else if (v > 10.0f)
    {
        cout << "Error: Velocidad de corte excede el límite (" << v << " m/s). Se fuerza a 10.0 m/s." << endl;
        velocidadCorte = 10.0f; // Corrección forzada
    }
    else
    {
        velocidadCorte = v;
        cout << "Velocidad de corte asignada correctamente: " << velocidadCorte << " m/s." << endl;
    }
}

void CortadoraLaser::grabarDetalle(string patron)
{
    cout << "Grabando detalle: "
         << patron
         << endl;
}

void CortadoraLaser::procesarPieza()
{
    if (!puedeProcesar())
    {
        cout << "No se puede procesar la pieza."
             << endl;
        return;
    }

    cout << "La cortadora laser esta grabando la pieza."
         << endl;

    registrarPieza();
    agregarTiempo(15);

    bool funciona = lente.reducirVida();

    if (!funciona)
    {
        cout << "Lente desgastada."
             << endl;
        reportarFalla();
    }
}

void CortadoraLaser::realizarMantenimiento()
{
    cout << "Realizando mantenimiento..."
         << endl;

    lente.restaurar();
    registrarMantenimiento();
}

void CortadoraLaser::mostrarEstado() const
{
    Maquina::mostrarEstado();

    cout << "Potencia laser: "
         << potenciaLaser
         << endl;

    cout << "Velocidad de corte: "
         << velocidadCorte
         << endl;

    cout << "Vida util del lente: "
         << lente.getVidaUtil()
         << endl;
}