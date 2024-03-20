// C++ code
//
#define LDR_PIN A0
#define LED_PIN 7

#define LUMINOSITY_THRESHOLD 700

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  pinMode(LDR_PIN,INPUT);
  Serial.begin(9600);
}

void loop()
{
  
  int luminosity = analogRead(LDR_PIN);

  if(luminosity < LUMINOSITY_THRESHOLD){
    digitalWrite(LED_PIN,HIGH);
  } else{
    digitalWrite(LED_PIN,LOW);
  }
  
  delay(1000); // Wait for 1000 millisecond(s)
  
}
