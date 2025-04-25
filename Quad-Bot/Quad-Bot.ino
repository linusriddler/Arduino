#include <Servo.h>

// Definir pines del sensor ultrasónico
const int trigPin = 5;
const int echoPin = 6;

// Definir pines de los servomotores
const int servoPin1 = 9;
const int servoPin2 = 10;

// Definir distancia de detección
const int distanceThreshold = 20; // Distancia de detección en centímetros

// Crear objetos para los servomotores
Servo servo1;
Servo servo2;

void setup() {
  // Inicializar los pines del sensor ultrasónico
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Inicializar los servomotores
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);

  // Colocar los servos en su posición inicial
  servo1.write(90); // Posición inicial de servo1 (90 grados)
  servo2.write(90); // Posición inicial de servo2 (90 grados)
}

void loop() {
  // Realizar la medición de distancia
  long distance = getUltrasonicDistance();

  // Verificar si hay un obstáculo a menos de 20 cm
  if (distance < distanceThreshold) {
    // Girar servo1 a la izquierda (ejemplo: 45 grados)
    servo1.write(45);
    delay(1000); // Puedes ajustar el tiempo de giro hacia la izquierda

    // Detener servo1
    servo1.write(90);

    // Girar servo2 a la derecha (ejemplo: 135 grados)
    servo2.write(135);
    delay(1000); // Puedes ajustar el tiempo de giro hacia la derecha

    // Detener servo2
    servo2.write(90);
  } else {
    // Ambos servos avanzan hacia adelante (ejemplo: 0 grados)
    servo1.write(0);
    servo2.write(0);
  }
}

long getUltrasonicDistance() {
  // Generar un pulso de 10 microsegundos en el pin Trig
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Medir la duración del pulso en el pin Echo
  long duration = pulseIn(echoPin, HIGH);

  // Calcular la distancia en centímetros
  long distance = duration * 0.034 / 2;

  return distance;
}
