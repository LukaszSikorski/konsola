#include <avr/io.h>

#define SIZE_BUFFOR 8

class ListSignals{
    public:
        uint8_t table[SIZE_BUFFOR];
        uint8_t head;//  uint8_t head = 0; ->bo  warning: non-static data member initializers only available with -std=c++11 or -std=gnu++11
        uint8_t tail;
        ListSignals();
        uint8_t getValue();
        void appendValue(uint8_t value);
};