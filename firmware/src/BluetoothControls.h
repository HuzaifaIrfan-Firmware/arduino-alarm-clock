#ifndef BluetoothControls_h
#define BluetoothControls_h

#include "Arduino.h"


void bluetoothControlsSetup(){
    
}

void bluetoothControlsLoop(String serialData){

    short intdata = serialData.toInt();

    if(intdata == 2){
        buzz=true;
    }

    if(intdata == 3){
        buzz=false;
    }


}


#endif
