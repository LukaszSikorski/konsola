#include <avr/io.h>
#ifndef _LED_H
#define _LED_H
class Led {
    public:
        volatile uint8_t *port;
        uint8_t pin;



        Led(volatile uint8_t * port, uint8_t pin);
        void set(void);
        void clear(void);
        void toggle(void);
};
#endif //