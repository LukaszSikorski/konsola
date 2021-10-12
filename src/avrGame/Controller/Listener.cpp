#include "Listener.h"
#include "Signals.h"

Listener::Listener(Mediator *m){
    this->med = m;
}

void Listener::update(){
    uint8_t signal = this->fasadeButtons.getValue();
    while(signal){
        this->recvButtons.appendValue(signal);
        signal = this->fasadeButtons.getValue();

    }
}

void Listener::handleSignals(){
    uint8_t signal = this->recvButtons.getValue();
    while(signal != 0){
        if( signal == Signals::buttonLeftA){
            this->med->reactOnButtonLeftA();
        }
        else if( signal == Signals::buttonLeftB){
            this->med->reactOnButtonLeftB();
        }
        else if( signal == Signals::buttonLeftC){
            this->med->reactOnButtonLeftC();
        }
        else if( signal == Signals::buttonRightA){
            this->med->reactOnButtonRightA(); 
        }
        else if( signal == Signals::buttonRightB){
            this->med->reactOnButtonRightB(); 
        }
        else if( signal == Signals::buttonRightC){
            this->med->reactOnButtonRightC(); 

        }
        signal = this->recvButtons.getValue();
    }
    this->med->capture();
}

void Listener::updateTimers(){
    this->timer--;
    if ( !this->timer){
        this->fasadeButtons.updateTimers();
        this->med->updateTimers();
        this->timer = 30;
    }
}