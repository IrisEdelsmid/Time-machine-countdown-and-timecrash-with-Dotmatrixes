void displayYear(int jaar) {
  for (int i = 0; i < totalScreens; i++) {
    lc1.clearDisplay(i);
  }
  int y1 = jaar % 10;
  int y2 = (jaar / 10) % 10;
  int y3 = (jaar / 100) % 10;
  int y4 = (jaar / 1000) % 10;

  for (int i = 0; i < 8; i ++) {
    lc1.setRow(3, i, NUMBER [y1] [i]);
    lc1.setRow(2, i, NUMBER [y2] [i]);
    lc1.setRow(1, i, NUMBER [y3] [i]);
    lc1.setRow(0, i, NUMBER [y4] [i]);
  }
}

void displayHomeYear() {
  for (int i = 0; i < totalScreens; i++) {
    lc2.clearDisplay(i);
  }
  int y1 = homeYear % 10;
  int y2 = (homeYear/ 10) % 10;
  int y3 = (homeYear / 100) % 10;
  int y4 = (homeYear / 1000) % 10;

  for (int i = 0; i < 8; i ++) {
    lc2.setRow(3, i, NUMBER [y1] [i]);
    lc2.setRow(2, i, NUMBER [y2] [i]);
    lc2.setRow(1, i, NUMBER [y3] [i]);
    lc2.setRow(0, i, NUMBER [y4] [i]);
  }
}

void startHomeYear(){
    for (int i = 0; i < 8; i ++) {
    lc2.setRow(3, i, NUMBER [0] [i]);
    lc2.setRow(2, i, NUMBER [0] [i]);
    lc2.setRow(1, i, NUMBER [0] [i]);
    lc2.setRow(0, i, NUMBER [0] [i]);
  }
}

