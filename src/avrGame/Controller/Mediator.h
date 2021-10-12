#ifndef _MEDIATOR_H
#define _MEDIATOR_H
#include "Led.h"
#include <avr/io.h>
class Model;

class Mediator{
    public:
        uint16_t delay;
        volatile uint16_t timer;
        static Led led;
        Model *mod;
        Mediator();
        Mediator(Model *mod);
        void reactOnButtonLeftA(void);
        void reactOnButtonLeftB(void);
        void reactOnButtonLeftC(void);
        void reactOnButtonRightA(void);
        void reactOnButtonRightB(void);
        void reactOnButtonRightC(void);
        void updateTimers(void);
        void capture();
};

#endif // _MEDIATOR_H