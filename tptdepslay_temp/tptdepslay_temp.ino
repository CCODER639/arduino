#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>
#include "DHT.h"

#define DHTPIN 19        // Pin where the DHT11 is connected
#define DHTTYPE DHT11    // DHT11 sensor

DHT dht(DHTPIN, DHTTYPE);  // Create DHT sensor object

// Define your pins
#define TFT_CS     5
#define TFT_RST    4
#define TFT_DC     2
#define TFT_SCLK   18
#define TFT_MOSI   23
// Optional: #define TFT_BLK    21

// Create display object (for ST7735)
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  dht.begin();  // Initialize sensor
  Serial.begin(115200);
  tft.initR(INITR_BLACKTAB);  // For most 1.8" displays
  tft.setRotation(1);         // Landscape mode (0-3)
  tft.fillScreen(ST77XX_WHITE);

  // Example drawing:
  tft.setTextColor(ST77XX_BLACK);
  tft.setTextSize(3);
  tft.setCursor(10, 10);
  tft.println("WEATHER");

}

void loop() {
    // Read humidity and temperature
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();  // Default is Celsius
  // Check if any reads failed
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // Print values

  Serial.print("Humidity: ");
  Serial.print(humidity, 4);
  Serial.println(" %");

  Serial.print("Temperature: ");
  Serial.print(temperature, 4);
  Serial.println(" °C");
  tft.setTextSize(3);
  tft.fillRect(10, 50, 50, 16, ST77XX_WHITE);  // Clear old number
  tft.setCursor(10, 50);
  tft.setTextColor(ST77XX_BLACK);
  tft.setTextSize(2);
  
  tft.print(String(temperature) + " temp");

  tft.setTextSize(3);
  tft.fillRect(10, 100, 50, 16, ST77XX_WHITE);  // Clear old number
  tft.setCursor(10, 100);
  tft.setTextColor(ST77XX_BLACK);
  tft.setTextSize(2);
  tft.print(String(humidity) + " humd");

  delay(5000);

}



