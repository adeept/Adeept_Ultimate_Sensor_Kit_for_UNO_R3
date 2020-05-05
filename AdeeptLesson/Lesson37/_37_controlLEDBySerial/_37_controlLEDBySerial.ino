/***********************************************************
File name: _37_controlLEDBySerial.ino
Description: If you send a character ‘1’ or ‘0’ on the 
             serial monitor, the status of LED will be lit 
             or gone out.
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/03 
***********************************************************/

int ledpin=13;           //definition digital 13 pins as pin to control the LED

void setup()
{
  Serial.begin(9600);   // opens serial port, sets data rate to 9600 bps
  pinMode(ledpin,OUTPUT);//Set digital 13 port mode, the OUTPUT for the output
}
void loop()
{
    char receiveVal;                  // Defined receive data
   
    if(Serial.available() > 0)       //Receive serial data
    {        
        receiveVal = Serial.read();  //Save the serial data received 
        
       if(receiveVal == '1')          //Receive data is 1, lit LED lights    
       { 
           digitalWrite(ledpin,HIGH); //print out the value of the LED       
           Serial.println("LED:ON"); //send data to the serial monitor
       }
       if(receiveVal == '0')          //Receive data is 0, off LED lights
       { 
           digitalWrite(ledpin,LOW);  //print out the value of the LED                
           Serial.println("LED:OFF");//send data to the serial monitor
      } 
    }
  delay(50);                          //delay 50ms
}

