#include <avr/io.h>

#ifndef _MATRIX_H
#define _MATRIX_H

#include "Colors.h"
#define WIDTH 8

class Matrix{
    private:
        uint8_t _matrix[3][WIDTH];
    public:
        Matrix();
        uint8_t matrix[3][WIDTH];
};

#endif //