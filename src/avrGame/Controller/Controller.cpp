#include "Controller.h"

Controller::Controller(Listener *l){
    listener = l;
}

void Controller::capture(){
    this->listener->update();
    this->listener->handleSignals();
}

void Controller::updateTimers(void){
    this->listener->updateTimers();
}
