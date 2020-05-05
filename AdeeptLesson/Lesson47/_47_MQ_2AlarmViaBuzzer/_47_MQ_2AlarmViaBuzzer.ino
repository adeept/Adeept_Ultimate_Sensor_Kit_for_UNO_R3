/***********************************************************
File name:   _47_MQ_2AlarmViaBuzzer.ino
Description: MQ2 detected smoke or gas, buzzer sounded.
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/03 
***********************************************************/
int gassensorSPin = 7;       //connect S pin to digital 7 pin 
int gassensorAPin = 1;       //connect A pin to analog 1 pin
int passiveBuzzerPin = 5;    //definition digital 5 pins as pin to control the passive buzzer
int gassensorThreshold = 100;//0~1023

void setup() 
{                
  pinMode(gassensorSPin,INPUT);     //initialize the MQ-2 gas sensor S pin as input
  pinMode(gassensorAPin,INPUT);     //initialize the MQ-2 gas sensor A pin as input
  pinMode(passiveBuzzerPin,OUTPUT); //set digital 5 port mode, the OUTPUT for the output
}
void loop() 
{
  int data = analogRead(gassensorAPin);
  if(digitalRead(gassensorSPin)==LOW){
    tone(passiveBuzzerPin,1000);        //1000Hz frequency: 31~65535Hz 
    delay(1000);                        //set the delay time，1000ms
    noTone(passiveBuzzerPin);           //Turn off the buzzer
    delay(2000);                        //set the delay time，2000ms 
  }
  if(data>gassensorThreshold){
    tone(passiveBuzzerPin,1000);        //1000Hz frequency: 31~65535Hz 
    delay(1000);                        //set the delay time，1000ms
    noTone(passiveBuzzerPin);           //Turn off the buzzer
    delay(1000);                        //set the delay time，1000ms 
    }
  delay(100);                           //set the delay time，1000ms 
}

