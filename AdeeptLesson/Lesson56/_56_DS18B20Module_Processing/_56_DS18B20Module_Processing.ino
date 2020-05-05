/***********************************************************
File name: _56_DS18B20Module_Processing.ino
Description: We measure the information of temperatuure, and 
             displayed in the serial monitor 
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/12 
***********************************************************/
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#define ONE_WIRE_BUS 7                //ds18b20 module attach to pin7
OneWire oneWire(ONE_WIRE_BUS);       // Setup a oneWire instance to communicate with any OneWire devices
DallasTemperature sensors(&oneWire);// Pass our oneWire reference to Dallas Temperature. 
void setup(void)
{
  
  Serial.begin(9600);//opens serial port, sets data rate to 9600 bps
  sensors.begin();   //initialize the bus
}
void loop(void)
{ 
  int temp;
  // call sensors.requestTemperatures() to issue a global temperature 
  // request to all devices on the bus
  sensors.requestTemperatures();           //send the command to get temperatures
  temp = sensors.getTempCByIndex(0);
  Serial.write(temp);//send data to the serial monitor
  delay(500);//delay 1s
}

