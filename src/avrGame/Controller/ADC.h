#ifndef _ADC_H
#define _ADC_H
#include <avr/io.h>

class Adc{
    public:
        Adc();
        uint16_t getSingle(uint8_t pin);

};

#endif //