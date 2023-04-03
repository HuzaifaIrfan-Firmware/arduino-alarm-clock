#ifndef Utils_h
#define Utils_h

#include "Arduino.h"


void(* resetFunc) (void) = 0;  // declare reset fuction at address 0


String separate_string(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;

  for(int i=0; i<=maxIndex && found<=index; i++){
    if(data.charAt(i)==separator || i==maxIndex){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }

  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
}



int get_command(String payload){
  return separate_string(payload,'>',1).toInt();
}

String get_data(String payload){
  return separate_string(payload,'>',2);
}

int get_int_data(String data, int index=0){
  return separate_string(data,',',index).toInt();
}


String getLeadingZeroNumber(short num){
    if(num<10){
        return "0" + String(num);
    }else{
        return String(num);
    }
}


#endif
