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
int x,y;

       // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)


void setup() {
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
  
  Serial.println(F("Benchmark                Time (microseconds)"));
  delay(10);
  Serial.print(F("Screen fill              "));
  


  Serial.print(F("Rectangles (filled)      "));
  Serial.println(testFilledRects(ILI9341_YELLOW, ILI9341_MAGENTA));
  delay(500);

  

}

void loop() {
}

unsigned long testFilledRects(uint16_t color1, uint16_t color2) {
  unsigned long start, t = 0;
  int           n, i, i2,
                cx = tft.width()  / 2 - 1,
                cy = tft.height() / 2 - 1;

  tft.fillScreen(ILI9341_BLACK);
                
  start = micros();
  while(1)
  {datox= analogRead(A8);
  x = map(datox, 0, 1023, 0, 230);
  start = micros();
    datox= analogRead(A8);
  x = map(datox, 0, 1023, 0, 230);
  tft.fillRect(x, 30, 30, 10,ILI9341_WHITE);
  delay(50);
  tft.fillRect(x, 30, 30, 10,ILI9341_BLACK);
  datoy= analogRead(A9);
  y = map(datoy, 0, 1023, 0, 230);
  tft.fillRect(y, 260, 30, 10,ILI9341_WHITE);
  delay(50);
  tft.fillRect(y, 260, 30, 10,ILI9341_BLACK);
}
return micros() - start; 
}
