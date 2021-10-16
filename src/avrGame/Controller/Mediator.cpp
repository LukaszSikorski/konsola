#include "Mediator.h"
#include "../Model/Model.h"

Mediator::Mediator(Model *mod){
     this->mod = mod;
     delay = 250;
     timer = 0;
}

Mediator::Mediator(){
     delay = 250;
     timer = 0;
}  

void Mediator::capture(){
     mod->capture();
}

void Mediator::reactOnButtonLeftA(){
     this->delay = 75;
     this->mod->reactOnButtonLeftA();
}

void Mediator::reactOnButtonLeftB(){
     this->mod->reactOnButtonLeftB();
     this->delay = 75;
}

void Mediator::reactOnButtonDown(){
     this->mod->reactOnButtonDown();
     this->delay = 100;
}

void Mediator::reactOnButtonTop(){
     this->delay = 100;
     this->mod->reactOnButtonTop();
}

void Mediator::reactOnButtonLeft(){
     this->mod->reactOnButtonLeft();
}

void Mediator::reactOnButtonRight(){
     this->mod->reactOnButtonRight();
}


void Mediator::updateTimers(){
     if( this->timer) this->timer--;
     if (!this->timer) {
          this->timer = 30;
     }
     this->mod->update();
}

Led Mediator::led = Led(&DDRD, 4);