# Arduino Multiplexer

When you need to handle a lot of GPIO (lots of leds, sensors...) the amount of pins provided by Arduino are not enough. The solution is use multiplexers. The objective of this library is make easy to use and maintain a project that uses multiplexers.


Configuration
=============
The first step is create the multiplexer

```c
Multiplexer m(DATA_PIN, TOTAL_LINES, linePins);
```

Where data pin is the pin where the data pin of the multiplexer is connected, total lines is size in bits of the address of your multiplexer and linePins is the pins used to build the address.
For example the cd4051b multiplexer/demultiplexer has 3 lines (pins 11, 10 and 9) and linePins shoud be an array of size 3 specifying the arduino pins

```c
#define DATA_PIN 4
#define TOTAL_LINES 3

int linePins[] = {A1,A2,A3};

Multiplexer m(DATA_PIN, TOTAL_LINES, linePins);
```
In this example we will use the following pins: 4, A1, A2 and A3


Available methods
=================

digitalWrite(address, VALUE);
-----------------------------
Write HIGH or LOW to the pin specified in the address. The address 0b000 is your first channel and 0b111 is your last

analogWrite(address, VALUE);
-----------------------------
Only in case that your multiplexer can handle analog values

digitalRead(address);
-----------------------------
Read a digital value. Only for demultiplexers

analogWrite(address, VALUE);
-----------------------------
Read an analog value. Only for demultiplexers that can handle analog values.


Examples
========

For more detailed examples check the examples provided by this library. You can find examples for multiplexer, demultiplexer and nested multiplexers

I have recorded some videos using this library, some leds and some cd4051b:
[Simple multiplexer](https://youtu.be/yOmDRKJGldk)
[Nested multiplexer](https://youtu.be/ufwgveMhR6g)



