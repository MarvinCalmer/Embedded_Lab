/******************************************************************************
 * Projektname:     Arduino Distance Measurement and Touch Display
 * Datei:           EmbeddebLab2.c
 * Ersteller:       Marvin Calmer

 * Beschreibung:    Temperature and Brightness Measurement
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
  tft.begin();
  tft.setRotation(1); 
  tft.fillScreen(BLACK);
}

void loopDisplay() {
  tft.setCursor(0, 0);
  tft.setTextColor(ILI9341_WHITE, ILI9341_BLACK);
  tft.setTextSize(1);
  tft.print("Temperature: ");
  tft.print(temp);
  tft.print(" Degrees C    ");
  tft.print("Brightness: ");
  tft.print(brightness);
  tft.print(" %    ");
}

