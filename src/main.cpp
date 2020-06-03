using namespace std;

#include <Arduino.h>
#include <BUZZER.h>

#define speaker 10
#define led 12
#define sensor 11

BUZZER *Buzzer = new BUZZER(speaker);

void setup() {
  Serial.begin(115200);
  Buzzer->setEnable(true);

  pinMode(speaker, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(sensor, INPUT_PULLUP);
  delay(500);
  

  for (size_t i = 0; i < 10; i++) {
    Serial.print(".");
    digitalWrite(led,!digitalRead(led));
    delay(200);
  }
  Serial.print(".");
  Serial.println(" Ready!");
  Buzzer->question(1000);  
}

void morreu() {
  digitalWrite(led, HIGH);
  Buzzer->cancel(2000);
  Buzzer->question(200); 
  digitalWrite(led, LOW); 
}

void loop() {
  int sensorValue = digitalRead(sensor);
  Serial.println(sensorValue);
    
  if(sensorValue == 0) {
    morreu();
  }
}