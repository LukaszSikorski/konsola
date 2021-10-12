#include "Model.h"


Model::Model(Matrix *matrix){
    this->matrix = matrix;
    x = 0;
    y = 0;
    rects[0] = avrGame::rect(2, 2, 2, 2);
    rects[1] = avrGame::rect(2, 2, 3, 3);
}

void Model::reactOnButtonLeftA(){
    y--;
    if ( y < -1) y = 9;
    rects[0].move(x,y);
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
    avrGame::draw.rect(*(this->matrix), rects[0], red);
}

void update(){
    
}