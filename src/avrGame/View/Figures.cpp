#include "Figures.h"

void Rect::moveTo(const uint8_t x, const uint8_t y){
    this->x = x;
    this->y = y;
}

Rect::Rect(){
    
}

Rect::Rect( uint8_t x,  uint8_t y,  uint8_t width,  uint8_t height){
    this->width = width;
    this->height = height;
    this->x = x;
    this->y = y;
}