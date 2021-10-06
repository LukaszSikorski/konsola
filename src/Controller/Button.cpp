#include "headers.h"
#include <avr/io.h>
#include "Button.h"
#include <util/delay.h>

Button::Button(volatile uint8_t *port, uint8_t pin){
    *port &= ~(1<<pin);
    *(port + 1) |= ( 1 <<pin);
    this->port = port;
    this->pin = pin;
}

uint8_t Button::isPush(){
    uint8_t result = 0;
    if( !(( *(this->port - 1)) & (1 << this->pin))){
        _delay_ms(50);
        if( !(( *(this->port - 1)) & (1 << this->pin))){
            result = 1;
        }
    }
    return result;
}