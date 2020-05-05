/***********************************************************
File name: _21_ReedModule.ino
Description: The information of reed module has been
             detected by UNO R3,and displayed in the serial monitor 
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/15 
***********************************************************/
int reedPin=8;             //Set the digital 8 to the S pin
void setup() {
  pinMode( reedPin,INPUT); //initialize the reed pin as input
  Serial.begin(9600);     //opens serial port, sets data rate to 9600 bps
}

void loop() {
  if(digitalRead(reedPin)==LOW){
     Serial.println("Reed not pull"); //send data to the serial monitor
  }else{
     Serial.println("Reed pull");     //send data to the serial monitor
  }
  delay(200);                          //delay 0.2s
}
