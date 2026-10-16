#include "Planta.h"
#include <iostream>

int Planta::procesarLote(int cantidad) {
    int piezasTerminadas = 0;

    for (int i = 1; i <= cantidad; ++i) {
        bool piezaCompletada = true;
        std::cout << "\n--- Procesando Pieza #" << i << " ---\n";

        for (Maquina* m : linea) {
            // Si la máquina está en falla, se le da mantenimiento inmediatamente
            if (m->estaEnFalla()) {
                std::cout << "Línea detenida: " << m->getNombre() << " requiere mantenimiento." << std::endl;
                m->realizarMantenimiento();
            }

            // Procesar la pieza
            m->procesarPieza();

            // Si la máquina entró en falla durante el proceso, la pieza se detiene aquí
            if (m->estaEnFalla()) {
                std::cout << "La pieza se detuvo en " << m->getNombre() << " debido a una falla." << std::endl;
                piezaCompletada = false;
                break;
            }
        }
        if (piezaCompletada) {
            piezasTerminadas++;
            std::cout << "Pieza #" << i << " terminada exitosamente.\n";
        }
    }
    return piezasTerminadas;
}

void Planta::generarReporte() {
    int tiempoTotal = 0;
    int parosTotales = 0;

    std::cout << "\n==========================================\n";
    std::cout << "          REPORTE FINAL DEL TURNO         \n";
    std::cout << "==========================================\n";

    for (Maquina* m : linea) {
        tiempoTotal += m->getTiempoTrabajado();
        parosTotales += m->getParos();
    }

    // Cada mantenimiento suma 120s según README
    int tiempoMantenimiento = parosTotales * 120;

    std::cout << "Tiempo total de operacion: " << (tiempoTotal + tiempoMantenimiento) << " s\n";
    std::cout << "Total de paros por mantenimiento: " << parosTotales << "\n";
    std::cout << "------------------------------------------\n";

    for (Maquina* m : linea) {
        std::cout << m->getNombre() << " \t| "
                  << m->getPiezasProcesadas() << " piezas | "
                  << m->getParos() << " paros | "
                  << (m->estaEnFalla() ? "ESTADO: FALLA" : "ESTADO: OK") << "\n";
    }
    std::cout << "==========================================\n";
}
