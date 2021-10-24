#ifndef _MODEL_H
#define _MODEL_H

#include <avr/io.h>
#include "../View/Figures.h"
#include "../View/Colors.h"
#include "State.h"


class Matrix;

class Model{
    public:
        State *state;
        SnakeState snakeState = SnakeState(this);
        MenuState menuState = MenuState(this);
        AnimationState animationState = AnimationState(this);
        MenuStateSnake menuStateSnake = MenuStateSnake(this);
        MenuStateTicTacToe menuStateTicTacToe = MenuStateTicTacToe(this);
        StateTicTacToe stateTicTacToe = StateTicTacToe(this);
        Matrix *matrix;
        uint8_t x,y;
        Model();
        Model(Matrix *matrix);
        void reactOnButtonLeftA(void);
        void reactOnButtonLeftB(void);
        void reactOnButtonDown(void);
        void reactOnButtonTop(void);
        void reactOnButtonLeft(void);
        void reactOnButtonRight(void);
        void capture(void);
        void update(void);
        void setAnimationTarget(State *state, bool ini);
};

#endif // _MODEL_H