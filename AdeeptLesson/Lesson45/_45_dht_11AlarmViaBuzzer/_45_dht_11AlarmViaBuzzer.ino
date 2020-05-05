/***********************************************************
File name: _45_dht_11AlarmViaBuzzer.ino
Description: DHT11 detects temperature and humidity, exceeds 
             the set threshold, and the buzzer sounds.
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/03 
***********************************************************/
#include <Adeept_DHT11.h>
Adeept_DHT11 Adeept_dht11;
#define DHT11PIN 2  //Set the digital 2 to the S pin

int passiveBuzzerPin = 5; //definition digital 5 pins as pin to control the passive buzzer
int humiThreshold = 65;//20~90%RH（±5%RH）
int tempThreshold = 30;//0~50 C（±2C）
void setup()
{ 
     Adeept_dht11.read(DHT11PIN);
     pinMode(passiveBuzzerPin,OUTPUT); //set digital 5 port mode, the OUTPUT for the output
     delay(1000);          //delay1000ms
}
void loop()
{
    
    int humi = Adeept_dht11.humidity;
    int temp = Adeept_dht11.temperature;

    if(humi>humiThreshold){
      tone(passiveBuzzerPin,1000);        //1000Hz frequency: 31~65535Hz 
      delay(1000);                        //set the delay time，1000ms
      noTone(passiveBuzzerPin);           //Turn off the buzzer
      delay(1000);                        //set the delay time，1000ms 
    }
    if(temp>tempThreshold){
      tone(passiveBuzzerPin,1000);        //1000Hz frequency: 31~65535Hz 
      delay(1000);                        //set the delay time，1000ms
      noTone(passiveBuzzerPin);           //Turn off the buzzer
      delay(1000);                        //set the delay time，1000ms 
    }
    delay(100);                           //set the delay time，1000ms 
}
