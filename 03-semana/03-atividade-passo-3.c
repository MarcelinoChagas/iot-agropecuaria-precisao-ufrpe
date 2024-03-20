// C++ code
//
#include <SoftwareSerial.h>

#define ADC_PIN A0
#define BLUE_LED 8
#define GREEN_LED 9
#define RED_LED 10
#define BAUDRATE 9600

int adc_value;

float temperature;

void setup()
{
  Serial.begin(BAUDRATE);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
}

void loop()
{
  adc_value = analogRead(ADC_PIN); 
  float voltage = adc_value * (5000.0 / 1024.0);
  temperature = (voltage - 500.0) / 10.0;
  Serial.print("Temperatura: ");
  Serial.print(temperature);
  Serial.println(" C");
  
  if (temperature < 18) {
    digitalWrite(BLUE_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, LOW);
  } else if (temperature >= 18 && temperature <= 30) {
    digitalWrite(BLUE_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
  } else {
    digitalWrite(BLUE_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);
  }
  
  
  delay(5000); // Wait for 5000 millisecond(s)
}
