#include <NewPing.h>
#include <Servo.h>
Servo m1;
Servo m2;
#define TRI_PIN 7
#define ECH_PIN 6
#define MAXD 200
NewPing sonar(TRI_PIN,ECH_PIN,MAXD);

void setup() {
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  m1.attach(11);
  m2.attach(9);
  Serial.begin(9600);
  
}

void frente(){
  m1.write(1);
  m2.write(180);
}

void tras(){
  m1.write(180);
  m2.write(1);
}

void esquerda(){
  m1.write(180);
  m2.write(180);
  }
void direita(){
  m1.write(1);
  m2.write(1);
}

void seguelinha(){
  
  int s1 = digitalRead(8);
  int s2 = digitalRead(9);

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
  
}


void loop() {

  int dist = sonar.ping_cm();
  
  
  Serial.print ("a distancia eh    ");
  Serial.print(dist);
  Serial.println("cm");
  
  

  seguelinha();

  if(dist<10 && dist>5){

    direita();
    delay(800);
    frente();
    delay(1500);
    esquerda();
    delay(800);
    frente();
    delay(2000);
    esquerda();
    delay(800);
    frente();
    delay(1000);
    direita();
    delay(800);
    
    
  }else{
    seguelinha();
  }

  





















  

}
