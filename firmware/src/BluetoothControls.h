#ifndef BluetoothControls_h
#define BluetoothControls_h

#include "Arduino.h"


void bluetoothControlsSetup(){

}


// Command List
/*

2 - Test Buzzer
3 - Turn Off Buzzer

4 - Set Alarm
5 - Turn Off Alarm

6 - Set Date
7 - Set Time

*/









void bluetoothControlsLoop(String serialData){
    // serialData Format
    // >command>v1,v2,v3>

    short command = get_command(serialData);
    String data = get_data(serialData);
    short v1 = get_int_data(data,0);
    short v2 = get_int_data(data,1);
    short v3 = get_int_data(data,2);


    switch(command){
        case 2:
        test_buzzer();
        break;
        case 3:
        turn_off_buzzer();
        break;
        case 4:
        set_alarm(v1,v2);
        break;
        case 5:
        turn_off_alarm();
        break;
        case 6:
        set_date(v1,v2,v3);
        break;
        case 7:
        set_time(v1,v2,v3);
        break;
    }






}


#endif
