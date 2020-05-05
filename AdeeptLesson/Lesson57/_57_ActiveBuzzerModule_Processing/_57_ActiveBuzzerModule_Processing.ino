/***********************************************************
File name: _57_ActiveBuzzerModule_Processing.ino
Description: Arduino uno continuous beeps control buzzer.
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/12 
***********************************************************/
int activebuzzerPin=8; //definition digital 8 pins as pin to control the active buzzer
int val;
void setup()
{
    pinMode(activebuzzerPin,OUTPUT); //set digital 8 port mode, the OUTPUT for the output
    Serial.begin(9600);             // Start the serial port, baud rate to 9600
}
void loop()
{  
    if(Serial.available()){ //Detect whether the serial data
      val = Serial.read(); //Read back the data stored in the val
    } 
    if(val == 'H'){
      digitalWrite(activebuzzerPin,HIGH); //set PIN 8 feet as HIGH = 5 v 
    }else{
      digitalWrite(activebuzzerPin,LOW);  //Set PIN 8 feet for LOW = 0 v 
    }
}
