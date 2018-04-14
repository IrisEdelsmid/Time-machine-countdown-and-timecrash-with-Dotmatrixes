#include "LedControl.h"

#define homeYear 2018
int currentYear = 0000;
extern byte NUMBER[] [8];

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
#define homeButtonPin 2

byte totalScreens = 4;
LedControl lc1 = LedControl(12, 11, 10, totalScreens);
LedControl lc2 = LedControl(9, 8, 7, totalScreens);

bool timeTravelling = false;
void setup() {
  pinMode(homeButtonPin, INPUT);
  delay(100);
  Serial.begin(9600);
  /* The MAX72XX is in power-saving mode on startup,
    we have to do a wakeup call */

  for (int i = 0; i < totalScreens; i++) {
    lc1.shutdown(i, false);
    lc1.setIntensity(i, 8);      /* Set the brightness to a medium values */
    lc1.clearDisplay(i);         /* and clear the display */
    lc2.shutdown(i, false);
    lc2.setIntensity(i, 8);      /* Set the brightness to a medium values */
    lc2.clearDisplay(i);         /* and clear the display */
  }
  startHomeYear();
  displayYear(0000);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (timeTravelling == false)
  {
    if (Serial.available() > 0) {
      String incomming = Serial.readStringUntil('\n'); // (use of string here is just for debugging)
      int currentYear = incomming.toInt();
      Serial.println(currentYear);
      displayYear(currentYear);
    }
    touchsensorReader();
  }
  else
  {
    
  }
  }
}
