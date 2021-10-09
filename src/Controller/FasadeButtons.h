#include <avr/io.h>
#include "Button.h"
#include "Signals.h"

#define NUMBER_BUTTONS 3

class FasadeButtons{
    private:
        Button listButtons[NUMBER_BUTTONS] = {
            Button(&DDRD,6), Button(&DDRD,7), Button(&DDRB,0)
        };

    public:
        uint8_t getValue();
        void updateTimers();
};