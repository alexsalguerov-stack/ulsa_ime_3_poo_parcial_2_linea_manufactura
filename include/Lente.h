#ifndef LENTE_H
#define LENTE_H

class Lente
{
private:
    int vidaUtil;

public:
    Lente(int vida = 10);

    bool reducirVida();

    int getVidaUtil() const;

    void restaurar();
};

#endif
