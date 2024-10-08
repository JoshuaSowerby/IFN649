#include "DHT.h"
//#include <SoftwareSerial.h>

#define DHTPIN 21      // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11

#define LEDPIN 11
#define BUZZER 13
const int soilPin = 12;


DHT dht(DHTPIN, DHTTYPE);

// Teensy 5V <--> HC-05 Vcc
// Teensy Ground <--> HC-05 GND
#define rxPin 7 // Teensy pin 7 <--> HC-05 Tx
#define txPin 8 // Teensy pin 8 <--> HC-05 Rx
//SoftwareSerial BTSerial =  SoftwareSerial(rxPin, txPin);
//String str="";
String buzzer_status="BUZZER_OFF";
String led_status="LED_OFF";

void setup() {
  // Setup serial for monitor
  Serial.begin(9600); 

  // Setup DHT Sensor
  pinMode(DHTPIN, INPUT);
  pinMode(BUZZER, OUTPUT);
  dht.begin();

  // Setup Serial1 for BlueTooth
  Serial1.begin(9600); // Default communication rate of the Bluetooth module
  
}

void loop() {
  if(1){//Serial1.available() > 0){ // Checks whether data is comming from the serial port
    //digitalWrite(BUZZER, HIGH);
    
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    int s = analogRead(soilPin);
    Serial1.print(F("Humidity: "));
    Serial1.print(h);
    Serial1.println(F("%"));
    delay(100);
    Serial1.print(F("Temperature: "));
    Serial1.print(t);
    Serial1.println(F("C"));
    delay(100);
    Serial1.print(F("Soil: "));
    Serial1.println(s);
    delay(100);

    //INPUT
    String input=Serial1.readString().substring(1);//Serial1.readString().substring(1);//this stops it from looping, idk why
    Serial.println(input);
    if (input=="BUZZER_ON" || input=="BUZZER_OFF"){
      buzzer_status= input;
    }
    if (input=="LED_ON" || input=="LED_OFF"){
      led_status= input;
    }

    //LED CONTROL
    if(led_status=="LED_ON"){
      digitalWrite(LEDPIN,HIGH);
    }else if (led_status=="LED_OFF"){
      digitalWrite(LEDPIN,LOW);
    }
    //BUZZER CONTROL
    if(buzzer_status=="BUZZER_ON"){
      digitalWrite(BUZZER,HIGH);
      //Serial.println("BUZZER ON");
      delay(500);
      digitalWrite(BUZZER,LOW);
      
    }else if (buzzer_status=="BUZZER_OFF"){
      digitalWrite(BUZZER,LOW);
      //Serial.println("BUZZER OFF");
    }
    delay(1000);


 }
}