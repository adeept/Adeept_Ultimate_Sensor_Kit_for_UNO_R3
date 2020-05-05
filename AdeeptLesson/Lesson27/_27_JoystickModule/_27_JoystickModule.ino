/***********************************************************
File name: _27_JoystickModule.ino
Description: We measure the information of joystick module, 
             and displayed in the serial monitor. 
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/16 
***********************************************************/
int joystickXPin = 0;           // the joystick X pin connected to analog pin 0
int joystickYPin = 1;           // the joystick Y pin connected to analog pin 1
int joystickZPin = 2;           // the joystick S pin connected to digital pin 2
void setup() 
{                
  pinMode(joystickXPin, INPUT); //Set analog 0 port mode, the INPUT for the input
  pinMode(joystickYPin, INPUT); //Set analog 1 port mode, the INPUT for the input
  pinMode(joystickZPin, INPUT_PULLUP); //Set digital 2 port mode, the INPUT for the input
  Serial.begin(9600);          //opens serial port, sets data rate to 9600 bps
}
void loop() 
{ 
 Serial.print("X:");             //send "X:" to the serial monitor
 Serial.print(analogRead(0));    //send X data to the serial monitor
 Serial.print("  Y:");           //send "  Y:" to the serial monitor
 Serial.print(analogRead(1));    //send Y data to the serial monitor
 Serial.print("  Z:");           //send "  Z:" to the serial monitor
 Serial.println(digitalRead(2)); //send Z data to the serial monitor
 delay(50);                      //delay 0.05 s
}




