#include "headers.h"
#include <avr/io.h>
#include "Button.h"
#include <util/delay.h>

Button::Button(volatile uint8_t *port, uint8_t pin){
    *port &= ~(1<<pin);
    *(port + 1) |= ( 1 <<pin);
    this->port = port;
    this->pin = pin;
    this->timer = 0;
}

uint8_t Button::isPush(){
    uint8_t result = 0;
    if( !(( *(this->port - 1)) & (1 << this->pin))){
        if ( this->timer == 0 && this->checked == 0){
            this->checked = 1;
            this->timer = TIMER_mS;
        }
        if( !(( *(this->port - 1)) & (1 << this->pin)) && this->timer == 0){
            result = 1;
            this->checked = 0;
        }
    }
    return result;
}

void Button::decTimer(){
    if( this->timer)timer--;
}