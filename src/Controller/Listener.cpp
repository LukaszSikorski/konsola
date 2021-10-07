#include "headers.h"
#include <avr/io.h>
#include "Listener.h"

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
            this->mediator.reactOnButtonLeftA();
        }
        else if( signal == Signals::buttonLeftB){
            this->mediator.reactOnButtonLeftB();
        }
        else if( signal == Signals::buttonLeftC){
            this->mediator.reactOnButtonLeftC();
        }
        else if( signal == Signals::buttonRightA){

        }
        else if( signal == Signals::buttonRightB){

        }
        else if( signal == Signals::buttonRightC){

        }
        signal = this->recvButtons.getValue();
    }
    this->mediator.run();
}

void Listener::updateTimers(){
    this->timer--;
    if ( !this->timer){
        this->fasadeButtons.decButtons();
        this->mediator.updateTimers();
        this->timer = 10;
    }
}