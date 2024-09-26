#include <SPI.h>                                  // SPI communication library
#include <Adafruit_GFX.h>                         // GFX-Grafics
#include <Adafruit_ILI9341.h>                     // Display-Library
#include <stdint.h>
#include "TouchScreen.h"

#define YP A2  // must be an analog pin, use "An" notation!
#define XM A3  // must be an analog pin, use "An" notation!
#define YM 8   // can be a digital pin
#define XP 9   // can be a digital pin

Adafruit_ILI9341 tft = Adafruit_ILI9341(46, 47);
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

#define LED_GREEN 18                            
#define LED_YELLOW 17                           
#define LED_RED 16                              
#define Trig_Pin 3                                  
#define Echo_Pin 9 


float distance;   
int status;
uint16_t barColor=ILI9341_BLACK;

void setup() 
{
  Serial.begin(9600);  
  initDisplay();                   
  initLed();
  
  

  // initialize digital iputs/outputs
  pinMode(Trig_Pin, OUTPUT);
  pinMode(Echo_Pin, INPUT); 
}

void loop() 
{
  uint32_t tstart, duration;              // Variables for time measurement
  const float vAir=0.0343;   

  loopDisplay(); 
  LoopLED();
  handleButtons();
  delay(100);                             // slow the program down
  
  // Perform distance measurement
  digitalWrite(Trig_Pin, HIGH);           // send trigger to ultrasonic module
  delayMicroseconds(10);                  // Wait for 10 µs
  digitalWrite(Trig_Pin,  LOW);           // ultrasonic module is triggered on falling edge
  while (digitalRead(Echo_Pin) == 0) { }  // wait until echo bin goes HIGH (start time of measurement)
  tstart = micros();                      // save start time
  while (digitalRead(Echo_Pin) == 1) { }  // wait until echo goes LOW again and measure pulse time
  duration = micros()-tstart;             // calculate duration of echo answer
  distance=(duration/2)*vAir;             

  // print the distance to Serial USB
  Serial.println(distance);               // for Serial Monitor or Serial Plotter  
}