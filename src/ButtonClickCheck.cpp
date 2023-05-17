#include "arduino.h"
#include "ButtonClickCheck.h"

/// @brief 저장된 핀번호의 값을 읽어 클릭정보를 판단한다.
/// @return 1=Up, 2=Down, 3=First Down, 4=First Up
int ButtonClickCheck::ClickCheck()
{
	//결과
	int nReturn = 0;
	
	if(0 < Pin)
	{//핀번호가 있다.
		nReturn = ClickCheck(digitalRead(Pin));
	}
	
	return nReturn;
}

/// @brief 전달된 값을 읽어 클릭정보를 판단한다.
/// @param nDigitalRead 입력된 디지털 값(전달된 값)
/// @return 1=Up, 2=Down, 3=First Down, 4=First Up
int ButtonClickCheck::ClickCheck(int nDigitalRead)
{
	//결과
	int nReturn = 0;
	
	//1.버튼 값이 기존과 다른지 여부 확인
	//1-1. 입력값 확인
	if( ButtonUpLevel != nDigitalRead)
	{//버튼이 눌림
		bBtnPush1 = true;
	}
	else
	{//버튼이 안눌림
		bBtnPush1 = false;
	}

	//1-2. 기존 입력값 확인
	if(bBtnPush2 == true)
	{//기존에 버튼이 눌려있었음
		//기존 상태 먼저 저장
		nReturn = 2;

		if(bBtnPush1 == false)
		{//이번엔 버튼이 안눌림
		  bBtnPush2 = false;
		  nReturn = 4;
		}
	}
	else if(bBtnPush2 == false)
	{//기존 버튼이 눌려있지 않음
		//기존 상태 먼저 저장
		nReturn = 1;
		
		if(bBtnPush1 == true)
		{//이번엔 버튼이 눌림
		  bBtnPush2 = true;
		  nReturn = 3;
		}
	}
	
	return nReturn;
}

/// @brief 기존 상태 값인 'bBtnPush2'를 원하는 값으로 지정한다. 
/// @param bBtnPush2Value 기존 상태값에 저장할 데이터. on=true, off=false
void ButtonClickCheck::BtnPush2Set(bool bBtnPush2Value)
{
	bBtnPush2 = bBtnPush2Value;
}