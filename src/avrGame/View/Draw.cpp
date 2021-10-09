#include "Draw.h"


void Draw::point(Matrix &matrix, Colors color, uint8_t x, uint8_t y){
    x = 7 - x;
    matrix.matrix[color][x] &= ~(1 << y);
}