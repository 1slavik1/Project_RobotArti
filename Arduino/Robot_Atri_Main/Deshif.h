#ifndef Deshif_h
#define Deshif_h

class Deshif
{
public:
	Deshif();
		/*int motor_pin_5, int motor_pin_6, 
		int motor_pin_7, int motor_pin_8);*/
	~Deshif();
	void select();
	void SetCode(int IN3, int IN2, int IN1, int IN0);
	void Set_Pin_Shag1(int motor_pin_1, int motor_pin_2, int motor_pin_3, int motor_pin_4);
	void Set_Pin_Shag2(int motor_pin_1, int motor_pin_2, int motor_pin_3, int motor_pin_4);
	//void Set_Servo_1(int pin);
	//void Set_Servo_2(int pin);
	void Set_Pin_left_wheel(int pin);
	void Set_Pin_right_wheel(int pin);
	
private:
	int IN3, IN2, IN1, IN0;	//информационные ходы для 16-ти ричной системы

	void wait(); //режим ожидания

	//функции для движения робота
	void forward();
	void back();
	void left();
	void right();

	//функции для движения моторов
	void shag_up_forward();
	void shag_up_back();
	void shag_down_forward();
	void shag_down_back();

	//внутрение функции для движения шаговых моторов
	void een(int pin1, int pin2, int pin3, int pin4);
	void twee(int pin1, int pin2, int pin3, int pin4);
	void drie(int pin1, int pin2, int pin3, int pin4);
	void vier(int pin1, int pin2, int pin3, int pin4);
	void motorOff(int pin1, int pin2, int pin3, int pin4);

	// пины для шаговых моторов
	int motor_pin_1_1;
	int motor_pin_1_2;
	int motor_pin_1_3;
	int motor_pin_1_4;
	int motor_pin_2_1;
	int motor_pin_2_2;
	int motor_pin_2_3;
	int motor_pin_2_4;

	//int servo_pin_1;
	//int servo_pin_2;

	//пины ходовой части
	int left_wheel_pin;
	int right_wheel_pin;
};

#endif