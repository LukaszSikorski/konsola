
#ifndef _LISTENER_H
#define _LISTENER_H
#include <avr/io.h>
#include "Mediator.h"
#include "ListSignals.h"
#include "FasadeButtons.h"

class Listener{
    private:
    public:
        Listener(Mediator *);
        Mediator *med;
        ListSignals recvButtons;
        FasadeButtons fasadeButtons;
        volatile uint8_t timer;
        void update();
        void handleSignals(void);
        void updateTimers(void);
};

#endif //