#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS A0
#define LCD_I2C_ADDRESS 0x27

LiquidCrystal_I2C lcd(LCD_I2C_ADDRESS, 16, 2);
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  sensors.begin();
}

void loop() {
  sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0);
  lcd.setCursor(0, 0);
  lcd.print("Temperatur: ");
  lcd.setCursor(0, 1);
  lcd.print(tempC);
  lcd.print("*C");
}
