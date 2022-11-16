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
char line_rem = 'W';
int line_offset = 10;
int line_count = 0;

// PID
float err, last_err, integral;
long PIDtimer;

float err1, last_err1, integral1;
long PIDtimer1;

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

//Pixy Camera
// #define UART
#include <Pixy2UART.h>
Pixy2UART pixy;
long pixytimer;
int loops = 0;
float offset_deg = 0;
int nearest_index;
int nearest_value;



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
  Servo1(215);
  servo_deg = 215;
  Servo2(0);
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
  delay(1000);
  strip.begin();
  strip.show();
  strip.setBrightness(30);
  // delay(1000);
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

  Serial1.setRX(17);
  Serial1.setTX(16);

  Serial.print("Starting...\n");
  // Serail1
  pixy.init();

  while (analogRead(26) != 1023) {
    RGBUpdate(false);
    CompassUpdate();
    UltraSonicUpdate();
    rainbow(10);
  }
  RGBtimer = millis() - 500;
}





void loop() {

  while (line_count < 12 || millis() - RGBtimer < 2000) {
    pixy.ccc.getBlocks();
    if (pixy.ccc.numBlocks != 0) {
      nearest_index = 0;
      nearest_value = pixy.ccc.blocks[nearest_index].m_height;

      for (int i = 0; i < pixy.ccc.numBlocks; i++) {
        if (pixy.ccc.blocks[i].m_height > nearest_value) {
          nearest_index = i;
          nearest_value = pixy.ccc.blocks[i].m_height;
        }
        // loops = loops + 1;
        // Serial.print("[ ");
        // Serial.print(1000 / (millis() - timer1));
        // Serial.print(" fps ]");
        // Serial.print("  block ");
        // Serial.print(i);
        // Serial.print(": ");
        // Serial.print(1000 * 2 / pixy.ccc.blocks[i].m_height);
        // Serial.print("\t");
        // Serial.print(1000 * 2 / pixy.ccc.blocks[i].m_height * tan(float(map(pixy.ccc.blocks[i].m_x, 0, 316, -30, 30)) / 180 * PI));
        // Serial.print("\t");
      }
      if (pixy.ccc.blocks[nearest_index].m_signature == 1) {
        servo_deg = 215;
        line_offset = 10;
        // Serial.println(float(atan2(1000 * 2 / pixy.ccc.blocks[nearest_index].m_height * tan(float(map(pixy.ccc.blocks[nearest_index].m_x, 0, 316, -30, 30) + Wrap(bearingPID - initial_deg, -180, 179)) / 180 * PI), 1000 * 2 / pixy.ccc.blocks[nearest_index].m_height)) * 180 / PI);
        Blocks((float(atan2(1000 * 2 / pixy.ccc.blocks[nearest_index].m_height * tan(float(map(pixy.ccc.blocks[nearest_index].m_x, 0, 316, -30, 30) + Wrap(bearingPID - initial_deg, -180, 179)) / 180 * PI) - 20, 1000 * 2 / pixy.ccc.blocks[nearest_index].m_height - 10)) * 180 / PI), 15);
        if (offset_deg > 0) {
          Blocks(0, 35);
        }
      } else {
        servo_deg = 55;
        line_offset = -10;
        // Serial.println(float(atan2(1000 * 2 / pixy.ccc.blocks[nearest_index].m_height * tan(float(map(pixy.ccc.blocks[nearest_index].m_x, 0, 316, -30, 30) + Wrap(bearingPID - initial_deg, -180, 179)) / 180 * PI), 1000 * 2 / pixy.ccc.blocks[nearest_index].m_height)) * 180 / PI);
        // offset_deg = *0.25 + offset_deg;
        Blocks((float(atan2(1000 * 2 / pixy.ccc.blocks[nearest_index].m_height * tan(float(map(pixy.ccc.blocks[nearest_index].m_x, 0, 316, -30, 30) + Wrap(bearingPID - initial_deg, -180, 179)) / 180 * PI) + 20, 1000 * 2 / pixy.ccc.blocks[nearest_index].m_height - 10)) * 180 / PI), 15);
        if (offset_deg < 0) {
          Blocks(0, 35);
        }
      }

    } else {
      Blocks(0, 35);
    }


    UltraSonicUpdate();


    motor1(constrain(map(abs(Wrap((bearingPID - initial_deg), -180, 179)), 25, 0, 10, 15), 10, 25), 40);


    if (line == 'R' && pixy.ccc.numBlocks == 0) {
      initial_deg = initial_deg + 90;
      line_offset = -10;
      line = 'W';
      line_rem = 'R';
      servo_deg = 55;
      // Servo1(45);
      Serial.println("REDD");
    } else if (line == 'B' && pixy.ccc.numBlocks == 0) {
      initial_deg = initial_deg - 90;
      line_offset = 10;
      line = 'W';
      line_rem = 'B';
      servo_deg = 215;
    }


    // Servo2(Wrap((Wrap(bearingPID - initial_deg, -180, 179) * mapf(abs(Wrap(bearingPID - initial_deg + offset_deg * constrain(mapf(USread, 20, 40, 0, 1), 0, 1), -180, 179)), 0, 90, 0.3, 1.4) - line_offset * constrain(mapf(USread, 20, 65, -1, 1), -1, 0.2) * mapf(abs(Wrap(bearingPID - initial_deg, -180, 179)), 0, 90, 0.8, 0.5)) * -1 * mapf(abs(Currentspeed), 10, 30, 1, 0.3) + offset_deg * constrain(mapf(USread, 20, 40, 0, 1), 0, 1), -180, 179)  + 135);

    Servo2(Wrap(Wrap((bearingPID - initial_deg), -180, 179) * mapf(abs(Wrap((bearingPID - initial_deg), -180, 179)), 0, 45, 0.5, 1) * -1 + offset_deg * constrain(mapf(USread, 25, 40, 0, 1), 0, 1) * 0.75 - line_offset * constrain(mapf(USread, 25, 40, 0, 1), -5, 0.2), -180, 179));

    // Serial.println(constrain(mapf(USread, 25, 40, 0, 1), -5, 0.2));

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
  // RGBUpdate(true);

  rainbow(10);
}



void Blocks(float input, long Blocktimer) {
  if (millis() - pixytimer > Blocktimer) {
    offset_deg = constrain(offset_deg, -65, 65);
    offset_deg = (input - offset_deg) * 0.15 + offset_deg;
    pixytimer = millis();
  }
}

void Servo1(int theta) {
  theta = constrain(theta, 45, 225) + map(theta, 0, 360, -10, 20);  // Limit Servo degree
  theta = int(map(theta, 0, 270, 0, 180));                          // Map degree to correct the position
  myservo1.write(theta);
}

void Servo2(int theta) {
  theta = constrain(theta + 135, 90, 180);  // Limit servo degree
  theta = int(map(theta, 0, 270, 0, 180));  // Map degree to correct the position
  myservo2.write(theta);
}

void UltraSonicUpdate() {

  USread = map(analogRead(29), 0, 1023, 0, 500);
  // Serial.println(USread);
}

float PID1(float input, float kp, float ki, float kd) {
  if (millis() - PIDtimer1 > 15) {
    err1 = input * kp + integral1 * ki + (input - last_err1) * kd;
    integral1 = integral1 + err1;
    last_err1 = input;
    PIDtimer1 = millis();
  }
  return err1;
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
  if (millis() - PIDtimer > 15) {
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

  if (v.c < 1500 && (millis() - RGBtimer) > 1500 && line == 'W' && Line_read) {
    if (red > blue && (line_rem == 'W' || line_rem == 'R')) {
      // Serial.println("Red: ");
      MeanRGB = (MeanRGB + 1);
    }
    if (red <= blue && (line_rem == 'W' || line_rem == 'B')) {
      // Serial.println("Blue: ");
      MeanRGB = (MeanRGB - 1);

      //      while (true);
    }


  } else if (MeanRGB != 0) {
    if (MeanRGB > 0) {
      Serial.println("RED");

      line = 'R';


    } else {
      Serial.println("BLUE");
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