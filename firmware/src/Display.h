#ifndef Display_h
#define Display_h


#include "Arduino.h"
#include <LiquidCrystal.h>  
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);


byte Bell[] = {
  B00100,
  B01110,
  B01110,
  B01110,
  B11111,
  B00000,
  B00100,
  B00000
};

void displaySetup(){
  lcd.begin(16, 2);
  lcd.createChar(1, Bell);
  lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("Alarm Clock By");
    lcd.setCursor(0,1);
    lcd.print("Huzaifa Irfan");
    delay(400);
}

void displayDateTime(short year, short month, short day, String dayOfTheWeek, short hour, short minute, short second, bool alarmSet, bool alarmSettingView, bool cursor, short alarmHour, short alarmMinute){


    lcd.setCursor(0,0);
    lcd.print(year);
    lcd.print("/");
    lcd.print(month);
    lcd.print("/");
    lcd.print(day);
    lcd.print(" - ");
    lcd.print(dayOfTheWeek);
    lcd.print("  ");

    lcd.setCursor(0,1);

    lcd.print(hour);
    lcd.print(":");
    lcd.print(minute);
    lcd.print(":");
    lcd.print(second);
    lcd.print(" ");

    if(alarmSet){
      lcd.write(byte(1));
      if(alarmSettingView and not cursor){
        lcd.print(">");
      }
      lcd.print(alarmHour);
      lcd.print(":");
      if(alarmSettingView and cursor){
        lcd.print(">");
      }
      lcd.print(alarmMinute);
    }

    lcd.print("       ");



}


void displayLoop(){

}

#endif
