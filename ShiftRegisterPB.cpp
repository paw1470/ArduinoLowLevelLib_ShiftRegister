#include "ShiftRegisterPB.h"
#include "BitOperations.h"

void ShiftRegisterPB::init(uint8_t dataPin, uint8_t latchPin, uint8_t clockPin){
    this->dataPin = dataPin;
    this->latchPin = latchPin;
    this->clockPin = clockPin;
    pinMode(dataPin, OUTPUT);
    pinMode(latchPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    this->data = 0;
}
        
byte ShiftRegisterPB::getDataByte(){
    return data;
}
        
bool ShiftRegisterPB::isBitOn(uint8_t bitPosition){
    return BitVal(data, bitPosition);
}

void ShiftRegisterPB::setBit(uint8_t bitPosition, bool bitNewState){
    if(bitNewState){
        data = SetBit(data, bitPosition);
    } else{
        data = ClearBit(data, bitPosition);
    }
}

void ShiftRegisterPB::setDataByte(byte data){
    if(this->data != data){
        this->data = data;
        updateRegister();
    }
}

void ShiftRegisterPB::updateRegister(){
	digitalWrite(latchPin, LOW);
   	shiftOut(dataPin, clockPin, LSBFIRST, data);
   	digitalWrite(latchPin, HIGH);
}

void ShiftRegisterPB::testShift(){
    this->data = 1;
    for(int i=0; i<8; i++){
        updateRegister();
        this->data <<= 1;
        delay(250);
    }
    this->data = 0;
    updateRegister();
}

void ShiftRegisterPB::testBlink0(){
    for(int i=0; i<10; i++){
        setBit(0, (i/2 == 0 ? false : true));
        updateRegister();
        delay(250);
    }
    this->data = 0;
    updateRegister();
}