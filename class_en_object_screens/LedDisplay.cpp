/*
      LedDisplay.cpp - A library for controling Leds with a MAX7219/MAX7221
      Copyright (c) 2007 Eberhard Fahle

      Permission is hereby granted, free of charge, to any person
      obtaining a copy of this software and associated documentation
      files (the "Software"), to deal in the Software without
      restriction, including without limitation the rights to use,
      copy, modify, merge, publish, distribute, sublicense, and/or sell
      copies of the Software, and to permit persons to whom the
      Software is furnished to do so, subject to the following
      conditions:

      This permission notice shall be included in all copies or
      substantial portions of the Software.

      THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
      EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
      OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
      NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
      HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
      WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
      FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
      OTHER DEALINGS IN THE SOFTWARE.
*/


#include "LedDisplay.h"
//extern int year;
//the opcodes for the MAX7221 and MAX7219
#define OP_NOOP   0
#define OP_DIGIT0 1
#define OP_DIGIT1 2
#define OP_DIGIT2 3
#define OP_DIGIT3 4
#define OP_DIGIT4 5
#define OP_DIGIT5 6
#define OP_DIGIT6 7
#define OP_DIGIT7 8
#define OP_DECODEMODE  9
#define OP_INTENSITY   10
#define OP_SCANLIMIT   11
#define OP_SHUTDOWN    12
#define OP_DISPLAYTEST 15

LedDisplay::LedDisplay(int dataPin, int clkPin, int csPin, int numDevices) {
  SPI_MOSI = dataPin;
  SPI_CLK = clkPin;
  SPI_CS = csPin;
  if (numDevices <= 0 || numDevices > 8 )
    numDevices = 8;
  maxDevices = numDevices;
  pinMode(SPI_MOSI, OUTPUT);
  pinMode(SPI_CLK, OUTPUT);
  pinMode(SPI_CS, OUTPUT);
  digitalWrite(SPI_CS, HIGH);
  SPI_MOSI = dataPin;
  for (int i = 0; i < 64; i++)
    status[i] = 0x00;
  for (int i = 0; i < maxDevices; i++) {
    spiTransfer(i, OP_DISPLAYTEST, 0);
    //scanlimit is set to max on startup
    setScanLimit(i, 7);
    //decode is done in source
    spiTransfer(i, OP_DECODEMODE, 0);
    clearDisplay(i);
    //we go into shutdown-mode on startup
    shutdown(i, true);
  }
}

int LedDisplay::getDeviceCount() {
  return maxDevices;
}

void LedDisplay::shutdown(int addr, bool b) {
  if (addr < 0 || addr >= maxDevices)
    return;
  if (b)
    spiTransfer(addr, OP_SHUTDOWN, 0);
  else
    spiTransfer(addr, OP_SHUTDOWN, 1);
}

void LedDisplay::setScanLimit(int addr, int limit) {
  if (addr < 0 || addr >= maxDevices)
    return;
  if (limit >= 0 || limit < 8)
    spiTransfer(addr, OP_SCANLIMIT, limit);
}

void LedDisplay::setIntensity(int addr, int intensity) {
  if (addr < 0 || addr >= maxDevices)
    return;
  if (intensity >= 0 || intensity < 16)
    spiTransfer(addr, OP_INTENSITY, intensity);

}

void LedDisplay::clearDisplay(int addr) {
  int offset;

  if (addr < 0 || addr >= maxDevices)
    return;
  offset = addr * 8;
  for (int i = 0; i < 8; i++) {
    status[offset + i] = 0;
    spiTransfer(addr, i + 1, status[offset + i]);
  }
}

void LedDisplay::setLed(int addr, int row, int column, boolean state) {
  int offset;
  byte val = 0x00;

  if (addr < 0 || addr >= maxDevices)
    return;
  if (row < 0 || row > 7 || column < 0 || column > 7)
    return;
  offset = addr * 8;
  val = B10000000 >> column;
  if (state)
    status[offset + row] = status[offset + row] | val;
  else {
    val = ~val;
    status[offset + row] = status[offset + row] & val;
  }
  spiTransfer(addr, row + 1, status[offset + row]);
}

void LedDisplay::setRow(int addr, int row, byte value) {
  int offset;
  if (addr < 0 || addr >= maxDevices)
    return;
  if (row < 0 || row > 7)
    return;
  offset = addr * 8;
  status[offset + row] = value;
  spiTransfer(addr, row + 1, status[offset + row]);
}

void LedDisplay::setColumn(int addr, int col, byte value) {
  byte val;

  if (addr < 0 || addr >= maxDevices)
    return;
  if (col < 0 || col > 7)
    return;
  for (int row = 0; row < 8; row++) {
    //     val = value >> (7 - row);   //original
    val = value >> (row);         // mirrored
    val = val & 0x01;
    setLed(addr, row, col, val);
  }
}

void LedDisplay::setDigit(byte screen, byte digit) {
  for (byte i = 0; i < 8; i ++) {
    setRow(screen, i, numberTable [digit] [i]);
  }
}

// note. iest raars.
// digits maakt gebruik van setRow(). dat komt omdat ik handmatig alle cijfers een kwartslag heb gedraaid
// ik had daar geen zin in bij de letters. dus die maken gebruik van setColumn(),
// in setColumn() heb ik iets aangepast waardoor alles in spiegelbeeld is, waardoor de letters normaal op het scherm komen.

void LedDisplay::setChar(byte screen, char value) {
  if (value == ' ' || value < 97) {
    clearDisplay(screen);
  }
  else {
    unsigned int digit = value - 97;
    for (byte i = 0; i < 8; i ++) {
      setColumn(screen, i, charTable [digit] [i]);
    }
  }
}

void LedDisplay::setString(String message) {
  int L = message.length();
  if (L >= maxDevices)(L = maxDevices);   // the message can not be longer than the number of LED modules

  // clear all LED modules befor printing new content
  for (int i = 0; i <=  maxDevices ; i++) (clearDisplay(i));

  // Print one charecter at the time.
  for (byte i = 0; i < L ; i ++) {
    char C = message.charAt(i);
    setChar(i, C);
  }
}



void LedDisplay::displayYear() {
    // clear all LED modules befor printing new content
  for (int i = 0; i <=  maxDevices ; i++) (clearDisplay(i));
  
  long inpunt = year;
  int valLength;    // find the number of digits
  int y [8];
  for (int i = 0; i < 8 ; i++) {
    if (abs(inpunt) >= pow(10, i))(valLength = i + 1);
  }

  for (int j = 0; j < 8 ; j++) {
    long t = (abs(inpunt) / pow(10, j));
    y[j] = t % 10;
  }

  if (inpunt < 0) {
    y[valLength] = 10;
    valLength ++;
  }

  for (int i = valLength - 1 , j = 0 ; i >= 0 && j < valLength ; i -- , j++) {
    setDigit(j, y[i]);
  }
}


void LedDisplay::spiTransfer(int addr, volatile byte opcode, volatile byte data) {
  //Create an array with the data to shift out
  int offset = addr * 2;
  int maxbytes = maxDevices * 2;

  for (int i = 0; i < maxbytes; i++)
    spidata[i] = (byte)0;
  //put our device data into the array
  spidata[offset + 1] = opcode;
  spidata[offset] = data;
  //enable the line
  digitalWrite(SPI_CS, LOW);
  //Now shift out the data
  for (int i = maxbytes; i > 0; i--)
    shiftOut(SPI_MOSI, SPI_CLK, MSBFIRST, spidata[i - 1]);
  //latch the data onto the display
  digitalWrite(SPI_CS, HIGH);
}


