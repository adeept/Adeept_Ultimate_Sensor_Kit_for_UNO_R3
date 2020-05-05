/***********************************************************
File name: _32_LEDBarModule.ino
Description: This example will show you how to use the setBits() 
             function of this library.Set any combination of 
             LEDs using 10 bits.
             The setBits() function sets the current state, 
             one bit for each LED.First 10 bits from the right
             control the 10 LEDs.
             eg. 0b00000jihgfedcba
             a = LED 1, b = LED 2, c = LED 3, etc.
             dec    hex     binary
             0    = 0x0   = 0b000000000000000 = all LEDs off
             5    = 0x05  = 0b000000000000101 = LEDs 1 and 3 on, all others off
             341  = 0x155 = 0b000000101010101 = LEDs 1,3,5,7,9 on, 2,4,6,8,10 off
             1023 = 0x3ff = 0b000001111111111 = all LEDs on
                      |        |
                      10       1.
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/17 
***********************************************************/
#include <Adeept_Bar.h>
Adeept_Bar bar(7, 6);  // Clock pin, Data pin
void setup()
{
  bar.begin();             // initialize
}
void loop()
{
  // Turn off all LEDs
  bar.setBits(0x0);
  delay(1000);
  // Turn on LED 1
  bar.setBits(0b000000000000001);// 0b000000000000001 can also be written as 0x1:
  delay(1000);
  // Turn on LED 12
  bar.setBits(0b000000000000011);// 0b000000000000011 can also be written as 0x3:
  delay(1000);
  // Turn on LED 123  
  bar.setBits(0b000000000000111);// 0b000000000000111 can also be written as 0x7:
  delay(1000);
  // Turn on LED 1234
  bar.setBits(0b000000000001111);// 0b000000000001111 can also be written as 0xf:
  delay(1000);
  // Turn on LED 12345
  bar.setBits(0b000000000011111);// 0b000000000011111 can also be written as 0x1f:
  delay(1000);
  // Turn on LED 123456
  bar.setBits(0b000000000111111);// 0b000000000111111 can also be written as 0x3f:
  delay(1000);
  // Turn on LED 1234567 
  bar.setBits(0b000000001111111);// 0b000000001111111 can also be written as 0x7f:
  delay(1000);
  // Turn on LED 12345678
  bar.setBits(0b000000011111111);// 0b000000011111111 can also be written as 0xff:
  delay(1000);
  // Turn on LED 123456789
  bar.setBits(0b000000111111111);// 0b000000111111111 can also be written as 0x1ff:
  delay(1000);
  // Turn on all LEDs
  bar.setBits(0x3ff);
  delay(1000);
  // Turn on LED 123456789
  bar.setBits(0b000000111111111);// 0b000000111111111 can also be written as 0x1ff:
  delay(1000);
  // Turn on LED 12345678
  bar.setBits(0b000000011111111);// 0b000000011111111 can also be written as 0xff:
  delay(1000);  
  // Turn on LED 1234567 
  bar.setBits(0b000000001111111);// 0b000000001111111 can also be written as 0x7f:
  delay(1000);
  // Turn on LED 123456
  bar.setBits(0b000000000111111);// 0b000000000111111 can also be written as 0x3f:
  delay(1000);
  // Turn on LED 12345
  bar.setBits(0b000000000011111);// 0b000000000011111 can also be written as 0x1f:
  delay(1000);
  // Turn on LED 1234
  bar.setBits(0b000000000001111);// 0b000000000001111 can also be written as 0xf:
  delay(1000);
  // Turn on LED 123  
  bar.setBits(0b000000000000111);// 0b000000000000111 can also be written as 0x7:
  delay(1000);
  // Turn on LED 12
  bar.setBits(0b000000000000011);// 0b000000000000011 can also be written as 0x3:
  delay(1000);
  // Turn on LED 1
  bar.setBits(0b000000000000001);// 0b000000000000001 can also be written as 0x1:
  delay(1000);
}
