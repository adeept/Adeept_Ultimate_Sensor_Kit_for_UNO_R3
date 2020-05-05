/***********************************************************
File name: _46_dht_11AlarmViaRGB.ino
Description: DHT11 detects temperature and humidity, exceeds 
             the set threshold, and RGB color change.
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/03 
***********************************************************/
#include <Adeept_DHT11.h>
Adeept_DHT11 Adeept_dht11;
#define DHT11PIN 2  //Set the digital 2 to the S pin

int redPin = 11;         // R petal on RGB LED module connected to digital pin 11 
int greenPin = 10;       // G petal on RGB LED module connected to digital pin 10 
int bluePin = 6;         // B petal on RGB LED module connected to digital pin 6
int humiThreshold = 65;  //20~90%RH（±5%RH）
int tempThreshold = 30;  //0~50 C（±2C）

void setup()
{ 
     Adeept_dht11.read(DHT11PIN);
     pinMode(redPin, OUTPUT);   // sets the redPin to be an output 
     pinMode(greenPin, OUTPUT); // sets the greenPin to be an output 
     pinMode(bluePin, OUTPUT);  // sets the bluePin to be an output 
     delay(1000);               // delay1000ms
}
void loop()
{
    
    int humi = Adeept_dht11.humidity;
    int temp = Adeept_dht11.temperature;

    if(humi>humiThreshold||tempThreshold>25){
      color(255, 0, 0);  // turn the RGB LED red  
    }else{
      color(0,255, 0);   // turn the RGB LED green 
    }
    delay(100);          //set the delay time，1000ms 
}
void color (unsigned char red, unsigned char green, unsigned char blue)// the color generating function  
{    
     analogWrite(redPin, 255-red);     // PWM signal output   
     analogWrite(greenPin, 255-green); // PWM signal output
     analogWrite(bluePin, 255-blue);   // PWM signal output
}   
