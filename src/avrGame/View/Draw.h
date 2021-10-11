#ifndef _DRAW_H
#define _DRAW_H
#include <avr/io.h>
#include "Figures.h"
#include "Matrix.h"

class Draw{
    public:
     void rect(Matrix &, Rect &,Colors color);
     void point(Matrix &, uint8_t x, uint8_t y, Colors color);

};
#endif //