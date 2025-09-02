#include "DHT.h"

#define DHTPIN 2      // DHT22 data pin connected to digital pin 2
#define DHTTYPE DHT22 // Type of sensor

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000); // Wait 2 seconds between readings

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature(); // Celsius
  float tempF = dht.readTemperature(true);   // Fahrenheit

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C ");
  Serial.print(tempF);
  Serial.println(" °F");
}
