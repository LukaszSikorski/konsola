#ifndef _CONTROLLER_H
#define _CONTROLLER_H
#include <avr/io.h>
#include "Listener.h"
class Controller{

    public:
        Controller(Listener *);
        void capture();
        void updateTimers();
        Listener *listener;
};

#endif //