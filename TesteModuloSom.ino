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
  //Inicializa a serial do Arduino
  Serial.begin(9600);

  //Verifica se o modulo esta respondendo e se o
  //cartao SD foi encontrado
  Serial.println();
  Serial.println(("DFRobot DFPlayer Mini"));
  Serial.println(("Inicializando modulo DFPlayer... (3~5 segundos)"));
  if (!myDFPlayer.begin(mySoftwareSerial))
  {
    Serial.println(F("Nao inicializado"));
    while (true);
  }
  
  Serial.println();
  Serial.println(F("Modulo DFPlayer Mini inicializado!"));
  
  myDFPlayer.volume(17);
  myDFPlayer.EQ(0);
  myDFPlayer.play(-47);

  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
}

void loop()
{
//  toca_alarme();
  
  if(digitalRead(sensor1)){
    Serial.println(1);
    toca_alarme();
  }
  if(digitalRead(sensor2)){
    Serial.println(2);
    toca_alarme();
  }
  if(digitalRead(sensor3)){
    Serial.println(3);
    toca_alarme();
  }

}

void toca_alarme() {
  myDFPlayer.start();
  delay(4500);
}
