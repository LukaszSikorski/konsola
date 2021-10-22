#include "CareTaker.h"

CareTaker::CareTaker(){
    index = 0;
}

void CareTaker::saveSnapShot(Snake *snake){
    this->mementoSnake[index] = MementoSnake(snake, snake->lenght, snake->lives, snake->chunks, snake->direction);
    ++index;
    if(index >= SIZE_SNAPSHOT){
        index = 0;
    }
}

void CareTaker::undo(){
    this->mementoSnake[index].restore();
    --index;
    if (index < 0)
    {
        index = SIZE_SNAPSHOT - 1;
    }
    
}