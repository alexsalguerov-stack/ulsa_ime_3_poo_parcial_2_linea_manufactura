#pragma once

class Extrusor {
  private:
      int vidaUtil;       // Cantidad de piezas que puede procesar antes de fallar
      int vidaMaxima;     // Valor original para resetear durante el mantenimiento

  public:
      Extrusor(int limite = 15) : vidaUtil(limite), vidaMaxima(limite) {}

      // Reduce la vida util de la pieza conforme se completan los ciclos
      bool reducirVida() {
          if (vidaUtil > 0) {
              vidaUtil--;
          }

          return (vidaUtil > 0);    // Retorna false si la vida llegó a 0, indicando que ha fallado
      }

      // Regresa al valor inicial despues del mantenimiento
      void restaurarVida() {
          vidaUtil = vidaMaxima;
      }

      int getVidaRestante() const {
          return vidaUtil;
      }

      int getVidaMaxima() const {
          return vidaMaxima;
      }
};
