#include "Matrix.h"

Matrix::Matrix(){
    for(uint8_t color=0; color < 3; ++color){
        for (uint8_t i = 0; i < WIDTH; ++i){
            this->matrix[color][i] = 255;
        }
    }
}