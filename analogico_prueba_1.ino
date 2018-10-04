#include "SPI.h"
#include "Adafruit_GFX.h"
#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"

#define TFT_DC 9
#define TFT_CS 10
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

const int analogInPin1 = A8; // Analog input pin that the potentiometer is attached to
const int analogInPin2 = A9;
const int analogOutPin = 9; // Analog output pin that the LED is attached to

int datox=0;
int datoy=0;

       // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)


void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  Serial.println("ILI9341 Test!"); 
 
  tft.begin();

  // read diagnostics (optional but can help debug problems)
  uint8_t x = tft.readcommand8(ILI9341_RDMODE);
  Serial.print("Display Power Mode: 0x"); Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDMADCTL);
  Serial.print("MADCTL Mode: 0x"); Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDPIXFMT);
  Serial.print("Pixel Format: 0x"); Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDIMGFMT);
  Serial.print("Image Format: 0x"); Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDSELFDIAG);
  Serial.print("Self Diagnostic: 0x"); Serial.println(x, HEX); 
  tft.fillScreen(ILI9341_BLACK);
  Serial.println(F("Benchmark                Time (microseconds)"));
  delay(10);
 

  Serial.print(F("Circles (outline)        "));
  Serial.println(testCircles(10, ILI9341_WHITE));
  delay(500);

  delay(500);

  Serial.println(F("Done!"));

}
void loop() {
}
unsigned long testCircles(uint8_t radius, uint16_t color) {
  unsigned long start;
  int           x=115, y=160, r2 = radius * 2,
                w = tft.width()  + radius,
                h = tft.height() + radius;
                
  start = micros();
  while(1)
  {datox= analogRead(A8);
  x = map(datox, 0, 1023, 0, 230);
  tft.drawCircle(x, y, radius, color);
  tft.drawCircle(x, y, radius, ILI9341_BLACK);
  datoy= analogRead(A9);
  y = map(datoy, 0, 1023, 0, 230);
  tft.drawCircle(x, y, radius, color);
  tft.drawCircle(x, y, radius, ILI9341_BLACK);
}
return micros() - start; 
}

