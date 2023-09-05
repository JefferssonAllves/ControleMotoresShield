#include <ControleMotores.h>
#include <AFMotor.h>
#include <Arduino.h>

ControleMotores::ControleMotores(const byte (&PORTAS_MOTORES)[4]) : motorEsquerda1(PORTAS_MOTORES[0]), motorEsquerda2(PORTAS_MOTORES[1]), motorDireita1(PORTAS_MOTORES[2]), motorDireita2(PORTAS_MOTORES[3]) {
  Serial.print("4 Motores foram iniciados");
}
ControleMotores::ControleMotores(const byte (&PORTAS_MOTORES)[2]) : motorEsquerda1(PORTAS_MOTORES[0]), motorEsquerda2(0), motorDireita1(PORTAS_MOTORES[1]), motorDireita2(0){
  Serial.print("2 Motores foram iniciados");
}
void ControleMotores::parado(){
  motorEsquerda1.run(RELEASE);
  motorEsquerda2.run(RELEASE);
  motorDireita1.run(RELEASE);
  motorDireita2.run(RELEASE);
}
void ControleMotores::acionar(short velocidadeEsquerda, short velocidadeDireita) {

  if (velocidadeEsquerda >= 0) {
    motorEsquerda1.run(FORWARD);
    motorEsquerda2.run(FORWARD);
  } else {
    velocidadeEsquerda *= -1;
    motorEsquerda1.run(BACKWARD);
    motorEsquerda2.run(BACKWARD);
  }
  motorEsquerda1.setSpeed(constrain(velocidadeEsquerda, 0, 255));
  motorEsquerda2.setSpeed(constrain(velocidadeEsquerda, 0, 255));

  if (velocidadeDireita >= 0) {
    motorDireita1.run(FORWARD);
    motorDireita2.run(FORWARD);
  } else {
    velocidadeDireita *= -1;
    motorDireita1.run(BACKWARD);
    motorDireita2.run(BACKWARD);
  }
  motorDireita1.setSpeed(constrain(velocidadeDireita, 0, 255));
  motorDireita2.setSpeed(constrain(velocidadeDireita, 0, 255));
}

void ControleMotores::acionar(short velocidadeEsquerda, short velocidadeDireita, short time){
  ControleMotores::acionar(velocidadeEsquerda, velocidadeDireita);
  delay(time);
  ControleMotores::parado();
}
