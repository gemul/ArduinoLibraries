/*
  TwoBytesShifting_4x7segments
  Control 4 digits 7 segments using 2 (two) 74595 Shift register IC (2 bytes)

  More documentation and the wiring (soon) at http://asudahlah.com

  This example code is in the public domain.

  by Gema Ulama Putra
*/

#include "ShiftRegister.h"

int latchPin = 7; //Pin connected to Pin 12 of 74HC595 (Latch)
int clockPin = 4; //Pin connected to Pin 11 of 74HC595 (Clock)
int dataPin = 6; //Pin connected to Pin 14 of 74HC595 (Data)]

ShiftRegister sr(clockPin,latchPin,dataPin); //create a new ShiftRegister Object

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  updateSegments();
}

void updateSegments(){
  sr.openLatch();
  //shifting out two times (1 Byte each) between opening and closing latch for total 2 Bytes
  //the first shifted bytes goes to last register in chain
  sr.shiftOut(B00000001); //Selecting first digit
  sr.shiftOut(B11000000); //Number 0
  sr.closeLatch();
  sr.openLatch();
  sr.shiftOut(B00000010); //Selecting second digit
  sr.shiftOut(B11111001); //Number 1
  sr.closeLatch();
  sr.openLatch();
  sr.shiftOut(B00000100); //Selecting third digit
  sr.shiftOut(B10100100); //Number 2
  sr.closeLatch();
  sr.openLatch();
  sr.shiftOut(B00001000); //Selecting fourth digit
  sr.shiftOut(B10110000); //Number 3
  sr.openLatch();
  sr.closeLatch();
}


