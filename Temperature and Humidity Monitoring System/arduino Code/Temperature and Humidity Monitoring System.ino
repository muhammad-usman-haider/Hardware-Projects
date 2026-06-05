#include <SPI.h>
#include <SD.h>
#include "DHT.h"

#define DHTPIN A5
#define DHTTYPE DHT22 // Change to DHT22 if you're using that sensor
#define CSPIN 4       // Chip select pin for the SD card

DHT dht(DHTPIN, DHTTYPE);
File myFile;

void setup() {
  Serial.begin(9600);
  dht.begin();
  Serial.print("Initializing SD card...");
  if (!SD.begin(CSPIN)) {
    Serial.println("Initialization failed!");
    return;
  }
  Serial.println("Initialization done.");
}

void loop() {
  float humidity = dht.readHumidity();
  float temperatureC = dht.readTemperature();
  float temperatureF = dht.readTemperature(true);
  
  if (isnan(humidity) || isnan(temperatureC) || isnan(temperatureF)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  
  long timestamp = millis();
  
  myFile = SD.open("dataLog.txt", FILE_WRITE);
  if (myFile) {
    myFile.print("Humidity: ");
    myFile.print(humidity);
    myFile.print("%, Temperature: ");
    myFile.print(temperatureF);
    myFile.print("°F, ");
    myFile.print(temperatureC);
    myFile.print("°C, Timestamp: ");
    myFile.println(timestamp);
    myFile.close();
    Serial.println("Data written to SD card.");
  } else {
    Serial.println("Error opening file!");
  }

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("%, Temperature: ");
  Serial.print(temperatureF);
  Serial.print("°F, ");
  Serial.print(temperatureC);
  Serial.print("°C, Timestamp: ");
  Serial.println(timestamp);

  delay(10000); // Wait for 2 seconds before the next reading
}
