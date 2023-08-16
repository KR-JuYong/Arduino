#include <LiquidCrystal_I2C.h>
#include "DHT.h"
class LiquidCrystal_I2C lcd(0x27, 16, 2);
class DHT dht(A2, 11);
void setup() {
  // put your setup code here, to run once:
  lcd.init(); //LCD 초기화
  dht.begin(); //dht 초기화
  Serial.begin(115200UL);
  Serial1.begin(9600UL); //블루투스
  lcd.home();
  lcd.backlight();
  lcd.clear(); //화면을 한번 지워주세요.

}

void loop() {
  // put your main code here, to run repeatedly:
  float temperature= 0.0F;
  float percentHumidity= 0.0F;
  if(dht.read()){
    temperature =dht.readTemperature();
    percentHumidity = dht.readHumidity();
  }
  lcd.setCursor(0,0);
  lcd.print("TEMPER : ");
  lcd.print(temperature);
  lcd.setCursor(0,1);
  lcd.print("HUMID : ");
  lcd.print(percentHumidity);
  Serial.print(F("TEMPER : "));
  Serial.println(temperature);
  Serial.print(F("HUMID : "));
  Serial.println(percentHumidity);
  Serial1.print(F("온도 : "));
  Serial1.println(temperature);
  Serial1.print(F("습도 : "));
  Serial1.println(percentHumidity);
  delay(500UL);
  lcd.clear();
}
