/***********************************************************
File name: _07_PhotoresistorModule.ino
Description: We measure the light intensity of information with
             photosensitive resistance, and displayed in the 
             serial monitor. 
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/12 
***********************************************************/
int photoresistorPin = 0;          // photoresistor  connected to analog pin 0
void setup() 
{                
  pinMode(photoresistorPin, INPUT);//Set analog 0 port mode, the INPUT for the input
  Serial.begin(9600);             //opens serial port, sets data rate to 9600 bps
}
void loop() 
{
 Serial.println(analogRead(0));   //send data to the serial monitor
 delay(50);                        //delay 0.05 s
}




