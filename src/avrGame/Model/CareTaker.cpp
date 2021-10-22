#include "CareTaker.h"

CareTaker::CareTaker(){
    index = 0;
}

void CareTaker::saveSnapShot(Snake *snake){
    this->mementoSnake[index] = MementoSnake(snake, snake->lenght, snake->lives, snake->chunks, snake->direction);
    ++index;
    if(index > SIZE_SNAPSHOT){
        index = 0;
    }
}

void CareTaker::undo(){
    int8_t tmpIndex = index - 1;
    if (tmpIndex < 0)
    {
        tmpIndex = SIZE_SNAPSHOT;
    }
    
    this->mementoSnake[index].restore();
}