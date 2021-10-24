#ifndef _DRAW_H
#define _DRAW_H
#include <avr/io.h>
#include "Figures.h"
#include "Matrix.h"

class Draw{
    public:
     void rect(Matrix &, Rect &, Colors color);
    //  void line(Matrix &, Line &, const Colors color);
     void point(Matrix &, const uint8_t x, const uint8_t y, const Colors color);

};
#endif //