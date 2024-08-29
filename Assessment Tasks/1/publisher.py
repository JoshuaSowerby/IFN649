import paho.mqtt.publish as publish
from IP import IP
publish.single("ifn649", "Hello World", hostname=IP)#IP or "localhost", would be better to import this
print("Done")