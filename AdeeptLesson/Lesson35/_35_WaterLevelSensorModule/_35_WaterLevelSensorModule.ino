/***********************************************************
File name: _35_WaterLevelSensorModule.ino
Description: Now, when UNO collect water level sensor module data,
             you will see the data in the serial monitor 
        
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/20 
***********************************************************/
int waterlevelPin = 0;                 // water level sensor module A pin connected to analog pin 0
void setup() 
{                
  pinMode(waterlevelPin, INPUT);       //Set Analog 0 port mode, the INPUT for the input
  Serial.begin(9600);                 // opens serial port, sets data rate to 9600 bps
}
void loop() 
{
 Serial.print("Water level sensor data: "); //send data to the serial monitor
 Serial.println(analogRead(0));             //send data to the serial monitor
 delay(1000);                                //delay 1 s
}




