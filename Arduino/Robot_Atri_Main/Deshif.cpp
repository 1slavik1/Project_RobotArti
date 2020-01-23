#include "Arduino.h"
#include "Deshif.h"
//#include <Servo.h>

int count = 0;
int count1 = 0;
long del = 2000;
bool flag_right = false; //false - назад, true - вперед
bool flag_left = false;

#define PIN_TRIG 42
#define PIN_ECHO 44
long duration, cm;

//Servo servo_1;
//Servo servo_2;

Deshif::Deshif()
{	
}

/*void Deshif::Set_Servo_1(int pin)
{
	this->servo_pin_1 = pin;
	servo_1.attach(servo_pin_1);
}

void Deshif::Set_Servo_2(int pin)
{
	this->servo_pin_2 = pin;
	servo_2.attach(servo_pin_2);
}*/

void Deshif::Set_Pin_right_wheel(int pin)
{
	this->right_wheel_pin = pin;
	//Serial.println("Motor ON");
}

void Deshif::Set_Pin_left_wheel(int pin)
{
	this->left_wheel_pin = pin;
}

void Deshif::SetCode(int IN3, int IN2, int IN1, int IN0)
{
	this->IN0 = IN0;
	this->IN1 = IN1;
	this->IN2 = IN2;
	this->IN3 = IN3;
}

void Deshif::Set_Pin_Shag1(int motor_pin_1, int motor_pin_2, int motor_pin_3, int motor_pin_4)
{
	this->motor_pin_1_1 = motor_pin_1;
	this->motor_pin_1_2 = motor_pin_2;
	this->motor_pin_1_3 = motor_pin_3;
	this->motor_pin_1_4 = motor_pin_4;
}

void Deshif::Set_Pin_Shag2(int motor_pin_1, int motor_pin_2, int motor_pin_3, int motor_pin_4)
{
	this->motor_pin_2_1 = motor_pin_1;
	this->motor_pin_2_2 = motor_pin_2;
	this->motor_pin_2_3 = motor_pin_3;
	this->motor_pin_2_4 = motor_pin_4;
}

void Deshif::een(int pin1, int pin2, int pin3, int pin4)
{
	digitalWrite(pin1, LOW);
	digitalWrite(pin2, HIGH);
	digitalWrite(pin3, HIGH);
	digitalWrite(pin4, LOW);
	delayMicroseconds(del);
}
void Deshif::twee(int pin1, int pin2, int pin3, int pin4) {
	digitalWrite(pin1, LOW);
	digitalWrite(pin2, HIGH);
	digitalWrite(pin3, LOW);
	digitalWrite(pin4, HIGH);
	delayMicroseconds(del);
}
void Deshif::drie(int pin1, int pin2, int pin3, int pin4) {
	digitalWrite(pin1, HIGH);
	digitalWrite(pin2, LOW);
	digitalWrite(pin3, LOW);
	digitalWrite(pin4, HIGH);
	delayMicroseconds(del);
}
void Deshif::vier(int pin1, int pin2, int pin3, int pin4) {
	digitalWrite(pin1, HIGH);
	digitalWrite(pin2, LOW);
	digitalWrite(pin3, HIGH);
	digitalWrite(pin4, LOW);
	delayMicroseconds(del);
}
void Deshif::motorOff(int pin1, int pin2, int pin3, int pin4) {
	digitalWrite(pin1, LOW);
	digitalWrite(pin2, LOW);
	digitalWrite(pin3, LOW);
	digitalWrite(pin4, LOW);
	Serial.println("Motor OFF");
}

void Deshif::select()
{
		 if (this->IN3 == 0 && this->IN2 == 0 && this->IN1 == 0 && this->IN0 == 0) wait();
	else if (this->IN3 == 0 && this->IN2 == 0 && this->IN1 == 0 && this->IN0 == 1) forward();
	else if (this->IN3 == 0 && this->IN2 == 0 && this->IN1 == 1 && this->IN0 == 0) back();
	else if (this->IN3 == 0 && this->IN2 == 0 && this->IN1 == 1 && this->IN0 == 1) left();
	else if (this->IN3 == 0 && this->IN2 == 1 && this->IN1 == 0 && this->IN0 == 0) right();
	else if (this->IN3 == 0 && this->IN2 == 1 && this->IN1 == 0 && this->IN0 == 1) shag_up_forward();
	else if (this->IN3 == 0 && this->IN2 == 1 && this->IN1 == 1 && this->IN0 == 0) shag_up_back();
	else if (this->IN3 == 0 && this->IN2 == 1 && this->IN1 == 1 && this->IN0 == 1) shag_down_forward();
	else if (this->IN3 == 1 && this->IN2 == 0 && this->IN1 == 0 && this->IN0 == 0) shag_down_back();
}

void Deshif::wait()
{
	//servo_1.write(120);
	//servo_2.write(120);
	//digitalWrite(31, LOW);
	analogWrite(left_wheel_pin, 0);
	analogWrite(right_wheel_pin, 0);
	motorOff(this->motor_pin_1_1, this->motor_pin_1_2, this->motor_pin_1_3, this->motor_pin_1_4);
	motorOff(this->motor_pin_2_1, this->motor_pin_2_2, this->motor_pin_2_3, this->motor_pin_2_4);
}

void Deshif::forward()
{
	/*servo_1.write(140);
	delay(15);
	servo_2.write(140);
	delay(15);*/
	/*if (flag1 == false || flag2 == false)
	{
		//analogWrite(left_wheel_pin, 0);
		analogWrite(right_wheel_pin, 0);
		digitalWrite(31, HIGH);
		//digitalWrite(33, HIGH);
		flag1 = true;
		//flag2 = true;
	}*/
	if (flag_left == false || flag_right == false)
	{
		analogWrite(left_wheel_pin, 0);
		analogWrite(right_wheel_pin, 0);
		digitalWrite(31, LOW);
		delay(50);
		digitalWrite(33, LOW);
		delay(50);
		flag_left = true;
		flag_right = true;

		//analogWrite(left_wheel_pin, 160);
		//analogWrite(right_wheel_pin, 160);
		//Serial.println("Back to Forward");
	}
	else
	{
		
		analogWrite(left_wheel_pin, 120);
		analogWrite(right_wheel_pin, 120);

	}
	//analogWrite(left_wheel_pin, 120);
	
	/*digitalWrite(31, LOW);
	delay(50);
	digitalWrite(33, LOW);
	delay(50);
	
	analogWrite(right_wheel_pin, 140);

	analogWrite(left_wheel_pin, 160);*/
	
}

void Deshif::back()
{
	/*servo_1.write(10);
	delay(15);
	servo_2.write(10);
	delay(15);*/
	/*if (flag1 == true || flag2 == true)
	{
		//analogWrite(left_wheel_pin, 0);
		analogWrite(right_wheel_pin, 0);
		digitalWrite(31, LOW);
		//digitalWrite(33, LOW);
		flag1 = false;
		//flag2 = false;
	}
	//analogWrite(left_wheel_pin, 120);
	analogWrite(right_wheel_pin, 120);*/

	if (flag_left == true || flag_right == true)
	{
		analogWrite(left_wheel_pin, 0);
		analogWrite(right_wheel_pin, 0);
		digitalWrite(31, HIGH);
		delay(50);
		digitalWrite(33, HIGH);
		delay(50);
		flag_left = false;
		flag_right = false;

		/*analogWrite(left_wheel_pin, 160);
		analogWrite(right_wheel_pin, 160);
		Serial.println("Forward to Back");*/
	}
	else
	{
		analogWrite(left_wheel_pin, 172);
		analogWrite(right_wheel_pin, 117);
	}

	/*digitalWrite(31, HIGH);
	delay(50);
	digitalWrite(33, HIGH);
	delay(50);
	
	analogWrite(right_wheel_pin, 140);
	analogWrite(left_wheel_pin, 160);*/
}

void Deshif::left()
{
	if ((flag_left == true && flag_right == false) || (flag_left == true && flag_right == true) || (flag_left == false && flag_right == false))
	{
		analogWrite(left_wheel_pin, 0);
		analogWrite(right_wheel_pin, 0);
		digitalWrite(31, HIGH);	
		digitalWrite(33, LOW);
		flag_left = false;
		flag_right = true;

		
	}
	else
	{
		analogWrite(left_wheel_pin, 175);
		analogWrite(right_wheel_pin, 117);
	}

	/*digitalWrite(31, HIGH);
	
	digitalWrite(33, LOW);
	
	analogWrite(left_wheel_pin, 175);
	analogWrite(right_wheel_pin, 117);*/
	
	
	
}

void Deshif::right()
{
	if ((flag_left == false && flag_right == true) || (flag_left == true && flag_right == true) || (flag_left == false && flag_right == false))
	{
		analogWrite(left_wheel_pin, 0);
		analogWrite(right_wheel_pin, 0);
		digitalWrite(31, LOW);
		digitalWrite(33, HIGH);
		flag_left = true;
		flag_right = false;


	}
	else
	{
		analogWrite(left_wheel_pin, 175);
		analogWrite(right_wheel_pin, 117);
	}
	/*analogWrite(left_wheel_pin, 115);
	analogWrite(right_wheel_pin, 115);

	digitalWrite(31, LOW);
	
	digitalWrite(33, HIGH);
	
	analogWrite(left_wheel_pin, 175);
	analogWrite(right_wheel_pin, 111);*/
}

void Deshif::shag_up_forward()
{
	vier(this->motor_pin_1_1, this->motor_pin_1_2, this->motor_pin_1_3, this->motor_pin_1_4);
	drie(this->motor_pin_1_1, this->motor_pin_1_2, this->motor_pin_1_3, this->motor_pin_1_4);
	twee(this->motor_pin_1_1, this->motor_pin_1_2, this->motor_pin_1_3, this->motor_pin_1_4);
	een(this->motor_pin_1_1, this->motor_pin_1_2, this->motor_pin_1_3, this->motor_pin_1_4);
	count++;
	if (count % 200 == 0)
	{
		Serial.println("TUT");
		yield();
		count = 0;
	}
}

void Deshif::shag_up_back()
{
	een(this->motor_pin_1_1, this->motor_pin_1_2, this->motor_pin_1_3, this->motor_pin_1_4);
	twee(this->motor_pin_1_1, this->motor_pin_1_2, this->motor_pin_1_3, this->motor_pin_1_4);
	drie(this->motor_pin_1_1, this->motor_pin_1_2, this->motor_pin_1_3, this->motor_pin_1_4);
	vier(this->motor_pin_1_1, this->motor_pin_1_2, this->motor_pin_1_3, this->motor_pin_1_4);
	count++;
	if (count % 200 == 0)
	{
		yield();
		count = 0;
	}
}

void Deshif::shag_down_forward()
{
	vier(this->motor_pin_2_1, this->motor_pin_2_2, this->motor_pin_2_3, this->motor_pin_2_4);
	drie(this->motor_pin_2_1, this->motor_pin_2_2, this->motor_pin_2_3, this->motor_pin_2_4);
	twee(this->motor_pin_2_1, this->motor_pin_2_2, this->motor_pin_2_3, this->motor_pin_2_4);
	een(this->motor_pin_2_1, this->motor_pin_2_2, this->motor_pin_2_3, this->motor_pin_2_4);
	count++;
	if (count % 200 == 0)
	{
		yield();
		count = 0;
	}
}

void Deshif::shag_down_back()
{
	een(this->motor_pin_2_1, this->motor_pin_2_2, this->motor_pin_2_3, this->motor_pin_2_4);
	twee(this->motor_pin_2_1, this->motor_pin_2_2, this->motor_pin_2_3, this->motor_pin_2_4);
	drie(this->motor_pin_2_1, this->motor_pin_2_2, this->motor_pin_2_3, this->motor_pin_2_4);
	vier(this->motor_pin_2_1, this->motor_pin_2_2, this->motor_pin_2_3, this->motor_pin_2_4);
	count++;
	if (count % 200 == 0)
	{
		yield();
		count = 0;
	}
}

Deshif::~Deshif()
{
}