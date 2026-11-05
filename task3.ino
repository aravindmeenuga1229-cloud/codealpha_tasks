#include <DHT.h>

const uint8_t DHT_PIN = 2;
#define DHT_TYPE DHT11

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000);  // DHT11 requires a slow sampling interval.

  float humidity = dht.readHumidity();
  float temperatureC = dht.readTemperature();

  if (isnan(humidity) || isnan(temperatureC)) {
    Serial.println("Sensor read failed");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperatureC, 1);
  Serial.print(" C  Humidity: ");
  Serial.print(humidity, 1);
  Serial.println(" %");
}
