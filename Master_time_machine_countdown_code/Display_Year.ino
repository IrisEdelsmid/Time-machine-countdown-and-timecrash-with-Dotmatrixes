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
