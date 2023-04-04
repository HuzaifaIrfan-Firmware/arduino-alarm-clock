import serial
import time
import json
import random


class SerialCOM:
    def __init__(self,comport, baudrate=9600):

        self.maxCheckPorts=10
        self.SERIALPORT_FORMATS=["/dev/ttyUSB","/dev/ttyACM","COM"]

        self.comport=comport
        self.baudrate=baudrate

        try:
            self.arduino = serial.Serial(port=self.comport,
                baudrate=self.baudrate, 
                timeout=.1, 
                parity=serial.PARITY_NONE,
                stopbits=serial.STOPBITS_ONE,
                bytesize=serial.EIGHTBITS,
                dsrdtr = False)
        except:
            self.auto_connect()

        
    


    def auto_connect(self):


        for i in range(self.maxCheckPorts):

            for SERIALPORT_FORMAT in self.SERIALPORT_FORMATS:
                self.comport=f"{SERIALPORT_FORMAT}{i}"
                try:
                    print(f'Connecting to Serial: {self.comport}')

                    self.arduino = serial.Serial(port=self.comport,
                        baudrate=self.baudrate, 
                        timeout=.1, 
                        parity=serial.PARITY_NONE,
                        stopbits=serial.STOPBITS_ONE,
                        bytesize=serial.EIGHTBITS,
                        dsrdtr = None)

                    print(f'Connected to Serial: {self.comport}')

                    return True
                
                except serial.serialutil.SerialException:

                    print(f'Cant connect to Serial: {self.comport} not Available')

        raise Exception("Cant Connect to Serial Ports")
    
    def set_controller(self, controller):
        self.controller=controller
        
    def write_serial(self,serial_data):
        if serial_data:
            print('User: ', serial_data)
            self.arduino.write(bytes(serial_data, 'utf-8'))
            return True
        return False

    def read_serial(self):
        time.sleep(0.5)
        byte_data = self.arduino.readline()
        try:
            data=str(byte_data, 'UTF-8')
            if data:
                print('Arduino: ', data)
                return data
            else:
                return False
        except:
            return False

    def write_read(self,data):
        self.write_serial(data)
        return self.read_serial()


    def serial_loop(self):
        while(1):
            serial_data=self.read_serial()
            if serial_data:
                self.controller.use_serial_data(serial_data)