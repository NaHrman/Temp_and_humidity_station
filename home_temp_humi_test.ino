
#include <LiquidCrystal.h>
#include "DHT.h"

#define DHTPIN 7     
#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Temp:");
  lcd.setCursor(0,1);
  lcd.print("Humidity:");
  dht.begin();
}

void loop() {
  String celsius = "C";
  String humidity = "%";
 
  float h = dht.readHumidity();

  float t = dht.readTemperature();
  
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  lcd.setCursor(5,0);
  lcd.print(t+celsius);
  lcd.setCursor(9,1);
  lcd.print(h+humidity);
  delay(60000);
  /*
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.println();*/
}
