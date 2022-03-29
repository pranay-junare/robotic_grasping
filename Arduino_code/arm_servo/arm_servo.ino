#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();


//#define SERVOMIN  150 // This is the 'minimum' pulse length count (out of 4096)
//#define SERVOMAX  600 // This is the 'maximum' pulse length count (out of 4096)
#define USMIN  600 // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX  2400 // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates




// our defines
uint16_t SERVOMIN[6] = { 90, 140, 350, 350, 350, 250 };
uint16_t SERVOMAX[6] = {440, 450, 150, 150, 150, 450 };
uint16_t ANGLEMAX[6] = {180, 170, 116, 113, 103, 180 }; // last gripper 180 not used

//waist rotation
#define SERVO_1   0
//shoulder elevation
#define SERVO_2   1c
//elbow elevation
#define SERVO_3   2
//wrist elevation
#define SERVO_4   3
//wrist rotation
#define SERVO_5   4
//gripper open
#define SERVO_6   5


int incomingByte = 0;
int choice = 0;



///////////////////////////////////////////////////////////////////

// our servo # counter
uint8_t servonum = 0;


void setup() {
  Serial.begin(9600);
  Serial.println("8 channel Servo test!");

  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates

  delay(10);
  move_servo_home();   // move servo to our defined home.
}




#define SERVO_MAX_SPEED 10
int angle =180;
int mot_num=0;
int pulse_val = 0;

String mot_num_str, pulse_val_str;
int val_curr[6];
int val_prev[6] = {320,240,180,220,300,350};  // initial values
int speed_ser =15; //15: medium ; 5: slow  ; 30 max
int servo_angle_offset[6] =  { 25 , -13, -42, -40, -15, 0}; //115-90 ( calib angle - orignal angle )



/*
 // Servo Motor Parameters, Refernces
 // int orig_angle[6] =  { 90, 90 , 90, 90, 90};
 // int calib_angle[6] = { 115 , 77, 48, 50, 75};  // angles at 90 degree
 //gripper max x =450 (servo pwm) ,  48 mm
 //gripper min x= 250  (servo pwm) , 10 mm

*/

   //uint16_t ANGLEMAX[6] = {180, 170, 116, 113, 103, 180 };   
   // Test_motion_00();
   //home = {90,110,120,130}




void loop(){

  

  //float value = read_Serialterminal();
  //move_servo_gripper(value);

}
