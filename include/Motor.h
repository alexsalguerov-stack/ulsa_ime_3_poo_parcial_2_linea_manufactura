#ifndef MOTOR_H
#define MOTOR_H

class Motor
{
private:
    int vidaUtil;
    int vidaActual;

public:
    Motor(int vidaIncial = 100);

    bool reducirVida();
    bool restablecerVida();

    int getVidaActual() const;
    bool sigueVivo() const;
};

#endif
