/******************************************************************************
 * Projektname:     Arduino Distance Measurement and Touch Display
 * Datei:           EmbeddebLab2.c
 * Ersteller:       Marvin Calmer

 * Beschreibung:    Temperature and Brightness Measurement
 ******************************************************************************/
void initInternalADC(){
  pinMode(TEMP_MEASURE, INPUT);
  pinMode(TEMP_REF, OUTPUT);
  digitalWrite(TEMP_REF,HIGH);
}

void MeasureFromInternal(){
  float temp_read=analogRead(TEMP_MEASURE);
  float tempVoltage=temp_read/1023*5000;  // COnvert to Voltage based on 10 BIT ADC 2^10= 1024
  float absolutTemp=tempVoltage/10.0;     // Convert to absolut Reading based on Sheet
  temp=absolutTemp-273;                   // Convert to actual temp
  // Serial.print(temp);
  // Serial.print("\n");
}