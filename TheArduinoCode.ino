#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN            0      
#define DHTTYPE           DHT11      
DHT_Unified dht(DHTPIN, DHTTYPE);

uint32_t delayMS;

void setup() {
  Serial.begin(9600); 
  delayMS = 1000;
}

void loop() {
  delay(delayMS);
  sensors_event_t event;  
  dht.temperature().getEvent(&event);
  Serial.print(event.temperature);
  Serial.print(",");
  dht.humidity().getEvent(&event);
  Serial.print(event.relative_humidity);
  Serial.print(",");
  int sensorValue = analogRead(1);
  Serial.println(sensorValue);
}
