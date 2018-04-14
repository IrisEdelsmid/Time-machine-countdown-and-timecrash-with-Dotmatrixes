#include "LedControl.h"

#define homeYear 2018  
extern byte NUMBER[] [8];

byte totalScreens = 4;
LedControl lc = LedControl(12, 11, 10, totalScreens);

void setup() {
  delay(100);
  Serial.begin(9600);
  /* The MAX72XX is in power-saving mode on startup,
    we have to do a wakeup call */
  
  for (int i = 0; i < totalScreens; i++) {
    lc.shutdown(i, false);
    lc.setIntensity(i, 5);      /* Set the brightness to a medium values */
    lc.clearDisplay(i);         /* and clear the display */
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    String incomming = Serial.readStringUntil('\n'); // (use of string here is just for debugging)
    int newYear = incomming.toInt();
    Serial.println(newYear);
    displayYear(newYear);
  }
}
