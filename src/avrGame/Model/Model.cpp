#include "Model.h"


Model::Model(){ 
    x = 0;
}

void Model::reactOnButtonLeftA(){
    x++;
}

void Model::capture(){
    r1.move(x, 0);
}