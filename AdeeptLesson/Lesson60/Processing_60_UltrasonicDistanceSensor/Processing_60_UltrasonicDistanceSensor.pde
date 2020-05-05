/***************************************************************
File name:   Processing_60_VibrationSensor.pde
Description: Arduino and processing interactive
             The vibration sensor data which Arduino collected send 
             the processing software to display.
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/12 
*****************************************************************/ 
import processing.serial.*;//Transferred to the serial library
PImage img;
Serial myPoart;            //Create Serial objects myPoart
int data;                  //Storing the received serial data     
float m;
int n;                     //Color circle diameter

void setup() 
{
  size(600, 600);//To set the canvas size, you can then modify the larger
  background(255,255,255);//White canvas background
  noStroke();
  smooth();
  img = loadImage("Adeept.png");
  // Open the serial port and set the baud rate to 9600
  // This experiment arduino board is connected to COM3, here please
  // adjust according to actual situation.
  myPoart = new Serial(this,"COM3",9600);//Set communication port COM3, 9600
}  

void draw() 
{
  background(255,255,255);//White canvas background 
  image(img, 175, 190);
  img.resize(250,220);
  if(myPoart.available()>0){
     data=myPoart.read(); //Variable data = Arduino data transmitted
     println(data);       //The data of Arduino transmitted appear in the console
     m = map(data,5,35,5,155);
     n = int(m);
     n = 155 - n;
     println(n);
  }
  //Generating an array of color circle
   for(float x1=50;x1<=550;x1+=100){
       for(float y1=50;y1<=600;y1+=100){
         if(n<75){
          fill(0, 255, 0, 200); 
          ellipse(x1,y1,n,n);
         }else{
          fill(0, 255, 0, 125); 
          ellipse(x1,y1,n,n);
         }
        }
   }
   //Generating an array of color circle
   for(float x1=0;x1<=600;x1+=100){
      for(float y1=0;y1<=600;y1+=100){
         if(n<75){
          fill(255, 0, 0, 200); 
          ellipse(x1,y1,n,n);
         }else{
          fill(255, 0, 0, 125); 
          ellipse(x1,y1,n,n);
         }
         }
   }

}