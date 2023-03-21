#ifndef Display_h
#define Display_h


#include "Arduino.h"
#include <LiquidCrystal.h>  
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);



void displaySetup(){
  lcd.begin(16, 2);
  lcd.clear();
}


void displayLoop(){

}

#endif
