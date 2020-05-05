/***********************************************************
File name: _40_controlBuzzerByButton.ino
Description: Press the button to control the buzzer.
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/02 
***********************************************************/
int passiveBuzzerPin=5;  //definition digital 5 pins as pin to control the passive buzzer
int blueButton1Pin=13;   //Set the digital 13 to blue 1 button module interface 
int blueButton2Pin=12;   //Set the digital 12 to blue 2 button module interface 
int redButtonPin=1;      //Set the digital 1 to red button module interface 
int whiteButtonPin=0;    //Set the digital 0 to white button module interface 
void setup()
{
   pinMode(passiveBuzzerPin,OUTPUT); //set digital 8 port mode, the OUTPUT for the output
   pinMode(blueButton1Pin,INPUT); //Set digital 13 port mode, the INPUT for the input
   pinMode(blueButton2Pin,INPUT); //Set digital 12 port mode, the INPUT for the input
   pinMode(redButtonPin,INPUT);   //Set digital 1 port mode, the INPUT for the input
   pinMode(whiteButtonPin,INPUT); //Set digital 0 port mode, the INPUT for the input
}
void loop()
{  
 if(digitalRead(blueButton1Pin)==LOW) //Detection button interface to low
  {   
      delay(10); //Delay 10ms for the elimination of key leading-edge jitter
      if(digitalRead(blueButton1Pin)==LOW) //Confirm button is pressed
      {     
         tone(passiveBuzzerPin,31);          //31Hz frequency: 31~65535Hz 
         delay(500);                        //set the delay time，500ms
      }
   }
  if(digitalRead(blueButton2Pin)==LOW) //Detection button interface to low
  {   
      delay(10);  //Delay 10ms for the elimination of key leading-edge jitter
      if(digitalRead(blueButton2Pin)==LOW) //Confirm button is pressed
      {     
          tone(passiveBuzzerPin,100);          //100Hz frequency: 31~65535Hz 
          delay(500);                        //set the delay time，500ms
      }
   }
  if(digitalRead(redButtonPin)==LOW) //Detection button interface to low
  {   
      delay(10);  //Delay 10ms for the elimination of key leading-edge jitter
      if(digitalRead(redButtonPin)==LOW) //Confirm button is pressed
      {       
          tone(passiveBuzzerPin,500);          //500Hz frequency: 31~65535Hz 
          delay(500);                        //set the delay time，500ms
      }
   }   
  if(digitalRead(whiteButtonPin)==LOW) //Detection button interface to low
  {   
      delay(10);  //Delay 10ms for the elimination of key leading-edge jitter
      if(digitalRead(whiteButtonPin)==LOW) //Confirm button is pressed
      {       
          tone(passiveBuzzerPin,2000);          //2000Hz frequency: 31~65535Hz 
          delay(500);                        //set the delay time，500ms
      }
   } 
  noTone(passiveBuzzerPin);//Turn off the buzzer
  delay(100);                        //set the delay time，100ms 
}
