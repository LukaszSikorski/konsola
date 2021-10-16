#ifndef _STATE_H
#define _STATE_H

#include "Snake/Snake.h"
#include <avr/io.h>
#include "../View/Figures.h"

class Model;

class State{
    public:
        State(Model *);
        Model *model;
        virtual void reactOnButtonLeftA(void);
        virtual void reactOnButtonLeftB(void);
        virtual void reactOnButtonTop(void);
        virtual void reactOnButtonDown(void);
        virtual void reactOnButtonRight(void);
        virtual void reactOnButtonLeft(void);
        virtual void capture();
        virtual void update();

};


class SnakeState:public State{
    public:
        SnakeState(Model *);
        void reactOnButtonLeftA(void);
        void reactOnButtonLeftB(void);
        void reactOnButtonTop(void);
        void reactOnButtonDown(void);
        void reactOnButtonRight(void);
        void reactOnButtonLeft(void);
        void capture(void);
        void update();
        Snake snake;

};

#endif