#include <ButtonClickCheck.h>

#define Button01 2
#define Button02 4

//테스트 1
ButtonClickCheck BCC_1(HIGH);
//테스트 2
ButtonClickCheck BCC_2(LOW);

void setup() 
{
  Serial.begin(9600);
  
  pinMode(Button01, INPUT);
  pinMode(Button02, INPUT);
}

void loop() 
{
  
  //컴퓨터에 신호를 준다.
  int nBtnState01 = BCC_1.ClickCheck(digitalRead(Button01));
  int nBtnState02 = BCC_2.ClickCheck(digitalRead(Button02));
  
  Serial.print(nBtnState01);
  Serial.print(" : ");
  Serial.println(nBtnState02);
  
  delay(500);
}
