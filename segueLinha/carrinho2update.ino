#include <Servo.h>

Servo m1;
Servo m2;



void setup() {
m1.attach(2);
m2.attach(4);
pinMode(8, INPUT);
pinMode(7, INPUT);

Serial.begin(9600);
}

void loop() {
  int s1 = digitalRead(8);
  int s2 = digitalRead(7);

  Serial.print ("S1: ");
  Serial.print (s1);
  Serial.print (" S2: ");
  Serial.println (s2);


   

  if (s1==0){
    m1.write(1);
    }
  if (s1==1){
      m1.write(180);
    }

  if (s2==0){
    m2.write(180);
    } 
  if (s2==1){
      m2.write(1);
    }
  
 if (s1==1 && s2==1){
    m1.write(1);
    m2.write(180);
  }
  
 if (s1==0 && s2==0){
    m1.write(1);
    m2.write(180);
  }

}
