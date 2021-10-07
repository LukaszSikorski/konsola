#include <avr/io.h>
#include "Colors.h"

#define WIDTH 8

class Matrix{
    public:
        Matrix();
        uint8_t matrix[3][WIDTH];
};