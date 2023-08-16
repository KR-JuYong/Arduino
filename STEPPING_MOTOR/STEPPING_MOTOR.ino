#include <Stepper.h>

const int STEP_PER_REVOLUTION= 64 * 32; //2048 == 기어의 1회전
//(회전수, IN4 8, IN2 10, IN3 9, IN1 11) 으로 작성 해야 함.
class Stepper stepping = Stepper(STEP_PER_REVOLUTION,8,10,9,11);
void setup() {
  // put your setup code here, to run once:
  stepping.setSpeed(14L); //PRM -> SPEED == 기본 세팅이 14이다. (1분당 14번 회전), L==LongTime
  Serial.println(115200UL); 
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(F("시계방향으로 전진"));
  stepping.step(STEP_PER_REVOLUTION); //한바퀴 회전
  delay(1000UL);
  Serial.println(F("반시계방향으로 전진"));
  stepping.step(-STEP_PER_REVOLUTION); //거꾸로 한바퀴 앞에 - 를 붙여주면 됨
  delay(1000UL);

  //반바퀴 == stepping.step(STEP_PER_REVOLUTION /2));
  //1/4바퀴 == stepping.step(STEP_PER_REVOLUTION /4);
}
