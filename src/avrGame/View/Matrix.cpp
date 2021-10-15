#include "Matrix.h"

Matrix::Matrix(){
    this->clear();
}


// TODO: Można zrobic to tylko w jednej petli, wszystkie kolory naraz, ale zostawie
// sprawdze czy bedzie wyrabiac, najwyzej poprawie :)
void Matrix::clear(){
    for (uint8_t i = 0; i < WIDTH; ++i){
        this->matrix[red][i] = 0xffff;
        this->matrix[green][i] = 0xffff;
        this->matrix[blue][i] = 0xffff;

    }
}

void Matrix::fill(){
    this->clear(); 
}

void Matrix::flip(){
    for(uint8_t i = 0; i < WIDTH; i++){
        this->_matrix[red][i] = this->matrix[red][i];
        this->_matrix[green][i] = this->matrix[green][i];
        this->_matrix[blue][i] = this->matrix[blue][i];
    }
    this->clear();
}
