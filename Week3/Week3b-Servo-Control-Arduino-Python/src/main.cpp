#include <Arduino.h>
#include <Servo.h>

Servo servo;
int angle = 90;
void setup() {
  Serial.begin(9600);
  servo.attach(9); // Attach the servo to dig. pin 9
}
void loop() {
if (Serial.available() >0) {
  angle = Serial.parseInt();
}
servo.write(angle); // Set to the desired angle
// delay(1000); // Wait for 1 second
// angle = 180 - angle; // Reverse the angle
}