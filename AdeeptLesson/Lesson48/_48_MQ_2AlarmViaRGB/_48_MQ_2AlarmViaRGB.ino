/***********************************************************
File name:   _48_MQ_2AlarmViaRGB.ino
Description: MQ2 detected smoke or gas, RGB color change.
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/03 
***********************************************************/
int redPin = 11;         // R petal on RGB LED module connected to digital pin 11 
int greenPin = 10;       // G petal on RGB LED module connected to digital pin 10 
int bluePin = 6;         // B petal on RGB LED module connected to digital pin 6
int gassensorSPin = 7;   //connect S pin to digital 7 pin 
int gassensorAPin = 1;   //connect A pin to analog 1 pin
int gassensorThreshold = 100;//0~1023

void setup() 
{                
  pinMode(redPin, OUTPUT);     // sets the redPin to be an output 
  pinMode(greenPin, OUTPUT);   // sets the greenPin to be an output 
  pinMode(bluePin, OUTPUT);    // sets the bluePin to be an output 
  pinMode(gassensorSPin,INPUT);//initialize the MQ-2 gas sensor S pin as input
  pinMode(gassensorAPin,INPUT);//initialize the MQ-2 gas sensor A pin as input
}
void loop() 
{
  int data = analogRead(gassensorAPin);
  if(digitalRead(gassensorSPin)==LOW){
    color(255, 0, 0);  // turn the RGB LED red 
  }else{
    color(0,255, 0);   // turn the RGB LED green  
  }
  if(data>gassensorThreshold){
    color(255, 0, 0);  // turn the RGB LED red 
    }else{
      color(0,255, 0); // turn the RGB LED green  
    }
  delay(100);          //set the delay time，1000ms 
}
void color (unsigned char red, unsigned char green, unsigned char blue)// the color generating function  
{    
     analogWrite(redPin, 255-red);     // PWM signal output   
     analogWrite(greenPin, 255-green); // PWM signal output
     analogWrite(bluePin, 255-blue);   // PWM signal output
}     
