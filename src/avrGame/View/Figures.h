#pragma once
#include <avr/io.h>
#ifndef _FIGURES_H
#define _FIGURES_H

class Rect{
    public:
        Rect(const uint8_t x, const uint8_t y, const uint8_t width, const uint8_t height);
        Rect();
        void moveTo(const uint8_t x, const uint8_t y);
        uint8_t width:4;
        uint8_t height:4;
        uint8_t x:4;
        uint8_t y:4;
};

#endif //