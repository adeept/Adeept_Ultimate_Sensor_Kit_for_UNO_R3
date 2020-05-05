/***********************************************************
File name:   _22_FlameSensorModule.ino
Description: The information of flame sensor module has been
             detected by UNO R3,and displayed in the serial monitor 
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/15 
***********************************************************/
int flamesensorSPin = 8;//connect S pin to digital 8 pin 
int flamesensorAPin = 0;//connect A pin to analog 0 pin

void setup() 
{                
  pinMode(flamesensorSPin,INPUT);//initialize the flame sensor S pin as input
  pinMode(flamesensorAPin,INPUT);//initialize the flame sensor A pin as input
  Serial.begin(9600);   // opens serial port, sets data rate to 9600 bps
}
void loop() 
{
  if(digitalRead(flamesensorSPin)==1){
    Serial.print("No flame .   Flame intensity:"); //send data to the serial monitor
  }else{
    Serial.print("Flame    .   Flame intensity:");   //send data to the serial monitor
  }
  Serial.println(analogRead(0));         //send analog data(A pin) to the serial monitor
  delay(50);
}

