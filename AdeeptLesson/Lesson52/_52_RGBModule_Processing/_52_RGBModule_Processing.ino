/***********************************************************
File name: _52_RGBModule_Processing.ino
Description:Control the RGB LED emitting white red, green, blue, 
            light,  
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/12 
*************************************************************/
int redPin = 11;   // R petal on RGB LED module connected to digital pin 11 
int greenPin = 10; // G petal on RGB LED module connected to digital pin 9 
int bluePin = 9;   // B petal on RGB LED module connected to digital pin 10 
int temp = 0;
int RGB[3] = {0,0,0};
int data = 0;
void color (unsigned char red, unsigned char green, unsigned char blue);// the color generating function  
void setup()    
{   
   pinMode(redPin, OUTPUT);   // sets the redPin to be an output 
   pinMode(greenPin, OUTPUT); // sets the greenPin to be an output 
   pinMode(bluePin, OUTPUT);  // sets the bluePin to be an output 
   Serial.begin(9600);            // Start the serial port, baud rate to 9600
}    
void loop()  // run over and over again  
{    
   int j = 0;
   while(Serial.available()){ //Detect whether the serial data    
      temp  = Serial.read(); //Read back the data stored in the val
      switch(data){
        case 1: RGB[0] = temp; data = 0; break;
        case 2: RGB[1] = temp; data = 0; break;
        case 3: RGB[2] = temp; data = 0; break;
        default: break;
        }
      switch(temp){
        case 'R': data=1;  break;
        case 'G': data=2;  break;
        case 'B': data=3;  break;
        default: break;
        }
        delay(2);
   }
    color(RGB[0], RGB[1], RGB[2]); // turn the RGB LED red  
    delay(100);
}     
void color (unsigned char red, unsigned char green, unsigned char blue)// the color generating function  
{    
     analogWrite(redPin, 255-red);     // PWM signal output   
     analogWrite(greenPin, 255-green); // PWM signal output
     analogWrite(bluePin, 255-blue);   // PWM signal output
}     


