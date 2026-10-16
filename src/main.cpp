#include <iostream>
#include "Planta.h"
#include "3DP.h"
#include "BandaTransportadora.h"
#include "CortadoraLaser.h"
#include "RobotEnsamblador.h"
#include "Estacioninspeccion.h"

int main()
{
    Planta miPlanta;

    // --- CREACIÓN DE MÁQUINAS ---

    // Impresora 3D (id, nombre)
    Impresora3D impresora(1, "Impresora 3D");

    // Banda (velocidad, cargaMax, id, nombre, vidaMotor)
    BandaTransportadora banda(1.5f, 20.0f, 2, "Banda Transportadora", 50);

    // Cortadora (id, nombre, potencia, velocidad)
    CortadoraLaser laser(3, "Cortadora Laser", 100.0f, 5.0f);

    // Robot (id, nombre, precision, fuerza, vidaUtilPinza)
    RobotEnsamblador robot(4, "Robot Ensamblador", 10, 50.5f, 40);

    // Inspeccion (id, nombre, tolerancia, limiteSensor, segundos)
    EstacionInspeccion inspeccion(5, "Estacion de Inspeccion", 0.01f, 25, 25);

    // Registro en la planta en orden de flujo
    miPlanta.registrarMaquina(&impresora);
    miPlanta.registrarMaquina(&banda);
    miPlanta.registrarMaquina(&laser);
    miPlanta.registrarMaquina(&robot);
    miPlanta.registrarMaquina(&inspeccion);

    // --- ESCENARIO OBLIGATORIO ---

    // 1. Intentar procesar con máquinas apagadas
    std::cout << "--- TEST 1: Verificando rechazo (Máquinas apagadas) ---\n";
    impresora.procesarPieza();
    std::cout << "----------------------------------------------------\n\n";

    // 2. Encender todas las máquinas
    std::cout << "--- Encendiendo linea de produccion ---\n";
    impresora.encender();
    banda.encender();
    laser.encender();
    robot.encender();
    inspeccion.encender();

    // 3. Procesar lote de 20 piezas
    std::cout << "\n--- Iniciando procesado de lote (20 piezas) ---\n";
    int piezasFinales = miPlanta.procesarLote(20);

    // 4. Reporte Final
    std::cout << "\nLote finalizado. Piezas completadas: " << piezasFinales << "/20\n";
    miPlanta.generarReporte();

    // 5. Apagar línea
    impresora.apagar();
    banda.apagar();
    laser.apagar();
    robot.apagar();
    inspeccion.apagar();

    return 0;
}
