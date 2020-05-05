/***********************************************************
File name: _17_LimitSwitchModule.ino
Description: The information of limit switch module has been
             detected by UNO R3,and displayed in the serial monitor 
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/15 
***********************************************************/
int limitswitchPin=8;            //Set the digital 8 to the S pin
void setup() {
  pinMode( limitswitchPin,INPUT);//initialize the S pin as input
  Serial.begin(9600);           //opens serial port, sets data rate to 9600 bps
}

void loop() {
  if(digitalRead(limitswitchPin)==LOW)
  {
     Serial.println("Limit switch is not triggering!"); //send data to the serial monitor
  }else
  {
     Serial.println("Limit Switch triggered!");         //send data to the serial monitor
  }
  delay(500);                                            //delay 0.5s
}
