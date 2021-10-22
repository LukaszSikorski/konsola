#ifndef _STATE_H
#define _STATE_H

#include "Snake/Snake.h"
#include <avr/io.h>
#include "../View/Figures.h"
#include "CareTaker.h"

#define HUMNAN_SIZE_SPEED 6
#define SIZE_SPEED HUMNAN_SIZE_SPEED 
#define TIMER_ANIMATION 60
#define SIZE_STATES 2
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
        Snake snake = Snake(2);
        CareTaker careTaker;

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
        int8_t index;
        State *current;
        State *states[SIZE_STATES];
        Games games;

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
        inline State *setTarget(State *target);
        State *targetState;
    private:
        void drawAnimation();
        uint8_t timerAnimation;
        uint8_t loading;


};

class MenuStateSnake:public State{
    public:
        MenuStateSnake(Model *);
        void reactOnButtonLeftA(void);
        void reactOnButtonLeftB(void);
        void reactOnButtonTop(void);
        // void reactOnButtonDown(void);
        void reactOnButtonRight(void);
        void reactOnButtonLeft(void);
        void capture(void);
        // void update();
        // void init();
    private:

        void drawLevelSpeed();
        Games games;
        uint8_t levelSpeed;

};

class MenuStateTest:public State{
    public:
        MenuStateTest(Model *);
        // void reactOnButtonLeftA(void);
        // void reactOnButtonLeftB(void);
        void reactOnButtonTop(void);
        // void reactOnButtonDown(void);
        // void reactOnButtonRight(void);
        // void reactOnButtonLeft(void);
        void capture(void);
        // void update();
        // void init();
    private:

        // void drawLevelSpeed();


};

#endif