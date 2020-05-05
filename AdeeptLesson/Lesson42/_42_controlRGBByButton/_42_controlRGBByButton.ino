/***********************************************************
File name: _42_controlRGBByButton.ino
Description:The button control RGB LED color change 
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/02 
*************************************************************/
int redPin = 11;         // R petal on RGB LED module connected to digital pin 11 
int greenPin = 10;       // G petal on RGB LED module connected to digital pin 10 
int bluePin = 6;         // B petal on RGB LED module connected to digital pin 6
int blueButton1Pin=13;   //Set the digital 13 to blue 1 button module interface 
int blueButton2Pin=12;   //Set the digital 12 to blue 2 button module interface 
int redButtonPin=1;      //Set the digital 1 to red button module interface 
int whiteButtonPin=0;    //Set the digital 0 to white button module interface 

void setup()    
{   
   pinMode(redPin, OUTPUT);   // sets the redPin to be an output 
   pinMode(greenPin, OUTPUT); // sets the greenPin to be an output 
   pinMode(bluePin, OUTPUT);  // sets the bluePin to be an output 
   pinMode(blueButton1Pin,INPUT); //Set digital 13 port mode, the INPUT for the input
   pinMode(blueButton2Pin,INPUT); //Set digital 12 port mode, the INPUT for the input
   pinMode(redButtonPin,INPUT);   //Set digital 1 port mode, the INPUT for the input
   pinMode(whiteButtonPin,INPUT); //Set digital 0 port mode, the INPUT for the input
   color(0,0,0);                  //turn off  
}    
void loop()      // run over and over again  
{    
  if(digitalRead(blueButton1Pin)==LOW) //Detection button interface to low
  {   
      delay(10); //Delay 10ms for the elimination of key leading-edge jitter
      if(digitalRead(blueButton1Pin)==LOW) //Confirm button is pressed
      {     
         color(0, 0, 255);  // turn the RGB LED blue
         delay(100);        // delay for 0.1 second  
      }
   }
  if(digitalRead(blueButton2Pin)==LOW) //Detection button interface to low
  {   
      delay(10);  //Delay 10ms for the elimination of key leading-edge jitter
      if(digitalRead(blueButton2Pin)==LOW) //Confirm button is pressed
      {     
         color(0,255, 0);  // turn the RGB LED green  
         delay(100);       // delay for 0.1 second  
      }
   }
  if(digitalRead(redButtonPin)==LOW) //Detection button interface to low
  {   
      delay(10);  //Delay 10ms for the elimination of key leading-edge jitter
      if(digitalRead(redButtonPin)==LOW) //Confirm button is pressed
      {       
         color(255, 0, 0);  // turn the RGB LED red  
         delay(100);        // delay for 0.1 second  
      }
   }   
  if(digitalRead(whiteButtonPin)==LOW) //Detection button interface to low
  {   
      delay(10);  //Delay 10ms for the elimination of key leading-edge jitter
      if(digitalRead(whiteButtonPin)==LOW) //Confirm button is pressed
      {       
         color(255,255,255); // turn the RGB LED white   
         delay(100);         // delay for 0.1 second  
      }
   } 
   delay(100); // delay for 0.1 second 
}     
     
void color (unsigned char red, unsigned char green, unsigned char blue) // the color generating function  
{    
     analogWrite(redPin, 255-red);     // PWM signal output   
     analogWrite(greenPin, 255-green); // PWM signal output
     analogWrite(bluePin, 255-blue);   // PWM signal output
}     


