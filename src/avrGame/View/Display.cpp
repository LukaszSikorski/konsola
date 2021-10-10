#include "Display.h"



void Display::flip(Matrix &matrix){
    uint8_t col = this->getColumns();
    uint8_t green = this->getGreen(matrix);
    uint8_t bytes1 = (col & 0xf0) | (0x0f & green);
    uint8_t bytes2 = (col & 0x0f) | (0xf0 & green);
    uint8_t bytes3 = getBlue(matrix);
    uint8_t bytes4 = getRed(matrix);
    this->spi.sendBytes(bytes1, bytes2, bytes3, bytes4);
    matrix.flip();
    this->colums++;
}



uint16_t Display::getColumns(){
    uint8_t result = (1 << this->colums);
    return result;
}

uint8_t Display::getGreen(Matrix &matrix){
    uint16_t result = 0xffff;
    uint8_t col = colums + 1;
    uint16_t tmp = 0xffff;
    for(uint8_t i = 1;i < WIDTH; i++){
        if (!(matrix.matrix[green][col] & (1 << (WIDTH - i -1)))){
            tmp &= ~(1 << (i - 1));
        }
    }  
    result = ((tmp << 4) & 0xf0) | ((tmp >> 4) & 0x0f);
    return result;


}

uint8_t Display::getBlue(Matrix &matrix){
    uint16_t result = 0xFFFF;
    uint8_t col = this->colums + 1;
    for(uint8_t i = 1;i < WIDTH; i++){
        if (!(matrix.matrix[blue][col] & (1 << i))){
            result &= ~(1 << (i - 1));
        }
    }   
    return result;
}

uint8_t Display::getRed(Matrix &matrix){
    uint16_t result = 0xFFFF;
    uint8_t col = this->colums + 1;
    for(uint8_t i = 1;i < WIDTH; i++){
        if (!(matrix.matrix[red][col] & (1 << i))){
            result &= ~(1 << (i - 1));
        }
    }   
    return result;
}