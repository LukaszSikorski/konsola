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
        Chunk();
        Chunk(uint8_t x, uint8_t y);
        void clear();
        void move(uint8_t x, uint8_t y);
        void moveTo(const uint8_t x,const uint8_t y);
        void moveTo(Chunk *chunk);
        void setX(uint8_t x);
        void setY(uint8_t y);
        void show()const;
        uint8_t getX(void) const;
        uint8_t getY(void) const;
        bool operator==(const Chunk &chunk)const;
        bool operator!=(const Chunk &chunk)const;
    private:
        uint8_t x:4;
        uint8_t y:4;
};

class Snake{
    uint8_t live;
    
    public:
        Snake(const uint8_t live = 2);
        void clear();
        uint8_t lenght;
        Chunk chunks[64];
        Direction::Direction direction;

};




#endif //