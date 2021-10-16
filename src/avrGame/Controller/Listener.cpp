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
        else if( signal == Signals::reactOnButtonDown){
            this->med->reactOnButtonDown();
        }
        else if( signal == Signals::buttonTop){
            this->med->reactOnButtonTop(); 
        }
        else if( signal == Signals::buttonLeft){
            this->med->reactOnButtonLeft(); 
        }
        else if( signal == Signals::reactOnButtonRight){
            this->med->reactOnButtonRight(); 

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