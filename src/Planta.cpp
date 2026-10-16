#include "Planta.h"
#include "Maquina.h"
#include <iostream>

Planta::Planta()
{
    piezasTerminadas = 0;
}

void Planta::agregarMaquina(Maquina *maquina)
{
    maquinas.push_back(maquina);
}

void Planta::procesarLote(int cantidadPiezas)
{
    int tiempoMantenimientoTotal = 0;

    for (int i = 0; i < cantidadPiezas; i++)
    {
        for (Maquina *m : maquinas)
        {
            if (!m->puedeProcesar())
            {
                std::cout << "La maquina " << m->getNombre()
                          << " requiere de mantenimiento" << std::endl;

                if (!m->estaEncendida())
                {
                    m->encender();
                }

                tiempoMantenimientoTotal += 120;
            }
        }
        piezasTerminadas++;
    }

    std::cout << "Tiempo total de mantenimiento en el lote: "
              << tiempoMantenimientoTotal << " segundos." << std::endl;
}

void Planta::mostrarReporte() const
{
    std::cout << "\n==================================" << std::endl;
    std::cout << "      REPORTE DE LA PLANTA        " << std::endl;
    std::cout << "==================================" << std::endl;
    std::cout << "Piezas completadas en el turno: " << piezasTerminadas << std::endl;
    std::cout << "\n--- Estado de cada Estacion ---" << std::endl;

    for (const Maquina *m : maquinas)
    {
        m->mostrarEstado();
        std::cout << "----------------------------------" << std::endl;
    }
}