/***********************************************************
File name: _16_RotaryEncoderModule.ino
Description: The information of rotary encoder module has been
             detected by UNO R3,and displayed in the serial monitor 
             When the rotary encoder turns clockwise, the angular 
             displacement is increased;when it turns counterclockwise,
             it’s decreased.If you press the switch on the rotary 
             encoder, related readings will return to zero
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/15 
***********************************************************/
const int APin= 2; //Set the digital 2 to A pin
const int BPin= 3; //Set the digital 3 to B pin
const int SPin= 4 ;//Set the digital 4 to S pin

int encoderVal = 0;

void setup()
{
  pinMode(APin, INPUT);//initialize the A pin as input
  pinMode(BPin, INPUT);//initialize the B pin as input
  pinMode(SPin, INPUT);//initialize the S pin as input
  Serial.begin(9600); //opens serial port, sets data rate to 9600 bps
}

void loop()
{
  int change = getRotaryEncoder();
  encoderVal = encoderVal - change;
  if(digitalRead(SPin) == LOW)
  {
    encoderVal = 0;
  }
  Serial.println(encoderVal);
}

int getRotaryEncoder(void)
{
  static int oldA = HIGH; //set the oldA as HIGH
  static int oldB = HIGH; //set the oldB as HIGH
  int result = 0;
  int newA = digitalRead(APin); //read the value of APin to newA
  int newB = digitalRead(BPin); //read the value of BPin to newB
  if (newA != oldA || newB != oldB)//if the value of APin or the BPin has changed
  {  
    if (oldA == HIGH && newA == LOW)// something has changed
    {
      result = (oldB * 2 - 1);
    }
  }
  oldA = newA;
  oldB = newB;
  return result;
}
