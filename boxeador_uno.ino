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
const int analogInPin3 = A10; // Analog input pin that the potentiometer is attached to
const int analogInPin4 = A11;
const int analogInPin5 = A12;
const int analogInPin6 = A13;
const int analogOutPin = 9; // Analog output pin that the LED is attached to
int a,b,x,y,radius,z=1,c=1,s,t,i;
int datox=0;
int datoy=0;
int datoa=0;
int datob=0;
int datot=0;
int datos=0;
int q,w;

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
  tft.fillScreen(ILI9341_GREEN);
  Serial.println(F("Benchmark                Time (microseconds)"));
  delay(10);
 

  Serial.print(F("Circles (outline)        "));

  
  Serial.print(F("Lines                    "));
 
  

  delay(500);

  Serial.println(F("Done!"));

}
void loop() {
  while(1)
  {radius=20;
  tft.drawLine(29, 19, 29, 310,ILI9341_WHITE);
  tft.drawLine(30, 19, 30, 310,ILI9341_WHITE);
  tft.drawLine(31, 19, 31, 310,ILI9341_WHITE);
  tft.drawLine(32, 19, 32, 310,ILI9341_WHITE);
  tft.drawLine(29, 309, 230, 309,ILI9341_WHITE);
  tft.drawLine(29, 310, 230, 310,ILI9341_WHITE);
  tft.drawLine(29, 311, 230, 311,ILI9341_WHITE);
  tft.drawLine(29, 312, 230, 312,ILI9341_WHITE);
  tft.drawLine(229, 19, 229, 312,ILI9341_WHITE);
  tft.drawLine(230, 19, 230, 312,ILI9341_WHITE);
  tft.drawLine(231, 19, 231, 312,ILI9341_WHITE);
  tft.drawLine(232, 19, 232, 312,ILI9341_WHITE);
  tft.drawLine(29, 19, 230, 19,ILI9341_WHITE);
  tft.drawLine(29, 20, 230, 20,ILI9341_WHITE);
  tft.drawLine(29, 21, 230, 21,ILI9341_WHITE);
  tft.drawLine(29, 22, 230, 22,ILI9341_WHITE); 
  datot=analogRead(A12);
  t=map(datot,0,1023,0,225);
  datos=analogRead(A13);
  s=map(datos,0,1023,0,225);
  datox= analogRead(A8);
  x = map(datox, 0, 1023, 29, 250);
  datoa= analogRead(A10);
  a = map(datoa, 0, 1023, 29, 250);
  datoy= analogRead(A9);
  y = map(datoy, 0, 1023, 0, 160);
  datob= analogRead(A11);
  b = map(datob, 0, 1023, 160, 320);
  q=y;w=b;
  tft.fillCircle(x, y, radius,ILI9341_WHITE);
  tft.fillCircle(x, y+20, 5,ILI9341_WHITE);
  tft.fillCircle(x+56.5, y+25, 15,ILI9341_WHITE);
  tft.fillCircle(x-56.5, y+25, 15,ILI9341_WHITE);
  
  tft.fillCircle(a, b, radius,ILI9341_BLACK);
  tft.fillCircle(a, b-20, 5,ILI9341_BLACK);
  tft.fillCircle(a-56.5, b-25, 15,ILI9341_BLACK);
  tft.fillCircle(a+56.5, b-25, 15,ILI9341_BLACK);
  if(t==0)
 {if(z%2==0)
  { tft.fillCircle(x-56.5, q+25, 15,ILI9341_GREEN);
    q=y+30;
    //BRAZO DER SUP
  for(i=18;i<=25;i++)
  {tft.drawLine(x-i, y, x-35-i, q-30,ILI9341_WHITE);
  }
  for(i=53;i<=60;i++)
  {tft.drawLine(x-i, q-30, x-i, q+25,ILI9341_WHITE);
  }
  tft.fillCircle(x-56.5, q+25, 15,ILI9341_WHITE);
  delay(100);
  //BRAZO DER SUP
  for(i=18;i<=25;i++)
  {tft.drawLine(x-i, y, x-35-i, q-30,ILI9341_GREEN);
  }
  for(i=53;i<=60;i++)
  {tft.drawLine(x-i, q-30, x-i, q+25,ILI9341_GREEN);
  }
  tft.fillCircle(x-56.5, q+25, 15,ILI9341_GREEN);
  q=y-30;
  z=1;
    }
  else{tft.fillCircle(x+56.5, q+25, 15,ILI9341_GREEN);
  q=y+30;
   //BRAZO IZQ SUP
  for(i=18;i<=25;i++)
  {tft.drawLine(x+i, y, x+i+35, q-30,ILI9341_WHITE);
  }
  for(i=53;i<=60;i++)
  {tft.drawLine(x+i, q-30, x+i, q+25,ILI9341_WHITE);
  }  
  tft.fillCircle(x+56.5, q+25, 15,ILI9341_WHITE);
  delay(100);
  
  //BRAZO IZQ SUP
  for(i=18;i<=25;i++)
  {tft.drawLine(x+i, y, x+i+35, q-30,ILI9341_GREEN);
  }
  for(i=53;i<=60;i++)
  {tft.drawLine(x+i, q-30, x+i, q+25,ILI9341_GREEN);
  }  
  tft.fillCircle(x+56.5, q+25, 15,ILI9341_GREEN);
  q=y-30;
    z=2;
    } 
   }

if(s==0)
 {if(c%2==0)
  {tft.fillCircle(a-56.5, w-25, 15,ILI9341_GREEN);
    w=b-30;
  
    //BRAZO IZQ INF 
   for(i=18;i<=25;i++)
    {tft.drawLine(a-i, b, a-i-35, w+30,ILI9341_BLACK);
    }
   for(i=53;i<=60;i++)
    {tft.drawLine(a-i, w+30, a-i, w-25,ILI9341_BLACK);
    }
    tft.fillCircle(a-56.5, w-25, 15,ILI9341_BLACK);
    delay(100);
    //BRAZO IZQ INF 
    for(i=18;i<=25;i++)
    {tft.drawLine(a-i, b, a-i-35, w+30,ILI9341_GREEN);
    }
   for(i=53;i<=60;i++)
    {tft.drawLine(a-i, w+30, a-i, w-25,ILI9341_GREEN);
    }
    tft.fillCircle(a-56.5, w-25, 15,ILI9341_GREEN);
    w=b+30;
    c=1;}
 else{tft.fillCircle(a+56.5, w-25, 15,ILI9341_GREEN);
    w=b-30;
  //BRAZO DER INF
   for(i=18;i<=25;i++)
   {tft.drawLine(a+i, b, a+i+35, w+30,ILI9341_BLACK);
   }
   for(i=53;i<=60;i++)
   {tft.drawLine(a+i, w+30, a+i, w-25,ILI9341_BLACK);
   }
   tft.fillCircle(a+56.5, w-25, 15,ILI9341_BLACK);
  delay(100);
  //BRAZO DER INF
   for(i=18;i<=25;i++)
   {tft.drawLine(a+i, b, a+i+35, w+30,ILI9341_GREEN);
   }
   for(i=53;i<=60;i++)
   {tft.drawLine(a+i, w+30, a+i, w-25,ILI9341_GREEN);
   }
   tft.fillCircle(a+56.5, w-25, 15,ILI9341_GREEN);
    w=b+30;
    c=2;} 
   }
  //BRAZO DER SUP
  for(i=18;i<=25;i++)
  {tft.drawLine(x-i, y, x-35-i, y-30,ILI9341_WHITE);
  }
  for(i=53;i<=60;i++)
  {tft.drawLine(x-i, y-30, x-i, y+25,ILI9341_WHITE);
  }
  //BRAZO IZQ SUP
  for(i=18;i<=25;i++)
  {tft.drawLine(x+i, y, x+i+35, y-30,ILI9341_WHITE);
  }
  for(i=53;i<=60;i++)
  {tft.drawLine(x+i, y-30, x+i, y+25,ILI9341_WHITE);
  }
//BRAZO IZQ INF 
for(i=18;i<=25;i++)
  {tft.drawLine(a-i, b, a-i-35, b+30,ILI9341_BLACK);
  }
for(i=53;i<=60;i++)
  {tft.drawLine(a-i, b+30, a-i, b-25,ILI9341_BLACK);
  }
  //BRAZO DER INF
  for(i=18;i<=25;i++)
  {tft.drawLine(a+i, b, a+i+35, b+30,ILI9341_BLACK);
  }
  for(i=53;i<=60;i++)
  {tft.drawLine(a+i, b+30, a+i, b-25,ILI9341_BLACK);
  }
  
  tft.fillCircle(x, y, radius,ILI9341_GREEN);
  tft.fillCircle(x, y+25, 15,ILI9341_GREEN);
  tft.fillCircle(x+56.5, y+25, 15,ILI9341_GREEN);
  tft.fillCircle(x-56.5, y+25, 15,ILI9341_GREEN);
    
  tft.fillCircle(a, b, radius,ILI9341_GREEN);
  tft.fillCircle(a, b-25, 15,ILI9341_GREEN);
  tft.fillCircle(a-56.5, b-25, 15,ILI9341_GREEN);
  tft.fillCircle(a+56.5, b-25, 15,ILI9341_GREEN);
  //BRAZO DER SUP
  for(i=18;i<=25;i++)
  {tft.drawLine(x-i, y, x-35-i, y-30,ILI9341_GREEN);
  }
  for(i=53;i<=60;i++)
  {tft.drawLine(x-i, y-30, x-i, y+25,ILI9341_GREEN);
  }
  //BRAZO IZQ SUP
  for(i=18;i<=25;i++)
  {tft.drawLine(x+i, y, x+i+35, y-30,ILI9341_GREEN);
  }
  for(i=53;i<=60;i++)
  {tft.drawLine(x+i, y-30, x+i, y+25,ILI9341_GREEN);
  }
//BRAZO IZQ INF 
for(i=18;i<=25;i++)
  {tft.drawLine(a-i, b, a-i-35, b+30,ILI9341_GREEN);
  }
for(i=53;i<=60;i++)
  {tft.drawLine(a-i, b+30, a-i, b-25,ILI9341_GREEN);
  }
  //BRAZO DER INF
  for(i=18;i<=25;i++)
  {tft.drawLine(a+i, b, a+i+35, b+30,ILI9341_GREEN);
  }
  for(i=53;i<=60;i++)
  {tft.drawLine(a+i, b+30, a+i, b-25,ILI9341_GREEN);
  }
  



   
}

  
}



