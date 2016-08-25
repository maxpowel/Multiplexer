#include "Multiplexer.h"

/*
  In this example I am going to use an CD4051 which is an
  8 channel Multiplexer/Demultiplexer
  It means that we need 3 pins (2^3=8) to manage all possible addresses.

  As the CD4051 is multiplexer/demultiplexer it means that is bi-directional.
  http://www.ti.com/lit/ds/symlink/cd4051b.pdf
  Once the desired address is set we can write and read from our data pin

  Please note that most devices are only multiplexer or demultiplexer but not both:
  Multiplexer: Can use write
  Demultiplexer: Can use read
  Check your device datasheet
*/

/*
Wiring

CD4051
1 -> Input 6
2 -> Input 7
3 -> To arduino pin4
4 -> Input 8
5 -> Input 5
6 -> Ground
7 -> Ground
8 -> Ground
9 -> Arduino pin A3
10 -> Arduino pin A2
11 -> Arduino pin A1
12 -> Input 4
13 -> Input 1
14 -> Input 2
15 -> Input 3
16 -> Vcc 5V
*/

/* The pin where data will be read/write */
#define DATA_PIN 4
#define TOTAL_LINES 3

int linePins[] = {A1,A2,A3};

Multiplexer m(DATA_PIN, TOTAL_LINES, linePins);

void setup(){
     Serial.begin(115200);
}

void loop(){
   /*
     In this example I have 8 data sources (sensors).
     CD4051 can handle analog inputs but most devices are only digital.
     Check your datasheet
   */
    for(int address = 0; address < 0b111; address++){
          Serial.print("Input: ");
          Serial.print(address);
          Serial.print(" value: ");
          Serial.println(m.analogRead(address));

    }
    delay(1000);

}
