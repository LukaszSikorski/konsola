#include <avr/io.h>
#include "Colors.h"

#define WIDTH 8

class Matrix{
    private:
        uint8_t _matrix[3][WIDTH];
    public:
        Matrix();
        uint8_t matrix[3][WIDTH];
};