import paho.mqtt.client as mqtt
import serial
import string

from IP import IP
def on_connect(client, userdata, flags, rc): #func for making connection
    print("connected to MQQT")
    print(f"Connection result: {str(rc)}")
          
    client.subscribe("test/teensy1/input")
def on_message(client, userdata, msg): #func for sending message
    print(msg.topic+": "+(msg.payload).decode())#str.decode adds a b for bytes, this looks better but doesnt have as much info i guess
    
    cmd=str.encode(" "+msg.payload.decode()) #it keeps cutting of first letter so we add soemthign unimportant to cutt off
    ser=serial.Serial("/dev/rfcomm0",9600)
    ser.write(cmd)

client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message

#IP="3.27.30.149"#AWS instance IP or "localhost"
client.connect(IP,1883,60)

client.loop_forever()
