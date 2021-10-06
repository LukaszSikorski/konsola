#include "headers.h"
#include <avr/io.h>
#include "Mediator.h"

Mediator::Mediator(){
}

void Mediator::reactOnButtonLeftA(){
     this->delay = 100;
}

void Mediator::reactOnButtonLeftB(){
     this->delay = 500;
}

void Mediator::reactOnButtonLeftC(){
     this->delay = 1000;
}

void Mediator::run(){
     this->led.toggle();
     uint16_t tmp = this->delay;
     while(tmp) {
          tmp--;
          _delay_ms(1);
     }
}

