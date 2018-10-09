#include <Adafruit_NeoPixel.h>
#define PIN 6
#define NUM_LEDS 8
// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

// *** REPLACE FROM HERE ***
void loop() {

      strip.setPixelColor(0, 255, 0, 0);  
      strip.show();
      delay(100);
      strip.setPixelColor(1, 0255, 255, 0);
            strip.show();
      delay(100);
      strip.setPixelColor(2, 0, 255, 0);
            strip.show();
      delay(100);
      strip.setPixelColor(3, 0,128, 128);
            strip.show();
      delay(100);
      
      strip.setPixelColor(4, 0, 0, 255);
            strip.show();
      delay(100);
      strip.setPixelColor(5, 128, 0, 128);
            strip.show();
      delay(200);
      strip.setPixelColor(7, 90,90,90);
            strip.show();
      delay(800);

      for(int i=0; i<NUM_LEDS; i++){
        strip.setPixelColor(i, 0,0,0);
        strip.show();
      }

delay(1000);
}


