#include "DHT.h";
const uint8_t DHT_PIN {A2};
const uint8_t RELAY_SW {12U};
const uint8_t LED(5U);
class DHT dht = DHT(DHT_PIN, 11);
uint8_t FND[]{0b11111100, 0b01100000, 0b11011010, 0b11110010,
0b01100110, 0b10110110, 0b00111110, 0b11100100, 0b11111110, 0b11100110};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL); //시리얼포트 속도 셋팅
  Serial1.begin(9600UL); //bluetooth
  dht.begin(); //온도, 습도 센서 시작 == default 값
  pinMode(RELAY_SW, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED,OUTPUT);
  for(int i=22; i<=29; ++i){
    pinMode(i, OUTPUT);
  }
}

void loop() {
  //Serial.println("LOOP");
  // put your main code here, to run repeatedly:
  if(dht.read()){ //dht센서에서 문제없이 읽었다면
    float temperature = dht.readTemperature();
    float percentHumidity = dht.readHumidity();
    float heat = dht.computeHeatIndex(temperature, percentHumidity);
    Serial.print(F("Temperature: "));
    Serial.println(String(temperature) + " C");
    Serial.print(F("Humidity: "));
    Serial.println(String(percentHumidity) + " %");
    Serial.print(F("Heat: "));
    Serial.println(String(heat));

    //Serial1.begin -- bluetooth
    Serial1.print(F("Temperature: "));
    Serial1.println(String(temperature) + " C");
    Serial1.print(F("Humidity: "));
    Serial1.println(String(percentHumidity) + " %");
    Serial1.print(F("Heat: "));
    Serial1.println(String(heat));

    //열 감지 위험도 
    const uint16_t mapped_Heat_value = map(heat, 0,100,0,9); 
    Serial.println(String("Heat_value: ")+ mapped_Heat_value);
    //온도 감지
    if(temperature>=30.0){
      digitalWrite(LED, HIGH);
      digitalWrite(RELAY_SW,HIGH);
      delay(1000UL);
      digitalWrite(RELAY_SW,LOW);
      delay(1000UL);
    }
    //열감지 위험도 FND 시각화
    for(int i=2; i<=9; ++i){
      if(bitRead(FND[mapped_Heat_value], 9 - i)){
        digitalWrite(i +20, HIGH);
      }else{
        digitalWrite(i + 20, LOW);
      }
    }
    delay(1000UL);
  }
  delay(10UL);
}
