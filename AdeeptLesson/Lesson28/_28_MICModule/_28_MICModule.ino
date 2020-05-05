/***********************************************************
File name: _28_MICModule.ino
Description:We measure the information of MIC module, 
            and displayed in the serial monitor. 
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/18 
***********************************************************/

int micSPin = 8;//the mic module X pin connected to digital pin 8
int micAPin = 0;//the mic module A pin connected to analog pin 0
void setup() 
{                
  pinMode(micSPin, INPUT);//Set digital 8 port mode, the INPUT for the input
  pinMode(micAPin, INPUT);//Set analog 0 port mode, the INPUT for the input
  Serial.begin(9600);    //open serial port, sets data rate to 9600 bps
}
void loop() 
{
  if(digitalRead(micSPin)==HIGH){
    Serial.print("NO sound");    //send "NO sound" to the serial monitor
  }else{
    Serial.print("Sound");       //send "Sound" to the serial monitor
  }
  Serial.println(analogRead(0)); //send A pin data to the serial monitor
  delay(100);                    //delay 0.1s
}

