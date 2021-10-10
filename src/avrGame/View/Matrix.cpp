#include "Matrix.h"

Matrix::Matrix(){
    this->clear();
}


// TODO: Można zrobic to tylko w jednej petli, wszystkie kolory naraz, ale zostawie
// sprawdze czy bedzie wyrabiac, najwyzej poprawie :)
void Matrix::clear(){
    for(uint8_t color=0; color < 3; ++color){
        for (uint8_t i = 0; i < WIDTH; ++i){
            this->matrix[color][i] = 0xffff;
        }
    } 
}

void Matrix::flip(){
    this->clear(); 
}

