/***********************************************************
File name: _55_Photoresistor_Processing.ino
Description: Arduino and processing interactive
             Phototresistor control the brightness of the photo
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/12 
***********************************************************/
int photoresistorPin = 0;           // photoresistor connected to analog pin 0
int sensorValue;
int outputValue;
void setup() 
{                
  pinMode(photoresistorPin, INPUT);//Set analog 0 port mode, the INPUT for the input
  Serial.begin(9600);             //opens serial port, sets data rate to 9600 bps
}
void loop() 
{
   sensorValue = analogRead(photoresistorPin);
   outputValue = map(sensorValue,0,1023,0,255);//Transform data
   Serial.write(outputValue); //send data to the serial monitor
   delay(100);
}
