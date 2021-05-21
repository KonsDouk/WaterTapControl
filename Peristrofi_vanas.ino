//Peristrofi vanas vrusis
#include <Servo.h>

Servo myServo;

int value;
int currentAngle = 0;
double angle1 = 160;
double angle2 = 0;

int btnKal = 6;
int btnTher = 7;

int ledKal = 10;
int ledTher = 11;

void setup()
{
  Serial.begin(9600);
  myServo.attach(9);
  
  pinMode(btnKal, INPUT);
  pinMode(btnTher, INPUT);
  
  pinMode(ledKal, OUTPUT);
  pinMode(ledTher, OUTPUT);
  
}

void wrongAngle(){
  currentAngle == myServo.read();
  
  if (currentAngle != 90 && currentAngle != 0){
    digitalWrite(ledKal, HIGH);
    digitalWrite(ledTher, HIGH);
    delay(50);
    digitalWrite(ledKal, LOW);
    digitalWrite(ledTher, LOW);
    delay(50);
  }
}

void loop(){
  
  wrongAngle();
  int btn1State = digitalRead(btnKal);
  int btn2State = digitalRead(btnTher);

  if (btn1State == HIGH){
    myServo.write(180);
    digitalWrite(ledKal, HIGH);
    digitalWrite(ledTher, LOW);
  }else if (btn2State == HIGH){
    myServo.write(0);
    digitalWrite(ledTher, HIGH);
    digitalWrite(ledKal, LOW);
    }
  
}
