#include <avr/io.h>

class Led {
    public:
        volatile uint8_t *port;
        uint8_t pin;



        Led(volatile uint8_t * port, uint8_t pin);
        void set(void);
        void clear(void);
        void toggle(void);
};