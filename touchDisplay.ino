/******************************************************************************
 * Projektname:     Arduino Distance Measurement and Touch Display
 * Datei:           EmbeddebLab1.c
 * Ersteller:       Marvin Calmer

 * Beschreibung:    Distance Measurement with an Ultrasonic sensor
 ******************************************************************************/
#define X_MIN  129
#define X_MAX  910
#define Y_MIN  137
#define Y_MAX  912

void loopTouch() {
  TSPoint t;                                                // create new TSPoint variable to save not calibrated touch points
  t = ts.getPoint();                                        // read touch points

  if (t.z > ts.pressureThreshhold) {                        // if touch pressure is higher than treshhold it´s a touch event
    touchPoint.x = map(t.y, Y_MIN, Y_MAX, 0, WIDTH);     // calibrate touchScreen point and save it to the global variable
    touchPoint.y = map(t.x, X_MAX, X_MIN, 0, HEIGTH);     // calibrate touchScreen point and save it to the global variable

    // print touch coords to Serial monitor for debugging
    Serial.print("X = "); Serial.print(touchPoint.x);
    Serial.print("\tY = "); Serial.print(touchPoint.y);
    Serial.print("\tPressure = "); Serial.println(t.z);


    if (touchPoint.x > 110 && touchPoint.x < 210 && touchPoint.y > 120 && touchPoint.y < 200) {
      activeMeasurement = 1;
    }
    tft.drawPixel(touchPoint.x,touchPoint.y,0xFFFF);
  }
}