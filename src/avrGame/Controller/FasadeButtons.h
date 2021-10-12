#include <avr/io.h>
#include "Button.h"
#include "Signals.h"

#define NUMBER_BUTTONS 6

class FasadeButtons{
    private:
            Button listButtons[NUMBER_BUTTONS] = {// do poprawki dużo warning,, dodaj deklaracja w konstruktorze
            Button(&DDRD,6),
            Button(&DDRD,7),
            Button(&DDRB,0),
            Button(&DDRC,2),
            Button(&DDRC,1),
            Button(&DDRC,0),
        };

    public:
        uint8_t getValue();
        void updateTimers();
};