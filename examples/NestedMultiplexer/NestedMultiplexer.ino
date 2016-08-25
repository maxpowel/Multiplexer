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
 * Check a real example here https://youtu.be/ufwgveMhR6g
 */

/*
Wiring

First CD4051 (controls pins 1-8)
1 -> Led 5
2 -> Led 7
3 -> To arduino pin 4
4 -> Led 8
5 -> Led 6
6 -> Third CD4051, pin 13
7 -> Ground
8 -> Ground
9 -> Arduino pin A3
10 -> Arduino pin A2
11 -> Arduino pin A1
12 -> Led 4
13 -> Led 1
14 -> Led 2
15 -> Led 3
16 -> Vcc 5V

Second CD4051 (controls pins 9-16)

1 -> Led 13
2 -> Led 15
3 -> To arduino pin4
4 -> Led 16
5 -> Led 14
6 -> Third CD4051, pin 14
7 -> Ground
8 -> Ground
9 -> Arduino pin A3
10 -> Arduino pin A2
11 -> Arduino pin A1
12 -> Led 12
13 -> Led 9
14 -> Led 10
15 -> Led 11
16 -> Vcc 5V

Third CD4051 (controls which CD4051 are enabled, depending on the address). 
With this build you can address unti 8 CD4051, so you can handle 64 Leds.
Of course you can nest more CD4051 (more leds the bigger address) to get more io pins.

1 -> Other CD4051 or not connected
2 -> Other CD4051 or not connected
3 -> Vcc 5V
4 -> Other CD4051 or not connected
5 -> Other CD4051 or not connected
6 -> Ground
7 -> Ground
8 -> Ground
9 -> Arduino pin A0
10 -> Ground or next address pin
11 -> Ground or next address pin
12 -> Other CD4051 or not connected
13 -> First CD4051 pin 6
14 -> Second CD4051 pin 6
15 -> Would go to another CD4051 pin 6 for manage 8 leds more and so on
16 -> Vcc 5V


*/

/* The pin where data will be read/write */
#define DATA_PIN 4
#define TOTAL_LINES 4

int linePins[] = {A1,A2,A3,A0};

Multiplexer m(DATA_PIN, TOTAL_LINES, linePins);

void setup(){
  Serial.begin(115200);

}

void loop(){
   /*
     This example will turn on all leds, one by one.
     Every led has it own address, so pin 1 has the address
     0b000, the pin 2 has the address 0b001 and so on.
     Finally, the pin 8 has the address 0b111
   */
    for(int address = 0; address <= 0b1111; address++){
          /* Turn on the led */
          m.digitalWrite(address, HIGH);
          Serial.println(address, BIN);
          delay(500);
          /* Turn off the led */
          m.digitalWrite(address, LOW);
          delay(100);
    }

}
