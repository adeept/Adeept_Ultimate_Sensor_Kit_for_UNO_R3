/***********************************************************
File name:  _18_LaserTransmitterModule.ino
Description:  Emitting laser 5 seconds,
              stop emitting laser 5 seconds.
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/12 
***********************************************************/
int lasertransmitterPin=8; //definition digital 8 pin to control the laser transmitter module
void setup()
{
    pinMode(lasertransmitterPin,OUTPUT);    //Set the digital 8 port mode, OUTPUT: Output mode
}
void loop()
{  
    digitalWrite(lasertransmitterPin,HIGH); //HIGH is set to about 5V PIN8
    delay(5000);                            //Set the delay time, 5000 = 5S
    digitalWrite(lasertransmitterPin,LOW);  //LOW is set to about 5V PIN8
    delay(5000);                            //Set the delay time, 5000 = 5S
} 
