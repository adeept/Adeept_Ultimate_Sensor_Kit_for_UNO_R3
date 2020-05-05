/******************************************************************************
File name:   Processing_51_Button.pde
Description: Arduino and processing interactive
              
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/12 
********************************************************************************/ 
import processing.serial.*; //Transferred to the serial library
PImage img;
PImage whitebutton1;
PImage whitebutton2;
PImage redbutton1;
PImage redbutton2;
PImage bluebutton1;
PImage bluebutton2;
Serial serial;//Create Serial objects myPoart 
PFont font;//Create font variant
int data;

void setup() { 
  // set the canvas size is 600 x 600
  size(600, 600);  
  noStroke();
  smooth();
  img = loadImage("Adeept.png");
  whitebutton1 = loadImage("whitebutton1.png");
  whitebutton2 = loadImage("whitebutton2.png");
  redbutton1 = loadImage("redbutton1.png");
  redbutton2 = loadImage("redbutton2.png");
  bluebutton1 = loadImage("bluebutton1.png");
  bluebutton2 = loadImage("bluebutton2.png");
  // Open the serial port and set the baud rate to 9600
  // This experiment arduino board is connected to COM3, here please
  // adjust according to actual situation.
  serial = new Serial(this, "COM3", 9600); 
} 
  
void draw() { 
   // Draw a circle on canvas
    background(255); // Background to white
    image(img, 80, 90);//Display LOGO
    img.resize(450,400);
  if(serial.available()>0){
    data=serial.read();//Variable data = Arduino data transmitted
  }

  if((data & 0x01) == 0x01){ //Determine whether the mouse in a red led area
    image(redbutton1, 50, 50);//Display red led
  }else{
    image(redbutton2, 50, 50);//Display led
  }
  
  if((data & 0x02) == 0x02){ //Determine whether the mouse in a green led area
    image(whitebutton1, 350, 50);//Display green led
  }else{
   image(whitebutton2, 350, 50);//Display led
  }
  
  if((data & 0x04) == 0x04){ //Determine whether the mouse in a blue led area   
    image(bluebutton1, 50, 350);//Display blue led
  }else{
    image(bluebutton2, 50, 350);//Display led
  }
  if((data & 0x08) == 0x08){ //Determine whether the mouse in a yellow led area
    image(bluebutton1, 350, 350);//Display yellow led
  }else{
    image(bluebutton2, 350, 350);//Display led
  }
  println(data);
} 