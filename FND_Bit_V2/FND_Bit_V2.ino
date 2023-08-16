//const uint8_t PINS[]{22U,23U,24U,25U,26U,27U,28U,29U};
uint8_t FND[]{0b11111100, 0b01100000, 0b11011010, 0b11110010, 0b01100110, 0b10110110, 0b00111110, 0b11100100, 0b11111110, 0b11100110};
const uint8_t VR_PIN{A0};
void setup() {
  // put your setup code here, to run once:
 /* for(auto&&i : PINS){
    pinMode(i, OUTPUT);
  }
  for(auto&&i : FND){
    pinMode(i,OUTPUT);
  }*/
  Serial.begin(115200UL);
  for(int i=22; i<=29; ++i){
    pinMode(i, OUTPUT);
  }
  pinMode(A0, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  uint16_t Number_value = analogRead(VR_PIN);
  uint16_t mapped_Number_value = map(Number_value, 0, 1023, 0,9);
  Serial.println(mapped_Number_value);
  for(int j=0; j<=9; ++j){
    for(int i=2; i<=9; ++i){
      if(bitRead(FND[mapped_Number_value], 9 - i)){
        digitalWrite(i +20, HIGH);
      }else{
        digitalWrite(i + 20, LOW);
      }
    }
    delay(10UL);
  }
}
