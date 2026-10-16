#include "3DP.h"
#include <iostream>

Impresora3D::Impresora3D(int id, const std::string& nombre) : Maquina(id, nombre) {
    extrusor = new Extrusor(15); // Límite de 15 piezas
    tempBoquilla = 0.0f;
    tempExtrusor = 0.0f;
    velocidadImpresion = 1.0f;
}

Impresora3D::~Impresora3D() {
    delete extrusor;
}

void Impresora3D::calentarBoquilla(float temp) {
    tempBoquilla = temp;
    std::cout << "Impresora 3D: Calentando boquilla a " << temp << " grados..." << std::endl;
}

void Impresora3D::fabricarPieza(const std::string& id) {
    std::cout << "Impresora 3D: Iniciando fabricacion de pieza " << id << std::endl;
    procesarPieza();
}

void Impresora3D::procesarPieza() {
    if (!puedeProcesar()) {
        std::cout << "Impresora 3D: No puede procesar (Apagada o en Falla)." << std::endl;
        return;
    }

    // Verificar desgaste del componente
    if (!extrusor->reducirVida()) {
        reportarFalla();
        std::cout << "Impresora 3D: Falla en la operación, vida útil del extrusor agotada, mantenimiento requerido." << std::endl;
        return;
    }

    // Si no hay falla, procesar tiempo y pieza
    agregarTiempo(180); // 180s
    registrarPieza();
    std::cout << "Impresora 3D: Pieza fabricada exitosamente." << std::endl;
}

void Impresora3D::realizarMantenimiento() {
    extrusor->restaurarVida();
    registrarMantenimiento();
    std::cout << "Impresora 3D: Mantenimiento realizado. El extrusor ha sido reemplazado." << std::endl;
}
