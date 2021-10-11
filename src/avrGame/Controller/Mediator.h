#ifndef _MEDIATOR_H
#define _MEDIATOR_H
#include "Led.h"
#include <avr/io.h>
#include "../Model/Model.h"

class Mediator{
    public:
        uint16_t delay;
        volatile uint16_t timer;
        static Led led;
        // Model model;
        Mediator();
        void reactOnButtonLeftA(void);
        void reactOnButtonLeftB(void);
        void reactOnButtonLeftC(void);
        void updateTimers(void);
        void run();
};

#endif // _MEDIATOR_H