/*
 * This program demonstrates controlling a non-addressable 12VDC 5050 RGB LED light strip using an P9813 based LED strip 
 * driver module.  To make  building an interface to the module easy, an app was developed using MIT's AppInventor (link 
 * to the app below).  The Android app establishes a connection to an Arduino equipped with a Bluetooth module, and permits
 * easy control of the LED strip using a combination of sliders and buttons. 
 * 
 * Commands received via Bluetooth are used to control the LED strip, allowing custom colors to be chosen in either RGB or
 * HCV format, as well as selecting between turning the strip on and off, breathing, and blinking modes.
  *
 * Download the android app at https://drive.google.com/open?id=0B8rKcOSD8CvQOF8wYVl2bXlnVWc.
 * If you have concerns about installing an app from an unknown source, you can also visit the MIT AppInventor website at
 * http://ai2.appinventor.mit.edu.
 * Once there, you can download the AppInventor source code from https://drive.google.com/open?id=0B8rKcOSD8CvQWkRCeWNBV1VXOWc,
 * and view the source code before installing, or use the browser based IDE and AI Companion to run the app.
*/


#include "FastLED.h"            // https://github.com/FastLED/FastLED
//#include <AltSoftSerial.h>      // https://github.com/PaulStoffregen/AltSoftSerial

/*
 * A special thank you to Paul Ruinelli, whose RGB to HSV code snippet
 * (http://www.ruinelli.ch/rgb-to-hsv) simplified this project.  Sample code at the 
 * link provides easy transformation from RGB to HSV and vice versa.
 */

struct RGB_set {         // structs to store the RGB and HSV values:
  unsigned char r;
  unsigned char g;
  unsigned char b;
} RGB_set;

struct HSV_set {
  signed int h;
  unsigned char s;
  unsigned char v;
} HSV_set;


#define NUM_LEDS 1       // Since the LEDs in my RGB LED strip are NOT individually addressable, and 
                         // are being controlled with a P9813 based module, there is only '1' LED

#define DATA_PIN 5       // Clock and data pins for LED data
#define CLOCK_PIN 4


CRGB leds[NUM_LEDS];                // Define LED object
//AltSoftSerial blueToothSerial;      // Define BlueTooth object

char BTstring[50];                  // Bluetooth string
int index = 0;                      // Current length of incoming Bluetooth string

// various program control variables
int cycleTime =  10;                
int blinkTime = 1000;
byte mode = 1;
boolean randomColor = true;
boolean RGBMode;
boolean on = false;

// variables for holding color data in several differnt forms
int hue, saturation, brightness;
int colorTable[3];
struct RGB_set C_RGB;
struct HSV_set HSV;


void setup() {
  delay(2000);
  LEDS.addLeds<P9813, DATA_PIN, CLOCK_PIN>(leds, NUM_LEDS);  // initialize LED control object
  //Serial.begin(115200);
//  blueToothSerial.begin(57600);                              // Initalize Bluetooth object
}

void loop() 
{
//      if (strstr(BTstring, "Breathe: ")) {   // If the string contains "breathe" data, set the mode to breathe
//        mode = 1;
//        cycleTime = atoi(BTstring + 9);
//      }
                                              // If there isn't any new text received via BlueTooth, or a complete command has been received,
                                                    // either change the RGB display mode appropriately, or loop through the current display mode
                                                    
    if (randomColor) {                              // If the current display mode chooses a color at random, choose a color at random
      hue = random(256);
      saturation = random(256);
      brightness = 48 + random(208);
      leds[0].setHSV(hue, 255, 255); // full power

    }
    else if (RGBMode) {                             // If if current mode ISN'T random, set the color data using either the RGB or HSV data  
      C_RGB.r = colorTable[0];
      C_RGB.g = colorTable[1];
      C_RGB.b = colorTable[2];
      leds[0] = CRGB(colorTable[0] , colorTable[1] , colorTable[2]);

      RGB2HSV(C_RGB, &HSV);                         // Translate RGB to HSV for use by the "breathe" mode, using Paul Ruinelli's transformation function below 
      hue = HSV.h * 0.7103;
      saturation = HSV.s;
      brightness = HSV.v;
    }
    else if (!RGBMode) {
      hue = round(colorTable[0] * 0.7103);
      saturation = round(colorTable[1] * 2.55);
      brightness = round(colorTable[2] * 2.55);
      leds[0].setHSV(hue, saturation, brightness);
    }

    mode = 3;
    switch (mode) {               // Execute code depending on the current display mode 
      case 0:                     // If the "off" mode is selected, turn off the LEDs
        on = false;
        leds[0] = CRGB::Black;  
        FastLED.show();
        break;
        
      case 1:                     // If the "breathe" mode is chosen, loop through the brighness, increasing, then decreasing it
        on = false;               // at the chosen cycle speed
        for (int w = 40; w < brightness; w++) {
          leds[0].setHSV(hue, saturation, w);
          FastLED.show();
          delay(cycleTime * (230 / (brightness - 40)));
        }
        for (int w = brightness; w > 40; w--) {
          leds[0].setHSV(hue, saturation, w);
          FastLED.show();
          delay(cycleTime * (230 / (brightness - 40)));
        }
        break;  
      case 2:                     // If the "blink" mode is chosen, alternate between displaying the selected color and turning      
        on = false;               // off the LEDs
        FastLED.show();
        delay(blinkTime);
        leds[0] = CRGB::Black;
        FastLED.show();
        delay(blinkTime);
        break;
      case 3:                     // if the "on" mode is chosen, check to see if the LEDs are already on, and if they aren't,
        if (!on) 
          FastLED.show();  // turn them on
        on = true;
        delay(blinkTime);
        FastLED.show();
        break;
    }
}

/*******************************************************************************
 * Function RGB2HSV
 * Description: Converts an RGB color value into its equivalent in the HSV color space.
 * Copyright 2010 by George Ruinelli
 * The code I used as a source is from http://www.cs.rit.edu/~ncs/color/t_convert.html
 * Parameters:
 *   1. struct with RGB color (source)
 *   2. pointer to struct HSV color (target)
 * Notes:
 *   - r, g, b values are from 0..255
 *   - h = [0,360], s = [0,255], v = [0,255]
 *   - NB: if s == 0, then h = 0 (undefined)
 ******************************************************************************/
void RGB2HSV(struct RGB_set C_RGB, struct HSV_set *HSV) {
  unsigned char min, max, delta;

  if (C_RGB.r < C_RGB.g)min = C_RGB.r; else min = C_RGB.g;
  if (C_RGB.b < min)min = C_RGB.b;

  if (C_RGB.r > C_RGB.g)max = C_RGB.r; else max = C_RGB.g;
  if (C_RGB.b > max)max = C_RGB.b;

  HSV->v = max;                // v, 0..255

  delta = max - min;                      // 0..255, < v

  if ( max != 0 )
    HSV->s = (int)(delta) * 255 / max;      // s, 0..255
  else {
    // r = g = b = 0        // s = 0, v is undefined
    HSV->s = 0;
    HSV->h = 0;
    return;
  }

  if ( C_RGB.r == max )
    HSV->h = (C_RGB.g - C_RGB.b) * 60 / delta;    // between yellow & magenta
  else if ( C_RGB.g == max )
    HSV->h = 120 + (C_RGB.b - C_RGB.r) * 60 / delta; // between cyan & yellow
  else
    HSV->h = 240 + (C_RGB.r - C_RGB.g) * 60 / delta; // between magenta & cyan

  if ( HSV->h < 0 )
    HSV->h += 360;
}


