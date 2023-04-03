#ifndef Buzzer_h
#define Buzzer_h

#include "Arduino.h"

short buzzerPin = A2;
bool buzz = false;
bool buzNow = false;

void buzzerSetup()
{

  pinMode(buzzerPin, OUTPUT);
}



void buzzerLoop()
{
  if (buzz)
  {
    if (buzNow)
    {
      digitalWrite(buzzerPin, HIGH);
      Serial.println("Buz Now");
    }
    else
    {
      digitalWrite(buzzerPin, LOW);
    }
    buzNow = not buzNow;
  }
  else
  {
    digitalWrite(buzzerPin, LOW);
  }
}


    void test_buzzer(){
        buzz=true;
    }

      void  turn_off_buzzer(){
        buzz=false;
      }

#endif
