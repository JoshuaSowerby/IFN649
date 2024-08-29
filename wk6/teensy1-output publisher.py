import paho.mqtt.publish as publish
from IP import IP

ser = serial.Serial("/dev/rfcomm0", 9600)
ser.write(str.encode('Start\r\n'))

while True:
    if ser.in_waiting > 0:
        rawserial = ser.readline()
        cookedserial = rawserial.decode('utf-8').strip('\r\n')
        publish.single("test/teensy1/output", cookedserial, hostname=IP)#IP or "localhost", would be better to import this

        #print(cookedserial)
        if('10' in cookedserial):
            ser.write(str.encode('BUZZER_ON'))
            #time.sleep(0.5) 
        else:
            ser.write(str.encode('BUZZER_OFF'))
#publish.single("ifn649", "Hello World", hostname="3.27.30.149")#IP or "localhost", would be better to import this
#print("Done")