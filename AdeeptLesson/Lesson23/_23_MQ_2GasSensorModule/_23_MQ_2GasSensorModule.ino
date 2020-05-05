/***********************************************************
File name:   _23_MQ_2GasSensorModule.ino
Description: The information of MQ-2 gas sensor module has been
             detected by UNO R3,and displayed in the serial monitor 
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/15 
***********************************************************/
int gassensorSPin = 8;//connect S pin to digital 8 pin 
int gassensorAPin = 0;//connect A pin to analog 0 pin

void setup() 
{                
  pinMode(gassensorSPin,INPUT);//initialize the MQ-2 gas sensor S pin as input
  pinMode(gassensorAPin,INPUT);//initialize the MQ-2 gas sensor A pin as input
  Serial.begin(9600);         //opens serial port, sets data rate to 9600 bps
}
void loop() 
{
  if(digitalRead(gassensorSPin)==HIGH){
    Serial.print("Methane gas is not detected.   Analog data:"); //send data to the serial monitor
  }else{
    Serial.print("Methane gas is detected.       Analog data:");   //send data to the serial monitor
  }
  Serial.println(analogRead(0));         //send analog data(A pin) to the serial monitor
  delay(50);
}

