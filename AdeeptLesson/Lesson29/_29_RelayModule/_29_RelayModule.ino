/***********************************************************
File name: _29_RelayModule.ino
Description:When the relay sucks, the LED will light up; when 
            the relay breaks, the LED will go out.
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/16 
***********************************************************/
const int relayPin = 8;          //the relay module S pin connected to digital pin 8

void setup()
{
  pinMode(relayPin, OUTPUT);    //initialize the relayPin as an output
}

void loop()
{
  digitalWrite(relayPin, HIGH); //drive relay closure conduction
  delay(1000);                  //wait for a second

  digitalWrite(relayPin, LOW);  //drive the relay is closed off
  delay(1000);                  //wait for a second
}

