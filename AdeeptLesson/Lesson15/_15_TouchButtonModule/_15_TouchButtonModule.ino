/***********************************************************
File name: _15_TouchButtonModule.ino
Description: The information of touch button module has been
             detected by UNO R3,and displayed in the serial monitor 
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/15 
***********************************************************/
int touchbuttonPin=8;            //Set the digital 8 to touch button
void setup() {
  pinMode( touchbuttonPin,INPUT);//initialize the touch button pin as input
  Serial.begin(9600);           //opens serial port, sets data rate to 9600 bps
}

void loop() {
  if(digitalRead(touchbuttonPin)==LOW)
  {
     Serial.println("No finger touched!"); //send data to the serial monitor
  }else
  {
     Serial.println("Finger touched!");    //send data to the serial monitor
  }
  delay(1000);                              //delay 1s
}
