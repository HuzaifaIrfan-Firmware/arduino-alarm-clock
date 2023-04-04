



import sys
from PyQt5 import QtCore, QtGui

from PyQt5.QtCore import Qt

from PyQt5.QtGui import QIcon

from PyQt5.QtWidgets import (
    QApplication,
    QMainWindow,
    QVBoxLayout,
    QHBoxLayout,
    QWidget,
    QLabel,
QPushButton,
QTimeEdit

)


from SerialCOM import SerialCOM

from utils import *


comport="COM9"

serialcom=SerialCOM(comport,9600)



DAYS_OF_WEEK = [
    'None',
    'Monday',
    'Tuesday',
    'Wednesday',
    'Thursday',
    'Friday',
    'Saturday',
    'Sunday'
    ]

MONTHS = [
    'Non',
    'Jan',
    'Feb',
    'Mar',
    'Apr',
    'May',
    'Jun',
    'Jul',
    'Aug',
    'Sep',
    'Oct',
    'Nov',
    'Dec'
    ]
   
class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Arduino Alarm Clock App")
        self.setWindowIcon(QtGui.QIcon('logo.png'))

        width = 500
        height = 400
        # setting  the fixed size of window
        self.setFixedSize(width, height)

        layout = QVBoxLayout()


        self.DateLabel = QLabel("Date")
        self.DateLabel.setStyleSheet('.QLabel { font-size: 32pt;}')
        self.DateLabel.setAlignment(Qt.AlignHCenter)
        layout.addWidget(self.DateLabel)

        self.DayLabel = QLabel("Week Day")
        self.DayLabel.setStyleSheet('.QLabel { font-size: 48pt;}')
        self.DayLabel.setAlignment(Qt.AlignHCenter)
        layout.addWidget(self.DayLabel)

        self.TimeLabel = QLabel("Time")
        self.TimeLabel.setStyleSheet('.QLabel { font-size: 64pt;}')
        self.TimeLabel.setAlignment(Qt.AlignHCenter)
        layout.addWidget(self.TimeLabel)

        self.AlarmLabel = QLabel("Alarm")
        self.AlarmLabel.setStyleSheet('.QLabel { font-size: 32pt;}')
        self.AlarmLabel.setAlignment(Qt.AlignHCenter)
        layout.addWidget(self.AlarmLabel)



        alarmlayout = QHBoxLayout()
        self.timeEdit = QTimeEdit()
        self.timeEdit.setDisplayFormat("HH:mm")
        # self.timeEdit.timeChanged.connect(lambda: self.setAlarm())
        alarmlayout.addWidget(self.timeEdit)

        self.setAlarmBtn =QPushButton("Set Alarm")
        self.setAlarmBtn.clicked.connect(self.setAlarm)
        alarmlayout.addWidget(self.setAlarmBtn)

        self.offAlarmBtn =QPushButton("Turn Off Alarm")
        self.offAlarmBtn.clicked.connect(self.offAlarm)
        alarmlayout.addWidget(self.offAlarmBtn)

        layout.addLayout(alarmlayout)

        buzzlayout = QHBoxLayout()


        self.testBuzzerBtn =QPushButton("Test Buzzer")
        self.testBuzzerBtn.clicked.connect(self.testBuzzer)
        buzzlayout.addWidget(self.testBuzzerBtn)

        self.offBuzzerBtn =QPushButton("Turn Off Buzzer")
        self.offBuzzerBtn.clicked.connect(self.offBuzzer)
        buzzlayout.addWidget(self.offBuzzerBtn)

        layout.addLayout(buzzlayout)


        widget = QWidget()
        widget.setLayout(layout)
        self.setCentralWidget(widget)


    def use_serial_data(self, serial_data):
        print(serial_data)
        try:
            split_data=serial_data.split('>')[1].split(',')
            year=int(split_data[0])
            month=int(split_data[1])
            day=int(split_data[2])
            day_of_week_index=int(split_data[3])
            hour=int(split_data[4])
            minute=int(split_data[5])
            second=int(split_data[6])
            alarm_set=int(split_data[7])
            alarm_hour=int(split_data[8])
            alarm_minute=int(split_data[9])
            buzz=int(split_data[10])


            self.DateLabel.setText(f'{returnLeadingZero(day)} {MONTHS[month]} {year}')

            self.DayLabel.setText(f'{DAYS_OF_WEEK[day_of_week_index]}')

            self.TimeLabel.setText(f'{returnLeadingZero(hour)}:{returnLeadingZero(minute)}:{returnLeadingZero(second)}')

            if(alarm_set):
                self.AlarmLabel.setText(f'Alarm Set: {returnLeadingZero(alarm_hour)}:{returnLeadingZero(alarm_minute)}')
            else:
                self.AlarmLabel.setText('')

        except:
            pass

    def setAlarm(self):
        alarm_hour= self.timeEdit.time().hour()
        alarm_minute= self.timeEdit.time().minute()
        serialcom.write_serial(f'>4>{alarm_hour},{alarm_minute}>\n')

        
    def offAlarm(self):
        serialcom.write_serial('>5>\n')

    def testBuzzer(self):
        serialcom.write_serial('>2>\n')
    def offBuzzer(self):
        serialcom.write_serial('>3>\n')
        
        
        


from qt_material import apply_stylesheet
import threading

def serial_thread_loop():
    serialcom.serial_loop()



def main(args=None):
    app = QApplication(sys.argv)
    app.setWindowIcon(QIcon("logo.png"))
    apply_stylesheet(app, theme='dark_blue.xml')
    window = MainWindow()
    serialcom.set_controller(window)
    serial_thread = threading.Thread(target=serial_thread_loop)
    serial_thread.daemon = True
    window.show()
    serial_thread.start()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()