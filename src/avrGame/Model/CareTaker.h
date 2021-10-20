#ifndef _CARETAKER_H
#define _CARETAKER_H

#include <avr/io.h>
#include "Snake/Snake.h"

class CareTaker{
    public:
        CareTaker();
        void saveSnapShot(Snake *);
        void undo();

    private:
        MementoSnake mementoSnake[1];
        int8_t index;

};

#endif