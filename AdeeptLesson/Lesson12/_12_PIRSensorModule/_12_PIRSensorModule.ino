/***********************************************************
File name: _12_PIRSensorModule.ino
Description: The motion has been detected by PIR sensor module,
             and displayed in the serial monitor 
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/14 
***********************************************************/
int PIRPin=8;           //Set the digital 8 to PIR
void setup() {
  pinMode( PIRPin,INPUT);//initialize the  PIR pin as input
  Serial.begin(9600);   //opens serial port, sets data rate to 9600 bps
}

void loop() {
  if(digitalRead(PIRPin)==LOW)
  {
     Serial.println("No invasion"); //send data to the serial monitor
  }else
  {
     Serial.println("Invasion");    //send data to the serial monitor
  }
  delay(1000);                       //delay 1s
}
