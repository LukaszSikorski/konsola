#include "Model.h"
#include "../avrGame.h"


Model::Model(Matrix *matrix){
    this->matrix = matrix;
    this->animationState.targetState = &stateTicTacToe;
    this->state = &animationState;
}

void Model::reactOnButtonLeftA(){
    this->state->reactOnButtonLeftA();
}

void Model::reactOnButtonLeftB(){
    this->state->reactOnButtonLeftB();
}

void Model::reactOnButtonDown(){
    this->state->reactOnButtonDown();

}

void Model::reactOnButtonTop(){
    this->state->reactOnButtonTop();
}

void Model::reactOnButtonLeft(){
    this->state->reactOnButtonLeft();
}

void Model::reactOnButtonRight(){
    this->state->reactOnButtonRight();
}

void Model::capture(){
    this->state->capture();
}

void Model::update(){
    this->state->update();
    
}