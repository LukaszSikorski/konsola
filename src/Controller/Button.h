#include <avr/io.h>


/* Port D */
#define _PIND	0x10
#define _DDRD	0x11
#define _PORTD	0x12

/* Port C */
#define _PINC	0x13
#define _DDRC	0x14
#define _PORTC	0x15

/* Port B */
#define _PINB	0x16
#define _DDRB	0x17
#define _PORTB	0x18
#define TIMER_mS 30

class Button{
    private:
        volatile uint8_t *port;
        uint8_t checked = 0;
        uint8_t pin;
    public:
        volatile uint8_t timer;
        Button(volatile uint8_t *port, uint8_t pin);
        uint8_t isPush();
        void decTimer(void);
};