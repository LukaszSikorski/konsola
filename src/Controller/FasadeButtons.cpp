#include "FasadeButtons.h"

uint8_t FasadeButtons::getValue() {
    uint8_t result = 0;
    if (this->listButtons[0].isPush()) result = Signals::buttonLeftA;
    else if (this->listButtons[1].isPush()) result = Signals::buttonLeftB;
    else if (this->listButtons[2].isPush()) result = Signals::buttonLeftC;
    return result;
}

void FasadeButtons::updateTimers(){
    for (int i = 0;i < NUMBER_BUTTONS; i++){
        this->listButtons[i].decTimer();
    }
}