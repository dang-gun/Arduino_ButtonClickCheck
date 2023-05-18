# ButtonClickCheck

This is a library for checking the state of a button connected to an Arduino.

Detailed explanation (Korean) : [[Arduino] 버튼 처리를 위한 라이브러리 - ButtonClickCheck](https://blog.danggun.net/7268)


## Index
  - [Overview](#overview) 
  - [Getting Started](#getting-started)
  - [Running the tests](#running-the-tests)
  - [Document](#Document)
  - [Update history](#update-history)
  - [Contributing](#contributing)
  - [Authors](#authors)
  - [License](#license)


## Overview

- Save the last state of the button
- Detect state change of button


## Getting Started

- Download the file from github or
- Create 'ButtonClickCheck.h' and 'ButtonClickCheck.cpp' and copy the source.

Follow the instructions below to install.

### Prerequisites

Tested on Arduino 1.8.19

### Installing

Create 'ButtonClickCheck' folder in 'libraries' folder of Arduino software

Insert 'ButtonClickCheck.h', 'ButtonClickCheck.cpp'.

Launch the Arduino software and add the following code.


```
#include <ButtonClickCheck.h>
```


## Running the tests

Put the code below in your sketch to test it.

```
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
```

## Document

Name|Description
---|---|
ButtonClickCheck(int nButtonUpLevel)|A library for button judgment<br />@param nButtonUpLevel The judgment value when the button is not pressed. LOW or HIGH
ButtonClickCheck(uint8_t uintPin, int nButtonUpLevel)|Library for judging buttons (specifying which pins to use)<br />@param uintPin pre-assign pins.<br />@param nButtonUpLevel Judgment value when the button is not pressed. LOW or HIGH
&nbsp;|&nbsp; 
int ClickCheck()|Read the value of the stored pin number to determine the click information.<br />@return 1=Up, 2=Down, 3=First Down, 4=First Up
int ClickCheck(int nDigitalRead)|Read the delivered value to determine the click information.<br />@param nDigitalRead Input digital value (passed value)<br />@return 1=Up, 2=Down, 3=First Down, 4=First Up
BtnPush2Set(bool bBtnPush2Value)|@param bBtnPush2Value Data to store in the existing state value. on=true, off=false

## Update history

#### 2023-05-17 : 
- Added 'BtnPush2Set' function
- storage separation

#### 2023-05-15 : 
- tidy up comments

#### 2023-05-11 : 
- Added '4=First Up' function

#### 2019-07-28 : 
- development completed

## Contributing

1) Fork (https://github.com/yourname/yourproject/fork).
2) Create a new branch with (git checkout -b feature/fooBar) command.
3) Commit with the command (git commit -am 'Add some fooBar').
4) Push to the branch with (git push origin feature/fooBar) command.
5) Please send a pull request.

## Authors
  - [dang-gun](https://github.com/dang-gun)

See also the list of [contributors](https://github.com/dang-gun/ArduinoSample/contributors)
who participated in this project.


## License
[MIT](https://github.com/dang-gun/Arduino_ButtonClickCheck/blob/main/LICENSE)
