#include <Wtv020sd16p.h>

int resetPin = 4;
int clockPin = 5;
int dataPin = 6;
int busyPin = 7;

int sensor1 = 9;
int sensor2 = 10;
int sensor3 = 11;

Wtv020sd16p wtv020sd16p(resetPin,clockPin,dataPin,busyPin);

void setup() {
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  
  //Initializes the module.
  wtv020sd16p.reset();
}

void loop() {
  
  wtv020sd16p.setVolume(5);
  
  if(digitalRead(sensor1)){
    wtv020sd16p.asyncPlayVoice(1);
    delay(4500);
    wtv020sd16p.stopVoice();
  }
  if(digitalRead(sensor2)){
    wtv020sd16p.asyncPlayVoice(1);
    delay(4500);
    wtv020sd16p.stopVoice();
  }
  if(digitalRead(sensor3)){
    wtv020sd16p.asyncPlayVoice(1);
    delay(4500);
    wtv020sd16p.stopVoice();
  }
}


