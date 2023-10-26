#include <Arduino.h>
int potpin = 0;

void setup() {
  // Initialize serial communication at a baud rate of 9600
  Serial.begin(9600);
}

void loop() {
  // Read the analog value from the potentiometer on analog pin 0
  int potValue = analogRead(potpin);
  
  // Print the potentiometer value to the serial monitor
  Serial.println(potValue);

  // Add a delay to avoid flooding the serial monitor with data
  delay(50);
}
