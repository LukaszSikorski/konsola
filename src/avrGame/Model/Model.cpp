#include "Model.h"
#include "../avrGame.h"


Model::Model(Matrix *matrix){
    this->matrix = matrix;
    this->state = &snakeState;
}

void Model::reactOnButtonLeftA(){
    this->state->reactOnButtonLeftA();
}

void Model::reactOnButtonLeftB(){
    this->state->reactOnButtonLeftB();
}

void Model::reactOnButtonLeftC(){

}

void Model::reactOnButtonRightA(){
    this->state->reactOnButtonRightA();
}

void Model::reactOnButtonRightB(){
    this->state->reactOnButtonRightB();
}

void Model::reactOnButtonRightC(){

}

void Model::capture(){
    this->state->capture();
}

void Model::update(){
    this->state->update();
    
}