/***********************************************************
File name:  _01_LEDModule.ino
Description:  Lit LED, let LED blinks.
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/07/12 
***********************************************************/
int ledPin=8; //definition digital 8 pin to control the LED module
void setup()
{
    pinMode(ledPin,OUTPUT);    //Set the digital 8 port mode, OUTPUT: Output mode
}
void loop()
{  
    digitalWrite(ledPin,HIGH); //HIGH is set to about 5V PIN8
    delay(500);                //Set the delay time, 500 = 0.5S
    digitalWrite(ledPin,LOW);  //LOW is set to about 5V PIN8
    delay(500);                //Set the delay time, 500 = 0.5S
} 
