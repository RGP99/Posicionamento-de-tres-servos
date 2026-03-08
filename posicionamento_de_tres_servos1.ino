#include <Servo.h>

Servo servochulonA;
Servo servochulonB;
Servo servochulonC;

void setup() {
  servoA.attach(9);
  servoB.attach(10);
  servoC.attach(11);
  Serial.begin(9600);
}

void loop() {
  /* Hacemos la conversion del potenciometro a grados para que se puedan comunicar
   los potenciometros con los servos*/
  int gradosA = map(analogRead(A0), 0, 1023, 0, 180);
  int gradosB = map(analogRead(A1), 0, 1023, 0, 180);
  int gradosC = map(analogRead(A2), 0, 1023, 0, 180);

  // Ajustamos la precision de cada servo para que cumpla lo que pide la practica
  gradosA = (gradosA / 12) * 12;  // precision 12 grados
  gradosB = (gradosB / 5) * 5;    // precision 5 grados
  gradosC = (gradosC / 1) * 1;    // precision 1 grado

  // Movemos los servos
  servoA.write(gradosA);
  servoB.write(gradosB);
  servoC.write(gradosC);

  // Mostramos los valores por el monitor serie
  Serial.print("Acimut: ");
  Serial.print(gradosA);
  Serial.print("  Altura: ");
  Serial.print(gradosB);
  Serial.print("  Pinza: ");
  Serial.println(gradosC);

  // Esperamos 125ms 
  delay(125);
}