#ifndef Buzzer_h
#define Buzzer_h

#include "Arduino.h"

short buzzerPin = 13;
bool buz=false;

void buzzerSetup(){

  pinMode(buzzerPin, OUTPUT);


}


void buzzerLoop(){
    if(Serial.available()){
      buz=true;
    }

    if(buz){
      // digitalWrite(buzzerPin, HIGH);
      for(int i = 0; i  < 4; i++){
        digitalWrite(buzzerPin, HIGH);
        delay(200);
        digitalWrite(buzzerPin, LOW);
        delay(200);
      }
      delay(2000);

    }

}


#endif
