#include "headers.h"
#include <avr/io.h>
#include "Mediator.h"
#include "ListSignals.h"

class Listener{
    private:
        Mediator mediator = Mediator();
        ListSignals recvButtons = ListSignals();

    public:
        void update(uint8_t);
        void handleSignals(void);
};