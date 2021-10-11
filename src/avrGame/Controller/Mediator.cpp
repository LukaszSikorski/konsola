#include "Mediator.h"


Mediator::Mediator(){
     delay = 250;
     timer = 0;
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

Led Mediator::led = Led(&DDRD, 4);