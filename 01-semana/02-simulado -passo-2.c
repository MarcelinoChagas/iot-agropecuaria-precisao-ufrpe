// C++ code
//
#include <Adafruit_NeoPixel.h>

#define NUMPIXELS_PER_STRIP 8 	// quantidade de LEDs na fita
#define NUM_STRIPS          8	// numero total de fitas
#define DELAY				100 // tempo de delay entre pixels

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

// Setamos que a primeira Fita de LED começe da Esquerda para Direita
// Logo do pino 9 ao 2
const uint8_t PINS[NUM_STRIPS]={9,8,7,6,5,4,3,2};


void setPixel2D(uint8_t x, uint8_t y, struct RGBLED_t ledValues) {
  
  // Verifica se as coordenadas estão dentro dos limites das fitas
  if(x >= NUM_STRIPS || y >= NUMPIXELS_PER_STRIP){
    return; // Se estiver fora do limite, sai da função.
  }
	

  // Define a cor do LED apenas na posição (x,y) em cada fita.
  for (int i = 0; i < NUM_STRIPS; i++) {
    // Verifica se estamos na fita correta
    if (i == x) {
  	  // Seta a cor GREEN na respectiva fita e no respectivo LED. (x,y)
      strips[i].setPixelColor(y, strips[i].Color(ledValues.R, ledValues.G, ledValues.B));
      
      strips[i].show();  // Atualiza a fita de LED para exibir a nova cor
    }
  }
  
}



void setup(){
    // Inicialize cada fita de LED no array
  
    for (int i = 0; i < NUM_STRIPS; i++) {
        strips[i] = Adafruit_NeoPixel(NUMPIXELS_PER_STRIP, PINS[i], NEO_GRB + NEO_KHZ800);
        strips[i].begin();
    }
}

void loop(){
  	setPixel2D(4,5,GREEN);
    delay(DELAY);

}