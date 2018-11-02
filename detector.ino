#include <Servo.h>
  Servo servo1;
  Servo servo2;
  #define irpin1 2
  #define irpin2 3
  int j =90;
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
  
 for(int i =0; i < 180;){
  if(!digitalRead(irpin2)){
    angle1= (float)i;
    }else{servo1.write(i);
    i++;
    }
    
    sweep();
    detect();
  delay(100);
  }

}
void detect(){
  if(!digitalRead(irpin1) && !digitalRead(irpin2)) {
    y = (c / sin(angle1 + angle2))*sin(angle1)*sin(angle2);
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
    }else{servo2.write(j);
    j++;
    }
  if(j == 180){
    j=0;
    }
  }
