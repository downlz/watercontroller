/*Pump Controller 
Date: 7th Sep 2017
Author: AUGMENTO
Model:1
Two Float sensor at D2,D3.One Intellisense LED at D8,One LED for all time system status
*/

#define Water_Level_Sensor_Buttom 2 
#define Water_Level_Sensor_Top 3 
int relayPin = 10;   
int counter = 0;
int ledPin = 8;
int buttonStateButtom = 1; // variable for reading the pushbutton status
int buttonStateTop = 1; // variable for reading the pushbutton status

void setup() { 
  Serial.begin(9600); 
  pinMode(Water_Level_Sensor_Buttom, INPUT);
  pinMode(Water_Level_Sensor_Top, INPUT);
  pinMode(relayPin,OUTPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(relayPin,HIGH);
}

void loop() {
  if (digitalRead(ledPin) == HIGH) {
    digitalWrite(ledPin, LOW);
  }
  buttonStateButtom = digitalRead(Water_Level_Sensor_Buttom); 
  buttonStateTop = digitalRead(Water_Level_Sensor_Top); 
  if (buttonStateButtom == HIGH && buttonStateTop == HIGH) { 
    counter = counter + 1;
    if (counter > 6) {
    if (digitalRead(relayPin) == HIGH){
        digitalWrite(relayPin,LOW);
    }    
  }
    delay(5000); 
  }
  else if (buttonStateButtom == HIGH && buttonStateTop == LOW) { 
    digitalWrite(ledPin, HIGH);
    delay(2000);
    digitalWrite(ledPin, LOW);
    delay(2000);
    counter = 0;
    if (digitalRead(relayPin) == LOW) {
      digitalWrite(relayPin,HIGH);
    }
  }
  else if (buttonStateButtom == LOW && buttonStateTop == LOW) { 
    if (digitalRead(relayPin) == LOW) {
      digitalWrite(relayPin,HIGH);
    }
    digitalWrite(ledPin, HIGH);
    delay(10000);
    digitalWrite(ledPin, LOW);
    delay(10000);
    counter = 0; 
  }
  else if (buttonStateButtom == LOW && buttonStateTop == HIGH) { 
    counter = 0; 
    delay(5000);
  }
  else {
    if (digitalRead(relayPin) == LOW) {
      digitalWrite(relayPin,HIGH);
    }
      counter = 0;
      delay(5000);
  } 
}

