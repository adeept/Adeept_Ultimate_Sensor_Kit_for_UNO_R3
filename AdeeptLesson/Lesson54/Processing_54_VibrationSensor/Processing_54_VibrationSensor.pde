/***************************************************************
File name:   Processing_54_VibrationSensor.pde
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
// You can modify the four variables numBalls, spring, friction and gravity
// And you observe the bubble shock scene changes
int numBalls =13;     //Define the number of bubbles
float spring = 0.8;   //Elasticity collision between bubbles
float friction = -0.9;//Elasticity collision between bubbles and the wall
float gravity = 0.4;  //Gravitation coefficient bubbles during exercise
Ball[] balls = new Ball[numBalls];

void setup() 
{
  size(700, 250);//To set the canvas size, you can then modify the larger
  noStroke();
  smooth();
  img = loadImage("Adeept.png");
  // Open the serial port and set the baud rate to 9600
  // This experiment arduino board is connected to COM3, here please
  // adjust according to actual situation.
  myPoart = new Serial(this,"COM3",9600);//Set communication port COM3, 9600
  for (int i = 0; i < numBalls; i++) {     //Ball Object Initialization
    balls[i] = new Ball(random(width), random(height), random(20, 40), i, balls);}
}

void draw() 
{
   if(myPoart.available()>0){
     data=myPoart.read();//Variable data = Arduino data transmitted
     println(data);//The data of Arduino transmitted appear in the console
     if(data==1)  {     // If the vibration sensor triggered interrupts, Arduino upload flag value 1 
       for (int i = 0; i < numBalls; i++) {
         balls[i] = new Ball(random(width), random(height), random(20, 40), i, balls);//Ball Object Initialization
       }
      }
    }
  background(124,252,0);//Green canvas background
  image(img, 225, 10);
  img.resize(250,230);
  for (int i = 0; i < numBalls; i++) {
    balls[i].collide();//Call the collide function  
    balls[i].move();   //Call the move function
    balls[i].display();//Call the display function  
  }
}

class Ball {//Object Name Ball
  //Define the variables in the object
  float x, y;
  float diameter;
  float vx = 0;
  float vy = 0;
  int id;
  Ball[] others;
 //The definition of constructors, initial the value to object variable
  Ball(float xin, float yin, float din, int idin, Ball[] oin) {
    x = xin;
    y = yin;
    diameter = din;
    id = idin;
    others = oin;
  } 
 //Defined function collide
 //Analyzing Bubble impact conditions
 //After the crash and fix, bubble motion parameters
  void collide() {
    for (int i = id + 1; i < numBalls; i++) {
      float dx = others[i].x - x;
      float dy = others[i].y - y;
      float distance = sqrt(dx*dx + dy*dy);
      float minDist = others[i].diameter/2 + diameter/2;
      if (distance < minDist) { 
        float angle = atan2(dy, dx);
        float targetX = x + cos(angle) * minDist;
        float targetY = y + sin(angle) * minDist;
        float ax = (targetX - others[i].x) * spring;
        float ay = (targetY - others[i].y) * spring;
        vx -= ax;
        vy -= ay;
        others[i].vx += ax;
        others[i].vy += ay;
      }
    }   
  }
  //Definition of move () function
  //Analyzing post-impact condition between the bubble and the wall, and fix strike, bubble motion parameters
  //According to bubble motion parameters, calculate the coordinates of bubble value at various points in the trajectory
  void move() {
    vy += gravity;
    x += vx;
    y += vy;
    if (x + diameter/2 > width) {
      x = width - diameter/2;
      vx *= friction; 
    }
    else if (x - diameter/2 < 0) {
      x = diameter/2;
      vx *= friction;
    }
    if (y + diameter/2 > height) {
      y = height - diameter/2;
      vy *= friction; 
    } 
    else if (y - diameter/2 < 0) {
      y = diameter/2;
      vy *= friction;
    }
  }
  //Defined dispaly () function
  //Bubble trajectory coordinates of each point is the center circle
  //Bubble show's animation
  void display() {
    //fill(255, 204);
    fill(238,0,0,255);
    ellipse(x, y, diameter, diameter);
  }
}