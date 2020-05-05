/***********************************************************
File name: _25_SlidePotentiometerModule.ino
Description: Now, when you turning the slide potentiometer,
             you will see the data in the serial monitor    
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/15 
***********************************************************/
int slidepotentiometerPin = 0;           //slide potentiometer A pin connected to analog 0 pin
void setup() 
{                
  pinMode(slidepotentiometerPin, INPUT);//initialize the slide potentiometer A pin as input
  Serial.begin(9600);                  //opens serial port, sets data rate to 9600 bps
}
void loop() 
{
 Serial.println(analogRead(slidepotentiometerPin)); //send data to the serial monitor
 delay(50);                     // delay 0.05 s
}




