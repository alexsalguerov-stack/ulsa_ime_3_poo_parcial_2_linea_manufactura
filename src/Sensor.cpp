#include "Sensor.h"

Sensor::Sensor(int lim) {

    if (lim <= 0) {
        lim = 1;
    }

    limite = lim;
    vidaUtil = lim;
}

bool Sensor::reducirVida() {

    if (vidaUtil > 0) {
        vidaUtil = vidaUtil - 1;
    }

    if (vidaUtil == 0) {
        return true;
    }

    return false;
}

void Sensor::restaurar() {
    vidaUtil = limite;
}

int Sensor::getVidaUtil() const {
    return vidaUtil;
}

int Sensor::getLimite() const {
    return limite;
}