#include "LedDisplay.h"
// #include "LedControl.h"

//
//int homeYear = 2018;
//int currentYear = 0000;
//extern byte NUMBER[] [8];

/*
  LC1
  pin 12 is connected to the DataIn
  pin 11 is connected to the CLK
  pin 10 is connected to LOAD

  LC2
  pin 9 is connected to the DataIn
  pin 8 is connected to the CLK
  pin 7 is connected to LOAD
*/
//#define homeButtonPin 2
//#define startButtonPin 3
//#define fohnPin 13
//
byte totalScreens = 8;
LedDisplay lc1 = LedDisplay(12, 11, 10, totalScreens);
//LedControl lc1 = LedControl(12, 11, 10, totalScreens);
//LedDisplay lc2 = LedDisplay(9, 8, 7, totalScreens);


void setup() {
  delay(100);
  Serial.begin(9600);

  for (int i = 0; i < totalScreens; i++) {
    lc1.shutdown(i, false);
    lc1.setIntensity(i, 8);      /* Set the brightness to a medium values */
    lc1.clearDisplay(i);         /* and clear the display */
  }
}


void loop() {
  if (Serial.available()) {
    String binnen = Serial.readStringUntil('\n');
    long number = binnen.toInt();
    lc1.year = number;
    Serial.println(lc1.year);
    lc1.displayYear();
  }
}

