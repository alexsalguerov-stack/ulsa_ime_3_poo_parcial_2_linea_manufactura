
#ifndef PINZA_H
#define PINZA_H

class Pinza
{
private:
    int vidaUtilMaxima;
    int vidaRestante;

public:
    explicit Pinza(int vidaUtilInicial);

    // Consume una unidad de vida útil.
    // Devuelve false cuando la pinza se agota.
    bool reducirVida();

    // Restaura la vida útil original.
    void restablecerVida();

    // Consultas del estado del componente.
    int getVidaRestante() const;
    int getVidaUtilMaxima() const;

    void mostrarEstado() const;
};

#endif
