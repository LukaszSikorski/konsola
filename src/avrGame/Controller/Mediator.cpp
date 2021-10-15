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

void Mediator::reactOnButtonLeftC(){
     this->mod->reactOnButtonRightC();
     this->delay = 100;
}

void Mediator::reactOnButtonRightA(){
     this->delay = 100;
     this->mod->reactOnButtonRightA();
}

void Mediator::reactOnButtonRightB(){
     this->mod->reactOnButtonRightB();
}

void Mediator::reactOnButtonRightC(){
     this->mod->reactOnButtonRightC();
}


void Mediator::updateTimers(){
     if( this->timer) this->timer--;
     if (!this->timer) {
          this->timer = 30;
     }
     this->mod->update();
}

Led Mediator::led = Led(&DDRD, 4);