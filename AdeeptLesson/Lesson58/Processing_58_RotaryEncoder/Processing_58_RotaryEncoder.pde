/******************************************************************************
File name:   Processing_58_RotaryEncoder.pde
Description: Arduino and processing interactive
             
             
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/12 
********************************************************************************/ 
import processing.serial.*; //Transferred to the serial library
PImage img;
Serial serial;//Create Serial objects myPoart   
int data; //Storing the received serial data
float r;//Radius increment helix

void setup() { 
  // set the canvas size is 600 x 600
  size(600, 600);  
  noStroke();
  smooth();
  fill(0,255,0);
  img = loadImage("Adeept.png");
  // Open the serial port and set the baud rate to 9600
  // This experiment arduino board is connected to COM3, here please
  // adjust according to actual situation.
  serial = new Serial(this, "COM3", 9600); 
} 
  
void draw() { 
 // Draw a circle on canvas
  background(255); // Background to white
  image(img, 80, 90);
  img.resize(450,400);
  if ( serial.available() > 0) { 
    // Read from serial production sensor value.
    data = serial.read();  
    println(data); //Print out the processing received sensor value
  }
  for(int i=0;i<data;i++){
    fill(random(0, 255), random(0, 255), random(0, 255));
    pushMatrix();
    translate(300,300);
    rotate(radians(i*5));
    text(i,200,20);
    triangle(0,0,200,20,200,0);
    popMatrix();
  } 
} 