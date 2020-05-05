/***********************************************************
File name:  _50_LED_Processing.ino
Description:  Lit LED, let LED blinks.
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/12 
***********************************************************/
int redledPin=8;     //definition digital 8 pin to control the LED module
int greenledPin=9;   //definition digital 9 pin to control the LED module
int blueledPin=10;   //definition digital 10 pin to control the LED module
int yellowledPin=11; //definition digital 11 pin to control the LED module
int val;

void setup()
{
    pinMode(redledPin,OUTPUT);      //Set the digital 8 port mode, OUTPUT: Output mode
    pinMode(greenledPin,OUTPUT);    //Set the digital 9 port mode, OUTPUT: Output mode
    pinMode(blueledPin,OUTPUT);     //Set the digital 10 port mode, OUTPUT: Output mode
    pinMode(yellowledPin,OUTPUT);   //Set the digital 11 port mode, OUTPUT: Output mode   
    Serial.begin(9600);            // Start the serial port, baud rate to 9600
}
void loop()
{  
   if(Serial.available()){ //Detect whether the serial data
      val = Serial.read(); //Read back the data stored in the val
    } 
   if(val == 'R'){ //Analyzing the data read is not 'R'
      digitalWrite(redledPin,HIGH); //Red led on
    }else{
      digitalWrite(redledPin,LOW);  //Red led off
    }
    if(val == 'G'){//Analyzing the data read is not 'G'
       digitalWrite(greenledPin,HIGH); //Green led on
     }else{
       digitalWrite(greenledPin,LOW);  //Green led off
     }
     if(val == 'B'){//Analyzing the data read is not 'B'
       digitalWrite(blueledPin,HIGH);  //Blue led on 
     }else{
       digitalWrite(blueledPin,LOW);   //Blue led off
     }
     if(val == 'Y'){//Analyzing the data read is not 'Y'
       digitalWrite(yellowledPin,HIGH); //Yellow led on
     }else{
       digitalWrite(yellowledPin,LOW);  //Yellow led off
     }
} 
