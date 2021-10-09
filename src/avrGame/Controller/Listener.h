
#ifndef _LISTENER_H
#define _LISTENER_H

#include "headers.h"
#include <avr/io.h>
#include "Mediator.h"
#include "ListSignals.h"
#include "FasadeButtons.h"

class Listener{
    private:
        Mediator mediator = Mediator();
        ListSignals recvButtons = ListSignals();
        FasadeButtons fasadeButtons = FasadeButtons();
        volatile uint8_t timer = 0;

    public:
        uint8_t x = 0;
        uint8_t y = 0;
        void update();
        void handleSignals(void);
        void updateTimers(void);
};

#endif //