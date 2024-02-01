#include <SoftwareSerial.h>

// Define SoftwareSerial object for Bluetooth communication
SoftwareSerial BTSerial(10, 11); // RX, TX

unsigned long previousMillis = 0;
const long interval = 3000; // 3 seconds interval

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);  // Set the baud rate for your Bluetooth module
}

void loop() {
  // Check if it's time to send "AT+COLOR"
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    // Save the current time
    previousMillis = currentMillis;

    // Send "AT+COLOR" to the Bluetooth module
    BTSerial.println("AT+COLOR");
  }

  // Check if data is available from the Bluetooth module
  if (BTSerial.available() > 0) {
    // Read the string from the Bluetooth module
    String incomingString = BTSerial.readString();

    // Extract RGB values from the incoming string
    int r, g, b;
    if (sscanf(incomingString.c_str(), "+COLOR= R:%d G:%d B:%d OK", &r, &g, &b) == 3) {
      // Print the extracted RGB values
      Serial.print(r);
      Serial.print(",");
      Serial.print(g);
      Serial.print(",");
      Serial.println(b);
    }
  }
}
