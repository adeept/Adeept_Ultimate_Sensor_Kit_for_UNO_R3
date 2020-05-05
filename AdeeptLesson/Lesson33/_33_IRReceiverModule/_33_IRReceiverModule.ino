/***********************************************************
File name: _33_IRReceiverModule.ino
Description: When you click the button on the remote control,
             you can see the data on the serial montiol.
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/17 
***********************************************************/
#include <IRremote.h>

int RECV_PIN = 11;//The definition of the infrared receiver pin 11
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600); //Open serial 
  irrecv.enableIRIn(); // Initialization infrared receiver
} 

void loop() 
{
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);//Wrap output in hex receive code
    Serial.println();//For ease of viewing the output to add a blank line
    irrecv.resume(); //Receiving the next value
  }
}


