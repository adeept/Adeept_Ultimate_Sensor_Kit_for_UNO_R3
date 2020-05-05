/***********************************************************
File name: _09_DS18B20Module.ino
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
OneWire oneWire(ONE_WIRE_BUS);        // Setup a oneWire instance to communicate with any OneWire devices
DallasTemperature sensors(&oneWire);  // Pass our oneWire reference to Dallas Temperature. 
void setup(void)
{
  
  Serial.begin(9600);//opens serial port, sets data rate to 9600 bps
  sensors.begin();    //initialize the bus
}
void loop(void)
{ 
  // call sensors.requestTemperatures() to issue a global temperature 
  // request to all devices on the bus
  Serial.print("Requesting temperatures...");
  sensors.requestTemperatures();            //send the command to get temperatures
  Serial.print("Tem: ");
  Serial.print(sensors.getTempCByIndex(0));//send data to the serial monitor
  Serial.println(" C");
  delay(1000);                              //delay 1s
}

