#include "ShiftRegisterPB.h"
#include "Arduino.h"

#define PIN_SHIFT_REGISTER_CLOCK    10
#define PIN_SHIFT_REGISTER_LATCH    11
#define PIN_SHIFT_REGISTER_DATA     12

ShiftRegisterPB shiftRegister;

void setup(){
    shiftRegister.init(PIN_SHIFT_REGISTER_DATA, PIN_SHIFT_REGISTER_LATCH, PIN_SHIFT_REGISTER_CLOCK);
    shiftRegister.testShift();
    shiftRegister.testBlink0(); //not working
    shiftRegister.setDataByte(0b10101010);
    shiftRegister.updateRegister();
}

void loop(){
    shiftRegister.setDataByte(~(shiftRegister.getDataByte()));
    delay(250);
}