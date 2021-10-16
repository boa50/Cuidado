#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(5, 6); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

int sensor1 = 9;
int sensor2 = 10;
int sensor3 = 11;

//Para visualizar os prints corretamente é preciso alterar o valor do baud para 19200
//no Serial Monitor (Ctrl + Shift + M)
void setup()
{
  Serial.print("Início do Setup\n");
  
  mySoftwareSerial.begin(9600);
  Serial.begin(19200);
  delay(5000);
  
  Serial.print("Inicialização dos Módulos\n");
  
  if (!myDFPlayer.begin(mySoftwareSerial))
  {
    while (true);
  }

  Serial.print("Inicializado\n");
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
    Serial.print("sensor1\n");
    toca_alarme();
  }
  if(digitalRead(sensor2)){
    Serial.print("sensor2\n");
    toca_alarme();
  }
  if(digitalRead(sensor3)){
    Serial.print("sensor3\n");
    toca_alarme();
  }

}

void toca_alarme() {
  myDFPlayer.start();
  delay(5000);
}
