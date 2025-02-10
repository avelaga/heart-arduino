#include <FastLED.h>

#define NUM_LEDS 256
#define DATA_PIN 13

int brightness = 0;
float hue = 0;
float inc = 0;
float hueInc = .3;
int size = 16;

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
  drawHeart();
}

void drawHeart() {
  for (int row = 0; row < 16; row++) {
    for (int col = 0; col < 16; col++) {
      if(heart[row][col] == 1){
        if(row%2 == 1){ // IDK WHY THE OFF ROWS ARE ALL OFF BY ONE SO IM JUST COMPENSATING FOR THAT WITH THIS
          leds[(col-1)+(row*16)]=CRGB(0,10,0);
        } else{
            leds[(col)+(row*16)]=CRGB(0,10,0);
        }
        
      }
      else {
        leds[(col)+(row*16)]=CRGB(0,0,0);
      }
    }
  }
   FastLED.show();
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
  // hue = inc;
  // inc += .5;

  // for (int i = 0; i < NUM_LEDS; i++) {
  //   leds[i] = CHSV(hue, 255, 255);
  //   hue += .5; // incremenration of hues in the strip
  // }

  // FastLED.show();
}