/*-//-//-//-//-//-//-//-//-//- INFOMATION -//-//-//-//-//-//-//-//-//-*/

/* Future Engineer WRO Germany 2022
  by Thailand Team <https://ybrobot.club/>
*/

/*-//-//-//-//-//-//-//-//-//- LIBRARY SETUP -//-//-//-//-//-//-//-//-//-*/

// PID
float err, last_err, integral;
long PIDtimer;

// Ultrasonic Sensor
#include <NewPing.h>
NewPing sonar(28, 29, 100);  //initialisation class HCSR04 (trig pin , echo pin, max distance
long UStimer;
int USread;

// Cytron Maker Driver Library
#include "CytronMotorDriver.h"
CytronMD motor1(PWM_PWM, 3, 4);

// Compass
#include <Wire.h>
#define ADDRESS 0x60
byte highByte;
byte lowByte;
int bearing = 0;
long Ctimer;
int initial_deg;

// Servo (Ultrasonic and Steering)
#include <Servo.h>
Servo myservo1;  // Ultrasonic
Servo myservo2;  // Steering


/*-//-//-//-//-//-//-//-//-//- PROGRAM SETUP -//-//-//-//-//-//-//-//-//-*/


/* setup() and loop()
  is for executing steering control, speed contol, Ultrasonic servo control
*/

void setup() {
  pinMode(26, INPUT_PULLUP);  // Set START button pin mode
  myservo1.attach(13, 600, 2400);
  myservo2.attach(12, 600, 2400);

  while (digitalRead(26) == 1)  // Wait until START button is pressed
    ;
  initial_deg = bearing;  // Set initial robot direction
}

/* setup1() and loop1()
  is for conputing steering degree, speed, Ultrasonic servo degree, Block Detection
*/

void setup1() {
  Wire1.setSDA(6);  // Set SDA pin for I2C communication
  Wire1.setSCL(7);  // Set SCL pin for I2C communication
  Wire1.begin();
  Serial.begin(115200);  // Begin Serial communication for debugging
}


void loop() {

  motor1.setSpeed(255);

  // int pos;
  // for (pos = 0; pos <= 270; pos += 1) {  // goes from 0 degrees to 180 degrees
  //   Servo1(pos);                         // tell servo to go to position in variable 'pos'
  //   Servo2(135);
  //   Serial.print(USread);
  //   Serial.print(" cm ");
  //   Serial.print(bearing);
  //   Serial.print(" degree\n");
  //   delay(3);  // waits 15ms for the servo to reach the position
  // }
  // for (pos = 270; pos >= 0; pos -= 1) {  // goes from 180 degrees to 0 degrees
  //   Servo1(pos);                         // tell servo to go to position in variable 'pos'
  //   Servo2(135);
  //   Serial.print(USread);
  //   Serial.print(" cm ");
  //   Serial.print(bearing);
  //   Serial.print(" degree\n");
  //   delay(3);  // waits 15ms for the servo to reach the position
  // }
  // float wrap = Wrap((bearing - initial_deg) * -1, -180, 179);
  // float test = PID(wrap, 0.5, 0, 3);

  Servo2(PID(Wrap((bearing - initial_deg) * -1, -180, 179), 0.5, 0, 3) + 135);  // Set steering degree

  // Serial.print(wrap);
  // Serial.print(" --> ");
  // Serial.println(test);
  // float i = 0;
  // while (true) {
  //   // Serial.print(initial_deg);
  //   // Serial.print(" -> ");
  //   Serial.println(Wrap(bearing - initial_deg, 0, 359));
  //   // initial_deg = initial_deg + 360;
  //   delay(10);
  // }
}

void loop1() {

  CompassUpdate();
  UltraSonicUpdate();


  // Serial.println(bearing);
}

void Servo1(long theta) {
  theta = constrain(theta, 45, 225);   // Limit Servo degree
  theta = map(theta, 0, 270, 0, 180);  // Map degree to correct the position
  // Serial.println(pos);
  myservo1.write(theta);
}

void Servo2(long theta) {
  theta = constrain(theta, 90, 180);   // Limit servo degree
  theta = map(theta, 0, 270, 0, 180);  // Map degree to correct the position
  // Serial.println(pos);
  myservo2.write(theta);
}

void UltraSonicUpdate() {
  if (millis() - UStimer > 50) {  // Update Ultrasonic every 50 ms
    UStimer = millis();
    USread = sonar.ping_cm();
  }
}

void CompassUpdate() {
  if (millis() - Ctimer > 50) {        // Update Ultrasonic every 50 ms
    Wire1.beginTransmission(ADDRESS);  //starts communication with cmps03
    Wire1.write(2);                    //Sends the register we wish to read
    Wire1.endTransmission();

    Wire1.requestFrom(ADDRESS, 2);    //requests high byte
    while (Wire1.available() < 2) {}  //while there is a byte to receive
    highByte = Wire1.read();          //reads the byte as an integer
    lowByte = Wire1.read();
    bearing = ((highByte << 8) + lowByte) / 10;   // Convert to degree
    Ctimer = millis();
  }
}

float PID(float input, float kp, float ki, float kd) {
  if (millis() - PIDtimer > 10) {
    err = input * kp + integral * ki + (input - last_err) * kd;
    integral = integral + err;
    last_err = input;
    PIDtimer = millis();
  }
  return err;
}

float Wrap(float a, float min, float max) {  // Loop values in a certain range
  while (a > max || a < min) {
    if (a > max) {
      a = a - (max - min + 1);
    } else {
      a = a + (max - min + 1);
    }
  }
  return a;
}