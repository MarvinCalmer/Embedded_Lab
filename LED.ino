void initLed() {
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT); 
  pinMode(LED_RED, OUTPUT); 
  digitalWrite(LED_GREEN, LOW);   
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_RED, LOW);
}

void LoopLED(){
  if (distance>100){
      status=1;
      digitalWrite(LED_GREEN,  LOW);  
      digitalWrite(LED_YELLOW,  HIGH);
      digitalWrite(LED_RED,  HIGH);
    }
    else if(distance <= 100 && distance > 50){
      status=2;
      digitalWrite(LED_GREEN,  HIGH);  
      digitalWrite(LED_YELLOW,  LOW);
      digitalWrite(LED_RED,  HIGH); 
    }
    else{
      status=3;
      digitalWrite(LED_GREEN,  HIGH);  
      digitalWrite(LED_YELLOW,  HIGH);
      digitalWrite(LED_RED,  LOW);         
      delay(distance*10);                          
      digitalWrite(LED_RED,  HIGH);          
    }
}
