#ifndef _LOGIC_H
#define _LOGIC_H

#include <avr/io.h>
#include "../Snake.h"
#include "../../../avrGame.h"


class Logic{
    public:
        static void drawChunk(Chunk &,Colors color ,Matrix &matrix);
        static void drawScore(Colors color ,Matrix &matrix);
        static void drawSnake(Snake &, Matrix &matrix);
        static void moveChunk( Chunk *chunk);
        static void moveSnake( Snake *snake);
        static void moveLeft();
        static void moveRight();
        static void moveUp();
        static void moveDown();
        static Chunk getRandomChunk();
        static void addNewScore(Snake *snake);
        static bool isFreePos(Snake *snake,Chunk *chunk);
        static bool isOnScore(Snake *snake, Chunk *chunk);
        static void addChunkToSnake(Snake *snake, Chunk *chunk);
        static uint8_t getRandomPos(uint8_t from, uint8_t to);
        static Direction::Direction direction;
        static uint16_t timerMove;
        static Chunk score;


};


#endif //