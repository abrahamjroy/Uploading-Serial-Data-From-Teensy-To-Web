#include <Adafruit_Sensor.h>//YOU NEED THESE LIBRARIES
#include <DHT.h>//YOU NEED THESE LIBRARIES
#include <DHT_U.h>//YOU NEED THESE LIBRARIES

#define DHTPIN            0 //Pin where the DHT11 Temprature and Humidity sensors are connected     
#define DHTTYPE           DHT11 //Used to assign the type of DHT sensor used    
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
  Serial.print("Temprature:");
  Serial.print(event.temperature);
  Serial.print(",");
  dht.humidity().getEvent(&event);
  Serial.print("Humidity:");
  Serial.print(event.relative_humidity);
  Serial.print(",");
  Serial.print("CO2 PPM:");
  int sensorValue = analogRead(1);
  Serial.println(sensorValue);
}
