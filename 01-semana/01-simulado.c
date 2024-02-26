// C++ code
//

#define LED_PIN 9


void setup()
{
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  digitalWrite(LED_PIN, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(LED_PIN, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}