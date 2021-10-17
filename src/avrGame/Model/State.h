#ifndef _STATE_H
#define _STATE_H

#include "Snake/Snake.h"
#include <avr/io.h>
#include "../View/Figures.h"
#define HUMNAN_SIZE_SPEED 6
#define SIZE_SPEED HUMNAN_SIZE_SPEED 
#define TIMER_ANIMATION 50

class Model;

enum Games{
    snake,
    test
};

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
        virtual void init();

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
        void init();
        Snake snake;

    private:

};

class MenuState:public State{
    public:
        MenuState(Model *);
        void reactOnButtonLeftA(void);
        void reactOnButtonLeftB(void);
        void reactOnButtonTop(void);
        void reactOnButtonDown(void);
        void reactOnButtonRight(void);
        void reactOnButtonLeft(void);
        void capture(void);
        void update();
        void init();
    private:

        void drawLevelSpeed();
        Games games;
        uint8_t levelSpeed;

};

class AnimationState:public State{
    public:
        AnimationState(Model *);
        // void reactOnButtonLeftA(void);
        // void reactOnButtonLeftB(void);
        // void reactOnButtonTop(void);
        // void reactOnButtonDown(void);
        // void reactOnButtonRight(void);
        // void reactOnButtonLeft(void);
        void capture(void);
        // void update();
        void init();
        State *targetState;
    private:
        void drawAnimation();
        uint8_t timerAnimation;
        uint8_t loading;


};

#endif