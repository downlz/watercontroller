#define Water_Level_Sensor 2 
int relayPin = 10;   
int counter = 0;
int buttonState = 1; // variable for reading the pushbutton status

void setup() { 
  Serial.begin(9600); 
  pinMode(Water_Level_Sensor, INPUT);
  pinMode(relayPin,OUTPUT);
  digitalWrite(relayPin,HIGH);
}

void loop() {
  buttonState = digitalRead(Water_Level_Sensor); 
  //Serial.println("Bottom State:");
//  Serial.println(buttonState);
//  if (buttonState == HIGH) { 
//    Serial.println("EMPTY");
//  }
//  else if (buttonState == LOW) {
//    Serial.println("FULL");
//  }
//  else {
//    Serial.println("UNKNOWN");
//  }
  Serial.println(buttonState);
  
  if (buttonState == HIGH) { 
    Serial.println("WATER LEVEL - LOW.Send Signal to relay");
    counter = counter + 1;
    if (counter > 5) {
    if (digitalRead(relayPin) == HIGH){
        counter = 0;
        Serial.println("System Stablized.Pump will start now");
        Serial.println(digitalRead(relayPin));
        //delay(2000);
        digitalWrite(relayPin,LOW);
        Serial.println(digitalRead(relayPin));
        delay(660000); //Actual Timing
//        delay(5000); //For testing
        digitalWrite(relayPin,HIGH);
        //delay(5000); //For testing
        Serial.println(digitalRead(relayPin));
    }    
  } 
  }
  
  else {
      Serial.println(digitalRead(relayPin)); 
      Serial.println( "WATER LEVEL - HIGH.Start not required" );
      counter = 0;
  }
  delay(5000);    
}
