/******************************************************************************
 * Projektname:     Arduino Distance Measurement and Touch Display
 * Datei:           EmbeddebLab2.c
 * Ersteller:       Marvin Calmer

 * Beschreibung:    Temperature and Brightness Measurement
 ******************************************************************************/
#include <Adafruit_ADS1X15.h>

void initADC(){
  pinMode(TEMP_REF, OUTPUT);
  digitalWrite(TEMP_REF,LOW);
  ads.setGain(GAIN_ONE);
  ads.begin();
}

void MeasureADC(){

  digitalWrite(TEMP_REF,HIGH);
  delay(1);
  float temp_read=ads.readADC_SingleEnded(0);
  digitalWrite(TEMP_REF,LOW);
  float tempVoltage=temp_read*2 ;     // COnvert to Voltage based on 12 BIT ADC 2^10= 4096
  float absolutTemp=tempVoltage/10.0;     // Convert to absolut Reading based on Sheet
  temp=absolutTemp-273.15;                   // Convert to actual temp

  // Serial.print(temp_read);
  // Serial.print("\n");
  // Serial.print(temp);
  // Serial.print("\n");
}