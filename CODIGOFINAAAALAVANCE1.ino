#include <Stepper.h>

const int stepsPerRevolution = 400;

// Configuración de los pines de los motores
Stepper motor1(stepsPerRevolution, 8, 10, 9, 11); // Pines del motor 1
Stepper motor2(stepsPerRevolution, 4, 6, 5, 7);   // Pines del motor 2

// Pin de la bocina y del botón
int buzzer = 3;
int boton1 = 2;
int boton2 = 12; // Pin del botón 

void setup() {
  // Configurar la velocidad de los motores (en RPM)
  motor1.setSpeed(50);
  motor2.setSpeed(50);

  // Configurar el pin de la bocina y el botón
  pinMode(buzzer, OUTPUT);
  pinMode(boton1, INPUT);
  pinMode(boton2, INPUT);
}

void loop() {
  // Esperar a que se presione el botón
   if (digitalRead(boton1) == HIGH) {

    // Compuerta reservorio se abre
    motor1.step(400);
    delay(500);

    // Compuerta reservorio se cierra
    motor1.step(-400);
    delay(2000);

    // Compuerta vaso se abre
    motor2.step(400);
    delay(500);

    // compuerta vaso se cierra
    motor2.step(-400);
    delay(2000); 

    // 5. Sonar la bocina 3 veces 
    for (int i = 0; i < 3; i++) {
      digitalWrite(buzzer, HIGH);
      delay(500);
      digitalWrite(buzzer, LOW);
      delay(500);
    }
    
    // Detener el loop hasta que se presione el botón nuevamente
     // Espera hasta que se suelte el botón
    while (digitalRead(boton1) == HIGH);
  }

  if (digitalRead(boton2) == HIGH) {

    // 1. Mover motor 1 hacia adelante 90 grados
    motor1.step(200);

    // 2. Devolver motor 1 a su posición inicial
    motor1.step(-200);
    delay(2000);

    // 3. Mover motor 2 hacia adelante 90 grados
    motor2.step(400);

    // 4. Devolver motor 2 a su posición inicial
    motor2.step(-400);
    delay(2000);

    // 5. Sonar la bocina 3 veces con un intervalo de 500 ms entre sonidos
    for (int i = 0; i < 3; i++) {
      digitalWrite(buzzer, HIGH);
      delay(500);
      digitalWrite(buzzer, LOW);
      delay(500);
    }
    
    // Detener el loop hasta que se presione el botón nuevamente
    while (digitalRead(boton2) == HIGH); // Espera hasta que se suelte el botón
  }
}
