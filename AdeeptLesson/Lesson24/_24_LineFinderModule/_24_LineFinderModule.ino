/***********************************************************
File name: _24_LineFinderModule.ino
Description: The information of line finder module has been
             detected by UNO R3,and displayed in the serial monitor 
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/15 
***********************************************************/
int linefinderPin=8;             //Set the digital 8 to the S pin
void setup() {
  pinMode( linefinderPin,INPUT); //initialize the line finder S pin as input
  Serial.begin(9600);           //opens serial port, sets data rate to 9600 bps
}

void loop() {
  if(digitalRead(linefinderPin)==LOW){
     Serial.println("White"); //send data to the serial monitor
  }else{
     Serial.println("Black"); //send data to the serial monitor
  }
  delay(200);                  //delay 0.2s
}
