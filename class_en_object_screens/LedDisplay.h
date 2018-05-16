/*
      LedDisplay.h - A library for controling Leds with a MAX7219/MAX7221
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

#ifndef LedDisplay_h
#define LedDisplay_h

#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif


/* bytes numbers 0 to 9 are the corresponding digits.
   byte number 10 is minus '-'
*/
const static byte numberTable [][8] = {
  {B00000000, B01111110, B10000001, B10000001, B10000001, B01111110, B00000000, B00000000},
  {B00000000, B00000000, B00000001, B11111111, B01000001, B00000000, B00000000, B00000000},
  {B00000000, B00000000, B01110001, B10001001, B10000101, B10000011, B01000001, B00000000},
  {B00000000, B00000000, B01101110, B10010001, B10010001, B10000001, B01000010, B00000000},
  {B00000000, B00000000, B11111111, B01000100, B00100100, B00010100, B00001100, B00000000},
  {B00000000, B00000000, B10001110, B10010001, B10010001, B10010001, B11110010, B00000000},
  {B00000000, B00000000, B01001110, B10010001, B10010001, B10010001, B01111110, B00000000},
  {B00000000, B00000000, B11100000, B10010000, B10001000, B10000111, B10000000, B00000000},
  {B00000000, B00000000, B01101110, B10010001, B10010001, B10010001, B01101110, B00000000},
  {B00000000, B00000000, B01111110, B10001001, B10001001, B10001001, B01110010, B00000000},
  {B00000000, B00011000, B00011000, B00011000, B00011000, B00011000, B00011000, B00000000}  // # 10 = '-'
};

/* bytes number 0 to 25 are the letters A to Z.
   byte number 26 is '!'
   byte number 27 is '?'
*/

const static byte charTable[][8] = {
  {B00000000, B00111100, B01100110, B01100110, B01111110, B01100110, B01100110, B01100110},
  {B00000000, B01111100, B01100110, B01100110, B01111100, B01100110, B01100110, B01111100},
  {B00000000, B00111100, B01100110, B01100000, B01100000, B01100000, B01100110, B00111100},
  {B00000000, B01111100, B01100110, B01100110, B01100110, B01100110, B01100110, B01111100},
  {B00000000, B01111110, B01100000, B01100000, B01111100, B01100000, B01100000, B01111110},
  {B00000000, B01111110, B01100000, B01100000, B01111100, B01100000, B01100000, B01100000},
  {B00000000, B00111100, B01100110, B01100000, B01100000, B01101110, B01100110, B00111100},
  {B00000000, B01100110, B01100110, B01100110, B01111110, B01100110, B01100110, B01100110},
  {B00000000, B00111100, B00011000, B00011000, B00011000, B00011000, B00011000, B00111100},
  {B00000000, B00011110, B00001100, B00001100, B00001100, B01101100, B01101100, B00111000},
  {B00000000, B01100110, B01101100, B01111000, B01110000, B01111000, B01101100, B01100110},
  {B00000000, B01100000, B01100000, B01100000, B01100000, B01100000, B01100000, B01111110},
  {B00000000, B01100011, B01110111, B01111111, B01101011, B01100011, B01100011, B01100011},
  {B00000000, B01100011, B01110011, B01111011, B01101111, B01100111, B01100011, B01100011},
  {B00000000, B00111100, B01100110, B01100110, B01100110, B01100110, B01100110, B00111100},
  {B00000000, B01111100, B01100110, B01100110, B01100110, B01111100, B01100000, B01100000},
  {B00000000, B00111100, B01100110, B01100110, B01100110, B01101110, B00111100, B00000110},
  {B00000000, B01111100, B01100110, B01100110, B01111100, B01111000, B01101100, B01100110},
  {B00000000, B00111100, B01100110, B01100000, B00111100, B00000110, B01100110, B00111100},
  {B00000000, B01111110, B01011010, B00011000, B00011000, B00011000, B00011000, B00011000},
  {B00000000, B01100110, B01100110, B01100110, B01100110, B01100110, B01100110, B00111110},
  {B00000000, B01100110, B01100110, B01100110, B01100110, B01100110, B00111100, B00011000},
  {B00000000, B01100011, B01100011, B01100011, B01101011, B01111111, B01110111, B01100011},
  {B00000000, B01100011, B01100011, B00110110, B00011100, B00110110, B01100011, B01100011},
  {B00000000, B01100110, B01100110, B01100110, B00111100, B00011000, B00011000, B00011000},
  {B00000000, B01111110, B00000110, B00001100, B00011000, B00110000, B01100000, B01111110},
  {B00011000, B00111100, B00111100, B00011000, B00011000, B00000000, B00011000, B00011000}, // # 26 = !
  {B01111000, B11001100, B00001100, B00011000, B00110000, B00000000, B00110000, B00110000}  // # 27 = ?
};


class LedDisplay {
  private :
    /* The array for shifting the data to the devices */
    byte spidata[16];
    /* Send out a single command to the device */
    void spiTransfer(int addr, byte opcode, byte data);

    /* We keep track of the led-status for all 8 devices in this array */
    byte status[64];
    /* Data is shifted out of this pin*/
    int SPI_MOSI;
    /* The clock is signaled on this pin */
    int SPI_CLK;
    /* This one is driven LOW for chip selectzion */
    int SPI_CS;
    /* The maximum number of devices we use */
    // int maxDevices;

  public:
    /*
       Create a new controler
       Params :
       dataPin		pin on the Arduino where data gets shifted out
       clockPin		pin for the clock
       csPin		pin for selecting the device
       numDevices	maximum number of devices that can be controled
    */
    LedDisplay(int dataPin, int clkPin, int csPin, int numDevices = 1);

    // custom for time machine:
    long year;
    int maxDevices;

    /*
       Gets the number of devices attached to this LedDisplay.
       Returns :
       int	the number of devices on this LedDisplay
    */
    int getDeviceCount();

    /*
       Set the shutdown (power saving) mode for the device
       Params :
       addr	The address of the display to control
       status	If true the device goes into power-down mode. Set to false
     		for normal operation.
    */
    void shutdown(int addr, bool status);

    /*
       Set the number of digits (or rows) to be displayed.
       See datasheet for sideeffects of the scanlimit on the brightness
       of the display.
       Params :
       addr	address of the display to control
       limit	number of digits to be displayed (1..8)
    */
    void setScanLimit(int addr, int limit);

    /*
       Set the brightness of the display.
       Params:
       addr		the address of the display to control
       intensity	the brightness of the display. (0..15)
    */
    void setIntensity(int addr, int intensity);

    /*
       Switch all Leds on the display off.
       Params:
       addr	address of the display to control
    */
    void clearDisplay(int addr);

    /*
       Set the status of a single Led.
       Params :
       addr	address of the display
       row	the row of the Led (0..7)
       col	the column of the Led (0..7)
       state	If true the led is switched on,
     		if false it is switched off
    */
    void setLed(int addr, int row, int col, boolean state);

    /*
       Set all 8 Led's in a row to a new state
       Params:
       addr	address of the display
       row	row which is to be set (0..7)
       value	each bit set to 1 will light up the
     		corresponding Led.
    */
    void setRow(int addr, int row, byte value);

    /*
       Set all 8 Led's in a column to a new state
       Params:
       addr	address of the display
       col	column which is to be set (0..7)
       value	each bit set to 1 will light up the
     		corresponding Led.
    */
    void setColumn(int addr, int col, byte value);

    /*
       set a gitit on a screen.
       mod for time machine
       kusjes Pim
    */
    void setDigit(byte screen, byte digit);

    /*
       Display a character on a digit on one screen.
       mod for time machine
       kusjes Pim
    */

    void setChar(byte screen, char value);

    void setString(String message);

    void displayYear();

    void setupDisplay(int intensity);

    void fillDisplay(int addr);


};

#endif	//LedDisplay.h



