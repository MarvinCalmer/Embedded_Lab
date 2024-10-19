/******************************************************************************
 * Projektname:     Arduino Distance Measurement and Touch Display
 * Datei:           EmbeddebLab1.c
 * Ersteller:       Marvin Calmer

 * Beschreibung:    Distance Measurement with an Ultrasonic sensor
 ******************************************************************************/
void initDistance() {
  pinMode(Trig_Pin, OUTPUT);
  pinMode(Echo_Pin, INPUT);
}

void loopMeasure(){
  uint32_t tstart, duration;              // Variables for time measurement
  const float vAir=0.0343;   
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
