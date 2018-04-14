void error() {
  bool breakdouwn = false;
  for (int i = 0; i < totalScreens; i++) {
    lc1.clearDisplay(i);         /* and clear the display */
    lc2.clearDisplay(i);         /* and clear the display */
  }
  breakdouwn = true;
  int l, c, r;
  while (breakdouwn == true) {
    l =  random(0, 8);
    c = random (0, 8);
    r = random (0, 8);
    lc1.setLed(l, r, c, true);
    lc2.setLed(l, r, c, true);
    l =  random(0, 8);
    c = random (0, 8);
    r = random (0, 8);
    lc1.setLed(l, r, c, false);
    lc2.setLed(l, r, c, false);
    delay (100);
  }
}
