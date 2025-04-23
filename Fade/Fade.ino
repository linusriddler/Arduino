/*
  Fade

  This example shows how to fade an LED on pin 9 using the analogWrite()
  function.

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/basics/Fade/
*/

const int ledPins[] = {6, 9, 10, 11}; // PWM-capable pins
const int numLeds = sizeof(ledPins) / sizeof(ledPins[0]);
const int fadeDelay = 10; // Delay between brightness changes
const int fadeAmount = 5; // Brightness increment/decrement

void setup() {
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < numLeds; i++) {
    // Fade in
    for (int brightness = 0; brightness <= 255; brightness += fadeAmount) {
      analogWrite(ledPins[i], brightness);
      delay(fadeDelay);
    }
    // Fade out
    for (int brightness = 255; brightness >= 0; brightness -= fadeAmount) {
      analogWrite(ledPins[i], brightness);
      delay(fadeDelay);
    }
  }
}
