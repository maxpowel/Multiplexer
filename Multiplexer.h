//
// Created by alvaro on 26/07/15.
//

#ifndef PRUEBA_PLAT_MULTIPLEXER_H
#define PRUEBA_PLAT_MULTIPLEXER_H

#include "Arduino.h"

//Static array of size 8 should be enough for any multiplexer. If not, just increment this value
#define MULTIPLEXER_MAX_LINES 8

class Multiplexer {
private:
    int _dataPin;
    int _nLines;

    int _linePins[MULTIPLEXER_MAX_LINES];

public:
    Multiplexer(int dataPin, int nLines, int linePins[]);

    void setAddress(int address);
    void digitalWrite(int address, int value);
    void analogWrite(int address, int value);
    int digitalRead(int address);
    int analogRead(int address);

    int getDataPin();
    int getNLines();
};


#endif //PRUEBA_PLAT_MULTIPLEXER_H
