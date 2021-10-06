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

    public:
        void update();
        void handleSignals(void);
};