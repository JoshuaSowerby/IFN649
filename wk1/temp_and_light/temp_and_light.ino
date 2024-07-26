#include "DHT.h"

#define DHTPIN 21
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
const int ledPin = 11;
int message_delay;
int time_since_blink;
int light_status;
int blink_rate;
int message_rate;
void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  dht.begin();

  message_delay=0;
  time_since_blink=0;
  light_status=0;
  blink_rate=101;
  message_rate=2000;
}

void loop() {
  // Wait a few seconds between measurements.
  delay(1);
  time_since_blink=time_since_blink+1;
  message_delay= message_delay+1;
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  if (message_delay>message_rate){
    Serial.print(F("Humidity: "));
    Serial.print(h);
    Serial.print(F("%  Temperature: "));
    Serial.print(t);
    Serial.print(F("°C "));
    Serial.print(f);
    Serial.print(F("°F  Heat index: "));
    Serial.print(hic);
    Serial.print(F("°C "));
    Serial.print(hif);
    Serial.println(F("°F"));
    message_delay=0;
  }
  blink_rate=5000/((int)t);
  if (time_since_blink>blink_rate){
    time_since_blink=0;
    if (light_status==1){
      digitalWrite(ledPin, LOW);
      light_status=0;
    }else{
      digitalWrite(ledPin, HIGH);
      light_status=1;
      }
  }


}
