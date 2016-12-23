/*
 ShiftRegister.h - Library for sending data to shift register IC
 Created by Gema Ulama Putra, December 23, 2016
 Released into the public domain
*/
#include "Arduino.h"
#include "ShiftRegister.h"

ShiftRegister::ShiftRegister(int clock,int latch,int data){
	pinMode(clock,OUTPUT);
	pinMode(latch,OUTPUT);
	pinMode(data,OUTPUT);
	_clockPin=clock;
	_latchPin=latch;
	_dataPin=data;
}

void ShiftRegister::shiftOut(byte dataOut) {
  // Shift out 8 bits LSB first, clocking each with a rising edge of the clock line
  boolean pinState;
   
  for (int i=0; i<=7; i++) {
    // for each bit in dataOut send out a bit
    digitalWrite(_clockPin, LOW);
    //set clockPin to LOW prior to sending bit
     
    // if the value of DataOut and (logical AND) a bitmask
    // are true, set pinState to 1 (HIGH)
    if ( dataOut & (1<<i) ) {
      pinState = HIGH;
    }
    else {
      pinState = LOW;
    }
     
    //sets dataPin to HIGH or LOW depending on pinState
    digitalWrite(_dataPin, pinState); //send bit out before rising edge of clock
    digitalWrite(_clockPin, HIGH);
  }
  digitalWrite(_clockPin, LOW); //stop shifting out data
}
void ShiftRegister::openLatch(){
  digitalWrite(_latchPin,LOW); //open latch, ready to apply data to pinout
}
void ShiftRegister::closeLatch(){
  digitalWrite(_latchPin,HIGH); //close latch, applying stored data to pinout
}
