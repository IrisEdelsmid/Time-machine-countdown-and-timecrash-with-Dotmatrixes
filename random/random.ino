#include "LedControl.h"
byte aantal = 8;
LedControl lc = LedControl(12, 11, 10, aantal);
unsigned long delaytime = random (0, 100);

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

void loop() {
  // put your main code here, to run repeatedly:
int  l =  random(0, 8);
int  c = random (0, 8);
int  r = random (0, 8);
 lc.setLed(l, r, c, true);
delay (delaytime);
}
