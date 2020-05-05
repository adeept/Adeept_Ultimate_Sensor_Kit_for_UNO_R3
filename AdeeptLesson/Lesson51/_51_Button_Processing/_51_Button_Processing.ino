/***********************************************************
File name:  _51_Button_Processing.ino
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/12 
***********************************************************/
int redbuttonPin=8;      //definition digital 8 pin to control the button module
int whitebuttonPin=9;    //definition digital 9 pin to control the button module
int bluebutton1Pin=10;   //definition digital 10 pin to control the button module
int bluebutton2Pin=11;   //definition digital 11 pin to control the button module
int val;

void setup()
{
    pinMode(redbuttonPin,INPUT);       //Set the digital 8 port mode,  INPUT mode
    pinMode(whitebuttonPin,INPUT);     //Set the digital 9 port mode,  INPUT mode
    pinMode(bluebutton1Pin,INPUT);     //Set the digital 10 port mode, INPUT mode
    pinMode(bluebutton2Pin,INPUT);     //Set the digital 11 port mode, INPUT mode   
    Serial.begin(9600);               // Start the serial port, baud rate to 9600
}
void loop()
{  
    if(digitalRead(redbuttonPin)==LOW){  //Detection button interface to low
         val = val|0x01;    
    }else{
         val = val&0x0E; 
    }
     if(digitalRead(whitebuttonPin)==LOW){  //Detection button interface to low
          val = val|0x02;     
     }else{
          val = val&0x0D; 
     }
     if(digitalRead(bluebutton1Pin)==LOW){  //Detection button interface to low
          val = val|0x04;   
      }else{
          val = val&0x0B;  
     }
     if(digitalRead(bluebutton2Pin)==LOW){  //Detection button interface to low
         val = val|0x08;   
       }else{
         val = val&0x07; 
    }
    Serial.write(val); //send data to the serial monitor  
    delay(50);
} 
