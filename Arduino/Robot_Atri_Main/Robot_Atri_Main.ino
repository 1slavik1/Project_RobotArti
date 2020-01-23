#include "Deshif.h"

int Info_Pin_0 = 52;
int Info_Pin_1 = 50;
int Info_Pin_2 = 48;
int Info_Pin_3 = 46;

/*int inPin1 = 49;
int inPin2 = 51;*/

int ledPin1 = 22;
int ledPin2 = 24;
int ledPin3 = 26;
int ledPin4 = 28;

int ledPin5 = 23;
int ledPin6 = 25;
int ledPin7 = 27;
int ledPin8 = 29;

int ledPin9 = 9;
int ledPin10 = 10;
Deshif deshif;// ledPin5, ledPin6, ledPin7, ledPin8);

int val0 = 0;
int val1 = 0;
int val2 = 0;
int val3 = 0;

void setup()
{
  
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
  pinMode(ledPin7, OUTPUT);
  pinMode(ledPin8, OUTPUT);
  pinMode(ledPin9, OUTPUT);
  pinMode(ledPin10, OUTPUT);
  pinMode(Info_Pin_0, INPUT_PULLUP);
  pinMode(Info_Pin_1, INPUT_PULLUP);
  pinMode(Info_Pin_2, INPUT_PULLUP);
  pinMode(Info_Pin_3, INPUT_PULLUP);
  pinMode(31,OUTPUT); //реле
  pinMode(33,OUTPUT);
  deshif.SetCode(val3,val2,val1,val0);
  deshif.Set_Pin_Shag1(ledPin1, ledPin2, ledPin3, ledPin4);
  deshif.Set_Pin_Shag2(ledPin5, ledPin6, ledPin7, ledPin8);
  //deshif.Set_Servo_1(ledPin9);
  //deshif.Set_Servo_2(ledPin10);
  deshif.Set_Pin_left_wheel(ledPin9);
  deshif.Set_Pin_right_wheel(ledPin10);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val3 = digitalRead(Info_Pin_3);
  val2 = digitalRead(Info_Pin_2);
  val1 = digitalRead(Info_Pin_1);
  val0 = digitalRead(Info_Pin_0);
  Serial.print(val3);
  Serial.print(val2);
  Serial.print(val1);
  Serial.println(val0);
  deshif.SetCode(val3,val2,val1,val0);
  deshif.select();
  //Serial.println(val);
 /*digitalWrite(31, LOW);
 delay(5000);
 digitalWrite(31,HIGH);
 delay(5000);*/
}
