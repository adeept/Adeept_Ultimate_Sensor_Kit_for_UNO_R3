/******************************************************************************
File name:   Processing_50_LED.pde
Description: Arduino and processing interactive
              
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/12 
********************************************************************************/ 
import processing.serial.*; //Transferred to the serial library
PImage img;
PImage led;
PImage redled;
PImage greenled;
PImage blueled;
PImage yellowled;
Serial serial;//Create Serial objects myPoart 
PFont font;//Create font variant

void setup() { 
  // set the canvas size is 600 x 600
  size(600, 600);  
  noStroke();
  smooth();
  img = loadImage("Adeept.png");
  led = loadImage("led.png");
  redled = loadImage("redled.png");
  greenled = loadImage("greenled.png");
  blueled = loadImage("blueled.png");
  yellowled = loadImage("yellowled.png");
  // Open the serial port and set the baud rate to 9600
  // This experiment arduino board is connected to COM3, here please
  // adjust according to actual situation.
  serial = new Serial(this, "COM3", 9600); 
  font = createFont("adeept",48,true);//Loading System Fonts
} 
  
void draw() { 
   // Draw a circle on canvas
    background(255); // Background to white
    image(img, 80, 90);//Display LOGO
    img.resize(450,400);
  if(mouseOverRectR() == true){ //Determine whether the mouse in a red led area
    fill(255,0,0);
    textFont(font,50);
    text("RED",50,50);
    image(redled, 50, 50);//Display red led
    serial.write('R');
  }else{
    image(led, 50, 50);//Display led
    fill(255,0,0);
    textFont(font,50);
    text("RED",50,50);
  }
  
  if(mouseOverRectG() == true){ //Determine whether the mouse in a green led area
    fill(0,255,0);
    textFont(font, 50);
    text("Green", 350, 50);
    image(greenled, 350, 50);//Display green led
    serial.write('G');
  }else{
    image(led, 350, 50);//Display led
    fill(0,255,0);
    textFont(font, 50);
    text("Green", 350, 50);
  }
  
  if(mouseOverRectB() == true){ //Determine whether the mouse in a blue led area   
    fill(0,0,255);
    textFont(font, 50);
    text("Blue",50, 350);image(blueled, 50, 350);//Display blue led
    serial.write('B');
  }else{
    image(led, 50, 350);//Display led
    fill(0,0,255);
    textFont(font, 50);
    text("Blue",50, 350);
  }
  
  if(mouseOverRectY() == true){ //Determine whether the mouse in a yellow led area
    fill(255,255,0);
    textFont(font, 50);
    text("Yellow",350, 350);
    image(yellowled, 350, 350);//Display yellow led
    serial.write('Y');
  }else{
    image(led, 350, 350);//Display led
    fill(255,255,0);
    textFont(font, 50);
    text("Yellow",350, 350);
  }
} 
boolean mouseOverRectR(){
  return ((mouseX >= 50) && (mouseX <= 250) && (mouseY >= 50) && (mouseY <= 250));
}
boolean mouseOverRectG(){
  return ((mouseX >= 350) && (mouseX <= 550) && (mouseY >= 50) && (mouseY <= 250));
}
boolean mouseOverRectB(){
  return ((mouseX >= 50) && (mouseX <= 250) && (mouseY >= 350) && (mouseY <= 550));
}
boolean mouseOverRectY(){
  return ((mouseX >= 350) && (mouseX <= 550) && (mouseY >= 350) && (mouseY <= 550));
}