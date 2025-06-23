// motor 1
#define motor1_en 10
#define motor1_pin1 8
#define motor1_pin2 9

// motor 2
#define motor2_en 11
#define motor2_pin1 12
#define motor2_pin2 13

// setting up the speed
#define speed 80

// writing functions for motors, m1 stands for motor1 and cw stands for clockwise aka forward, aw stands for anticlockwise 

void m1_cw()
{
  analogWrite(motor1_en,speed);
  digitalWrite(motor1_pin1,HIGH);
  digitalWrite(motor1_pin2,LOW);
}

void m1_aw()
{
  analogWrite(motor1_en,speed);
  digitalWrite(motor1_pin1,LOW);
  digitalWrite(motor1_pin2,HIGH);
}

 // for motor2

void m2_cw()
 {
  analogWrite(motor2_en, speed);
  digitalWrite(motor2_pin1,HIGH);
  digitalWrite(motor2_pin2,LOW);
} 

void m2_aw()
{
  analogWrite(motor2_en,speed);
  digitalWrite(motor2_pin1,LOW);
  digitalWrite(motor2_pin2,HIGH);
}

// defining fucntions for whole robot, calling both motor functions
// the motor on the right is connected with pin3,pin4 so its actually motor2

void forward()
{
  m1_cw();
  m2_cw();
}

void right()
{
  m2_aw();
  m1_cw();
}

void left()
{
  m1_aw();
  m2_cw();
}

void back()
{
  m1_aw();
  m2_aw();
}

void stop()
{
  analogWrite(motor1_en,0);
  analogWrite(motor2_en,0);
}

void setup() {
  // motor1 setup
  pinMode(motor1_en,OUTPUT);
  pinMode(motor1_pin1,OUTPUT);
  pinMode(motor1_pin2,OUTPUT);

  // motor2 setup 
  pinMode(motor2_en,OUTPUT);
  pinMode(motor2_pin1,OUTPUT);
  pinMode(motor2_pin2,OUTPUT);

  Serial.begin(9600);

}

char direction;

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    direction=Serial.read();
    if(direction=='F') forward();
    else if(direction=='B') back();
    else if(direction=='R') right();
    else if(direction=='L') left();
    else if(direction=='S') stop();
    else Serial.print(direction); // incase if it sends wrong command, then for debugging
  }

}
