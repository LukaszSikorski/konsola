#ifndef _LOGIC_H
#define _LOGIC_H

#include <avr/io.h>
#include "../Snake.h"
#include "../../../avrGame.h"
#include "../Live.h"







class Logic{
    public:
        static void drawChunk(Chunk &,Colors color ,Matrix &matrix);
        static void drawScore(Colors color ,Matrix &matrix);
        static void drawLive(Colors color ,Matrix &matrix);
        static void drawSnake(Snake &, Matrix &matrix);
        static void moveChunk( Chunk *chunk, Direction::Direction const *);
        static void moveSnake( Snake *snake);
        static void moveLeft(Snake *snake);
        static void moveRight(Snake *snake);
        static void moveUp(Snake *snake);
        static void moveDown(Snake *snake);
        static Chunk getRandomChunk();
        static void addChunkToSnake(Snake *snake, Chunk *chunk);
        static bool isFreePos(Snake *snake,Chunk *chunk);
        static bool isSnakeOnChunk(Snake *snake, Chunk *chunk);
        static bool isCollsion(Snake *snake);
        static Chunk getNewChunk(Snake *snake);
        static uint8_t getRandomPos(uint8_t from, uint8_t to);
        static uint16_t timerMove;
        static uint16_t timeMove;
        static Chunk score;
        static Live live;
        static bool pause;

    private:
        static void addLiveToSnake(Snake *snake);
        static void setDirectionSnake(Snake *snake);
};


#endif //