/***********************************************************
File name: _26_DCMotorModule.ino
Description: The state of DC motor includes its forward, reverse,
             acceleration, deceleration and stop. And you will 
             see the data on the serial monitor 
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/18 
***********************************************************/

const int APin = 11;                       //DC motor module A pin connected to digital 11 pin
const int BPin = 10;                       //DC motor module B pin connected to digital 10 pin
int DCmotorspeed = 60;                     //motor speed  0~255

void setup()
{
  pinMode(APin,OUTPUT);                    //initialize the A pin as output 
  pinMode(BPin,OUTPUT);                    //initialize the B pin as output 
//Serial.begin(9600);                      //opens serial port, sets data rate to 9600 bps
}

void loop()
{
  clockwise(0);                             //motor stop
//Serial.println(0);                       //send data to the serial monitor
  delay(1000);                              //delay 1s
  DCmotorspeed = 60;
  for(int i=0;i<7;i++){
    DCmotorspeed = DCmotorspeed + 20;       //motor speed increases 20
    clockwise(DCmotorspeed);                //motor forward
//  Serial.println(DCmotorspeed);          //send data to the serial monitor
    delay(1000);                            //delay 1s
  }
  for(int i=0;i<6;i++){
    DCmotorspeed = DCmotorspeed - 20;       //motor speed reduction 20
    clockwise(DCmotorspeed);                //motor forward
//  Serial.println(DCmotorspeed);          //send data to the serial monitor
    delay(1000);                            //delay 1s
  }
  clockwise(0);                             //motor stop
  Serial.println(0);                       //send data to the serial monitor
  delay(1000);                              //delay 1s
  DCmotorspeed = 60;
  for(int i=0;i<7;i++){
    DCmotorspeed = DCmotorspeed + 20;       //motor speed increases 20
    counterclockwise(DCmotorspeed);         //motor reverse
//  Serial.println(DCmotorspeed);          //send data to the serial monitor
    delay(1000);                            //delay 1s
  }
  for(int i=0;i<6;i++){
    DCmotorspeed = DCmotorspeed - 20;        //motor speed reduction 20
    counterclockwise(DCmotorspeed);         //motor reverse
//  Serial.println(DCmotorspeed);           //send data to the serial monitor
    delay(1000);                            //delay 1s
  }
}
void clockwise(int Speed)                   //the function to drive motor rotate clockwise
{
  analogWrite(APin,Speed);                  //set the speed of motor
  analogWrite(BPin,0);                      //stop the B pin of motor
}
void counterclockwise(int Speed)            //the function to drive motor rotate counterclockwise
{
  analogWrite(APin,0);                      //stop the A pin of motor
  analogWrite(BPin,Speed);                  //set the speed of motor
}

