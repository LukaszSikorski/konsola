#include <avr/io.h>


class Rect{
    public:
        uint8_t width:4;
        uint8_t height:4;
        uint8_t x:4;
        uint8_t y:4;
};