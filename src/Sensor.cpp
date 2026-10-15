#ifndef SENSOR_H
#define SENSOR_H


class Sensor {
private:
    int vidaUtil;   
    int limite;    

public:
    Sensor(int lim);

    bool reducirVida();   
    void restaurar();    

    int getVidaUtil() const;
    int getLimite() const;
};

#endif