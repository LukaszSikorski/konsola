#ifndef _CARETAKER_H
#define _CARETAKER_H

#include <avr/io.h>
#include "Games/Snake.h"

#define SIZE_SNAPSHOT 2

class CareTaker{
    public:
        CareTaker();
        void saveSnapShot(Snake *);
        void undo();

    private:
        MementoSnake mementoSnake[SIZE_SNAPSHOT];
        int8_t index;

};

#endif