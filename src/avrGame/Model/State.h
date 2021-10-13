#ifndef _STATE_H
#define _STATE_H

#include <avr/io.h>
#include "../View/Figures.h"

class Model;

class State{
    public:
        State(Model *);
        Model *model;
        virtual void reactOnButtonLeftA(void);
        virtual void capture();
};


class SnakeState:public State{
    public:
        SnakeState(Model *);
        Rect rect;
        uint8_t x = 0, y = 0;
        void reactOnButtonLeftA(void);
        void capture(void);

};

#endif