/*-//-//-//-//-//-//-//-//-//- INFOMATION -//-//-//-//-//-//-//-//-//-*/

/* Future Engineer WRO Germany 2022
  by Thailand Team <https://ybrobot.club/>
*/

/*-//-//-//-//-//-//-//-//-//- LIBRARY SETUP -//-//-//-//-//-//-//-//-//-*/

//Adafruit TCS34725 Color Sensor
#include <ColorSensorTCS34725.h>
#define COLOR_SDA_PIN 12
#define COLOR_SCL_PIN 13
ColorSensorTCS34725 colorSensor(COLOR_SDA_PIN, COLOR_SCL_PIN);
float MeanRGB;
long RGBtimer;
char line = 'W';
int line_offset = 10;
int line_count = 0;

// PID
float err, last_err, integral;
long PIDtimer;

// Ultrasonic Sensor
#include <NewPing.h>
NewPing sonar(29, 28, 100);  //initialisation class HCSR04 (trig pin , echo pin, max distance
long UStimer;
int USread;

// Cytron Maker Driver Library
// #include "CytronMotorDriver.h"
// CytronMD motor1(PWM_PWM, 2, 3);
long motor1timer;
float Currentspeed;


// Compass
#include <Wire.h>
#define CMPSADDRESS 0x60
byte highByte;
byte lowByte;
bool Reading = false;
float bearing = 0;
float bearingPID = 0;
long Ctimer;
float initial_deg;

// Servo (Ultrasonic and Steering)
#include <Servo.h>
Servo myservo1;  // Ultrasonic
int servo_deg;
Servo myservo2;  // Steering

// Neopixel LEDs
#include <Adafruit_NeoPixel.h>
#define LED_COUNT 2
#define LED_PIN 11
long LEDtimer;
long firstPixelHue = 0;
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);


/*-//-//-//-//-//-//-//-//-//- PROGRAM SETUP -//-//-//-//-//-//-//-//-//-*/


/* setup() and loop()
  is for executing steering control, speed contol, Ultrasonic servo control
*/

void setup() {
  delay(1000);
  pinMode(26, INPUT);  // Set START button pin mode
  pinMode(28, INPUT);
  pinMode(29, INPUT);
  myservo1.attach(15, 600, 2400);
  myservo2.attach(14, 600, 2400);
  Servo1(75);
  servo_deg = 75;
  Servo2(135);
  // delay(1500);

  while (analogRead(26) != 1023) {
    // Serial.println(analogRead(26));
    // delay(100);
  }  // Wait until START button is pressed
  // CompassUpdate();
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
  strip.begin();
  strip.show();
  strip.setBrightness(30);
  delay(1000);
  pinMode(26, INPUT);  // Set START button pin mode
  Wire1.setSDA(6);     // Set SDA pin for I2C communication
  Wire1.setSCL(7);     // Set SCL pin for I2C communication
  Wire1.begin();
  Serial.begin(57600);  // Begin Serial communication for debugging

  Wire1.beginTransmission(CMPSADDRESS);  //starts communication with cmps03
  Wire1.write(12);
  Wire1.write(0x55);
  Wire1.endTransmission();
  Wire1.beginTransmission(CMPSADDRESS);  //starts communication with cmps03
  Wire1.write(13);
  Wire1.write(0x5A);
  Wire1.endTransmission();
  Wire1.beginTransmission(CMPSADDRESS);  //starts communication with cmps03
  Wire1.write(14);
  Wire1.write(0xA5);
  Wire1.endTransmission();
  Wire1.beginTransmission(CMPSADDRESS);  //starts communication with cmps03
  Wire1.write(15);
  Wire1.write(0x12);
  Wire1.endTransmission();

  colorSensor.setWaitTime(0);
  colorSensor.setIntegrationTime(5);
  colorSensor.setGain(CS_GAIN_16);
  if (!colorSensor.begin()) {
    Serial.println("RGB ERROR");
    while (true)
      ;
  }
  while (analogRead(26) != 1023) {
    RGBUpdate(false);
    CompassUpdate();
    UltraSonicUpdate();
    rainbow(10);
    
  }
  RGBtimer = millis() - 500;
}


void loop() {
  while (line_count < 12 || millis() - RGBtimer < 1000) {


    UltraSonicUpdate();
    // analogWrite(2, 4095);
    // analogWrite(3, 0);
    // analogWrite(8, map(abs(Wrap((bearingPID - initial_deg), -180, 179)), 90, 0, 1500, 2800));

    motor1(map(abs(Wrap((bearingPID - initial_deg), -180, 179)), 90, 0, 20, 80), 20);


    if (line == 'R') {
      initial_deg = initial_deg + 90;
      line_offset = -10;
      line = 'W';
      // Servo1(45);
      Serial.println("REDD");
    } else if (line == 'B') {
      initial_deg = initial_deg - 90;
      line_offset = 10;
      line = 'W';

      // Servo1(225);
      Serial.println("BLUEE");
    }

    // if (abs(Wrap((bearing - initial_deg), -180, 179)) > 25) {

    //   Servo2(Wrap((bearingPID - initial_deg) * -1, -180, 179) * 0.3 + 135);
    // } else {
    Servo2(Wrap((Wrap(bearingPID - initial_deg, -180, 179) * mapf(abs(Wrap(bearingPID - initial_deg, -180, 179)), 0, 90, 0.25, 0.4) - line_offset * constrain(mapf(USread, 25, 60, -1, 1), -1, 0.6) * mapf(abs(Wrap(bearingPID - initial_deg, -180, 179)), 0, 90, 0.8, 0.5)) * -1, -180, 179) + 135);
    // }

    Servo1(servo_deg + Wrap((bearing - initial_deg), -180, 179));
  }



  while (1) {
    analogWrite(2, 4095);
    analogWrite(3, 4095);
    analogWrite(8, 4095);
  }

  // Serial.println(map(abs(Wrap((bearingPID - initial_deg), -180, 179)), 180, 0, 500, 4095));
}

void loop1() {

  CompassUpdate();
  RGBUpdate(true);

  rainbow(10);
}

void Servo1(int theta) {
  theta = constrain(theta, 45, 225) + map(theta, 0, 360, -10, 20);  // Limit Servo degree
  theta = int(map(theta, 0, 270, 0, 180));                          // Map degree to correct the position
  myservo1.write(theta);
}

void Servo2(int theta) {
  theta = constrain(theta, 90, 180) + map(theta, 0, 360, 0, 10);  // Limit servo degree
  theta = int(map(theta, 0, 270, 0, 180));                        // Map degree to correct the position
  myservo2.write(theta);
}

void UltraSonicUpdate() {

  USread = map(analogRead(29), 0, 1023, 0, 500) * 0.866025;
}

void CompassUpdate() {
  Wire1.beginTransmission(CMPSADDRESS);  //starts communication with cmps03
  Wire1.write(2);                        //Sends the register we wish to read
  Wire1.endTransmission();
  Reading = true;


  Wire1.requestFrom(CMPSADDRESS, 2);  //requests high byte
  int errorTimer = millis();
  while (Wire1.available() < 2 && ((millis() - errorTimer) < 150)) { Serial.println("waiting..."); }  //while there is a byte to receive
  highByte = Wire1.read();                                                                            //reads the byte as an integer
  lowByte = Wire1.read();
  bearing = ((highByte << 8) + lowByte) / 10;  // Convert to degree
  bearingPID = PID(bearing, 1, 0, 3);
  // Serial.println(bearingPID);
  Reading = false;
  // Serial.println("Compass Updated...");
}

float PID(float input, float kp, float ki, float kd) {
  if (millis() - PIDtimer > 1) {
    err = input * kp + integral * ki + (input - last_err) * kd;
    integral = integral + err;
    last_err = input;
    PIDtimer = millis();
  }
  return err;
}

// motor(1, PID(analogRead(5), 0.5, 0, 0.2));

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

void RGBUpdate(bool Line_read) {

  RGBC v = colorSensor.readRGBC();
  float red = map(v.r, 0, 626, 0, 100);
  float green = map(v.g, 0, 825, 0, 100);
  float blue = map(v.b, 0, 927, 0, 100);

  // Serial.println(v.c);

  if (v.c < 1500 && (millis() - RGBtimer) > 1000 && line == 'W' && Line_read) {
    if (red > blue) {
      // Serial.println("Red: ");
      MeanRGB = (MeanRGB + 1);
    } else {
      // Serial.println("Blue: ");
      MeanRGB = (MeanRGB - 1);

      //      while (true);
    }


  } else if (MeanRGB != 0) {
    if (MeanRGB > 0) {
      Serial.println("RED");
      servo_deg = 195;
      line = 'R';


    } else {
      Serial.println("BLUE");
      servo_deg = 75;
      line = 'B';
    }
    RGBtimer = millis();
    // servo_deg = 135;
    // Serial.println(MeanRGB / i);
    MeanRGB = 0;
    line_count++;
    // i = 0;
  }
  // Serial.println(MeanRGB);
}

void rainbow(int wait) {
  if (millis() - LEDtimer > wait) {
    if (firstPixelHue >= 5 * 65536) {
      firstPixelHue = 0;
    }
    // for (long firstPixelHue = 0; firstPixelHue < 5 * 65536; firstPixelHue += 256) {
    for (int i = 0; i < strip.numPixels(); i++) {
      // int pixelHue = firstPixelHue + (i * 65536L / strip.numPixels());
      int pixelHue = firstPixelHue;
      strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
    }
    strip.show();
    LEDtimer = millis();
    firstPixelHue += 256;
    // }
  }
  // else {
  //   firstPixelHue = 0;
  // }
}

float mapf(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void motor1(int speed, int acceleration) {
  if (millis() - motor1timer > acceleration) {
    // digitalWrite(2, 1);
    // digitalWrite(3, 0);
    Currentspeed = (speed - Currentspeed) * 0.1 + Currentspeed;
    if (Currentspeed > 0) {
      analogWrite(2, 4095);
      analogWrite(3, 0);
    } else {
      analogWrite(2, 0);
      analogWrite(3, 4095);
    }
    analogWrite(8, map(abs(Currentspeed), 0, 100, 0, 4095));
    // Serial.print(speed);
    // Serial.print("\t");
    // Serial.println(Currentspeed);
    motor1timer = millis();
  }
}