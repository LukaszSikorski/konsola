#ifndef _SNAKE_H
#define _SNAKE_H

#include <avr/io.h>

namespace Direction{
    enum Direction{
        stop,
        left,
        right,
        up,
        down
    };
}

class Chunk{

    public:
        void move(uint8_t x, uint8_t y);
        void moveTo(uint8_t x, uint8_t y);
        void moveTo(Chunk *chunk);
        Chunk();
        Chunk(uint8_t x, uint8_t y);
        void setX(uint8_t x);
        void setY(uint8_t y);
        uint8_t getX(void);
        uint8_t getY(void);
    private:
        uint8_t x:4;
        uint8_t y:4;
};

class Snake{
    public:
        Snake();
        uint8_t lenght;
        Chunk chunks[64];


};




#endif //