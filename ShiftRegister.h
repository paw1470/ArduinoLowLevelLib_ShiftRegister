#ifndef SHIFTREGISTERPB_H
#define SHIFTREGISTERPB_H

#include <inttypes.h>
#include "Arduino.h"

class ShiftRegisterPB{
    private:
        uint8_t dataPin; 
        uint8_t latchPin; 
        uint8_t clockPin;
        byte data;
    public:
        void init(uint8_t dataPin, uint8_t latchPin, uint8_t clockPin);
        byte getDataByte();
        bool isBitOn(uint8_t bitPosition);
        void setBit(uint8_t bitPosition, bool bitNewState);
        void setDataByte(byte data);
        void updateRegister();
        void testShift();
        void testBlink0();
};

#endif