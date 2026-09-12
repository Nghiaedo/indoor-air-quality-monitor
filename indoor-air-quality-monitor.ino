#include <Wire.h>
#include <Adafruit_AHTX0.h>
#include <LiquidCrystal_I2C.h>
#include "ScioSense_ENS160.h"

int green = 2;
int yellow = 7;
int red = 12;

Adafruit_AHTX0 aht;
LiquidCrystal_I2C lcd(0x27, 16, 2);
ScioSense_ENS160 ens160(ENS160_I2CADDR_1);

float tempC;
float tempF;
float humidity;

void setup() {
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);

  digitalWrite(green, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(red, LOW);

  lcd.init();
  lcd.backlight();

  ens160.begin();

  if (ens160.available()) {
    ens160.getMajorRev();
    ens160.getMinorRev();
    ens160.getBuild();
    ens160.setMode(ENS160_OPMODE_STD);
  }

  if (!aht.begin()) {
    while (1) {
      delay(10);
    }
  }

  delay(5000);
}

void loop() {
  sensors_event_t humidity1, temp;

  aht.getEvent(&humidity1, &temp);

  tempC = temp.temperature;
  tempF = tempC * 1.8 + 32;
  humidity = humidity1.relative_humidity;

  digitalWrite(green, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(red, LOW);

  if (tempC < 24) {
    digitalWrite(green, HIGH);
  }
  else if (tempC < 27) {
    digitalWrite(yellow, HIGH);
  }
  else {
    digitalWrite(red, HIGH);
  }

  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.print(tempC, 1);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Hum:");
  lcd.print(humidity, 1);
  lcd.print("% rH");

  delay(5000);

  lcd.clear();
  lcd.setCursor(0, 0);

  if (ens160.available()) {
    ens160.set_envdata(tempC, humidity);

    ens160.measure(true);
    ens160.measureRaw(true);

    lcd.print("AQI:");
    lcd.print(ens160.getAQI());
    lcd.print(" ");

    lcd.print("TVOC:");
    lcd.print(ens160.getTVOC());
    lcd.print("ppb");

    lcd.setCursor(0, 1);
    lcd.print("eCO2:");
    lcd.print(ens160.geteCO2());
    lcd.print("ppm");
  }

  delay(5000);

  lcd.clear();

  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
}
