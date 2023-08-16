#include <LiquidCrystal_I2C.h>
//내부적으로 I2C 선으로 연결이 되어 있어야 함.
class LiquidCrystal_I2C lcd(0x27, 16, 2); //디스플레이 사이즈를 정해줘야함. 지금 사용 하는 것은 16x2 (한글을 두줄로 16자씩 총 32자를 출력 한다.)
//0x27이 안된다면 0x3F로 바꾼다.
void setup() {
  // put your setup code here, to run once:
  lcd.init(); //초기화
  lcd.backlight();
  lcd.home(); //화면의 커서 위치가 (0,0)에 위치하라는 것.
  lcd.print("HELLO JUYONG");
}

void loop() {
  // put your main code here, to run repeatedly:

}
