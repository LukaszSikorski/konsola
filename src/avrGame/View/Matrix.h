#include <avr/io.h>

#ifndef _MATRIX_H
#define _MATRIX_H

#include "Colors.h"
#define WIDTH 10

class Matrix{
    private:
        void clear();
    public:
        Matrix();
        void flip();
        uint16_t matrix[3][WIDTH];
};

#endif //