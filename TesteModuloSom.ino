#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(5, 6); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

int sensor1 = 9;
int sensor2 = 10;
int sensor3 = 11;

void setup()
{

  mySoftwareSerial.begin(9600);
  Serial.begin(19200);
  delay(5000);
  
  Serial.print("inicializa");
  
  if (!myDFPlayer.begin(mySoftwareSerial))
  {
    while (true);
  }

  Serial.print("inicializado");
  myDFPlayer.volume(14);
  myDFPlayer.EQ(0);
  myDFPlayer.play(-47);
  
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
}

void loop()
{
  myDFPlayer.volume(14); 
  
  if(digitalRead(sensor1)){
    Serial.print("sensor1");
    toca_alarme();
  }
  if(digitalRead(sensor2)){
    Serial.print("sensor2");
    toca_alarme();
  }
  if(digitalRead(sensor3)){
    Serial.print("sensor3");
    toca_alarme();
  }

}

void toca_alarme() {
  myDFPlayer.start();
  delay(5000);
}
