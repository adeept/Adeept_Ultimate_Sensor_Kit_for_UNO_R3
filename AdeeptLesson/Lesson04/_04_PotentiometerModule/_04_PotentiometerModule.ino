/***********************************************************
File name: _04_PotentiometerModule.ino
Description: Now, when you turning the shaft of the potentiometer,
             you will see the data in the serial monitor 
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/12 
***********************************************************/
int potentiometerPin = 0;        // potentiometer wiper (middle terminal) connected to analog pin 0
void setup() 
{                
  pinMode(potentiometerPin, INPUT);
  Serial.begin(9600);           // opens serial port, sets data rate to 9600 bps
}
void loop() 
{
 Serial.println(analogRead(0)); //send data to the serial monitor
 delay(50);                      // delay 0.05 s
}




