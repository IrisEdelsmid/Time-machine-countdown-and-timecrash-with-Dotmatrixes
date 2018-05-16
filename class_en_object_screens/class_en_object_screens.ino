#include "LedDisplay.h"
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {2, 3, 4, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 7, 8, 9}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

bool timeTravelling;
/*
  Current
  current.LedDisplay
  pin A0 is connected to the DataIn
  pin A1 is connected to the CLK
  pin A2 is connected to LOAD

  Destination
  destination.LedDisplay
  pin A3 is connected to the DataIn
  pin A4 is connected to the CLK
  pin A5 is connected to LOAD
*/
// byte totalScreens = 8;
LedDisplay current = LedDisplay(A0, A1, A2, 8);
LedDisplay destination = LedDisplay(A3, A4, A5, 8);


void setup() {
  delay(100);
  Serial.begin(9600);

  current.setupDisplay(8);  // setup the display with intensity 0 to 16
  delay(100);
  destination.setupDisplay(8);  // setup the display with intensity 0 to 16
  delay(100);
  // typeCurrentYear();
}


void loop() {
  // fillAll();
  //  delay(2000);
  // halloKinders();
  //current.setString("tttttttt");
  // destination.setString("ttttttta");
  checkInput();
}

void checkInput() {
  char customKey = keypad.getKey();
  if (customKey == 'A') {
    typeCurrentYear();
  }
  else if (customKey == 'B') {
    typeDestinationYear();
  }
  else if (customKey == 'D') {
    halloKinders();
  }
}

void fillAll() {
  for (int i = 0; i < 8; i++) {
    current.fillDisplay(i);
    destination.fillDisplay(i);
    delay(100);
  }
}
void halloKinders() {
  current.setString("hallo?");
  delay(2000);
  destination.setString("hallo??");
  delay(4000);
  current.setString("is daar");
  destination.setString("iemand?");
  delay(4000);
  current.setString("ik zie");
  destination.setString("jullie!!");
  delay(5000);
  current.setString(" hallo");
  destination.setString(" welpen");
  delay(4000);
  current.setString("ik ben");
  destination.setString("  ");
  delay(1000);
  destination.setString("janus!");
  delay(5000);
  // current.setString("en ik");
  destination.setString("de baas!");
  delay(5000);
  current.setString("van tijd");
  destination.setString(" ");
  delay(1000);
  destination.setString("altijd!");
  delay(4000);
  current.setString("pak me");
  destination.setString("dan");
  delay(3000);
  current.setString("als je");
  destination.setString("kan");
  delay(3000);
  fillAll();
}

