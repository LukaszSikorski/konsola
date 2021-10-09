#include "Draw.h"


void Draw::point(Matrix &matrix, uint8_t x, uint8_t y, Colors color){
    x = 7 - x;
    matrix.matrix[color][x] &= ~(1 << y);
}

void Draw::rect(Matrix &matrix, Rect & rect,Colors color){
    uint8_t tmp;
    for(uint8_t _x=0; _x < rect.width; _x++){
        for(uint8_t _y=0; _y < rect.height; _y++){
            tmp = 7- (_x + rect.x);
            matrix.matrix[color][tmp] &= ~( 1 << (_y + rect.y) );
        }
    }
}