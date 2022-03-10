#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();


#define SERVOMIN  150 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // This is the 'maximum' pulse length count (out of 4096)
#define USMIN  600 // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX  2400 // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates




// our defines

//waist rotation
#define SERVO_1   0
uint16_t servo1_angle = 1500;
uint16_t servo1_min = 500;
uint16_t servo1_max = 2500;

//shoulder elevation
#define SERVO_2   1
uint16_t servo2_angle = 1200;
uint16_t servo2_min = 800;
uint16_t servo2_max = 1900;

//elbow elevation
#define SERVO_3   2
uint16_t servo3_angle = 1900;
uint16_t servo3_min = 1000;
uint16_t servo3_max = 2400;

//wrist elevation
#define SERVO_4   3
uint16_t servo4_angle = 1500;
uint16_t servo4_min = 700;
uint16_t servo4_max = 2400;

//wrist rotation
#define SERVO_5   4
uint16_t servo5_angle = 1600;
uint16_t servo5_min = 500;
uint16_t servo5_max = 2500;

//gripper open
#define SERVO_6   5
uint16_t servo6_angle = 600;
uint16_t servo6_min = 550;
uint16_t servo6_max = 1250;



// our servo # counter
uint8_t servonum = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("8 channel Servo test!");

  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates

  delay(10);
}


// You can use this function if you'd like to set the pulse length in seconds
// e.g. setServoPulse(0, 0.001) is a ~1 millisecond pulse width. It's not precise!
void setServoPulse(uint8_t n, double pulse) {
  double pulselength;
  
  pulselength = 1000000;   // 1,000,000 us per second
  pulselength /= SERVO_FREQ;   // Analog servos run at ~60 Hz updates
  Serial.print(pulselength); Serial.println(" us per period"); 
  pulselength /= 4096;  // 12 bits of resolution
  Serial.print(pulselength); Serial.println(" us per bit"); 
  pulse *= 1000000;  // convert input seconds to us
  pulse /= pulselength;
  Serial.println(pulse);
  pwm.setPWM(n, 0, pulse);
}



/*
 * angleToPulse(int ang)
 * gets angle in degree and returns the pulse width
 * also prints the value on seial monitor
 * written by Ahmad Nejrabi for Robojax, Robojax.com
 */
int angleToPulse(int ang){
   int pulse = map(ang,0, 180, SERVOMIN,SERVOMAX);// map angle of 0 to 180 to Servo min and Servo max 
   Serial.print("Angle: ");Serial.print(ang);
   Serial.print(" pulse: ");Serial.println(pulse);
   return pulse;
}


int angle =180;
void loop(){

  
/*
    for( int angle =0; angle<=180; angle +=10){
      for(int i=0; i<16; i++)
        {      
            pwm.setPWM(i, 0, angleToPulse(angle) );
        }
    }

*/

 pwm.setPWM(0, 0, angleToPulse(10) );
 delay(1000);
 pwm.setPWM(0, 0, angleToPulse(120) );
 delay(1000);

}
