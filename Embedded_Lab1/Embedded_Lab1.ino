/******************************************************************************
 * Projektname:     Arduino Distance Measurement and Touch Display
 * Datei:           EmbeddebLab1.c
 * Ersteller:       Marvin Calmer

 * Beschreibung:    Distance Measurement with an Ultrasonic sensor
 ******************************************************************************/

#include <SPI.h>                                  // SPI communication library
#include <Adafruit_GFX.h>                         // GFX-Grafics
#include <Adafruit_ILI9341.h>                     // Display-Library
#include <stdint.h>
#include "TouchScreen.h"

#define YP A0                                       // must be an analog pin, use "An" notation!
#define XM A2                                       // must be an analog pin, use "An" notation!
#define YM 8                                        // can be a digital pin
#define XP 47                                       // can be a digital pin

Adafruit_ILI9341 tft = Adafruit_ILI9341(46, 47);

#define LED_GREEN 18                            
#define LED_YELLOW 17                           
#define LED_RED 16                              
#define Trig_Pin 3                                  
#define Echo_Pin 9 

TouchScreen ts = TouchScreen(47, A0, A2, 8, 300);
TSPoint touchPoint; 

float distance;   
int status=2;
int activeMeasurement=0;

void setup() 
{
  Serial.begin(9600);  
  initDisplay();                   
  initLED();
  initDistance();
}

void loop() 
{
  loopTouch();
  LoopLED();
  loopDisplay(); 
  handleButtons();
  if(activeMeasurement==1){
    loopMeasure();
  }
}