#ifndef _CONTROLLER_H
#define _CONTROLLER_H
#include <avr/io.h>
#include "Listener.h"

class Controller{
    private:
        Listener listener = Listener();

    public:
        void run();
        void updateTimers();

};

#endif //