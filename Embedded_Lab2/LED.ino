/******************************************************************************
 * Projektname:     Arduino Distance Measurement and Touch Display
 * Datei:           EmbeddebLab2.c
 * Ersteller:       Marvin Calmer

 * Beschreibung:    Temperature and Brightness Measurement
 ******************************************************************************/
void initLED(){
  pinMode(LED_GREEN, OUTPUT);
}

void loopLED(){
  float outputbrightness = map(brightness,0,100,255,0);
  analogWrite(LED_GREEN, outputbrightness);
}