#include "headers.h"
#include <avr/io.h>
#include "Listener.h"
#include "Signals.h"

void Listener::update(uint8_t signal){
    this->recvButtons.appendValue(signal);
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