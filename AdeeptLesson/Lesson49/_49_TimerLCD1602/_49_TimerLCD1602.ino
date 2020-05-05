/***********************************************************
File name:   _49_TimerLCD1602.ino
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/02 
***********************************************************/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//LiquidCrystal_I2C lcd(0x27,16,2); // set the LCD address to "0x27"(or "0x3f") for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x3f,16,2); // set the LCD address to "0x3f"(or "0x27") for a 16 chars and 2 line display
#define AR_SIZE( a ) sizeof( a ) / sizeof( a[0] )

char show0[]="      :  :      ";           
char show1[]=" www.adeept.com ";    
 
unsigned long oldTime=0;
unsigned long newTime;
unsigned long time;
int Time = 17;
int Minute = 35;
int Second = 10;

void setup()
{
  lcd.init(); //initialize the lcd
  lcd.backlight(); //turn on the backlight
  lcd.clear();                           //clears the LCD screen 
  lcd.setCursor(0,0);                   // set the cursor to column 0, line 1
  for (int positionCounter1 = 0; positionCounter1 < 16; positionCounter1++)
  {
      lcd.print(show0[positionCounter1]); // print a message to the LCD.
  }
  lcd.setCursor(0,1);                    // set the cursor to column 0, line 2
  for (int positionCounter2 = 0; positionCounter2 < 16; positionCounter2++)
  {
      lcd.print(show1[positionCounter2]); // print a message to the LCD.
  }
}

void loop()
{
  char strSecond[2];
  char strMinute[2];
  char strTime[2];
  newTime = millis();
  time = (newTime - oldTime)/1000;
  if(time>=1){
     oldTime = newTime;
     Second++;
  }
  if(Second >= 60){
     Second = 0;
     Minute++;
  }
  if(Minute>=60){
     Minute = 0;
     Time++;
   }
   if(Time>=24){
      Time = 0;
   }
  
   dtostrf(Second,2,0,strSecond);  //Converts a floating-point number to a string
   lcd.setCursor(10,0);                   // set the cursor to column 10, line 1
   for (int positionCounter1 = 0; positionCounter1 < 2; positionCounter1++)
   {
      lcd.print(strSecond[positionCounter1]); // print a message to the LCD.
   }
   
   dtostrf(Minute,2,0,strMinute);  //Converts a floating-point number to a string
   lcd.setCursor(7,0);                   // set the cursor to column 7, line 1
   for (int positionCounter1 = 0; positionCounter1 < 2; positionCounter1++)
   {
      lcd.print(strMinute[positionCounter1]); // print a message to the LCD.
   }

   dtostrf(Time,2,0,strTime);    //Converts a floating-point number to a string
   lcd.setCursor(4,0);                   // set the cursor to column 4, line 1
   for (int positionCounter1 = 0; positionCounter1 < 2; positionCounter1++)
   {
      lcd.print(strTime[positionCounter1]); // print a message to the LCD.
   }
   delay(100);
}
