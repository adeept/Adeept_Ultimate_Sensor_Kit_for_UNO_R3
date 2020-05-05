/***********************************************************
File name: _54_Vibration_Processing.ino
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
  Serial.begin(9600);   // opens serial port, sets data rate to 9600 bps
  //D2 port for the external interrupt 0, when a falling edge trigger call blink function
  attachInterrupt(digitalPinToInterrupt(vibrationPin), blink, FALLING);
}
void loop() 
{
  if(state != 0){//If the vibration sensor is interrupted
    Serial.write(1); //send '1' to the serial monitor
      digitalWrite(LledPin, HIGH);  //Output control status LED, ON 
      delay(500);//delay 500ms
      //The interrupt counter is cleared
        state = 0;//The shock caused by the first interruption after a number of interrupted shielding
    }else{
       //If the vibration sensor does not move, no interrupt is triggered
        Serial.write(0); //send '0' to the serial monitor     
        digitalWrite(LledPin, LOW);   //Output control status LED, OFF 
        delay(20); //Send the flag value 0 to Processing every 20ms   
    }
}
//If the vibration sensor initiates an interrupt, the interrupt service routine is automatically called
void blink()//Digital input sensor falling edge triggers interrupt service function
{
  state++;//Interrupt counter plus 1
}



