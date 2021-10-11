#ifndef _CONTROLLER_H
#define _CONTROLLER_H
#include <avr/io.h>
#include "Listener.h"
class Controller{

    public:
        Listener listener;
        void run();
        void updateTimers();
};

#endif //