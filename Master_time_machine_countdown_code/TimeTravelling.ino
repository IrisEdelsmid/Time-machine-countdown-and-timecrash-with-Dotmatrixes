void error() {
  digitalWrite(fohnPin, LOW);
  timeTravelling = false;
  bool breakdouwn = false;
  for (int i = 0; i < 8; i++) {
    //   lc1.clearDisplay(i);         /* and clear the display */
    //   lc2.clearDisplay(i);         /* and clear the display */
    lc1.setRow(3, i, B11111111);
    lc2.setRow(1, i, B11101111);
  }
  delay (1000);
  for (int i = 0; i < 7; i++) {
    lc1.setColumn(1, i, B11111011);
    lc2.setRow(2, i, B11111111);
  }
  delay (2000);
  for (int i = 0; i < 8; i++) {
    lc1.setRow(2, i, B11111111);
    lc2.setRow(0, i, B11111111);
  }
  delay (500);
  for (int i = 0; i < 8; i++) {
    lc1.setRow(0, i, B11111111);
    lc2.setRow(3, i, B11101111);
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

void Travel() {
  timeTravelling = true;
 
  digitalWrite(fohnPin, HIGH);
  if (currentYear > homeYear)(aflopen());
  else(oplopen());
}

void aflopen() {
  unsigned long interval = 1000;
    unsigned long next = millis() + interval;
  int count = 0;

  while (timeTravelling == true) {
    if (millis() >= next) {
      currentYear --;
      displayYear(currentYear);
      displayHomeYear();
      interval = interval / 2;
      next = millis() + interval;
      count ++;
      Serial.println(count);
    }

    if (count >= 52) {
      error();
    }
  }
}

void oplopen() {
  unsigned long interval = 2000;
  unsigned long next = millis() + interval;
  int count = 0;

  while (timeTravelling == true) {
    if (millis() >= next) {
      currentYear ++;
      displayYear(currentYear);
      displayHomeYear();
      interval = interval / 2;
      next = millis() + interval;
      count ++;
      // Serial.println(count);
    }
    if (count >= 52) {
      error();
    }
  }
}

