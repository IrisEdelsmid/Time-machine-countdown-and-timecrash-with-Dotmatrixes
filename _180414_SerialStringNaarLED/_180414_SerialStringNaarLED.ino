#include "LedControl.h"
extern byte NUMBER[] [8];

byte aantal = 4;
LedControl lc = LedControl(12, 11, 10, aantal);

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
    lc.setIntensity(i, 5);

    /* and clear the display */
    lc.clearDisplay(i);
  }
}


void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    String incomming = Serial.readStringUntil('\n');
    int newYear = incomming.toInt();
    Serial.println(newYear);
    displayYear(newYear);
  }
}

void displayYear(int jaar) {
  for (int i = 0; i < aantal; i++) {
    lc.clearDisplay(i);
  }
  int y1 = jaar % 10;
  int y2 = (jaar / 10) % 10;
  int y3 = (jaar / 100) % 10;
  int y4 = (jaar / 1000) % 10;

  for (int i = 0; i < 8; i ++) {
    lc.setRow(3, i, NUMBER [y1] [i]);
    lc.setRow(2, i, NUMBER [y2] [i]);
    lc.setRow(1, i, NUMBER [y3] [i]);
    lc.setRow(0, i, NUMBER [y4] [i]);
  }
}


