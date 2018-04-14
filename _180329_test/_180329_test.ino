//We always have to include the library
#include "LedControl.h"
//include this file so we can write down a byte in binary encoding
//#include <binary.h>

/*
  Now we need a LedControl to work with.
  pin 12 is connected to the DataIn
  pin 11 is connected to the CLK
  pin 10 is connected to LOAD
  We have only a single MAX72XX.
*/
byte aantal = 1;
LedControl lc = LedControl(12, 11, 10, aantal);

/* we always wait a bit between updates of the display */
unsigned long delaytime = 100;

void setup() {
  delay(100);
  Serial.begin(9600);
  /*
    The MAX72XX is in power-saving mode on startup,
    we have to do a wakeup call
  */
  for (int i = 0; i < aantal; i++) {
    lc.shutdown(i, false);

    /* Set the brightness to a medium values */
    lc.setIntensity(i, 2);

    /* and clear the display */
    lc.clearDisplay(i);
  }
}

byte NUMBER [][8] = {
  {
    B00010000,
    B00110000,
    B00010000,
    B00010000,
    B00010000,
    B00010000,
    B00010000,
    B00111000
  }, {
    B00111000,
    B01000100,
    B00000100,
    B00000100,
    B00001000,
    B00010000,
    B00100000,
    B01111100
  }, {
    B00111000,
    B01000100,
    B00000100,
    B00011000,
    B00000100,
    B00000100,
    B01000100,
    B00111000
  }, {
    B00000100,
    B00001100,
    B00010100,
    B00100100,
    B01000100,
    B01111100,
    B00000100,
    B00000100
  }, {
    B01111100,
    B01000000,
    B01000000,
    B01111000,
    B00000100,
    B00000100,
    B01000100,
    B00111000
  }, {
    B00111000,
    B01000100,
    B01000000,
    B01111000,
    B01000100,
    B01000100,
    B01000100,
    B00111000
  }, {
    B01111100,
    B00000100,
    B00000100,
    B00001000,
    B00010000,
    B00100000,
    B00100000,
    B00100000
  }, {
    B00111000,
    B01000100,
    B01000100,
    B00111000,
    B01000100,
    B01000100,
    B01000100,
    B00111000
  }, {
    B00111000,
    B01000100,
    B01000100,
    B01000100,
    B00111100,
    B00000100,
    B01000100,
    B00111000
  }, {
    B00111000,
    B01000100,
    B01000100,
    B01000100,
    B01000100,
    B01000100,
    B01000100,
    B00111000
  }
};
int c = 0;

void loop() {

  for (int j = 0; j < 10; j ++) {
    //  long j = random(10);
    for (int i = 0; i < 8; i ++) {
      for (int c = 0; c < aantal; c++) {
        lc.setRow(c, i, NUMBER [j] [i]);
      }
    }
    delay(2000);
    for ( int i = 0; i < aantal; i ++) {
      lc.clearDisplay(i);
    }
  }
  // lc.setColumn(0,0,B10101010);
  // delay(2000);
}
