#include <avr/io.h>
#include "Button.h"
#include "Signals.h"


class FasadeButtons{
    private:
        Button listButtons[3] = {
            Button(&DDRD,6), Button(&DDRD,7), Button(&DDRB,0)
        };

    public:
        uint8_t getValue();
};