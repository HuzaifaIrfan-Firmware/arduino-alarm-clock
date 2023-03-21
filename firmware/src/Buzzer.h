#ifndef Buzzer_h
#define Buzzer_h

#include "Arduino.h"

short buzzerPin = 13;
bool buzNow=false;

void buzzerSetup(){

  pinMode(buzzerPin, OUTPUT);


}


void buzzerLoop(){
    if(Serial.available()){
      buzNow=true;
    }

    if(buzNow){
      // digitalWrite(buzzerPin, HIGH);
      for(int i = 0; i  < 4; i++){
        digitalWrite(buzzerPin, HIGH);
        delay(200);
        digitalWrite(buzzerPin, LOW);
        delay(200);
      }


    }

}


#endif
