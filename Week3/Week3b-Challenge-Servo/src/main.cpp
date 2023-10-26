#include <Arduino.h>
#include <Servo.h>

// Create a servo object
Servo myservo;

// Define the analog pin for the potentiometer
int potentiometerPin = A0;

// Variables to store the potentiometer value and the mapped servo position
int potValue;
int servoPosition = -1;
int currentServoPosition;
void setup() {
  // Attach the servo to pin 9
  myservo.attach(9);
  Serial.begin(9600);
}

void loop() {
  // Read the potentiometer value
  potValue = analogRead(potentiometerPin);

  // Map the potentiometer value (0-1023) to the servo angle range (0-180)
  currentServoPosition = map(potValue, 0, 1023, 0, 180);

  // Set the servo position based on the mapped potentiometer value
  myservo.write(servoPosition);

  // Send the servo angle over the serial port only when there's a significant change
  if (currentServoPosition != servoPosition) {
    servoPosition = currentServoPosition;
    Serial.println(servoPosition);
  }

  // A short delay to stabilize the servo
  delay(15);
}