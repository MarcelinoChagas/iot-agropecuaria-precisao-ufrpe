// C++ code
// Neste Exemplo, funciona o ligamento de todas os LEDs das Fitas
#include <Adafruit_NeoPixel.h>

#define NUMPIXELS_PER_STRIP 8 	// quantidade de LEDs na fita
#define NUM_STRIPS          8	// numero total de fitas
#define DELAY				100 // tempo de delay entre pixels

typedef struct RGBLED_t {
	uint8_t R;
	uint8_t G;
	uint8_t B;
} RGBLED;


Adafruit_NeoPixel strips[NUM_STRIPS];

const uint8_t PINS[NUM_STRIPS]={2,3,4,5,6,7,8,9};


void setPixel2D(uint8_t x, uint8_t y, struct RGBLED_t ledValues) {

  
}



void setup(){
     // Inicialize cada fita de LED no array
    for (int i = 0; i <= NUM_STRIPS; i++) {
        strips[i] = Adafruit_NeoPixel(NUMPIXELS_PER_STRIP, PINS[i], NEO_GRB + NEO_KHZ800);
        strips[i].begin();
    }

}

void loop(){
  for(int i = 0; i <= NUM_STRIPS;i++){
    uint32_t color = (i % 2 == 0) ? strips[i].Color(255, 0, 0) : strips[i].Color(0, 255, 0);
    
    for (int j = 0; j <= NUMPIXELS_PER_STRIP; j++) {
	    strips[i].setPixelColor(j, color);
    }
    strips[i].show();
    delay(DELAY);
    
  }

}