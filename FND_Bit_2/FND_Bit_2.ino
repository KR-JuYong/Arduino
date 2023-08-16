void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL);
  /*\
  uint8_t value_a =0b10110101;
  Serial.println(bitRead(value_a, 1));
  */
  int value = 0b0000111100000111; //2바이트 -> 16비트 < int는 16비트 >
  Serial.println(highByte(value));
  Serial.println(lowByte(value));
  int low_value =lowByte(value);
  Serial.println(low_value); //00000111 == 7
  int high_value =highByte(value);
  Serial.println(high_value); //00001111 == 15
  bitWrite(low_value,3,1);
  Serial.println(low_value);
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
