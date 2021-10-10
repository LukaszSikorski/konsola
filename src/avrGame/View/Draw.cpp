#include "Draw.h"


void Draw::point(Matrix &matrix, uint8_t x, uint8_t y, Colors color){
    x = ((WIDTH - 1) - x) ;
    matrix.matrix[color][x] &= ~(1 << (y ));
}

void Draw::rect(Matrix &matrix, Rect & rect,Colors color){
    int8_t tmp;
    int8_t x,y;
    for(uint8_t _x=0; _x < rect.width ; _x++){
        for(uint8_t _y=0; _y < rect.height ; _y++){
            x = _x + rect.x;
            y = _y + rect.y;
            this->point(matrix, x, y, color);
        }
    }
}