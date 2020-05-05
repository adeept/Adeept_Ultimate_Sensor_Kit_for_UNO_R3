/***********************************************************
File name: _19_LaserReceiverModule.ino
Description: The information of laser receiver module has been
             detected by UNO R3,and displayed in the serial monitor 
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/15 
***********************************************************/
int laserreceiverPin=8;            //Set the digital 8 to the S pin
void setup() {
  pinMode( laserreceiverPin,INPUT);//initialize the S pin as input
  Serial.begin(9600);             //opens serial port, sets data rate to 9600 bps
}

void loop() {
  if(digitalRead(laserreceiverPin)==LOW){
     Serial.println("No laser received");      //send data to the serial monitor
  }else{
     Serial.println("Received laser");   //send data to the serial monitor
  }
  delay(200);                                //delay 0.2s
}
