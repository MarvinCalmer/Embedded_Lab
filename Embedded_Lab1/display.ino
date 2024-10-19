/******************************************************************************
 * Projektname:     Arduino Distance Measurement and Touch Display
 * Datei:           EmbeddebLab1.c
 * Ersteller:       Marvin Calmer

 * Beschreibung:    Distance Measurement with an Ultrasonic sensor
 ******************************************************************************/
#include <Adafruit_GFX.h>
#include <Adafruit_GrayOLED.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>

// Color definitions
#define BLACK 0x0000
#define BLUE 0x001F
#define RED 0xF800
#define GREEN 0x07E0
#define CYAN 0x07FF
#define MAGENTA 0xF81F
#define YELLOW 0xFFE0
#define WHITE 0xFFFF

#define WIDTH 320
#define HEIGTH 240

void initDisplay() {
  initUI();
}

void loopDisplay() {
  tft.setCursor(0, 0);
  tft.setTextColor(ILI9341_WHITE, ILI9341_BLACK);
  tft.setTextSize(2);
  tft.print("Distance: ");
  tft.print(distance);
  tft.print(" cm    ");
  tft.drawRect(5, 215, 310, 20, WHITE);
  tft.fillRect(8, 218, distance / 1024.0 * 300, 14, WHITE);
  tft.fillRect(map(distance, 0, 500, 0, 300) + 8, 218, 305 - map(distance, 0, 500, 0, 300), 14, WHITE);
}


void initUI(){
  tft.begin();
  tft.setRotation(1); 
  tft.fillScreen(BLACK);
  tft.drawRect(110, 120, 100, 80, WHITE);
}

void handleButtons() {
    switch (status) {
      case 1: 
              tft.drawRect(110, 120, 100, 80, GREEN);
              tft.fillRect(110, 120, 100, 80, ILI9341_GREEN);
              break;
      case 2: 
              tft.drawRect(110, 120, 100, 80, YELLOW);
              tft.fillRect(110, 120, 100, 80, YELLOW);
              break;
      case 3: 
              tft.drawRect(110, 120, 100, 80, RED);
              tft.fillRect(110, 120, 100, 80, RED);
              break;
      default:;
    }
}