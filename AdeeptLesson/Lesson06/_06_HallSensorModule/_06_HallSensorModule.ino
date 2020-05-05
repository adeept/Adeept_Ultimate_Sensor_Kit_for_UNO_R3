/***********************************************************
File name: _06_HallSensorModule.ino
Description:  Now,when the magnet close to the module,
             you will see the data in the serial monitor 
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/12 
***********************************************************/
int hallsensorPin=2;             //Set the digital 2 to hall sensor module interface 

void setup()
{
  pinMode(hallsensorPin,INPUT);  //Set digital 2 port mode, the INPUT for the input
  Serial.begin(9600);           //opens serial port, sets data rate to 9600 bps
}

void loop()
{
  if(digitalRead(hallsensorPin)==HIGH) //Detection hall sensor module interface to high
  {   
      Serial.println("High");   //send data to the serial monitor
      delay(1000);               //delay 1 s
   }else{
      Serial.println("low");    //send data to the serial monitor
      delay(1000);                //delay 1 s
   }
}
