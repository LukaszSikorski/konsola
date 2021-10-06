#include "headers.h"
#include <avr/io.h>
#include "Led.h"
#include <util/delay.h>


class Mediator{
    public:
        uint16_t delay = 1;
        Led led = Led(&DDRD, 4);
        Mediator();
        void reactOnButtonLeftA(void);
        void reactOnButtonLeftB(void);
        void reactOnButtonLeftC(void);
        void run();
};