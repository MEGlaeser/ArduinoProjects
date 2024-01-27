/*  ___   ___  ___  _   _  ___   ___   ____ ___  ____  
 * / _ \ /___)/ _ \| | | |/ _ \ / _ \ / ___) _ \|    \ 
 *| |_| |___ | |_| | |_| | |_| | |_| ( (__| |_| | | | |
 * \___/(___/ \___/ \__  |\___/ \___(_)____)___/|_|_|_|
 *                  (____/ 
 * Arduino Mecanum Omni Direction Wheel Robot Car
 * Tutorial URL http://osoyoo.com/?p=30022
 * CopyRight www.osoyoo.com

 * After running the code, smart car will 
 * go forward and go backward for 2 seconds, 
 * left turn and right turn for 2 seconds, 
 * right shift and left shift for 2 seconds,
 * left diagonal back and right diagonal forward for 2 seconds,
 * left diagonal forward and right diagonal back for 2 seconds,
 * then stop. 
 * 
 * Front Motors
 * ENA-D9
 * ENB-D10
 * IN1-D22
 * IN2-D24
 * IN3-D26
 * IN4-D28
 * 
 * Rear Motors
 * ENA-D11
 * ENB-D12
 * IN1-D5
 * IN2-D6
 * IN3-D7
 * IN4-D8
 * 
 */
#define SPEED 100
#define TURN_SPEED 100
#define time 1000
#define speedPinR 9           //  Front Wheel PWM pin connect Right MODEL-X ENA
#define RightMotorDirPin1 22  //Front Right Motor direction pin 1 to Right MODEL-X IN1  (K1)
#define RightMotorDirPin2 24  //Front Right Motor direction pin 2 to Right MODEL-X IN2   (K1)
#define LeftMotorDirPin1 26   //Front Left Motor direction pin 1 to Right MODEL-X IN3 (K3)
#define LeftMotorDirPin2 28   //Front Left Motor direction pin 2 to Right MODEL-X IN4 (K3)
#define speedPinL 10          //  Front Wheel PWM pin connect Right MODEL-X ENB

#define speedPinRB 11         //  Rear Wheel PWM pin connect Left MODEL-X ENA
#define RightMotorDirPin1B 5  //Rear Right Motor direction pin 1 to Left  MODEL-X IN1 ( K1)
#define RightMotorDirPin2B 6  //Rear Right Motor direction pin 2 to Left  MODEL-X IN2 ( K1)
#define LeftMotorDirPin1B 7   //Rear Left Motor direction pin 1 to Left  MODEL-X IN3  (K3)
#define LeftMotorDirPin2B 8   //Rear Left Motor direction pin 2 to Left  MODEL-X IN4 (K3)
#define speedPinLB 12         //  Rear Wheel PWM pin connect Left MODEL-X ENB

/*motor control*/
void forward(int speed, int step) {
  for (int i = 0; i < step; i++) {
    RL_fwd(speed);
    RR_fwd(speed);
    FR_fwd(speed);
    FL_fwd(speed);
    delay(time);
    stop_Stop();
    delay(time);
  };
}
void backward(int speed, int step) {
  for (int i = 0; i < step; i++) {
    RL_bck(speed);
    RR_bck(speed);
    FR_bck(speed);
    FL_bck(speed);
    delay(time);
    stop_Stop();
    delay(time);
  };
}
void strafe_right(int speed_fl_fwd, int speed_rl_bck, int speed_rr_fwd, int speed_fr_bck, int step) {
  for (int i = 0; i < step; i++) {
    FL_fwd(speed_fl_fwd);
    RL_bck(speed_rl_bck);
    RR_fwd(speed_rr_fwd);
    FR_bck(speed_fr_bck);
    delay(time);
    stop_Stop();
    delay(time);
  };
}
void strafe_left(int speed_fl_bck, int speed_rl_fwd, int speed_rr_bck, int speed_fr_fwd, int step) {
  for (int i = 0; i < step; i++) {
    FL_bck(speed_fl_bck);
    RL_fwd(speed_rl_fwd);
    RR_bck(speed_rr_bck);
    FR_fwd(speed_fr_fwd);
    delay(time);
    stop_Stop();
    delay(time);
  };
}

void left_turn(int speed, int step) {
  for (int i = 0; i < step; i++) {
    RL_bck(0);
    RR_fwd(speed);
    FR_fwd(speed);
    FL_bck(0);
    delay(time);
    stop_Stop();
    delay(time);
  };
}
void right_turn(int speed, int step) {
  for (int i = 0; i < step; i++) {
    RL_fwd(speed);
    RR_bck(0);
    FR_bck(0);
    FL_fwd(speed);
    delay(time);
    stop_Stop();
    delay(time);
  };
}
void left_back(int speed, int step) {
  for (int i = 0; i < step; i++) {
    RL_fwd(0);
    RR_bck(speed);
    FR_bck(speed);
    FL_fwd(0);
    delay(time);
    stop_Stop();
    delay(time);
  };
}
void right_back(int speed, int step) {
  for (int i = 0; i < step; i++) {
    RL_bck(speed);
    RR_fwd(0);
    FR_fwd(0);
    FL_bck(speed);
    delay(time);
    stop_Stop();
    delay(time);
  };
}
void clockwise(int speed, int step) {
  for (int i = 0; i < step; i++) {
    RL_fwd(speed);
    RR_bck(speed);
    FR_bck(speed);
    FL_fwd(speed);
    delay(time);
    stop_Stop();
    delay(time);
  };
}
void countclockwise(int speed, int step) {
  for (int i = 0; i < step; i++) {
    RL_bck(speed);
    RR_fwd(speed);
    FR_fwd(speed);
    FL_bck(speed);
    delay(time);
    stop_Stop();
    delay(time);
  };
}


void FR_fwd(int speed)  //front-right wheel forward turn
{
  digitalWrite(RightMotorDirPin1, HIGH);
  digitalWrite(RightMotorDirPin2, LOW);
  analogWrite(speedPinR, speed);
}
void FR_bck(int speed)  // front-right wheel backward turn
{
  digitalWrite(RightMotorDirPin1, LOW);
  digitalWrite(RightMotorDirPin2, HIGH);
  analogWrite(speedPinR, speed);
}
void FL_fwd(int speed)  // front-left wheel forward turn
{
  digitalWrite(LeftMotorDirPin1, HIGH);
  digitalWrite(LeftMotorDirPin2, LOW);
  analogWrite(speedPinL, speed);
}
void FL_bck(int speed)  // front-left wheel backward turn
{
  digitalWrite(LeftMotorDirPin1, LOW);
  digitalWrite(LeftMotorDirPin2, HIGH);
  analogWrite(speedPinL, speed);
}

void RR_fwd(int speed)  //rear-right wheel forward turn
{
  digitalWrite(RightMotorDirPin1B, HIGH);
  digitalWrite(RightMotorDirPin2B, LOW);
  analogWrite(speedPinRB, speed);
}
void RR_bck(int speed)  //rear-right wheel backward turn
{
  digitalWrite(RightMotorDirPin1B, LOW);
  digitalWrite(RightMotorDirPin2B, HIGH);
  analogWrite(speedPinRB, speed);
}
void RL_fwd(int speed)  //rear-left wheel forward turn
{
  digitalWrite(LeftMotorDirPin1B, HIGH);
  digitalWrite(LeftMotorDirPin2B, LOW);
  analogWrite(speedPinLB, speed);
}
void RL_bck(int speed)  //rear-left wheel backward turn
{
  digitalWrite(LeftMotorDirPin1B, LOW);
  digitalWrite(LeftMotorDirPin2B, HIGH);
  analogWrite(speedPinLB, speed);
}

void stop_Stop()  //Stop
{
  analogWrite(speedPinLB, 0);
  analogWrite(speedPinRB, 0);
  analogWrite(speedPinL, 0);
  analogWrite(speedPinR, 0);
}


//Pins initialize
void init_GPIO() {
  pinMode(RightMotorDirPin1, OUTPUT);
  pinMode(RightMotorDirPin2, OUTPUT);
  pinMode(speedPinL, OUTPUT);

  pinMode(LeftMotorDirPin1, OUTPUT);
  pinMode(LeftMotorDirPin2, OUTPUT);
  pinMode(speedPinR, OUTPUT);
  pinMode(RightMotorDirPin1B, OUTPUT);
  pinMode(RightMotorDirPin2B, OUTPUT);
  pinMode(speedPinLB, OUTPUT);

  pinMode(LeftMotorDirPin1B, OUTPUT);
  pinMode(LeftMotorDirPin2B, OUTPUT);
  pinMode(speedPinRB, OUTPUT);

  stop_Stop();
}

void setup() {
  init_GPIO();

  forward(SPEED, 3);
  strafe_left(SPEED, SPEED, SPEED, SPEED, 3);
  strafe_right(SPEED, SPEED, SPEED, SPEED, 3);
  backward(SPEED, 3);
};
void loop() {
}
