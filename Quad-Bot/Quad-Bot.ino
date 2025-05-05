#include <Servo.h>

// Define ultrasonic sensor pins
const int trigPin = 5;
const int echoPin = 6;

// Define servo motor pins
const int servoPin1 = 9;
const int servoPin2 = 10;

// Define detection distance
const int distanceThreshold = 20; // Detection distance in centimeters

// Create objects for the servos
Servo servo1;
Servo servo2;

void setup() {
  // Initialize ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Initialize the servo motors
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);

  // Set the servos to their initial position
  servo1.write(90); // Initial position of servo1 (90 degrees)
  servo2.write(90); // Initial position of servo2 (90 degrees)
}

void loop() {
  // Measure the distance
  long distance = getUltrasonicDistance();

  // Check if there's an obstacle closer than 20 cm
  if (distance < distanceThreshold) {
    // Turn servo1 to the left (example: 45 degrees)
    servo1.write(180);
    delay(800); // You can adjust the time for turning left

    // Stop servo1
    servo1.write(180);

    // Turn servo2 to the right (example: 135 degrees)
    servo2.write(180);
    delay(800); // You can adjust the time for turning right

    // Stop servo2
    servo2.write(180);
  } else {
    // Both servos move forward (example: 0 degrees)
    servo1.write(0);
    servo2.write(0);
  }
}

long getUltrasonicDistance() {
  // Generate a 10-microsecond pulse on the Trig pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the pulse on the Echo pin
  long duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters
  long distance = duration * 0.034 / 2;

  return distance;
}
