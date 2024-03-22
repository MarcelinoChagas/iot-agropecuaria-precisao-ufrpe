// C++ code
//
const uint8_t LED_PIN = 7; // Pino do LED
const uint8_t INTERRUPT_PIN = 2; // Pino onde o botão está conectado
bool LED_STATE = LOW;	// Estado atual do LED
volatile int buttonCounter = 0; // Contador de eventos do botão
unsigned long lastPrintTime = 0;

void setup()
{
  pinMode(LED_PIN, OUTPUT); // Configura o pino do LED como saída
  pinMode(INTERRUPT_PIN, INPUT_PULLUP); // Configura o pino do botão como entrada com pull-up
  attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN),buttonISR,FALLING); // Configura a interrupção no pino do botão
  Serial.begin(9600); // Inicia a comunicação serial
}

void loop()
{
  unsigned long currentTime = millis();  // Obtém o tempo atual em milissegundos
  
  digitalWrite(LED_PIN,LED_STATE);
  // Verifica se passaram 5 segundos desde a última impressão e imprime o valor do contador

  if (currentTime - lastPrintTime >= 5000)
  {
    Serial.print("Contagem do botao: ");
    Serial.println(buttonCounter);
    lastPrintTime = currentTime;
  }
}

// Função de serviço da interrupção do botão
void buttonISR()
{
  buttonCounter++;  // Incrementa o contador de eventos do botão
  digitalWrite(LED_PIN, LED_STATE); // Acende o LED
  delay(100);
  LED_STATE = !LED_STATE; // Alterna o estado do LED
}
