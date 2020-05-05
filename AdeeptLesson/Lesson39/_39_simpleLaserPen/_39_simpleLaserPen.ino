/***********************************************************
File name: _39_simpleLaserPen.ino
Description: When you press the button, you can see the state
              of the laser will be toggled. (ON->OFF，OFF->ON).
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/12 
***********************************************************/

int laserpin=11;            //definition digital 11 pins as pin to control the laser module
int btnpin=2;               //Set the digital 2 to button module interface 

volatile int state = LOW;   // Defined output status LED Interface

void setup()
{
  pinMode(laserpin,OUTPUT);//Set digital 11 port mode, the OUTPUT for the output
  pinMode(btnpin,INPUT); //Set digital 2 port mode, the INPUT for the input
}

void loop()
{
  if(digitalRead(btnpin)==HIGH)          //Detection button interface to low
  {   
      delay(10);                        //Delay 10ms for the elimination of key leading-edge jitter
      if(digitalRead(btnpin)==HIGH)      //Confirm button is pressed
      {     
        while(digitalRead(btnpin)==HIGH);//Wait for key interfaces to high
        delay(10);                      //delay 10ms for the elimination of key trailing-edge jitter
        while(digitalRead(btnpin)==HIGH);//Confirm button release
        state = !state;                 //Negate operation, each time you run the program here, state the HGIH becomes LOW, or the state becomes the LOW HGIH.
        digitalWrite(laserpin,state);     //Output control status laser, ON or OFF 
      }
   }
}
