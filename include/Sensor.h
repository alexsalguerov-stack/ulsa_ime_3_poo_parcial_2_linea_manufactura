#ifndef SENSOR_H
#define SENSOR_H

class Sensor
{
private:
    int vidaUtil;
    int limite;

public:
    Sensor(int limiteInicial = 25);

    bool reducirVida();
    void restaurar();

    int getVidaUtil() const;
    int getLimite() const;
    void mostrarEstado() const;
};

#endif // SENSOR_H