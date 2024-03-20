// C++ code
//
#include <SoftwareSerial.h>

#define ADC_PIN A0
#define BAUDRATE 9600

int adc_value;

float temperature;

void setup()
{
  Serial.begin(BAUDRATE);
}

void loop()
{
  adc_value = analogRead(ADC_PIN); 
  float voltage = adc_value * (5000.0 / 1024.0);
  temperature = (voltage - 500.0) / 10.0;
  Serial.print("Temperatura: ");
  Serial.print(temperature);
  Serial.println(" C");
  
  delay(5000); // Wait for 5000 millisecond(s)
}
