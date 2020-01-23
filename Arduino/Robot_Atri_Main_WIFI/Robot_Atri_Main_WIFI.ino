#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
/* Put your SSID & Password */
const char* ssid = "NodeMCU";  // Enter SSID here
const char* password = "12345678";  //Enter Password here

/* Put IP Address details */
IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

ESP8266WebServer server(80);

int count=0;
long del = 2000;

int IN0 = D7;
int IN1 = D6;
int IN2 = D5;
int IN3 = D4;

int a=0;

bool forward_status = LOW;
bool back_status = LOW;
bool left_status = LOW;
bool right_status = LOW;
bool shag_up_forward_status = LOW;
bool shag_up_back_status = LOW;
bool shag_down_forward_status = LOW;
bool shag_down_back_status = LOW;

/*uint8_t LED3pin = D5;
bool LED3status = LOW;

uint8_t LED4pin = D4;
bool LED4status = LOW;*/


void setup() {
  Serial.begin(115200);
  
  pinMode(IN0, OUTPUT);  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  
  

  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(100);
  
  server.on("/", handle_OnConnect);
  
  server.on("/Move_forward_ON", Move_forward_ON);
  server.on("/Move_forward_OFF", Move_forward_OFF);
  
  server.on("/Move_back_ON", Move_back_ON);
  server.on("/Move_back_OFF", Move_back_OFF);
  
  server.on("/Move_left_ON", Move_left_ON);
  server.on("/Move_left_OFF", Move_left_OFF);
  
  server.on("/Move_right_ON", Move_right_ON);
  server.on("/Move_right_OFF", Move_right_OFF);
  
  server.on("/Move_shag_up_forward_ON", Move_shag_up_forward_ON);
  server.on("/Move_shag_up_forward_OFF", Move_shag_up_forward_OFF);
  
  server.on("/Move_shag_up_back_ON", Move_shag_up_back_ON);
  server.on("/Move_shag_up_back_OFF", Move_shag_up_back_OFF);

  server.on("/Move_shag_down_forward_ON", Move_shag_down_forward_ON);
  server.on("/Move_shag_down_forward_OFF", Move_shag_down_forward_OFF);
  
  server.on("/Move_shag_down_back_ON", Move_shag_down_back_ON);
  server.on("/Move_shag_down_back_OFF", Move_shag_down_back_OFF);
  
  server.onNotFound(handle_NotFound);
  
  server.begin();
  Serial.println("HTTP server started");
}
void loop() {  
  
  server.handleClient();


if (forward_status == HIGH) a=1;
else if (back_status == HIGH) a=2;
else if (left_status == HIGH) a=3;
else if (right_status == HIGH) a=4;
else if (shag_up_forward_status == HIGH) a=5;
else if (shag_up_back_status == HIGH) a=6;
else if (shag_down_forward_status == HIGH) a=7;
else if (shag_down_back_status == HIGH) a=8;

switch(a)
{
  case 1:
  {
    digitalWrite(IN0, HIGH);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    delay(15);
  }
  break;

  case 2:
  {
    digitalWrite(IN0, LOW);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    delay(15);
  }
  break;
  
  case 3:
  {
    digitalWrite(IN0, HIGH);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    delay(15);
  }
  break;
  
  case 4:
  {
    digitalWrite(IN0, LOW);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    delay(15);
  }
  break;
  
  case 5:
  {
    digitalWrite(IN0, HIGH);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    delay(15);
  }
  break;
  
  case 6:
  {
    digitalWrite(IN0, LOW);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    delay(15);
  }
  break;
  
  case 7:
  {
    digitalWrite(IN0, HIGH);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    delay(15);
  }
  break;
  
  case 8:
  {
    digitalWrite(IN0, LOW);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    delay(15);
  }
  break;
  
  default:
  {
    digitalWrite(IN0, LOW);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
  }
}

a=0;

 
}

void handle_OnConnect() {
  bool forward_status = LOW;
  bool back_status = LOW;
  bool left_status = LOW;
  bool right_status = LOW;
  bool shag_up_forward_status = LOW;
  bool shag_up_back_status = LOW;
  bool shag_down_forward_status = LOW;
  bool shag_down_back_status = LOW; 
}

//Вперед вкл
void Move_forward_ON() {
  forward_status = HIGH;  
}

//Вперед выкл
void Move_forward_OFF() {
  forward_status = LOW;  
}

//Назад вкл
void Move_back_ON() {
  back_status = HIGH;  
}

//Назад выкл
void Move_back_OFF() {
  back_status = LOW; 
}

//Влево вкл
void Move_left_ON() {
  left_status = HIGH;  
}

//Влево выкл
void Move_left_OFF() {
  left_status = LOW;  
}

//Вправо вкл
void Move_right_ON() {
  right_status = HIGH;  
}

//Вправо выкл
void Move_right_OFF() {
  right_status = LOW; 
}

//Шаговый вперед верхний вкл
void Move_shag_up_forward_ON() {
  shag_up_forward_status = HIGH;  
}

//Шаговый вперед верхний выкл
void Move_shag_up_forward_OFF() {
  shag_up_forward_status = LOW;  
}

//Шаговый назад верхний вкл
void Move_shag_up_back_ON() {
  shag_up_back_status = HIGH;  
}

//Шаговый назад верхний выкл
void Move_shag_up_back_OFF() {
  shag_up_back_status = LOW; 
}

//Шаговый вперед нижний вкл
void Move_shag_down_forward_ON() {
  shag_down_forward_status = HIGH;  
}

//Шаговый вперед нижний выкл
void Move_shag_down_forward_OFF() {
  shag_down_forward_status = LOW;  
}

//Шаговый назад нижний вкл
void Move_shag_down_back_ON() {
  shag_down_back_status = HIGH;  
}

//Шаговый назад нижний выкл
void Move_shag_down_back_OFF() {
  shag_down_back_status = LOW; 
}

void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}
