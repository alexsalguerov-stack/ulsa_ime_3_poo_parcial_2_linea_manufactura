#include "Planta.h"
#include <iostream>

int Planta::procesarLote(int cantidad)
{
    int piezasTerminadas = 0;

    for (int i = 1; i <= cantidad; ++i)
    {
        std::cout << "\n--- Procesando Pieza #" << i << " ---\n";

        for (Maquina *m : linea)
        {
            // 1. Si la máquina venía en falla, se repara antes de procesar
            if (m->estaEnFalla())
            {
                std::cout << "Alerta: " << m->getNombre() << " requiere mantenimiento. Reparando..." << std::endl;
                m->realizarMantenimiento();
            }

            // 2. Procesa la pieza en la estación actual
            m->procesarPieza();

            // 3. Si la máquina falló DURANTE el proceso (ej. pieza 15 en la impresora)
            if (m->estaEnFalla())
            {
                std::cout << "Alerta: " << m->getNombre() << " entro en falla. Realizando mantenimiento..." << std::endl;
                m->realizarMantenimiento();

                // Reintenta procesar la pieza actual para que no se pierda
                m->procesarPieza();
            }
        }

        piezasTerminadas++;
        std::cout << "Pieza #" << i << " terminada exitosamente.\n";
    }
    return piezasTerminadas;
}

void Planta::generarReporte()
{
    int tiempoTotal = 0;
    int parosTotales = 0;

    // 1. Calcula el tiempo máximo (cuello de botella) y acumula paros
    for (Maquina *m : linea)
    {
        if (m->getTiempoTrabajado() > tiempoTotal)
        {
            tiempoTotal = m->getTiempoTrabajado();
        }
        parosTotales += m->getParos();
    }

    // 2. Imprime el reporte general una sola vez
    std::cout << "\n==========================================\n";
    std::cout << "          REPORTE FINAL DEL TURNO         \n";
    std::cout << "==========================================\n";
    std::cout << "Tiempo total de operacion: " << tiempoTotal << " s\n";
    std::cout << "Total de paros por mantenimiento: " << parosTotales << "\n";
    std::cout << "------------------------------------------\n";

    // 3. Detalle de cada máquina
    for (Maquina *m : linea)
    {
        std::cout << m->getNombre() << " \t| "
                  << m->getPiezasProcesadas() << " piezas | "
                  << m->getParos() << " paros | "
                  << (m->estaEnFalla() ? "ESTADO: FALLA" : "ESTADO: OK") << "\n";
    }
    std::cout << "==========================================\n";
}