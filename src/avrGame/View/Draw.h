#include <avr/io.h>
#include "Figures.h"
#include "Matrix.h"

class Draw{
    public:
     void rect(Matrix &,Colors color, Rect &);
     void point(Matrix &,Colors color, uint8_t x, uint8_t y);

};