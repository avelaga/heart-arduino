#include <FastLED.h>

#define NUM_LEDS 256
#define DATA_PIN 13
#define SCALE 2000

int brightness = 0;
float hue = 0;
float inc = 0;
float hueInc = .3;
int size = 16;
float c = 0;

CRGB leds[NUM_LEDS];
int heart[16][16] = 
  {
    {0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0},
    {0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0},
    {0,0,1,1,1,1,1,1,0,1,1,1,1,1,1,0},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0},
    {0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
  };

void setup() {
  FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);
  LEDS.setBrightness(100);
}

void drawHeart() {
  for (int row = 0; row < 16; row++) {
    for (int col = 0; col < 16; col++) {
      uint16_t  noiseVal = inoise8(row * SCALE, col * SCALE, c);
      float mappedNoise = map(noiseVal, 0 , 255, 0, 150);
      float mappedBlue = map(noiseVal, 0 , 255, 0, 30);
      // if (mappedNoise<0){
      //   mappedNoise = 10;
      // }
      if(heart[row][col] == 1){
        if(row%2 == 1){ // IDK WHY THE ODD ROWS ARE ALL OFF BY ONE SO IM JUST COMPENSATING FOR THAT WITH THIS
          leds[(col-1)+(row*16)]=CRGB(0,mappedNoise,mappedBlue);
        } else{
            leds[(col)+(row*16)]=CRGB(0,mappedNoise,mappedBlue);
        }
        
      }
      else {
        leds[(col)+(row*16)]=CRGB(0,0,0);
      }
    }
  }
   FastLED.show();
   c += 4;
}

// void bootUp() {
//   while (brightness < 255) {
//     LEDS.setBrightness(brightness);
//     loop();
//     brightness += 1;
//     delay(5);
//   }
// }

void loop() {
  drawHeart();
  // hue = inc;
  // inc += .5;

  // for (int i = 0; i < NUM_LEDS; i++) {
  //   leds[i] = CHSV(hue, 255, 255);
  //   hue += .5; // incremenration of hues in the strip
  // }

  // FastLED.show();
}