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
        Matrix *matrix;
        uint8_t x,y;
        Model();
        Model(Matrix *matrix);
        Rect rects[2];
        void reactOnButtonLeftA(void);
        void reactOnButtonLeftB(void);
        void reactOnButtonLeftC(void);
        void reactOnButtonRightA(void);
        void reactOnButtonRightB(void);
        void reactOnButtonRightC(void);
        void capture(void);
        void update(void);
};

#endif // _MODEL_H