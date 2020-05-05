/***********************************************************
File name: _38_buttonDisplaySerial.ino
Description: When you press the button, you can see the state
             of the serial monitor.
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/03 
***********************************************************/

int btnpin=12;           //Set the digital 12 to button module interface 

void setup()
{
  Serial.begin(9600);   //opens serial port, sets data rate to 9600 bps
  pinMode(btnpin,INPUT); //Set digital 12 port mode, the INPUT for the input
}

void loop()
{
  if(digitalRead(btnpin)==LOW)              //Detection button interface to LOW
  {   
      delay(10);                              //Delay 10ms for the elimination of key leading-edge jitter
      if(digitalRead(btnpin)==LOW)           //Confirm button is pressed
      {     
        while(digitalRead(btnpin)==LOW);     //Wait for key interfaces to HIGH
        delay(10);                            //delay 10ms for the elimination of key trailing-edge jitter
        while(digitalRead(btnpin)==LOW);     //Confirm button release
         Serial.println("Press the button"); //send data to the serial monitor
      }
   }
   delay(100); //delay 0.1 s
}
