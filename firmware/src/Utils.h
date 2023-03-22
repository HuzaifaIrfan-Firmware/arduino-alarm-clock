#ifndef Utils_h
#define Utils_h

#include "Arduino.h"

String getLeadingZeroNumber(short num){
    if(num<10){
        return "0" + String(num);
    }else{
        return String(num);
    }
}


#endif
