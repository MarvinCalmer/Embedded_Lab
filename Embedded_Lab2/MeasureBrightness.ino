/******************************************************************************
 * Projektname:     Arduino Distance Measurement and Touch Display
 * Datei:           EmbeddebLab2.c
 * Ersteller:       Marvin Calmer

 * Beschreibung:    Temperature and Brightness Measurement
 ******************************************************************************/
#include <Adafruit_ADS1X15.h>

void initADCBrightness(){
  ads.setGain(GAIN_ONE);
  ads.begin();
}

void MeasureADCBrightness(){
  float brightness_read=ads.readADC_SingleEnded(3);
  brightness=map(brightness_read,0,2047,0,100);
//   Serial.print(brightness_read);
//   Serial.print("\n");
//   Serial.print(brightness);
//   Serial.print("\n");'
}