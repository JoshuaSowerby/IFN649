import paho.mqtt.publish as publish

publish.single("ifn649", "Hello World", hostname="3.27.30.149")#IP or "localhost", would be better to import this
print("Done")