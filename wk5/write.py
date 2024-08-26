import serial 
import time 
ser = serial.Serial("dev/rfcomm0", 100) 

while True:
    ser.write(str.encode('LED_ON'))
    time.sleep(0.5) 
    ser.write(str.encode('LED_OFF'))

"""
def write_read(x): 
	   arduino.write(bytes(x, 'utf-8')) 
	   time.sleep(0.05) 
	   data = arduino.readline() 
	   return data 
while True: 
	   num = input("Enter a number: ") # Taking input from user 
	   value = write_read(num) 
	   print(value) # printing the value 
"""