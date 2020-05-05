/***********************************************************
File name: _34_SoilMoistureModule.ino
Description: Now, when UNO collect soil moisture module data,
             you will see the data in the serial monitor 
        
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/20 
***********************************************************/
int soilmoisturePin = 0;               // soil moisture module A pin connected to analog pin 0
void setup() 
{                
  pinMode(soilmoisturePin, INPUT);     //Set Analog 0 port mode, the INPUT for the input
  Serial.begin(9600);                 // opens serial port, sets data rate to 9600 bps
}
void loop() 
{
 Serial.print("Soil moisture data: "); //send data to the serial monitor
 Serial.println(analogRead(0));        //send data to the serial monitor
 delay(1000);                           //delay 1 s
}




