
import serial
import time

import pyautogui


serial_port = serial.Serial(
    port = "COM5", baudrate = 9600, bytesize= serial.EIGHTBITS, parity = serial.PARITY_NONE, stopbits = serial.STOPBITS_ONE)
time.sleep(1)

while 1:
   
    incoming_Data=serial_port.read()#readline() function will get data from serial monitor line by line
    incoming_Data1=incoming_Data.decode('utf-8')

   #if 'up' in incoming_Data: #In python3 data needs to convert into byte so decode function is use for that 
    
    if (incoming_Data1=="u"):
       pyautogui.press('up')# function to perform up arrow functionality
    
