#include "DHT.h"
//#include <SoftwareSerial.h>

#define DHTPIN 21      // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11

#define LEDPIN 11

DHT dht(DHTPIN, DHTTYPE);

// Teensy 5V <--> HC-05 Vcc
// Teensy Ground <--> HC-05 GND
#define rxPin 7 // Teensy pin 7 <--> HC-05 Tx
#define txPin 8 // Teensy pin 8 <--> HC-05 Rx
//SoftwareSerial BTSerial =  SoftwareSerial(rxPin, txPin);
String str="";
void setup() {
  // Setup serial for monitor
  Serial.begin(9600); 

  // Setup DHT Sensor
  pinMode(DHTPIN, INPUT);
  pinMode(LEDPIN, OUTPUT);
  dht.begin();

  // Setup Serial1 for BlueTooth
  Serial1.begin(9600); // Default communication rate of the Bluetooth module
  
}

void loop() {
  if(1){//Serial1.available() > 0){ // Checks whether data is comming from the serial port
    //digitalWrite(BUZZER, HIGH);
    
    //float h = dht.readHumidity();
    float t = dht.readTemperature();
    //float f = dht.readTemperature(true);

    //float hif = dht.computeHeatIndex(f, h);
    //float hic = dht.computeHeatIndex(t, h, false);  

  //Serial is teensy, Serial1 is bluetooth
  /*
    Serial.print(F(" Humidity: "));
    Serial.print(h);
    Serial.print(F("%  Temperature: "));
    Serial.print(t);
    Serial.print(F("C "));
    Serial.print(f);
    Serial.print(F("F  Heat index: "));
    Serial.print(hic);
    Serial.print(F("C "));
    Serial.print(hif);
    Serial.println(F("F"));
  */

    Serial1.println(t);

    //Serial.println(Serial1.readString().substring(1));
    String input=Serial1.readString().substring(1);//Serial1.readString().substring(1);//this stops it from looping, idk why
    if (input=="LED_ON" || input=="LED_OFF"){
      str = input;
    }
    //Serial.println(str);
    if(str=="LED_ON"){
      digitalWrite(LEDPIN,HIGH);
      
    }else if (str=="LED_OFF"){
      digitalWrite(LEDPIN,LOW);
      //Serial.println("BUZZER OFF");
    }

    delay(1000);


 }
}