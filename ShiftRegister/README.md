# ShiftRegister
Library for sending data to serial input parallel output 8-bit shift register.

## Constructor
```
void ShiftRegister::ShiftRegister(int <clock pin>, int <data pin>, int <latch pin>);
```
clock pin = pin 11 in 595 IC
latch pin = pin 12 in 595 IC
data pin = pin 14 in 595 IC

## openLatch
```
void ShiftRegister::openLatch();
```
Opening latch. Ready to send serial data.

## closeLatch
```
void ShiftRegister::closeLatch();
```
Closing latch. Copy stored data to pins.

## shiftOut
```
void ShiftRegister::shiftOut(byte <data>);
```
Send serial data (byte) to shift register.
You can run this multiple time between opening and closing latch to send more than one byte(s). (chained 8-bit shift register)
