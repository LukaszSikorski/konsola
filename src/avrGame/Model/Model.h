#pragma once

#ifndef _MODEL_H
#define _MODEL_H

#include <avr/io.h>
#include "../View/Figures.h"
// #include "../avrGame.h"




class Model{
    public:
        uint8_t x;
        Model();
        Rect r1 = Rect(0, 0, 2, 2);
        void reactOnButtonLeftA(void);
        void capture(void);
};

#endif // _MODEL_H