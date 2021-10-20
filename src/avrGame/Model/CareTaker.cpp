#include "CareTaker.h"

CareTaker::CareTaker(){
    index = 0;
}

void CareTaker::saveSnapShot(Snake *snake){
    this->mementoSnake[0] = MementoSnake(snake, snake->lenght, snake->lives, snake->chunks, snake->direction);
    index++;
    if(index > 1){
        index = 0;
    }
}

void CareTaker::undo(){
    int8_t tmpIndex = index - 1;
    if (tmpIndex < 0)
    {
        tmpIndex = 1;
    }
    
    this->mementoSnake[0].restore();
}