/******************************************************************************
File name:   Photoresistor_55_Brightness.pde
Description: Arduino and processing interactive
             Phototresistor control the brightness of the photo
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/12 
********************************************************************************/ 
import processing.serial.*;//Load the serial library

Serial myPort; //Create a new serial port
PImage picture;//Create a new image
int val=0;     //Receiving port read data
 
void setup(){
  size(700,400);//Defines the dimension of the display window in units of pixels
  background(0);//sets the color used for the background of the Processing window
  picture = loadImage("Master Yoda.jpg");//Load the 'Lovely dog' picture
  // Open the serial port and set the baud rate to 9600
  // This experiment arduino board is connected to COM3, here please
  myPort = new Serial(this,"COM3",9600);
}

void draw(){
  if(myPort.available() > 0){
    val = myPort.read();//Received Arduino UNO data
   
    tint(val);//Sets the fill value(val) for displaying images 
    image(picture,0,0);//Display the 'Lovely dog' picture
    picture.resize(700,400);
  }
}