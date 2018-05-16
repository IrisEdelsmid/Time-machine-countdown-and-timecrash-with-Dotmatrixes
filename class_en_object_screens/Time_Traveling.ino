void Travel() {
  timeTravelling = true;

  // digitalWrite(fohnPin, HIGH);
  if (current.year > destination.year)(toPast());
  else(toFuture());
}

void toPast() {
  unsigned long interval = 1000;
  unsigned long next = millis() + interval;
  int count = 0;

  while (timeTravelling == true) {
    if (millis() >= next) {
      current.year --;
      current.displayYear();
      //  destination.displayYear();
      interval = interval / 2;
      next = millis() + interval;
      count ++;
      Serial.println(count);
    }

    if (count >= 52) {
      breakDouwn();
    }
  }
}

void toFuture() {
  unsigned long interval = 2000;
  unsigned long next = millis() + interval;
  int count = 0;

  while (timeTravelling == true) {
    if (millis() >= next) {
      current.year ++;
      current.displayYear();
      //destination.displayYear();
      interval = interval / 2;
      next = millis() + interval;
      count ++;
      // Serial.println(count);
    }
    if (count >= 52) {
      breakDouwn();
    }
  }
}



void breakDouwn() {
  long end = millis() + 1000;
  while (millis() < end) {
    int l =  random(0, 8);
    int c = random (0, 8);
    int d =  random(100, 500);

    current.fillDisplay(l);
    destination.fillDisplay(c);
    delay (d);
  }
  shutDouwn();
}

void shutDown() {
  for (int i = 0; i < 8 ; i++) {
    current.clearDisplay(i);
    destination.clearDisplay(i);
    delay(500);
  }


