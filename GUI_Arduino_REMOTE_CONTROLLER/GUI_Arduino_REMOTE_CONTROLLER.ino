#include "DHT.h"
class DHT dht(A0, 11);
const uint8_t RELAY_SW {30};
void setup() {
  // put your setup code here, to run once:
  dht.begin();
  Serial.begin(115200UL);
  pinMode(RELAY_SW, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  float temperature=0.0F;
  float percentHumidity=0.0F;
  if(dht.read()){
    temperature = dht.readTemperature();
    percentHumidity = dht.readHumidity();
  }
  if(Serial.available()){
    String str_command =Serial.readString(); //SW ON
    str_command.trim(); //개행문자를 날림.
    str_command.toUpperCase();
    if(str_command =="SW_ON"){
      digitalWrite(RELAY_SW, HIGH);
      delay(500UL);
    }else if(str_command =="SW_OFF"){
      digitalWrite(RELAY_SW, LOW);
      delay(500UL);
    }else{

    }
  }
  Serial.print(temperature);
  Serial.print(",");
  Serial.println(percentHumidity);
  delay(500UL);
}
