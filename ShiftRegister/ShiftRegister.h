/*
 ShiftRegister.h - Library for sending data to shift register IC
 Created by Gema Ulama Putra, December 23, 2016
 Released into the public domain
*/
#ifndef ShiftRegister_h
#define ShiftRegister_h

#include "Arduino.h"

class ShiftRegister{
	public:
		ShiftRegister(int clock,int latch,int data);
		void shiftOut(byte dataOut);
		void openLatch();
		void closeLatch();
	private:
		int _clockPin;
		int _latchPin;
		int _dataPin;
};

#endif
