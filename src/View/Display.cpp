#include "Display.h"

void Display::fill(Matrix &matrix){
    uint8_t col = this->getColumns();
    uint8_t green = this->getGreen(matrix);
    uint8_t bytes1 = (col & 0xf0) | (0x0f & green);
    uint8_t bytes2 = (col & 0x0f) | (0xf0 & green);
    uint8_t bytes3 = getBlue(matrix);
    uint8_t bytes4 = getRed(matrix);
    this->spi.sendBytes(bytes1, bytes2, bytes3, bytes4);
    this->colums++;
}

void Display::drawPoint(Matrix &matrix, Colors color, uint8_t x, uint8_t y){
    x = 7 - x;
    matrix.matrix[color][x] &= ~(1 << y);
}

uint8_t Display::getColumns(){
    uint8_t result = (1 << this->colums);
    return result;
}

uint8_t Display::getGreen(Matrix &matrix){
    uint8_t result = 0;
    uint8_t col = colums;
    uint8_t tmp = matrix.matrix[green][col];
    tmp = ((tmp << 4) & 0xf0) | ((tmp >> 4) & 0x0f);
    for(uint8_t i = 0;i < WIDTH; i++){
        if (tmp & (1 << (7 - i))){
            result |= (1 << i);
        }
    }   
    return result;


}

uint8_t Display::getBlue(Matrix &matrix){
    uint8_t result = 0;
    uint8_t col = this->colums;
    for(uint8_t i = 0;i < WIDTH; i++){
        if (matrix.matrix[blue][col] & (1 << i)){
            result |= (1 << i);
        }
    }   
    return result;
}

uint8_t Display::getRed(Matrix &matrix){
    uint8_t result = 0;
    uint8_t col = this->colums;
    for(uint8_t i = 0;i < WIDTH; i++){
        if (matrix.matrix[red][col] & (1 << i)){
            result |= (1 << i);
        }
    }   
    return result;
}