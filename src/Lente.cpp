#include "Lente.h"

Lente::Lente(int vida) {
    vidaUtil = vida;
}

bool Lente::reducirVida() {

    vidaUtil--;

    if (vidaUtil <= 0) {
        return false;
    }

    return true;
}

int Lente::getVidaUtil() {
    return vidaUtil;
}

void Lente::restaurar() {
    vidaUtil = 10;
}
