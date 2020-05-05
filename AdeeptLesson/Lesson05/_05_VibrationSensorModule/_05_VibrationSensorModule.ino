/***********************************************************
File name: _05_VibrationSensorModule.ino
Description: Observed the status LED lights when the shock sensor is shaking.
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/12 
***********************************************************/
int vibrationPin = 2;  //Set the digital 2 to button module interface 
int LledPin = 13;      //Set the digital 13 to L LED(on the UNO board) interface
int state = 0;         // Defined output status LED Interface
void setup() 
{                
  pinMode(LledPin, OUTPUT);       //Set digital 13 port mode, the OUTPUT for the output
  pinMode(vibrationPin, INPUT);   //Set digital 2 port mode, the INPUT for the input
}
void loop() 
{
  state = digitalRead(vibrationPin);//read the vibration sensor module status
  if(state == LOW){
      digitalWrite(LledPin, HIGH);  //Output control status LED, ON 
    }else{
      digitalWrite(LledPin, LOW);   //Output control status LED, OFF 
    }
}




