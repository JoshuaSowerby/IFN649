import paho.mqtt.client as mqtt

def on_connect(client, userdata, flags, rc): #func for making connection
    print("connected to MQQT")
    print(f"Connection result: {str(rc)}")
          
    client.subscribe("ifn649")
def on_message(client, userdata, msg): #func for sending message
    print(msg.topic+""+str(msg.payload))

client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message

IP="3.27.30.149"#AWS instance IP or "localhost"
client.connect(IP,1883,60)

client.loop_forever()