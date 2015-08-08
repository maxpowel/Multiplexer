//
// Created by alvaro on 26/07/15.
//

#include "Multiplexer.h"
#include "Arduino.h"

Multiplexer::Multiplexer(int dataPin, int nLines, int linePins[]){
    if(nLines > MULTIPLEXER_MAX_LINES){
        Serial.print("ERROR: Max number of lines is: ");
        Serial.println(MULTIPLEXER_MAX_LINES);
        Serial.println("The lines number will be truncated to this numer");
        nLines = MULTIPLEXER_MAX_LINES;
    }

    _dataPin = dataPin;
    _nLines = nLines;

    for(int i = 0; i < _nLines; i++){
        pinMode(linePins[i],OUTPUT);
        _linePins[i] = linePins[i];
    }
}


void Multiplexer::setAddress(int address) {
    for(int i = 0; i < _nLines; i++){
        ::digitalWrite(_linePins[i], bitRead(address, i));
    }
}

int Multiplexer::digitalRead(int address) {
    setAddress(address);
    return ::digitalRead(_dataPin);
}

int Multiplexer::analogRead(int address) {
    setAddress(address);
    return ::analogRead(_dataPin);
}

void Multiplexer::digitalWrite(int address, int value) {
    setAddress(address);
    return ::digitalWrite(_dataPin, value);
}

void Multiplexer::analogWrite(int address, int value) {
    setAddress(address);
    return ::analogWrite(_dataPin, value);
}

int Multiplexer::getDataPin() {
    return _dataPin;
}

int Multiplexer::getNLines() {
    return _nLines;
}
