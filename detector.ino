#include <Servo.h>
  Servo servo1;
  Servo servo2;
  #define irpin1 2
  #define irpin2 3
  boolean forward1 =true;
  boolean forward2 = true;
  int j =91;
  int i =0;
  float angle1;
  float angle2;
  float y = 0;
  float x = 0;
  float x0 = 0;
  const float c = 10; //distance between sensors
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(irpin1, INPUT_PULLUP);
  pinMode(irpin2, INPUT_PULLUP);
  servo1.attach(9);
  servo2.attach(10);
}




void loop() {
  
  if(!digitalRead(irpin2)){
    angle1= (float)i;
     Serial.print("angle1=");
    Serial.println(angle1);
    }else{
    servo1.write(i);
    if(forward1==true){
      i++;
      }else{
      i--;
        }
    }
  if(i==0||i==90){
    forward1 =  !forward1;
    }else{}
    
    sweep();
    calculate();
  delay(30);

}
void calculate(){
  if(!digitalRead(irpin1) && !digitalRead(irpin2)) {
    angle1= angle1*PI/180.0;
    angle2= angle2*PI/180.0;
    y = (c/(sin(angle1 + angle2)))*sin(angle1)*sin(angle2);
    x0 = (c / sin(angle1 + angle2))*sin(angle1)*cos(angle2);
    if(x0<(c/2)) {
      x = (-1*c/2 + x0);
    }
    else if(x0>(c/2)) {
      x = x0 - (c/2);
    }
     else {
      x = 0;
     }
     
      
      Serial.print("The flame is ");
      Serial.print(y);
      Serial.print(" cm away from me and ");
      Serial.print(abs(x));
      Serial.print("cm to the ");
      Serial.println("side");
     
  }
  else {
    Serial.println("I am not detecting a flame");
  }
  }
void sweep(){
  if(!digitalRead(irpin1)){
    angle2= 180 - (float)j;
    Serial.print("angle2=");
    Serial.println(angle2);
    }else{
    servo2.write(j);
    if(forward2==true){
      j++;
      }else{
      j--;
        }
    }
  if(j==180||j==90){
    forward2 =  !forward2;
    }else{}
  }
