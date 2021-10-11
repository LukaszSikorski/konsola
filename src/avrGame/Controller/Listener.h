
#ifndef _LISTENER_H
#define _LISTENER_H
#include <avr/io.h>
#include "Mediator.h"
#include "ListSignals.h"
#include "FasadeButtons.h"

class Listener{
    private:
    public:
        Mediator mediator;
        ListSignals recvButtons;
        FasadeButtons fasadeButtons;
        volatile uint8_t timer;

        uint8_t x;
        uint8_t y;
        void update();
        void handleSignals(void);
        void updateTimers(void);
};

#endif //