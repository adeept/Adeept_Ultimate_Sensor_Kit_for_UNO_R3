/***********************************************************
File name: _43_simpleStreetLight.ino
Description:Use the photoresistor to detect light, control 
            RGB to light or off.  
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/02 
*************************************************************/
int redPin = 11;          // R petal on RGB LED module connected to digital pin 11 
int greenPin = 10;        // G petal on RGB LED module connected to digital pin 10
int bluePin = 6;          // B petal on RGB LED module connected to digital pin 6
int photoresistorPin = 0; // photoresistor  connected to analog pin 0
void setup()    
{   
   pinMode(redPin, OUTPUT);         // sets the redPin to be an output 
   pinMode(greenPin, OUTPUT);       // sets the greenPin to be an output 
   pinMode(bluePin, OUTPUT);        // sets the bluePin to be an output 
   pinMode(photoresistorPin, INPUT);//Set analog 0 port mode, the INPUT for the input
}    
void loop()  // run over and over again  
{    
   int data = analogRead(0);
   if(data>=700)
   {
     color(0,0,0);       // turn the RGB LED off  
     delay(100);         // delay for 0.1 second  
   }else{
     color(255,255,255); // turn the RGB LED white  
     delay(100);         // delay for 0.1 second  
   } 
   delay(100);           // delay for 0.1 second  
}     
     
void color (unsigned char red, unsigned char green, unsigned char blue)// the color generating function  
{    
     analogWrite(redPin, 255-red);     // PWM signal output   
     analogWrite(greenPin, 255-green); // PWM signal output
     analogWrite(bluePin, 255-blue);   // PWM signal output
}     


