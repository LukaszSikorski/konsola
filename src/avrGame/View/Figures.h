#pragma once
#include <avr/io.h>
#ifndef _FIGURES_H
#define _FIGURES_H

class Rect{
    public:
        Rect(uint8_t width, uint8_t height, uint8_t x, uint8_t y);
        void move(uint8_t x, uint8_t y);
        uint8_t width:4;
        uint8_t height:4;
        uint8_t x:4;
        uint8_t y:4;
};

#endif //