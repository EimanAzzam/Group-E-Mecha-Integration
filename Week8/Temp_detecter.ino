#include <Arduino.h>
#include <BluetoothSerial.h>

#define vRef 3.30
#define ADC_Resolution 4095
#define LM35_Per_Degree_Volt 0.01
#define Zero_Deg_ADC_Value -253.27


BluetoothSerial SerialBT;

const int lm35_pin = 26;                /* Connect LM35 out pin to A0 of ESP32*/
const int led_pin = 13;

char x;


float _temperature, temp_val, ADC_Per_Degree_Val;
int temp_adc_val;

void setup(void){
  Serial.begin(9600);
  SerialBT.begin("Temp_scanner");
  ADC_Per_Degree_Val = (ADC_Resolution/vRef)*LM35_Per_Degree_Volt;

    while (!SerialBT.connected(1000)) 
    {
      delay(1000);
      Serial.println("Waiting for connection...");
    }

  Serial.println("Connected to Bluetooth");

  pinMode(led_pin,OUTPUT);
  digitalWrite(led_pin,LOW);
}

void loop(void){ 
 for (int i = 0; i < 10; i++) {
    temp_adc_val += analogRead(lm35_pin);  /* Read ADC value */
    delay(10);
  }

  x=(char)SerialBT.read();

  temp_adc_val = temp_adc_val/10.0;

  temp_adc_val = temp_adc_val - Zero_Deg_ADC_Value;
  temp_adc_val=(temp_adc_val/ADC_Per_Degree_Val);


  SerialBT.print("Temperature = ");
  SerialBT.print(temp_adc_val);           /* Print Temperature on the serial window */
  SerialBT.println("°C\n");
  Serial.println(x);
  delay(100);

  if(x =='a')
  {
    digitalWrite(led_pin,HIGH);
  }
  else if(x=='b')
  {
    digitalWrite(led_pin,LOW);
  }
}