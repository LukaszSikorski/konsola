#include "FasadeButtons.h"

uint8_t FasadeButtons::getValue() {
    uint8_t result = 0;
    if (this->listButtons[0].isPush() == 1) result = Signals::buttonLeftA;
    else if (this->listButtons[1].isPush() == 1) result = Signals::buttonLeftB;
    else if (this->listButtons[2].isPush() == 1) result = Signals::buttonLeftC;
    return result;
}