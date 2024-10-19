/******************************************************************************
 * Projektname:     Arduino Distance Measurement and Touch Display
 * Datei:           EmbeddebLab2.c
 * Ersteller:       Marvin Calmer

 * Beschreibung:    Temperature and Brightness Measurement
 ******************************************************************************/

#include <SPI.h>               // SPI communication library
#include <Adafruit_GFX.h>      // GFX-Grafics
#include <Adafruit_ILI9341.h>  // Display-Library
#include <stdint.h>
#include <Adafruit_ADS1X15.h>

#define YP A0  // must be an analog pin, use "An" notation!
#define XM A2  // must be an analog pin, use "An" notation!
#define YM 8   // can be a digital pin
#define XP 47  // can be a digital pin

Adafruit_ILI9341 tft = Adafruit_ILI9341(46, 47);
Adafruit_ADS1015 ads; 

#define TEMP_MEASURE A4
#define TEMP_REF 19
#define LED_GREEN 9

float temp;
float brightness;

void setup() {
  Serial.begin(9600);
  //initInternalADC();
  initDisplay();
  initADC();
  initADCBrightness();
  initLED();
}

void loop() {
  //MeasureFromInternal();
  MeasureADC();
  MeasureADCBrightness();
  loopDisplay();
  loopLED();
  //delay(500);
}