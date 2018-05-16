void typeCurrentYear() {
  for (int i = 0; i < 8; i ++) {
    current.clearDisplay(i);
  }
  String newDate;
  int screen = 0;
  bool typing = true;
  current.fillDisplay(screen);
  while (typing) {
    char customKey = keypad.getKey();
    if (customKey) {
      int input = customKey - 48;
      Serial.println(customKey);
      Serial.println(input);
      if (customKey == '#') {
        current.year = newDate.toInt();
        current.displayYear();
        typing = false;
      }
      else if (customKey == 'C') {
        Serial.println("-----------------");
        current.setDigit(screen, 10);
        current.fillDisplay(screen + 1);
        newDate += '-';
        screen ++;
      }
      else if (input >= 0 || input < 10) {
        current.setDigit(screen, input);
        current.fillDisplay(screen + 1);
        newDate += customKey;
        screen ++;
      }
    }
  }
}

void typeDestinationYear() {
  for (int i = 0; i < 8; i ++) {
    destination.clearDisplay(i);
  }
  String newDate;
  int screen = 0;
  bool typing = true;
  destination.fillDisplay(screen);
  while (typing) {
    char customKey = keypad.getKey();
    if (customKey) {
      int input = customKey - 48;
      Serial.println(customKey);
      Serial.println(input);
      if (customKey == '#') {
        destination.year = newDate.toInt();
        destination.displayYear();
        typing = false;
      }
      else if (customKey == 'C') {
        Serial.println("-----------------");
        destination.setDigit(screen, 10);
        destination.fillDisplay(screen + 1);
        newDate += '-';
        screen ++;
      }
      else if (input >= 0 || input < 10) {
        destination.setDigit(screen, input);
        destination.fillDisplay(screen + 1);
        newDate += customKey;
        screen ++;
      }
    }
  }
}
