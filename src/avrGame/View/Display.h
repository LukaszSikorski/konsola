#include <avr/io.h>
#include "Spi.h"
#include "Matrix.h"
#ifndef _DISPLAY_H
#define _DISPLAY_H

class Display{
    public:
        void flip(Matrix &matrix);
        Display() {this->colums = 0;}
    private:
        uint16_t getColumns();
        uint8_t getRed(Matrix &matrix);
        uint8_t getGreen(Matrix &matrix);
        uint8_t getBlue(Matrix &matrix);

        Spi spi = Spi();
        uint8_t colums:4;
        uint8_t colForDisplay:4;

};  

#endif //