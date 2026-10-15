#ifndef PLANTA_H
#define PLANTA_H

#include <vector>
#include <string>
#include "Maquina.h" // Necesario para reconocer la clase base Maquina

class Planta
{
private:
    int piezasTerminadas;
    // Guardamos punteros a Maquina para aceptar cualquier tipo de máquina derivada (como BandaTransportadora)
    std::vector<Maquina *> maquinas;

public:
    // Constructor
    Planta();

    // Permite agregar las máquinas en orden desde afuera
    void agregarMaquina(Maquina *maquina);

    // Procesa un lote de piezas haciendo que cada una pase por todas las máquinas
    void procesarLote(int cantidadPiezas);

    // Genera el reporte general al terminar el turno
    void mostrarReporte() const;
};

#endif // PLANTA_H