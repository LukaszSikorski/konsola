#include "headers.h"
#include <avr/io.h>

#define SIZE_BUFFOR 8

class ListSignals{
    public:
        uint8_t table[SIZE_BUFFOR];
        uint8_t head = 0;
        uint8_t tail = 0;
        uint8_t getValue();
        void appendValue(uint8_t value);
};