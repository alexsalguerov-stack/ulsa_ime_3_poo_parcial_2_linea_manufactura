#pragma once

#include "Maquina.h"
#include "Extrusor.h"
#include <string>

class Impresora3D : public Maquina {
private:
    Extrusor* extrusor;
    float tempBoquilla;
    float tempExtrusor;
    float velocidadImpresion;

public:
    Impresora3D(int id, const std::string& nombre);
    ~Impresora3D();

    void calentarBoquilla(float temp);
    void fabricarPieza(const std::string& id);
    void realizarMantenimiento();

    void procesarPieza() override;
};
