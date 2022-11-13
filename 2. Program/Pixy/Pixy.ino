//
// begin license header
//
// This file is part of Pixy CMUcam5 or "Pixy" for short
//
// All Pixy source code is provided under the terms of the
// GNU General Public License v2 (http://www.gnu.org/licenses/gpl-2.0.html).
// Those wishing to use Pixy source code, software and/or
// technologies under different licensing terms should contact us at
// cmucam@cs.cmu.edu. Such licensing terms are available for
// all portions of the Pixy codebase presented here.
//
// end license header
//
// This sketch is a good place to start if you're just getting started with
// Pixy and Arduino.  This program simply prints the detected object blocks
// (including color codes) through the serial console.  It uses the Arduino's
// ICSP SPI port.  For more information go here:
//
// https://docs.pixycam.com/wiki/doku.php?id=wiki:v2:hooking_up_pixy_to_a_microcontroller_-28like_an_arduino-29
//

// Uncomment one of these to enable another type of serial interface
//#define I2C
#define UART
// #define SPI_SS

#ifdef I2C

#include <Pixy2I2C.h>
Pixy2I2C pixy;

#else
#ifdef UART

#include <Pixy2UART.h>
Pixy2UART pixy;

#else
#ifdef SPI_SS

#include <Pixy2SPI_SS.h>
Pixy2SPI_SS pixy;

#else

#include <Pixy2.h>
Pixy2 pixy;

#endif
#endif
#endif

float timer1;
int loops = 0;

void setup() {
  // bool setRX(12);
  // bool setCS(13);
  // bool setSCK(14);
  // bool setTX(15);
  Serial1.setRX(17);
  Serial1.setTX(16);
  Serial.begin(57600);
  delay(5000);
  Serial.print("Starting...\n");
  // Serail1
  pixy.init();
  timer1 = millis();
}

void loop() {

  // int i;
  // grab blocks!
  pixy.ccc.getBlocks();

  // If there are detect blocks, print them !
  // if (pixy.ccc.numBlocks) {

  // Serial.println(pixy.ccc.numBlocks);
  for (int i = 0; i < pixy.ccc.numBlocks; i++) {
    // loops = loops + 1;
    Serial.print("  block ");
    Serial.print(i);
    Serial.print(": ");
    pixy.ccc.blocks[i].print();
    Serial.print("[ ");
    Serial.print(1000 / (millis() - timer1));
    Serial.print(" fps ]");
    Serial.println("Detected ");
    timer1 = millis();
  }
  // Serial.print(1000/(millis() - timer1));
  // }
  // else {
  //   Serial.println("No block detected!");
  // }
  // if (millis() - timer1 >= 10000) {
  //   Serial.println("Finished");
  //   Serial.println(loops);
  //   Serial.println("10 seconds");
  //   // Serial.println(loops / 10);
  //   // Serial.print(" loops per seconds");
  //   while (true)
  //     ;
  // }
}