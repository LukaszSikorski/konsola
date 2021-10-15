#include "Draw.h"


void Draw::point(Matrix &matrix, uint8_t x, uint8_t y, Colors color){
    x = ((WIDTH - 1) - x) ;
    if(color == Colors::yellow){
        matrix.matrix[red][x] &= ~(1 << (y ));
        matrix.matrix[green][x] &= ~(1 << (y ));
    }
    else if( color == Colors::purple){
        matrix.matrix[red][x] &= ~(1 << (y ));
        matrix.matrix[blue][x] &= ~(1 << (y ));
    }
    else if( color == Colors::white){
        matrix.matrix[red][x] &= ~(1 << (y ));
        matrix.matrix[blue][x] &= ~(1 << (y ));
        matrix.matrix[green][x] &= ~(1 << (y ));
    }
    else{
        matrix.matrix[color][x] &= ~(1 << (y ));
    }
}

void Draw::rect(Matrix &matrix, Rect & rect,Colors color){
    int8_t x,y;
    for(uint8_t _x=0; _x < rect.width ; _x++){
        for(uint8_t _y=0; _y < rect.height ; _y++){
            x = _x + rect.x;
            y = _y + rect.y;
            this->point(matrix, x, y, color);
        }
    }
}