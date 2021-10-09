#include "Controller.h"

void Controller::run(){
    this->listener.update();
    this->listener.handleSignals();
}

void Controller::updateTimers(void){
    this->listener.updateTimers();
}
