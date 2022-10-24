/*-//-//-//-//-//-//-//-//-//- INFOMATION -//-//-//-//-//-//-//-//-//-*/

/* Perfected Line Detection Program
  by Thailand Team <https://ybrobot.club/>

  Being able to differentiate Red and Blue lines in about 100 microseconds after detecting a line.
  Recorded 0% fail rate
*/



/*-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-*/

#include <Wire.h>
#include "Adafruit_TCS34725.h"

/* Example code for the Adafruit TCS34725 breakout library */

/* Connect SCL to analog 5
  Connect SDA to analog 4
  Connect VDD to 3.3V DC
  Connect GROUND to common ground */

/* Initialise with default values (int time = 2.4ms, gain = 1x) */
// Adafruit_TCS34725 tcs = Adafruit_TCS34725();

/* Initialise with specific int time and gain values */
Adafruit_TCS34725 tcs = Adafruit_TCS34725();

void setup(void) {
  Serial.begin(9600);

  if (tcs.begin()) {
    Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1);
  }

  // Now we're ready to get readings!
}
int i = 0;
float MeanRGB;
void loop(void) {
  uint16_t r, g, b, c, colorTemp, lux;

  tcs.getRawData(&r, &g, &b, &c);
  float red = map(r, 0, 18, 0, 100);
  float green = map(g, 0, 22, 0, 100);
  float blue = map(b, 0, 25, 0, 100);

  if (c < 45) {
    if (red > blue) {
      MeanRGB = (MeanRGB + 1) / 2;
    }
    else {

      MeanRGB = (MeanRGB-1) / 2;

      //      while (true);
    }
//    Serial.print("R: "); Serial.print(r); Serial.print(" ");
//    Serial.print("G: "); Serial.print(g); Serial.print(" ");
//    Serial.print("B: "); Serial.print(b); Serial.print(" ");
//    Serial.print("C: "); Serial.print(c); Serial.print(" ");
//    Serial.println(" ");
  }
  else if (MeanRGB != 0){
    if (MeanRGB > 0) {
      Serial.println("RED");
      
    }
    else {
      Serial.println("BLUE");
    }
    Serial.println(MeanRGB);
    MeanRGB = 0;
  }


}
