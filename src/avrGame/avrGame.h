#ifndef _AVRGAME_
#define _AVRGAME_

#include <avr/io.h>
#include "View/Display.h"
#include "View/Draw.h"
#include "Controller/Controller.h"

class avrGame{
    private:
        static Matrix _matrix;
    public:
        static Controller controller;
        static Draw draw;
        static Display display;
        static Matrix matrix(void);
        static Rect rect(uint8_t, uint8_t, uint8_t, uint8_t);
};

#endif