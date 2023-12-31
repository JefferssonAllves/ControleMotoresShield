#define CONTROLEMOTORES_H

#include <Arduino.h>
#include <AFMotor.h>

class ControleMotores {
public:
  // Construtor
  ControleMotores(const byte (&PORTAS_MOTORES)[4]);
  ControleMotores(const byte (&PORTAS_MOTORES)[2]);
  void parado();
  void acionar(short velocidadeEsquerda, short velocidadeDireita);
  void acionar(short velocidadeEsquerda, short velocidadeDireita, short time);
  void acionarPID(short velocdadeEsquerda, short velocidadeDireita);
private:
  AF_DCMotor motorEsquerda1;
  AF_DCMotor motorEsquerda2;
  AF_DCMotor motorDireita1;
  AF_DCMotor motorDireita2;
};
