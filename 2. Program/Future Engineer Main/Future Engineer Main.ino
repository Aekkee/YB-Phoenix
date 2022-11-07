/*-//-//-//-//-//-//-//-//-//- INFOMATION -//-//-//-//-//-//-//-//-//-*/

/* Future Engineer WRO Germany 2022
  by Thailand Team <https://ybrobot.club/>
*/

/*-//-//-//-//-//-//-//-//-//- LIBRARY SETUP -//-//-//-//-//-//-//-//-//-*/

// PID
// #include <PID_v2.h>
// PID_v2 myPID(1, 0, 1, PID::Direct);
float err, last_err, integral;
long PIDtimer;

// Ultrasonic Sensor
#include <NewPing.h>
NewPing sonar(28, 29, 100);  //initialisation class HCSR04 (trig pin , echo pin, max distance
long UStimer;
int USread;

// Cytron Maker Driver Library
#include "CytronMotorDriver.h"
CytronMD motor1(PWM_PWM, 2, 3);

// Compass
#include <Wire.h>
#define ADDRESS 0x60
byte highByte;
byte lowByte;
bool Reading = false;
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
  // myPID.Start(0,              // input
  //             0,              // current output
  //             0);             // setpoint
  pinMode(26, INPUT_PULLUP);  // Set START button pin mode
  myservo1.attach(13, 600, 2400);
  myservo2.attach(12, 600, 2400);
  CompassUpdate();
  while (digitalRead(26) == 0)  // Wait until START button is pressed
    ;
  initial_deg = bearing;  // Set initial robot direction
  // CompassUpdate();

  // while (digitalRead(26) == 1)  // Wait until START button is pressed
  //   ;
  // initial_deg = bearing;  // Set initial robot direction
}

/* setup1() and loop1()
  is for conputing steering degree, speed, Ultrasonic servo degree, Block Detection
*/

void setup1() {
  Wire1.setSDA(6);  // Set SDA pin for I2C communication
  Wire1.setSCL(7);  // Set SCL pin for I2C communication
  Wire1.begin();
  Serial.begin(115200);  // Begin Serial communication for debugging

  Wire1.beginTransmission(ADDRESS);  //starts communication with cmps03
  Wire1.write(12);
  Wire1.write(0x55);
  Wire1.endTransmission();
  Wire1.beginTransmission(ADDRESS);  //starts communication with cmps03
  Wire1.write(13);
  Wire1.write(0x5A);
  Wire1.endTransmission();
  Wire1.beginTransmission(ADDRESS);  //starts communication with cmps03
  Wire1.write(14);
  Wire1.write(0xA5);
  Wire1.endTransmission();
  Wire1.beginTransmission(ADDRESS);  //starts communication with cmps03
  Wire1.write(15);
  Wire1.write(0x12);
  Wire1.endTransmission();
}


void loop() {
  digitalWrite(2, 1);
  digitalWrite(3, 0);
  analogWrite(8, 4095);

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
  // Serial.println(Wrap((bearing - initial_deg) * -1, -180, 179));
  // int why = myPID.Run(Wrap((bearing - initial_deg) * -1, -180, 179)) + 135;
  // Servo2(why);

  // Servo2(PID(Wrap((bearing - initial_deg) * -1, -180, 179), 0.7, 0, 2000) + 135);  // Set steering degree

  Servo2(Wrap((PID(bearing - initial_deg, 1, 0, 5)) * -1, -180, 179) * 0.5 + 135);

  // Servo2(Wrap((bearing - initial_deg) * -1, -180, 179) + 135);

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
  // Serial.println(Wrap((PID(bearing - initial_deg, 1, 0, 5)) * 1, -180, 179) + 135);
  // Serial.println(Wrap((bearing - initial_deg) * -1 + 135, -180, 179));
}

void loop1() {

  CompassUpdate();
  // UltraSonicUpdate();


  // Serial.println(bearing);
}

void Servo1(int theta) {
  theta = constrain(theta, 45, 225);   // Limit Servo degree
  theta = map(theta, 0, 270, 0, 180);  // Map degree to correct the position
  // Serial.println(pos);
  myservo1.write(theta);
}

void Servo2(int theta) {
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
  if (Reading == false) {
    Wire1.beginTransmission(ADDRESS);  //starts communication with cmps03
    Wire1.write(2);                    //Sends the register we wish to read
    Wire1.endTransmission();
    Reading = true;
    Ctimer = millis();
    // Serial.println("Beginning Transimission");
  }
  if (millis() - Ctimer > 33) {  // Update Ultrasonic every 50 ms

    Wire1.requestFrom(ADDRESS, 2);    //requests high byte
    while (Wire1.available() < 2) {}  //while there is a byte to receive
    highByte = Wire1.read();          //reads the byte as an integer
    lowByte = Wire1.read();
    bearing = ((highByte << 8) + lowByte) / 10;  // Convert to degree
    Reading = false;
    // Serial.println(millis() - Ctimer);
  }
}

float PID(float input, float kp, float ki, float kd) {
  if (millis() - PIDtimer > 2) {
    err = input * kp + integral * ki + (input - last_err) * kd;
    integral = integral + err;
    last_err = input;
    PIDtimer = millis();
  }
  // Serial.println(err);
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