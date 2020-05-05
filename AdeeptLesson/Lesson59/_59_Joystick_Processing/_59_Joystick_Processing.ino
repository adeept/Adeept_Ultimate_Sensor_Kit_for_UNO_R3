/***********************************************************
File name:   _59_Joystick_Processing.ino
Description: Arduino and processing interactive
             The Joystiak data which Arduino collected send 
             the processing software to display.  
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/12
***********************************************************/
int xPin = 0; // Define UNO board A0 pin connect the Ioystick X pin
int yPin = 1; // Define UNO board A1 pin connect the Ioystick Y pin
int sPin = 2;   // Define UNO board digital 2 pin connect the Ioystick S pin

int xval = 0;
int yval = 0;
int sval= 0;

void setup() { 
  // Start the serial port, baud rate to 9600
  Serial.begin(9600); 
  pinMode(sPin,INPUT_PULLUP);//Set S Pin inputand pull up 
} 
  
void loop() { 
  // Read the Joystick x y sw information
  int xval = analogRead(xPin);
  int yval = analogRead(yPin);
  int sval = digitalRead(sPin);
  
  Serial.print(xval);//Dend xval value
  Serial.print(',');
  Serial.print(yval);//Dend yval value
  Serial.print(',');
  Serial.print(sval);//Dend swval value
  Serial.println(','); 
  delay(100); 
} 

