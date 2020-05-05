/******************************************************************************
File name:   Processing_53_Potentiometer.pde
Description: Arduino and processing interactive
             The size of the potentiometer voltage control circle on the PC 
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
  if ( serial.available() > 0) { 
    // Read from serial production sensor value.
    data = serial.read();  
    println(data); //Print out the processing received sensor value
    r = map(data,0,255,0.04,0.2);
  } 
    // Draw a circle on canvas
    background(255); // Background to white
    image(img, 80, 90);
    img.resize(450,400);
    float iniR = 1.0;//Helix initial point radius
   // Helix angle of rotation range: 0-360*8
   // Spiral rotation every 2 degrees, an incremental increase in the radius
   // By structure for generating spiral effect
    for(int i = 0; i < 360*8; i = i+2){
      float angle = radians(i);
      float x = 300 + (cos(angle)*iniR);
      float y = 300 + (sin(angle)*iniR);
      ellipse(x, y, 6, 6); //Helix Each point is a solid green circle
      iniR = iniR + r;//Spiral radius increases 2 degrees once per revolution
    }
} 