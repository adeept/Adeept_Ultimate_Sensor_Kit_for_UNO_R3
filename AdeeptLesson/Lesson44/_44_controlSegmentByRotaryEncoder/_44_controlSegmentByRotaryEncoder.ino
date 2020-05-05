/***********************************************************
File name: _44_controlSegmentByRotaryEncoder.ino
Description:Cumulative figures(number) from 0-9999 on the
            segment display module.
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/05 
***********************************************************/
const int stbPin = 7;  //the segment display module STB pin connected to digital pin 7
const int clkPin = 9;  //the segment display module CLK pin connected to digital pin 9
const int dioPin = 8;  //the segment display module DIO pin connected to digital pin 8
const int APin= 2;     //Set the digital 2 to A pin
const int BPin= 3;     //Set the digital 3 to B pin
const int SPin= 4 ;    //Set the digital 4 to S pin
int tump=0;            //segment display value

void sendCommand(uint8_t value) 
{ 
   digitalWrite(stbPin, LOW);                   //pin low.  To begin receiving data
   shiftOut(dioPin, clkPin, LSBFIRST, value);   //send data(value) to the segment display module
   digitalWrite(stbPin, HIGH);                  //pin high.  Stop receiving data
}  
bool number() 
{                       /*0*/ /*1*/ /*2*/ /*3*/ /*4*/ /*5*/ /*6*/ /*7*/ /*8*/ /*9*/ 
   uint8_t digits[] = { 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f };
                        /*H*/ /*E*/ /*L*/ /*L*/ /*O*/ /*.*/ /*.*/ /*.*/ /* */ /* */
// uint8_t digits[] = { 0x76, 0x79, 0x38, 0x38, 0x3f, 0x80, 0x80, 0x80, 0x00, 0x00 };    
   sendCommand(0x40);                                       //setting the Write Data Command,using automatic address genuine.
   digitalWrite(stbPin, LOW);                               //pin low.  To begin receiving data
   shiftOut(dioPin, clkPin, LSBFIRST, 0xc0);                //Set the start address 0C0H
   shiftOut(dioPin, clkPin, LSBFIRST, digits[tump/1000%10]);//thousand data
   shiftOut(dioPin, clkPin, LSBFIRST, 0x00);                //filling high 8-bit data               
   shiftOut(dioPin, clkPin, LSBFIRST, digits[tump/100%10]); //hundred data
   shiftOut(dioPin, clkPin, LSBFIRST, 0x00);                //filling high 8-bit data 
   shiftOut(dioPin, clkPin, LSBFIRST, digits[tump/10%10]);  //ten data
   shiftOut(dioPin, clkPin, LSBFIRST, 0x00);                //filling high 8-bit data 
   shiftOut(dioPin, clkPin, LSBFIRST, digits[tump%10]);     //bit data
   shiftOut(dioPin, clkPin, LSBFIRST, 0x00);                //filling high 8-bit data 
   digitalWrite(stbPin, HIGH);                              //pin high.  Stop receiving data
   return 0; 
 }  
  int getRotaryEncoder(void)
{
  static int oldA = HIGH;          //set the oldA as HIGH
  static int oldB = HIGH;          //set the oldB as HIGH
  int result = 0;
  int newA = digitalRead(APin);    //read the value of APin to newA
  int newB = digitalRead(BPin);    //read the value of BPin to newB
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
 
void setup() 
{ 
   pinMode(APin, INPUT);    //initialize the A pin as input
   pinMode(BPin, INPUT);    //initialize the B pin as input
   pinMode(SPin, INPUT);    //initialize the S pin as input
   pinMode(stbPin, OUTPUT); //initialize the stbPin as an output
   pinMode(clkPin, OUTPUT); //initialize the clkPin as an output
   pinMode(dioPin, OUTPUT); //initialize the dioPin as an output
   sendCommand(0x8f);       //activate 
} 
void loop() 
{ 
   number();        //show numbers on the segment display module
  int change = getRotaryEncoder();
  tump = tump - change;
  if(digitalRead(SPin) == LOW)
  {
    tump = 0;
  }
  if(tump<0)
  {
    tump = 0;
  }
} 
