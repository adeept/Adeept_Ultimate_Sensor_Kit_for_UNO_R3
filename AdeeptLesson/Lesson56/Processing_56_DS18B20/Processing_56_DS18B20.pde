/******************************************************************************
File name:   Processing_56_DS18B20.pde
Description: Arduino and processing interactive
              
Website: www.adeept.com
E-mail: support@adeept.com
Author: Tom
Date: 2017/03/12 
********************************************************************************/ 
import processing.serial.*; //Transferred to the serial library
PImage img;
Serial serial;//Create Serial objects myPoart 
PFont font;   //Create font variant
int data;     //Stores the current temperature data
int[] value= new int[600];//The temperature corresponding to the position

void setup() { 
  // set the canvas size is 600 x 600
  size(600, 600);  
  noStroke();
  smooth();
  img = loadImage("Adeept.png");
  // Open the serial port and set the baud rate to 9600
  // This experiment arduino board is connected to COM3, here please
  // adjust according to actual situation.
  serial = new Serial(this, "COM3", 9600); 
  font = createFont("adeept",30,true);//Loading System Fonts
  
} 
int getheight(int data){
  return (int)(data*7.5);//The transition temperature values for the height
}
  
void draw() { 
  // Draw a circle on canvas
  background(255); // Background to white
  image(img, 80, 90);//Display LOGO 
  img.resize(450,400);
  if(serial.available()>0){
    data=serial.read();//Variable data = Arduino data transmitted
  }
  
  for(int i=0; i<width-1; i++){//Temperature control line moves
    value[i] = value[i+1];
  }
  value[width-1] = data;
  fill(0,255,0);    //Set the font is green color:-)
  textFont(font,30);//Set the font
  textSize(30);     //Set the font size
  text("Temperature: "+data+"°C",80,50);//Output current temperature value
  stroke(200);      //Setting the line's color          
  strokeWeight(1);  //Setting the width of the line's
  text("  0°C",10,height);    //Display 0 degrees Celsius
  text("10°C",10,height-75);  //Display 10 degrees Celsius
  text("20°C",10,height-75*2);//Display 20 degrees Celsius
  text("30°C",10,height-75*3);//Display 30 degrees Celsius
  text("40°C",10,height-75*4);//Display 40 degrees Celsius
  text("50°C",10,height-75*5);//Display 50 degrees Celsius
  text("60°C",10,height-75*6);//Display 60 degrees Celsius
  text("70°C",10,height-75*7);//Display 70 degrees Celsius
  line(75,0,75,height);                  //Display grid lines
  line(75,height-75,width,height-75);    //Display grid lines
  line(75,height-75*2,width,height-75*2);//Display grid lines
  line(75,height-75*3,width,height-75*3);//Display grid lines
  line(75,height-75*4,width,height-75*4);//Display grid lines
  line(75,height-75*5,width,height-75*5);//Display grid lines
  line(75,height-75*6,width,height-75*6);//Display grid lines
  line(75,height-75*7,width,height-75*7);//Display grid lines
  stroke(255,0,0);//Display color temperature line's
  strokeWeight(3);//Setting the width of the line's
  for(int i=1; i<width; i++){//Temperature display line
    line(width-i+75, height-1-getheight(value[i-1]),width-1-i+75,height-1-getheight(value[i]));             
  }
  println(data);
} 