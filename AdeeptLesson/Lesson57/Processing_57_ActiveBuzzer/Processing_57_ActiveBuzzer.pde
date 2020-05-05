/******************************************************************************
File name:   Processing_57_ActiveBuzzer.pde
Description: Arduino and processing interactive
              
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/12 
********************************************************************************/ 
import processing.serial.*; //Transferred to the serial library
PImage img;
PImage sound;
Serial serial;//Create Serial objects myPoart 
PFont font;//Create font variant

void setup() { 
  // set the canvas size is 600 x 600
  size(600, 600);  
  noStroke();
  smooth();
  img = loadImage("Adeept.png");
  sound = loadImage("sound.png");
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
    text("SOUND",50,50);
    image(sound, 100, 100);//Display LOGO
    sound.resize(50,50);
    serial.write('H');
  }else{
    fill(0,255,0);
    textFont(font,50);
    text("No sound",50,50);
    image(sound, 100, 100);//Display LOGO
    sound.resize(50,50);
    serial.write('L');
  }
} 
boolean mouseOverRectR(){
  return ((mouseX >= 100) && (mouseX <= 150) && (mouseY >= 100) && (mouseY <= 150));
}