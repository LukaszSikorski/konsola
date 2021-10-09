#include <avr/io.h>
#include "Mediator.h"



Mediator::Mediator(){
}

void Mediator::reactOnButtonLeftA(){
     this->delay = 50;
}

void Mediator::reactOnButtonLeftB(){
     this->delay = 75;
}

void Mediator::reactOnButtonLeftC(){
     this->delay = 100;
}

void Mediator::run(){
     if ( !this->timer){
          this->led.toggle();
          this->timer = this->delay;
     }
}

void Mediator::updateTimers(){
     if( this->timer) this->timer--;
}


