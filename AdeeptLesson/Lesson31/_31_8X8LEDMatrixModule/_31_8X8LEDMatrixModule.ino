/***********************************************************
File name: _31_8X8LEDMatrixModule.ino
Description: you can see a rolling “Adeept” should be displayed
             on the 8x8 LED matrix module.
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/16 
***********************************************************/

const int st_cpPin = 12; //Pin connected to ST_CP of 74HC595
const int sh_cpPin = 8;  //Pin connected to SH_CP of 74HC595  
const int dsPin = 11;    //Pin connected to DS of 74HC595 
//Column scanning
int data[] = { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//Null
              0x00,0x3E,0x48,0x88,0x88,0x48,0x3E,0x00, //A
              0x00,0x00,0x0C,0x12,0x12,0xFE,0x00,0x00, //d
              0x00,0x00,0x7C,0x92,0x92,0x92,0x70,0x00, //e
              0x00,0x00,0x7C,0x92,0x92,0x92,0x70,0x00, //e
              0x00,0x00,0xFE,0x90,0x90,0x60,0x00,0x00, //p
              0x00,0x00,0x10,0x10,0x7E,0x12,0x10,0x00, //t
              0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00  //Null
              };
              
//Line scan            
unsigned char  tab[]={0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};  

void setup ()
{
  //set pins to output
  pinMode(st_cpPin,OUTPUT);//Set digital 12 port mode, the OUTPUT for the output
  pinMode(sh_cpPin,OUTPUT);//Set digital 8 port mode, the OUTPUT for the output
  pinMode(dsPin,OUTPUT);   //Set digital 11 port mode, the OUTPUT for the output
}

void loop()
{
    for(int n = 0; n < 56; n++) //Send column scanning cycle data
    {
        for(int t=0;t<100;t++)  //Control data scrolling speed
        {
            for(int num=n; num < 8+n; num++)//8 columns of data sent to a dot matrix
            {                       
                shiftOut(dsPin,sh_cpPin,MSBFIRST,data[num]); //Send column data to a dot matrix
                shiftOut(dsPin,sh_cpPin,MSBFIRST,tab[num-n]);//Send line data to a dot matrix
                //The rising edge of the data shift
                digitalWrite(st_cpPin,HIGH); //Output control latch HIGH  
                digitalWrite(st_cpPin,LOW);  //Output control latch LOW
            }
        }
    }
}
