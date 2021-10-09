#include "Led.h"

Led::Led(volatile uint8_t *port, uint8_t pin){
    (*port) |= (1 << pin);
    this->pin = pin;
    this->port = port;
}

void Led::set(){
    *this->port |= (1 << pin);
}

void Led::clear(){
    *this->port &= ~(1 << pin);
}

void Led::toggle(){
    PORTD ^= (1 << pin);
}