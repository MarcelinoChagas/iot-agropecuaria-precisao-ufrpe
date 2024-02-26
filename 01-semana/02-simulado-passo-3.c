// C++ code
//
#include <Adafruit_NeoPixel.h>

#define NUMPIXELS_PER_STRIP 8 	// quantidade de LEDs na fita
#define NUM_STRIPS          8	// numero total de fitas
#define DELAY				1000 // tempo de delay entre pixels
#define SWITCH_PIN          13  // pino do switch

typedef struct RGBLED_t {
	uint8_t R;
	uint8_t G;
	uint8_t B;
} RGBLED;

const RGBLED VIOLET = {148, 0, 211};
const RGBLED INDIGO = {75, 0, 130};
const RGBLED BLUE   = {0, 0, 255};
const RGBLED GREEN  = {0, 255, 0};
const RGBLED YELLOW = {255, 255, 0};
const RGBLED ORANGE = {255, 127, 0};
const RGBLED RED    = {255, 0, 0};
const RGBLED WITHE	= {255,255,255};


Adafruit_NeoPixel strips[NUM_STRIPS];

// Setamos que a primeira Fita de LED começe da Esquerda para Direita (0,0)
// Logo do pino 9 ao 2
const uint8_t PINS[NUM_STRIPS]={9,8,7,6,5,4,3,2};


void setStairs(struct RGBLED_t ledDesligado,struct RGBLED_t ledLigado){
  
  
  bool statePino = digitalRead(13);

  for(int x = 0; x < NUM_STRIPS;x++) {
    for(int y = 0; y < NUMPIXELS_PER_STRIP; y++){
      
      // X representa a Fita, Y Representa o LED da fita X.
      // Exemplo: (Fita x=1, y =1 ) Logo vai acender na fita 1 os led de 0..1
      // Lembrando que a contagem inicia apartir de 0.
      if(y <= x){
        // Se o estato do pino for HIGH (1), liga a cor GREEN
        if(statePino){     
          strips[x].setPixelColor(y,strips[x].Color(ledDesligado.R, ledDesligado.G, ledDesligado.B));
        } else{
        // Se o estado do pino for LOW (0), liga a cor RED
          strips[x].setPixelColor(y,strips[x].Color(ledLigado.R, ledLigado.G, ledLigado.B));
        }
     
      } else{
        // Apaga o LED se não estiver na "Stair"
        strips[x].setPixelColor(y,strips[x].Color(0,0,0));
      }
      strips[x].show();
    }
  }
  delay(DELAY);
}


void setup(){
  
    // Inicialize cada fita de LED no array
    for (int i = 0; i < NUM_STRIPS; i++) {
        strips[i] = Adafruit_NeoPixel(NUMPIXELS_PER_STRIP, PINS[i], NEO_GRB + NEO_KHZ800);
        strips[i].begin();
    }
  	
    // Configura o pino digital 13 como saida.
  	pinMode(SWITCH_PIN,OUTPUT);
  
}

void loop(){
  	
    // Inicio a função passando a cor LIGADA e DESLIGADA
    setStairs(RED,GREEN);
    delay(DELAY);
}