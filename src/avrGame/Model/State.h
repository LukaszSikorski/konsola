#ifndef _STATE_H
#define _STATE_H

#include "Games/Snake.h"
#include <avr/io.h>
#include "../View/Figures.h"
#include "CareTaker.h"
#include "Games/TicTacToe.h"

#define HUMNAN_SIZE_SPEED 8
#define SIZE_SPEED HUMNAN_SIZE_SPEED 
#define TIMER_ANIMATION 60
#define SIZE_STATES 2
#define COLOR_ANIMATION Colors::green
#define SNAKE_LIVES 3
#define SNAKE_SCORE  Colors::blue
#define SNAKE_HEAD Colors::green
#define SNAKE_TAIL Colors::red
#define SNAKE_LIVE Colors::purple
#define LIVE_CYCLE 10
#define MAX_LIVE 3
#define ROUND_FOR_NEW_LIVE 8

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
        Snake snake = Snake(SNAKE_LIVES);
        CareTaker careTaker;

    private:

};

class StateTicTacToe:public State{
    public:
        StateTicTacToe(Model *);
        void reactOnButtonLeftA(void);
        void reactOnButtonLeftB(void);
        // void reactOnButtonTop(void);
        // void reactOnButtonDown(void);
        // void reactOnButtonRight(void);
        // void reactOnButtonLeft(void);
        void capture(void);
        void update();
        // void init();

    private:
        TicTacToe ticTacToe;

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
        inline State *setTarget(State *target, bool = true);
        State *targetState;
    private:
        void drawAnimation();
        uint8_t timerAnimation;
        uint8_t loading;
        bool ini;


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

class MenuStateTicTacToe:public State{
    public:
        MenuStateTicTacToe(Model *);
        void reactOnButtonLeftA(void);
        void reactOnButtonLeftB(void);
        void reactOnButtonTop(void);
        // void reactOnButtonDown(void);
        // void reactOnButtonRight(void);
        // void reactOnButtonLeft(void);
        void capture(void);
        // void update(void);
        // void init();
    private:
        // void drawLevelSpeed();


};

#endif