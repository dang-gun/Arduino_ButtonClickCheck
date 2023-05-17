#include "arduino.h"

class ButtonClickCheck
{ 
public:
	/// @brief 핀번호
	uint8_t Pin;
	/// @brief 버튼이 눌리지 않았을때 판단값
	int ButtonUpLevel;
private:
	/// @brief 버튼 값이 바뀌였는지 여부1
	bool bBtnPush1;
	/// @brief 버튼 값이 바뀌였는지 여부2
	bool bBtnPush2;
	
public:
	/// @brief 버튼 판단을 위한 라이브러리
	/// @param nButtonUpLevel 버튼이 눌리지 않았을때 판단값. LOW or HIGH
	ButtonClickCheck(int nButtonUpLevel)
	{
		Pin = 0;
		ButtonUpLevel = nButtonUpLevel;
		
		bBtnPush1 = false;
		bBtnPush2 = false;
	}
	
	/// @brief 버튼 판단을 위한 라이브러리
	/// @param uintPin 핀을 미리 지정한다.
	/// @param nButtonUpLevel 버튼이 눌리지 않았을때 판단값. LOW or HIGH
	ButtonClickCheck(uint8_t uintPin, int nButtonUpLevel)
	{
		Pin = uintPin;
		ButtonUpLevel = nButtonUpLevel;
		
		bBtnPush1 = false;
		bBtnPush2 = false;
	}
	~ButtonClickCheck()
	{
	}


public:
  int ClickCheck();
  int ClickCheck(int nDigitalRead);

  void BtnPush2Set(bool bBtnPush2Value);
};
