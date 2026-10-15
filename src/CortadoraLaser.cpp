#include "CortadoraLaser.h"

CortadoraLaser::CortadoraLaser(
    int id,
    string nombre,
    float potencia,
    float velocidad
)
: Maquina(id, nombre)
{
    potenciaLaser = potencia;
    velocidadCorte = velocidad;
}

void CortadoraLaser::ajustarPotencia(float p) {

    if (p > 0) {
        potenciaLaser = p;
    }
}

void CortadoraLaser::grabarDetalle(string patron) {

    cout << "Grabando detalle: "
         << patron
         << endl;
}

void CortadoraLaser::procesarPieza() {

    if (!puedeProcesar()) {
        cout << "No se puede procesar la pieza."
             << endl;
        return;
    }

    cout << "La cortadora laser esta cortando la pieza."
         << endl;

    registrarPieza();

    agregarTiempo(15);

    bool funciona = lente.reducirVida();

    if (!funciona) {

        cout << "El lente se desgasto."
             << endl;

        reportarFalla();
    }
}

void CortadoraLaser::realizarMantenimiento() {

    cout << "Realizando mantenimiento..."
         << endl;

    lente.restaurar();

    registrarMantenimiento();
}

void CortadoraLaser::mostrarEstado() {

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
