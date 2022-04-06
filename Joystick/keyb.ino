#include <Keyboard.h>
#include "Mouse.h"

void setup(){
  Serial.begin(9600);
  pinMode(4, INPUT_PULLUP); //initialize the button/joystick
  pinMode(5, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
}

void loop(){
  /*Serial.println(String("LEFTX") + String(analogRead(A0)));   //These is only for testing the joystick and buttons
  Serial.println(String("LEFTY") + String(analogRead(A1)));
  Serial.println(String("RIGHTX") + String(analogRead(A3)));
  Serial.println(String("RIGHTY") + String(analogRead(A4)));
  Serial.println(String("LEFTB") + String(digitalRead(11)));
  Serial.println(String("RIGHTB") + String(digitalRead(10)));
  Serial.println(String("LA") + String(digitalRead(5)));
  Serial.println(String("RA") + String(digitalRead(4)));
  */
  int lx = analogRead(A0);  //left joystick X pin
  int ly = analogRead(A1);  //left joystick Y pin
  int rx = analogRead(A3);  //right joystick X pin
  int ry = analogRead(A4);  //right joystick Y pin
  int lb = digitalRead(11); //left joystick button pin
  int rb = digitalRead(10); //right joystick button pin
  int la = digitalRead(5);  //left button pin
  int ra = digitalRead(4);  //right button pin
  int speedfactor = 100; //how fast the mouse move
  if(lx<400){             //left joystick x move
    Keyboard.press('w');  //press w key
  }
  else if(lx>600){
    Keyboard.press('s');  //press s key
  }
  else{
    Keyboard.release('w');  //release w/s key
    Keyboard.release('s');
  }
  if(ly>600){       
    Keyboard.press('a');  //press a key
  }
  else if(ly<400){
    Keyboard.press('d');  //press d key
  }
  else{
    Keyboard.release('a');   //release a/d key
    Keyboard.release('d');
  }
  if(rx<400){
    Mouse.move(0,(rx-400)/speedfactor); //mouse move down
  }
  if(rx>600){
    Mouse.move(0,(rx-600)/speedfactor); //mouse move up
  }
  if(ry<400){
    Mouse.move((400-ry)/speedfactor,0); //mouse move left
  }
  if(ry>600){
    Mouse.move((600-ry)/speedfactor,0); //mouse move right
  }
  if(lb==0){  //left joystick botton pressed
    Keyboard.press('v');   //press shift key
  }
  else{
    Keyboard.release('v'); //release shift keya
  }
   if(rb==0){ //right joystick button pressed
     Keyboard.press('c');     //mouse right  click
  }
  else{
     Keyboard.release('c');
    }saw
   if(ra==1){ //right button pressed 
     Mouse.press(MOUSE_LEFT); //mouse left click
  }
  else{
     Mouse.release(MOUSE_LEFT);
  }
  if(la==1){  //left button pressed
    Keyboard.press(KEY_RIGHT_CTRL); //right control pressed
  }
  else{
    Keyboard.release(KEY_RIGHT_CTRL); //right control release
  }
}
