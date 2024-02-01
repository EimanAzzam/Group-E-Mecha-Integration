#include <Pixy.h>
Pixy pixy;

const int red=8;
const int green=9;
const int blue=10;

void setup() {
 Serial.begin(9600);
 pixy.init();

 pinMode(red,OUTPUT);
 pinMode(green,OUTPUT);
 pinMode(blue,OUTPUT);
}
void loop() {
 int blocks = pixy.getBlocks();
 if (blocks) {
 // Loop through detected blocks
 for (int i = 0; i < blocks; i++) {
 Serial.print("Block ");
 Serial.print(i);
 Serial.print(": ");
 Serial.print("Signature: ");
 Serial.print(pixy.blocks[i].signature);
 Serial.print(" X: ");
 Serial.print(pixy.blocks[i].x);
 Serial.print(" Y: ");
 Serial.println(pixy.blocks[i].y);

 // Add logic to identify and react based on the color signature
 if (pixy.blocks[i].signature == 1) {
 // Object with signature 1 detected (Color 1)
 // Add your action or code here
  digitalWrite(red,HIGH);
  digitalWrite(green,LOW);
  digitalWrite(blue,LOW);
 } else if (pixy.blocks[i].signature == 2) {
 // Object with signature 2 detected (Color 2)
 // Add your action or code here
   digitalWrite(red,LOW);
  digitalWrite(green,HIGH);
  digitalWrite(blue,LOW);
 } else if (pixy.blocks[i].signature == 3) {
 // Object with signature 3 detected (Color 3)
 // Add your action or code here
   digitalWrite(red,LOW);
  digitalWrite(green,LOW);
  digitalWrite(blue,HIGH);
 }
 }
 }
}
