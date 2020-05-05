/***********************************************************
File name: _14_IICInterfaceModule.ino
Description: LCD1602 display a string "Hello Geeks!" scrolling，
             then display “Adeept” and “www.adeept.com” static.
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom 
Date: 2017/03/14 
***********************************************************/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3f,16,2); // set the LCD address to "0x27"(or "0x3f") for a 16 chars and 2 line display
//LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to "0x27"(or "0x3f") for a 16 chars and 2 line display
char array1[]="     Adeept     ";                //the string to print on the LCD
char array2[]="  hello geeks!                ";  //the string to print on the LCD
char array3[]=" www.adeept.com ";                //the string to print on the LCD

int tim = 250;  //the value of delay time
void setup(void)
{
  lcd.init(); //initialize the lcd
  lcd.backlight(); //turn on the backlight
  
}
void loop(void)
{ 
    lcd.clear();                           //clears the LCD screen and positions the cursor in the upper-left corner
    lcd.setCursor(15,0);                   // set the cursor to column 15, line 1
    for (int positionCounter2 = 0; positionCounter2 < 30; positionCounter2++)
    {
      lcd.scrollDisplayLeft();             //scrolls the contents of the display one space to the left.
      lcd.print(array2[positionCounter2]); // Print a message to the LCD.
      delay(tim);                          //wait for 250 microseconds
    }

    lcd.clear();                           //clears the LCD screen and positions the cursor in the upper-left corner.   
    
    lcd.setCursor(0,0);                    // set the cursor to column 15, line 0
    for (int positionCounter1 = 0; positionCounter1 < 16; positionCounter1++)
    {
      lcd.print(array1[positionCounter1]); // print a message to the LCD.
      delay(tim);                          //wait for 250 microseconds
    }
    
    lcd.setCursor(0,1);                    // set the cursor to column 15, line 1
    for (int positionCounter3 = 0; positionCounter3 < 16; positionCounter3++)
    {
      lcd.print(array3[positionCounter3]); // print a message to the LCD.
      delay(tim);                          //wait for 250 microseconds
    }
   
   // lcd.setBacklight(0);
   // delay(1000);
   // lcd.setBacklight(1);
   // delay(1000);
}
