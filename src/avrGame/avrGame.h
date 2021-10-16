#ifndef _AVRGAME_
#define _AVRGAME_

#include <avr/io.h>
#include "View/Display.h"
#include "View/Draw.h"
#include "Controller/Controller.h"
#include "Model/Model.h"
#include "Controller/Rs232.h"
#include "Controller/ADC.h"


class Model;

class avrGame{
    private:
    public:
        static Adc adc;
        static Rs232 rs232;
        static Matrix _matrix;
        static Model mode;
        static Mediator mediato;
        static Listener listene;
        static Controller controller;
        static Draw draw;
        static Display display;
        static Matrix matrix(void);
        static Rect rect(uint8_t x, uint8_t y, uint8_t width, uint8_t height);
        static void ToggleLed();
};

#endif