/***********************************************************
File name: _08_ThermistorModule.ino
Description: We measure the information of thermistor, and 
             displayed in the serial monitor 
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/12 
***********************************************************/
int thermistorPin = 0;             //thermistor connected to analog pin 0
void setup() 
{                
  pinMode(thermistorPin, INPUT);   //Set analog 0 port mode, the INPUT for the input
  Serial.begin(9600);             //opens serial port, sets data rate to 9600 bps
}
void loop() 
{
  float a = analogRead(thermistorPin);
  //the calculating formula of temperature
  float resistor = (1023.0*10000)/a-10000;
  float tempC = (3435.0/(log(resistor/10000)+(3435.0/(273.15+25)))) - 273.15;
  Serial.print(tempC);          //send data to the serial monitor
  Serial.println(" C");          //send data to the serial monitor
  delay(50);                       //delay 0.05 s
}




