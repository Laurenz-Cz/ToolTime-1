#include <FastLED.h>
#define NUM_LEDS 13
#define DATA_PIN 6

// Define the array of leds
CRGB leds[NUM_LEDS];
void setup() { 
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  
}
void loop() { 
  // Turn the LED on, then pause 
  leds[0]= CRGB::Red;
  leds[1]= CRGB::White;
  leds[2]= CRGB::White;
  leds[3]= CRGB::White;
  leds[4]= CRGB::White;
  leds[5]= CRGB::White;
  leds[6]= CRGB::White;
  leds[7]= CRGB::White;
  leds[8]= CRGB::White;
  leds[9]= CRGB::White;
  leds[10]= CRGB::White;
  leds[11]= CRGB::White;
  leds[12]= CRGB::Green;
  FastLED.show();
  delay(500);
  // Now turn the LED off, then pause
  leds[0]= CRGB::Black;
  leds[12]= CRGB::Black;
  FastLED.show();
  delay(50);
} 
