/***********************************************************
File name: _10_ActiveBuzzerModule.ino
Description: The active buzzer beeps like the sound of "Di Di"..
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/14 
***********************************************************/
int activebuzzerPin=8; //definition digital 8 pins as pin to control the active buzzer
void setup()
{
    pinMode(activebuzzerPin,OUTPUT); //set digital 8 port mode, the OUTPUT for the output
}
void loop()
{  
    digitalWrite(activebuzzerPin,HIGH); //set PIN 8 feet as HIGH = 5 v "Di"
    delay(2000);                        //set the delay time，2000ms 
    digitalWrite(activebuzzerPin,LOW);  //Set PIN 8 feet for LOW = 0 v "no Di" 
    delay(2000);                        //set the delay time，2000ms 
}
