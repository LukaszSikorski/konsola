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
    x--;
    if (x < -1) x = 9;
    rects[0].move(x,y);
}

void Model::reactOnButtonLeftC(){
    y++;
    if (y > 9) y = -1;
    rects[0].move(x,y);
}

void Model::reactOnButtonRightA(){
    y--;
    if ( y < -1) y = 9;
    rects[0].move(x,y);
}

void Model::reactOnButtonRightB(){
    x++;
    if (x > 9) x = -1;
    rects[0].move(x,y);
}

void Model::reactOnButtonRightC(){
    y++;
    if (y > 9) y = -1;
    rects[0].move(x,y);
}

void Model::capture(){
    this->state->capture();
}

void update(){
    
}