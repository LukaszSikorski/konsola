#ifndef _LOGIC_H
#define _LOGIC_H

#include <avr/io.h>
#include "../Snake.h"
#include "../../../avrGame.h"


class Logic{
    public:
        static void drawChunk(Chunk &,Colors color ,Matrix &matrix);
        static void drawSnake(Snake &, Matrix &matrix);
        static void moveChunk( Chunk *chunk);
        static void moveSnake( Snake *snake);
        static Direction::Direction direction;
        static void moveLeft();
        static void moveRight();
        static void moveUp();
        static void moveDown();
        static uint16_t timerMove;


};


#endif //